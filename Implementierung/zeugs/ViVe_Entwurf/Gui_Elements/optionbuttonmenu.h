#ifndef OPTIONBUTTONMENU_H
#define OPTIONBUTTONMENU_H

#include <QFrame>

namespace Ui {
class OptionButtonMenu;
}

class OptionButtonMenu : public QFrame
{
    Q_OBJECT

public:
    explicit OptionButtonMenu(QWidget *parent = 0);
    ~OptionButtonMenu();

private:
    Ui::OptionButtonMenu *ui;
};

#endif // OPTIONBUTTONMENU_H
