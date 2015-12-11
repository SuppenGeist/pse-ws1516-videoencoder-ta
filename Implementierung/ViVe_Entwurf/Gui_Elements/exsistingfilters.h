#ifndef EXSISTINGFILTERS_H
#define EXSISTINGFILTERS_H

#include <QScrollArea>

namespace Ui {
class ExsistingFilters;
}

class ExsistingFilters : public QScrollArea
{
    Q_OBJECT

public:
    explicit ExsistingFilters(QWidget *parent = 0);
    ~ExsistingFilters();

private:
    Ui::ExsistingFilters *ui;
};

#endif // EXSISTINGFILTERS_H
