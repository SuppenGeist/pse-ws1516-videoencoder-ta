#include <QApplication>
#include "gui/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GUI::MainWindow mw;
    mw.show();

    return a.exec();
}
