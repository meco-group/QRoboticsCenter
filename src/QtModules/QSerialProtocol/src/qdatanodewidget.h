#ifndef QDATANODEWIDGET_H
#define QDATANODEWIDGET_H

#include <QWidget>
#include <qdatanode.h>

class QDataNodeWidget : public QDataNode
{
    Q_OBJECT
public:
    explicit QDataNodeWidget(QWidget *parent = 0);
    virtual QWidget *w() = 0;

};

#endif // QDATANODEWIDGET_H
