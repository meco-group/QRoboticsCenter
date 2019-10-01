#ifndef QPOSITIONCMDCSVCOMMAND_H
#define QPOSITIONCMDCSVCOMMAND_H

#include <qcsvcommanddatanodewidget.h>

class QPositionCmdCsvCommand : public QCsvReaderDataNodeWidget
{
    Q_OBJECT
public:
    QPositionCmdCsvCommand(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QPOSITIONCMDCSVCOMMAND_H
