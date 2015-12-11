#ifndef FILTERCONTAINER_H
#define FILTERCONTAINER_H

#include <QFrame>

namespace Ui {
class FilterContainer;
}

class FilterContainer : public QFrame
{
    Q_OBJECT

public:
    explicit FilterContainer(QWidget *parent = 0);
    ~FilterContainer();

private:
    Ui::FilterContainer *ui;
};

#endif // FILTERCONTAINER_H
