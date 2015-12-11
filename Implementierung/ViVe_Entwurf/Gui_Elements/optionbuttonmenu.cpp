#include "optionbuttonmenu.h"
#include "ui_optionbuttonmenu.h"

OptionButtonMenu::OptionButtonMenu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OptionButtonMenu)
{
    ui->setupUi(this);
}

OptionButtonMenu::~OptionButtonMenu()
{
    delete ui;
}
