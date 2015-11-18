#ifndef COMPARISONDIALOG_H
#define COMPARISONDIALOG_H

#include <QDialog>

namespace Ui {
class comparisonDialog;
}

class comparisonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit comparisonDialog(QWidget *parent = 0);
    ~comparisonDialog();

private:
    Ui::comparisonDialog *ui;
};

#endif // COMPARISONDIALOG_H
