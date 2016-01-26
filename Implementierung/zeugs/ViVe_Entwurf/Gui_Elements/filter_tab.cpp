#include "filter_tab.h"
#include "ui_filter_tab.h"
#include "qlabel.h"


Filter_tab::Filter_tab(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Filter_tab)
{
    ui->setupUi(this);

    //test to add some filter into the list
    findChild<QListWidget*>("selectedFilterList")->addItems(QString("a,b,c,d").split(","));
}

Filter_tab::~Filter_tab()
{
    delete ui;
}
