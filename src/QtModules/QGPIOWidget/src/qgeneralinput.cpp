#include "qgeneralinput.h"

QGeneralInput::QGeneralInput(QString label, QWidget *parent) :
    QGeneralIO(label,parent),
    _checkbox(new QCheckBox(this))
{
    setup(_checkbox);
}

bool QGeneralInput::isChecked()
{
    return _checkbox->isChecked();
}

void QGeneralInput::setChecked(bool check)
{
    _checkbox->setChecked(check);
}

QCheckBox *QGeneralInput::getCheckBox()
{
    return _checkbox;
}
