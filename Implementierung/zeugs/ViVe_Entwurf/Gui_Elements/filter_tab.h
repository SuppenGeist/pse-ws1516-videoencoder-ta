#ifndef FILTER_TAB_H
#define FILTER_TAB_H

#include <QFrame>

namespace Ui {
class Filter_tab;
}

class Filter_tab : public QFrame
{
    Q_OBJECT

public:
    explicit Filter_tab(QWidget *parent = 0);
    ~Filter_tab();

private:
    Ui::Filter_tab *ui;
};

#endif // FILTER_TAB_H
