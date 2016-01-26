#ifndef PICKABLEFILTERS_H
#define PICKABLEFILTERS_H

#include <QWidget>

namespace Ui {
class PickableFilters;
}

class PickableFilters : public QWidget
{
    Q_OBJECT

public:
    explicit PickableFilters(QWidget *parent = 0);
    ~PickableFilters();

private:
    Ui::PickableFilters *ui;
};

#endif // PICKABLEFILTERS_H
