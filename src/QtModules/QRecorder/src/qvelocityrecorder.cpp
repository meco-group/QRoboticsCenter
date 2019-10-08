#include "qvelocityrecorder.h"

QVelocityRecorder::QVelocityRecorder(QObject *parent) :
    QXMLRecorder("Velocity", LOG_VELOCITY, parent)
{
    //do nothing
}

QString QVelocityRecorder::insertHeader()
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
    insert += "\t\t<value>vx</value>\n";
    insert += "\t\t<value>vy</value>\n";
    insert += "\t\t<value>vz</value>\n";
    insert += "\t\t<value>vxcmd</value>\n";
    insert += "\t\t<value>vycmd</value>\n";
    insert += "\t\t<value>vzcmd</value>\n";
    insert += "\t\t<value>vxact</value>\n";
    insert += "\t\t<value>vyact</value>\n";
    insert += "\t\t<value>vzact</value>\n";
    insert += "\t\t<value>vxcont</value>\n";
    insert += "\t\t<value>vycont</value>\n";
    insert += "\t\t<value>vzcont</value>\n";
    insert += "\t</labels>\n";

    return insert;
}

void QVelocityRecorder::receive(velocity_t velocity)
{
    if(isRecording()){
        QString line = "\t\t<row>";
        line += QString::number(velocity.time);
        line += "\t" + QString::number(velocity.vx);
        line += "\t" + QString::number(velocity.vy);
        line += "\t" + QString::number(velocity.vz);
        line += "\t" + QString::number(velocity.vx_cmd);
        line += "\t" + QString::number(velocity.vy_cmd);
        line += "\t" + QString::number(velocity.vz_cmd);
        line += "\t" + QString::number(velocity.vx_act);
        line += "\t" + QString::number(velocity.vy_act);
        line += "\t" + QString::number(velocity.vz_act);
        line += "\t" + QString::number(velocity.vx_cont);
        line += "\t" + QString::number(velocity.vy_cont);
        line += "\t" + QString::number(velocity.vz_cont);
        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}
