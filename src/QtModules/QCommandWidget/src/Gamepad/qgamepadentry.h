#ifndef QGAMEPADENTRY_H
#define QGAMEPADENTRY_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGamepadManager>

class QGamepadEntry : public QWidget
{
    Q_OBJECT
public:
    explicit QGamepadEntry(const QString &name, QWidget *parent = 0);

    QPushButton *confButton();
    double value();

    void saveState(QString group);
    void restoreState(QString group);

private:
    QLabel *_name = new QLabel("");
    QLabel *_axis_label = new QLabel("");
    QDoubleSpinBox *_gain = new QDoubleSpinBox();
    QPushButton *_reverse = new QPushButton("rev.");
    QPushButton *_configure = new QPushButton("conf.");

    int _axis = -1;
    double _value = 0;

    void compute(double value);
    void configureAxis(int axis);
    void configure(int axis, double value);

signals:

public slots:
    void on_axis_changed(int axis, double value);

};

#endif // QGAMEPADENTRY_H
