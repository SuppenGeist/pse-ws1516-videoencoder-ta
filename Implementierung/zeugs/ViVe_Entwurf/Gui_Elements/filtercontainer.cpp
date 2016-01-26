#include "filtercontainer.h"
#include "ui_filtercontainer.h"

FilterContainer::FilterContainer(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FilterContainer)
{
    ui->setupUi(this);
}

FilterContainer::~FilterContainer()
{
    delete ui;
}
