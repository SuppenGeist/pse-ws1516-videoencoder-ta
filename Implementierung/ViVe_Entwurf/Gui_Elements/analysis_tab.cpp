#include "analysis_tab.h"
#include "ui_analysis_tab.h"

Analysis_Tab::Analysis_Tab(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Analysis_Tab)
{
    ui->setupUi(this);
}

Analysis_Tab::~Analysis_Tab()
{
    delete ui;
}
