#include "qpositionrecorder.h"

QPositionRecorder::QPositionRecorder(QObject *parent) :
    QXMLRecorder("Position", LOG_POSITION, parent)
{
    //do nothing
}

QString QPositionRecorder::insertHeader()
{
    QString insert;

    // Excitation
    insert += "\t<excitation>\n";
    insert += "\t\t<type>unknown</type>\n";
    insert += "\t\t<fmin>0</fmin>\n";
    insert += "\t\t<fmax>inf</fmax>\n";
    insert += "\t\t<fs>0</fs>\n";
    insert += "\t\t<period>inf</period>\n";
    insert += "\t</excitation>\n";

    // Labels
    insert += "\t<labels>\n";
    insert += "\t\t<value>time</value>\n";
    insert += "\t\t<value>x</value>\n";
    insert += "\t\t<value>y</value>\n";
    insert += "\t\t<value>z</value>\n";
    insert += "\t\t<value>xcmd</value>\n";
    insert += "\t\t<value>ycmd</value>\n";
    insert += "\t\t<value>zcmd</value>\n";
    insert += "\t\t<value>xact</value>\n";
    insert += "\t\t<value>yact</value>\n";
    insert += "\t\t<value>zact</value>\n";
    insert += "\t\t<value>xcont</value>\n";
    insert += "\t\t<value>ycont</value>\n";
    insert += "\t\t<value>zcont</value>\n";
    insert += "\t</labels>\n";

    return insert;
}

void QPositionRecorder::receive(position_t position)
{
    if(isRecording()){
        QString line = "\t\t<row>";
        line += QString::number(position.time);
        line += "\t" + QString::number(position.x);
        line += "\t" + QString::number(position.y);
        line += "\t" + QString::number(position.z);
        line += "\t" + QString::number(position.x_cmd);
        line += "\t" + QString::number(position.y_cmd);
        line += "\t" + QString::number(position.z_cmd);
        line += "\t" + QString::number(position.x_act);
        line += "\t" + QString::number(position.y_act);
        line += "\t" + QString::number(position.z_act);
        line += "\t" + QString::number(position.x_cont);
        line += "\t" + QString::number(position.y_cont);
        line += "\t" + QString::number(position.z_cont);
        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}
