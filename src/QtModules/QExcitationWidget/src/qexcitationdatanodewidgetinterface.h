#ifndef QEXCITATIONDATANODEWIDGETINTERFACE_H
#define QEXCITATIONDATANODEWIDGETINTERFACE_H

#include <qdatanodewidget.h>

class QExcitationDataNodeWidgetInterface : public QDataNodeWidget
{
    Q_OBJECT
public:
    explicit QExcitationDataNodeWidgetInterface(QWidget *parent = 0) :
        QDataNodeWidget(parent){}

    virtual void enableExcitation() = 0;
    virtual void disableExcitation() = 0;

};

#endif // QEXCITATIONDATANODEWIDGETINTERFACE_H
