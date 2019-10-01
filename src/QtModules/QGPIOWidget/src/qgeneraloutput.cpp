#include "qgeneraloutput.h"

QGeneralOutput::QGeneralOutput(QString label, QWidget *parent) :
    QGeneralIO(label,parent)
{
    //do nothing
}

void QGeneralOutput::setup()
{
    QGeneralIO::setup(getSpinBox());
    getSpinBox()->setFixedWidth(100);
}
