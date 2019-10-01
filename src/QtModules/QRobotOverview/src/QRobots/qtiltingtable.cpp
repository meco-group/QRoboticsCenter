#include "qtiltingtable.h"

QTiltingTable::QTiltingTable(int id, QObject *parent) :
    QBalancingRobot(id,"TiltingTable",parent)
{
    // setup
    QBalancingWidget* w = balancingWindow()->balance()->balance();
    w->setJumping(); // Setup jumping
    w->map()->setRange(100.0); // Setup map widget
    w->map()->getRobot()->getMarker()->setSize(5.0);
    w->map()->getRobot()->getMarker()->setSize(0.0);
}

QIcon QTiltingTable::icon()
{
    return QIcon(":/robot_icons/tiltingtable.png");
}
