#include "testmainwindow.h"

#include <memory>
#include <QPoint>

#include "../../src/memento/MainWindowMemento.h"



void TestMainWindow::init() {
    mw = new GUI::MainWindow;

}
void TestMainWindow::testAddFilterWithoutVid() {
    std::unique_ptr<Memento::MainWindowMemento> oldMemo = mw->getMemento();
    QTest::mouseClick(mw,Qt::LeftButton,0,QPoint(75,725));
    std::unique_ptr<Memento::MainWindowMemento> newMemo = mw ->getMemento();
    Memento::MainWindowMemento* m;
    QVERIFY(oldMemo->getFilterTabMemento()->getFilterList()->getSize() == newMemo->getFilterTabMemento()->getFilterList()->getSize());
    oldMemo.release();
    newMemo.release();
}
