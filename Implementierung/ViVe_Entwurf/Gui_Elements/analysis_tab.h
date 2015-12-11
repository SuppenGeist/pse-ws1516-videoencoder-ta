#ifndef ANALYSIS_TAB_H
#define ANALYSIS_TAB_H

#include <QFrame>

namespace Ui {
class Analysis_Tab;
}

class Analysis_Tab : public QFrame
{
    Q_OBJECT

public:
    explicit Analysis_Tab(QWidget *parent = 0);
    ~Analysis_Tab();

private:
    Ui::Analysis_Tab *ui;
};

#endif // ANALYSIS_TAB_H
