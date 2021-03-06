#ifndef QBALANCINGWIDGET_H
#define QBALANCINGWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QButtonGroup>
#include <QVector2D>
#include <QVector3D>
#include <QtMath>
#include <QLabel>
#include <qmapwidget.h>
#include <qpolarplot.h>

namespace Ui {
class QBalancingWidget;
}

class QBalancingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QBalancingWidget(QWidget *parent = 0);
    ~QBalancingWidget();

    QFrame* controlsFrame();
    QFrame* widgetsFrame();
    QMapWidget* map();
    QPolarPlot* balance();

    void setJumping(bool jumping = true);

private:
    Ui::QBalancingWidget *ui;
    QButtonGroup *_controls;
    int _control_mode;
    bool _jumping;

signals:
    void controlModeChanged(int mode);

private slots:
    virtual void handleControlsClicked(int id);

public slots:
    virtual void updatePosition(QVector3D position);
    virtual void updateAttitude(QVector3D attitude);
    virtual void updateSpeedCommand(QVector2D command);

};

#endif // QBALANCINGWIDGET_H
