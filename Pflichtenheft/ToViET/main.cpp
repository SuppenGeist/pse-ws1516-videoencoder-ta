#include <QApplication>
#include "gui.h"
#include "fileexplorer.h"
#include "propertiesdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileExplorer w;
    w.show();
    GUI g;
    g.show();

    PropertiesDialog d;
    d.show();


    return a.exec();
}
