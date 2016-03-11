#include "testanalysistab.h"
#include "testmainwindow.h"

void TestFilterTab::loadVideo(QString path, int width, int height, int fps,
                              Utility::Compression compression, Utility::YuvType type) {
    //get LoadVideo button
    QPushButton* loadVideo;
    QList<QPushButton*> buttonList = TestMainWindow::getCurrentMainWindow()->findChildren<QPushButton*>();
    for(int i = 0; i < buttonList.length() ; i++) {
        if(buttonList.at(i)->text() == "Load new video") {
            loadVideo = buttonList.at(i);
        }
    }
    QVERIFY2(loadVideo != NULL,"Could not find load video button");
    QTest::qSleep(500);
    WriteYuvFilePath* writer = new WriteYuvFilePath;
    writer->setPath(path);
    writer->setHeight(height);
    writer->setWidth(width);
    writer->setFps(fps);
    writer->setYuvType(type);
    writer->setCompression(compression);
    writer->setThread(QThread::currentThread());
    writer->start();
    loadVideo->clicked();

    QCoreApplication::processEvents();
    QTest::qSleep(2000);
    QVERIFY2(path == TestMainWindow::getCurrentMainWindow()->getMemento()->getFilterTabMemento()->getRawVideo()->getPath(), "Wrong video path");
}

void TestAnalysisTab::init() {
    mw = TestMainWindow::getMainWindow();
}
void TestAnalysisTab::testAddVideo() {

}
