#include "qgpioinputdialog.h"
#include "ui_qgpioinputdialog.h"

QGPIOInputDialog::QGPIOInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QGPIOInputDialog),
    _file(new QFile(this)),
    _stream(new QTextStream(_file)),
    _repeat(false),
    _popup(new QAction("CSV input", this))
{
    ui->setupUi(this);
    loadSettings();

    QObject::connect(ui->open,SIGNAL(released()),this,SLOT(openFile()));
    QObject::connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(handleStartButton(bool)));
    QObject::connect(_popup,SIGNAL(triggered()),this,SLOT(show()));
    QObject::connect(ui->name_lineEdit,SIGNAL(textEdited(QString)),this,SLOT(setFile(QString)));
}

QGPIOInputDialog::~QGPIOInputDialog()
{
    delete ui;
}

QAction *QGPIOInputDialog::getPopupAction()
{
    return _popup;
}

void QGPIOInputDialog::readHeader()
{
    QStringList columns;
    QString header;
    QString line;

    do {
        header += line;
        _csv_begin = _stream->pos();
        line = _stream->readLine();
        columns = line.split('\t',QString::SkipEmptyParts);
        line += '\n';
    } while(columns.length() < 2);
    resetCsv();

    ui->header_label->setText(header);
}

void QGPIOInputDialog::readCsvLine() {
  // read line and pack in struct
  if(!_stream->atEnd()) {
    QStringList columns = _stream->readLine().split('\t',QString::SkipEmptyParts);
    gpiox_t gpiox;
    if(columns.length() > 0) {
      gpiox.time = columns[0].toUInt();
    }
    if(columns.length() > 1) {
      int k = 1;
      while((k < QGPIOWIDGET_FLOAT_COUNT+1) && (k < columns.length())) {
        gpiox.gpio_float[k-1] = columns[k].toFloat();
        k++;
      }
    }

    emit setGpioOutput(gpiox);

    ui->progressBar->setValue(_stream->pos());
  }

  // check end of file
  if(_stream->atEnd()){
    if(!_repeat){
      stop();
    }
  }
}

void QGPIOInputDialog::resetCsv()
{
    _stream->seek(_csv_begin); //go to start of csv
}

void QGPIOInputDialog::saveSettings()
{
    QSettings settings("RobSoft", "QGPIOWidget");
    settings.beginGroup("QGPIOInputDialog");
    // save filename
    settings.setValue("filename",_file->fileName());
    settings.endGroup();
}

void QGPIOInputDialog::loadSettings()
{
    QSettings settings("RobSoft", "QGPIOWidget");
    settings.beginGroup("QGPIOInputDialog");
    // save filename
    setFile(settings.value("filename").toString());
    settings.endGroup();
}

void QGPIOInputDialog::timerEvent(QTimerEvent*)
{
    readCsvLine();
}

void QGPIOInputDialog::closeEvent(QCloseEvent*)
{
    saveSettings();
}

bool QGPIOInputDialog::setFile(QString absolute_path)
{
    if(_file->isOpen()){
        _file->close();
    }

    _file->setFileName(absolute_path);
    if(_file->exists()){
        ui->name_lineEdit->setText(absolute_path);
        ui->progressBar->setMaximum(_file->size());
        _file->open(QFile::ReadOnly);
        _stream->seek(0);
        readHeader();
        return true;
    }

    return false;
}

void QGPIOInputDialog::openFile()
{
    QFileInfo info(*_file);
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                info.path(),
                                                tr("CSV files (*.csv *.txt)"));
    if(!path.isEmpty()){
        setFile(path);
    }
}

void QGPIOInputDialog::handleStartButton(bool checked)
{
    if(checked)
        start();
    else
        stop();
}

void QGPIOInputDialog::start()
{
    _timer_id = startTimer(10,Qt::PreciseTimer);
    qDebug() << "started timer";
}

void QGPIOInputDialog::stop()
{
    killTimer(_timer_id);
    ui->start->setChecked(false);
    resetCsv();
}
