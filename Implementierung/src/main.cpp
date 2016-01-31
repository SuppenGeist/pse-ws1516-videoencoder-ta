#include <QApplication>
#include "gui/MainWindow.h"
#include "gui/FilterContainerTab.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GUI::MainWindow mw;
    mw.show();

    QMainWindow *w = new QMainWindow();
    w->setCentralWidget(new GUI::FilterContainerTab(w->centralWidget()));
    w->show();

    return a.exec();
}
