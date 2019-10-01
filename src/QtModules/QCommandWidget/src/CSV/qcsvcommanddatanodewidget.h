#ifndef QCSVREADERDATANODEWIDGET_H
#define QCSVREADERDATANODEWIDGET_H

#include <qdatanodewidget.h>
#include <qtypecommandinterface.h>
#include <qcsvreaderwidget.h>

class QCsvReaderDataNodeWidget : public QTypeCommandInterface
{
    Q_OBJECT
public:
    explicit QCsvReaderDataNodeWidget(const QString &name, QWidget *parent = 0);

    virtual QWidget *w();
    virtual void transmit_packet() = 0;
    virtual bool enabled();
    virtual void reset();

    virtual void saveState(QString group);
    virtual void restoreState(QString group);

protected:
    QCsvReaderWidget* _csv_reader;

};

#endif // QCSVREADERDATANODEWIDGET_H
