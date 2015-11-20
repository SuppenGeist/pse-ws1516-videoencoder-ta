#include "fileexplorer.h"
#include "ui_fileexplorer.h"

FileExplorer::FileExplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileExplorer)
{
    ui->setupUi(this);

    QString sPath = "C;/";
    dirmodel = new QFileSystemModel(this);
    dirmodel -> setRootPath(sPath);
    ui->treeView->setModel(dirmodel);
}

FileExplorer::~FileExplorer()
{
    delete ui;
}
