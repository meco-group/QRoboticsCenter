#include "qcsvcommanddatanodewidget.h"

QCsvReaderDataNodeWidget::QCsvReaderDataNodeWidget(const QString& name, QWidget *parent) :
    QTypeCommandInterface(parent), _csv_reader(new QCsvReaderWidget(name, parent))
{

}

QWidget *QCsvReaderDataNodeWidget::w()
{
    return _csv_reader;
}

bool QCsvReaderDataNodeWidget::enabled()
{
    return _csv_reader->enabled();
}

void QCsvReaderDataNodeWidget::reset()
{
    _csv_reader->getCsvReader()->reset();
}

void QCsvReaderDataNodeWidget::saveState(QString group)
{
    _csv_reader->saveState(group);
}

void QCsvReaderDataNodeWidget::restoreState(QString group)
{
    _csv_reader->restoreState(group);
}
