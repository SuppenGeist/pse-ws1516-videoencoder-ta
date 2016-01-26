#include "exsistingfilters.h"
#include "ui_exsistingfilters.h"

ExsistingFilters::ExsistingFilters(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::ExsistingFilters)
{
    ui->setupUi(this);
}

ExsistingFilters::~ExsistingFilters()
{
    delete ui;
}
