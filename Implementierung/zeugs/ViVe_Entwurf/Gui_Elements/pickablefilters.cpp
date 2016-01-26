#include "pickablefilters.h"
#include "ui_pickablefilters.h"
#include "filtercontainer.h"

PickableFilters::PickableFilters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PickableFilters)
{
    ui->setupUi(this);

    //test to add some Filters to pick
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
    findChild<QHBoxLayout*>("horizontalLayout")->addWidget(new FilterContainer());
}

PickableFilters::~PickableFilters()
{
    delete ui;
}
