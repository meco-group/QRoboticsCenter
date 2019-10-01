#include "qaxisdialog.h"
#include "ui_qaxisdialog.h"

QAxisDialog::QAxisDialog(QCPAxis *axis, bool *autoscale, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAxisDialog),
    _axis(axis),
    _autoscale(autoscale)
{
    ui->setupUi(this);
    this->setWindowTitle("Axis settings");

    QObject::connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(handleCheckboxToggled(bool)));
    ui->checkBox->setChecked(*autoscale);
    QObject::connect(this,SIGNAL(accepted()),this,SLOT(close()));
    QObject::connect(this,SIGNAL(rejected()),this,SLOT(close()));
}

QAxisDialog::~QAxisDialog()
{
    delete ui;
}

void QAxisDialog::handleCheckboxToggled(bool autoscale)
{
    if(autoscale)
        setReadOnly();
    else
        setEditable();
}

void QAxisDialog::setReadOnly()
{
    QList<QLineEdit*> list;
    list << ui->lineEdit_minimum << ui->lineEdit_maximum << ui->lineEdit_ticksize;
    QListIterator<QLineEdit*> i(list);
    while(i.hasNext()){
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::gray);
        palette->setColor(QPalette::Text,Qt::darkGray);
        i.peekNext()->setPalette(*palette);
        i.next()->setReadOnly(true);
    }
}

void QAxisDialog::setEditable()
{
    QList<QLineEdit*> list;
    list << ui->lineEdit_minimum << ui->lineEdit_maximum << ui->lineEdit_ticksize;
    QListIterator<QLineEdit*> i(list);
    while(i.hasNext()){
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::white);
        palette->setColor(QPalette::Text,Qt::black);
        i.peekNext()->setPalette(*palette);
        i.next()->setReadOnly(false);
    }
}

void QAxisDialog::closeEvent(QCloseEvent *)
{
    if(result()==QDialog::Accepted){
        // set the autoscaling field
        *_autoscale = ui->checkBox->isChecked();

        // set axis preferences
        if(!(*_autoscale)){
            if(!(ui->lineEdit_minimum->text().isEmpty() || ui->lineEdit_maximum->text().isEmpty())){
                _axis->setRange(ui->lineEdit_minimum->text().toDouble(),ui->lineEdit_maximum->text().toDouble());
            }
            if(!ui->lineEdit_ticksize->text().isEmpty()){
                //_axis->setAutoTickStep(false);
                //_axis->setTickStep(ui->lineEdit_ticksize->text().toDouble());
            }
        } else { // set autoticks on
            //_axis->setAutoTicks(true);
            _axis->rescale();
        }
    }
}


