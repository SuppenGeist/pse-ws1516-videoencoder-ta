#include <QApplication>
#include "gui.h"
#include "fileexplorer.h"
#include "comparisondialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileExplorer w;
    w.show();
    GUI g;
    g.show();

    comparisonDialog c;
    c.show();

    return a.exec();
}
