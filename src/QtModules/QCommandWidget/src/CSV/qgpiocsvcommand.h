#ifndef QGPIOCSVCOMMAND_H
#define QGPIOCSVCOMMAND_H

#include <qcsvcommanddatanodewidget.h>

class QGpioCsvCommand : public QCsvReaderDataNodeWidget
{
    Q_OBJECT
public:
    QGpioCsvCommand(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QGPIOCSVCOMMAND_H
