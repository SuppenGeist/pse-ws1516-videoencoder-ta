#include "analysisbox.h"
#include "ui_analysisbox.h"

AnalysisBox::AnalysisBox(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::AnalysisBox)
{
    ui->setupUi(this);
}

AnalysisBox::~AnalysisBox()
{
    delete ui;
}
