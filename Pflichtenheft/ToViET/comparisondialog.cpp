#include "comparisondialog.h"
#include "ui_comparisondialog.h"

comparisonDialog::comparisonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comparisonDialog)
{
    ui->setupUi(this);
}

comparisonDialog::~comparisonDialog()
{
    delete ui;
}
