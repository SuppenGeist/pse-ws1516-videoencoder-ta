#include "gui.h"
#include "ui_GUI.h"

GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);


}

GUI::~GUI()
{
    delete ui;
}

