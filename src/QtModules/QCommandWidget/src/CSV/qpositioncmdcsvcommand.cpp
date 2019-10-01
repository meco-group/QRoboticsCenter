#include "qpositioncmdcsvcommand.h"

QPositionCmdCsvCommand::QPositionCmdCsvCommand(QWidget *parent) :
    QCsvReaderDataNodeWidget("position cmd",parent)
{

}

void QPositionCmdCsvCommand::transmit_packet()
{
    position_cmd_t position_cmd;

    QList<double> values = _csv_reader->readLine();
    while(values.length() < 6)
        values.append(0.0);

    QListIterator<double> i(values);
    position_cmd.x = i.next();
    position_cmd.y = i.next();
    position_cmd.z = i.next();
    position_cmd.xFF = i.next();
    position_cmd.yFF = i.next();
    position_cmd.zFF = i.next();

    emit transmit(position_cmd);
}
