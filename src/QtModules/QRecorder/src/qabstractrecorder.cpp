#include "qabstractrecorder.h"

QAbstractRecorder::QAbstractRecorder(const QString& type, const int id, QObject *parent) :
    QDataNode(parent), _type(type), _id(id), _record(new QAction(_type, parent))
{
    _record->setCheckable(true);
    _record->setChecked(false);
    QObject::connect(_record, &QAction::toggled, this, &QAbstractRecorder::activate);
}

bool QAbstractRecorder::isRecording()
{
    return _record->isChecked();
}

QAction *QAbstractRecorder::record()
{
    return _record;
}

void QAbstractRecorder::start()
{
    // open file
    QString dir = QDir::homePath() + "/QRCrecords";
    QDir().mkdir(dir);
    _log = new QFile(dir + "/log_" + _type.toLower() + "_" + QDateTime::currentDateTime().toString("MM_dd_HH_mm") + ".xml", this);
    _log->open(QIODevice::WriteOnly);

    // create header
    createHeader();

    // send logging events
    event_t event;
    event.type = _id;
    transmit(event);
    event.type = LOG_START;
    transmit(event);
}

void QAbstractRecorder::stop()
{
    // send logging event
    event_t event;
    event.type = LOG_STOP;
    transmit(event);

    // close file
    createFooter();
    _log->close();
}

void QAbstractRecorder::createHeader()
{
    QString header;
    header = "<Q" + _type + "Record>\n";

    // Time
    QDateTime now = QDateTime::currentDateTime();
    header += "\t<time>\n";
    header += "\t\t<year>" + now.toString("yyyy") + "</year>\n";
    header += "\t\t<month>" + now.toString("MM") + "</month>\n";
    header += "\t\t<day>" + now.toString("dd") + "</day>\n";
    header += "\t\t<hour>" + now.toString("HH") + "</hour>\n";
    header += "\t\t<minute>" + now.toString("mm") + "</minute>\n";
    header += "\t</time>\n";

    // Version
    header += "\t<version>2.1</version>\n";

    // Comment
    header += "\t<comment></comment>\n";
    header += "\n";

    // Labels
    header += insertHeader();
    header += "\n";

    // Data
    header += "\t<data>\n";

    _log->write(header.toLocal8Bit());
}

void QAbstractRecorder::createFooter()
{
    QString footer;
    footer += "\t</data>\n";
    footer += "</Q" + _type + "Record>";

    _log->write(footer.toLocal8Bit());
}

QString QAbstractRecorder::insertHeader()
{
    return "";
}

void QAbstractRecorder::activate(bool active)
{
    if(active) {
        start();
    } else {
        stop();
    }
}
