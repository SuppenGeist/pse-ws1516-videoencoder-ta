#include "analysisboxcontainer.h"
#include "ui_analysisboxcontainer.h"

AnalysisBoxContainer::AnalysisBoxContainer(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::AnalysisBoxContainer)
{
    ui->setupUi(this);
}

AnalysisBoxContainer::~AnalysisBoxContainer()
{
    delete ui;
}
