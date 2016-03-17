#include "testanalysistab.h"
#include "testmainwindow.h"

#include "../../src/undo_framework/AddVideo.h"
#include "../../src/gui/AnalysisBoxContainer.h"
#include "../../src/undo_framework/UndoStack.h"
void TestAnalysisTab::loadVideo(QString path, int width, int height, int fps,
                                Utility::Compression compression, Utility::YuvType type) {
	//get LoadVideo button
	QPushButton* loadVideo;
	QList<QPushButton*> buttonList =
	    TestMainWindow::getCurrentMainWindow()->findChildren<QPushButton*>();
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
	QVERIFY2(path ==
	         TestMainWindow::getCurrentMainWindow()->getMemento()->getAnalysisTabMemento()->getRawVideo()->getPath(),
	         "Wrong video path");
}

void TestAnalysisTab::init() {
	mw = TestMainWindow::getMainWindow();
}
void TestAnalysisTab::testAddVideo() {
	QTabWidget* tabWidget = mw->findChildren<QTabWidget*>().first();
	tabWidget->setCurrentIndex(1);
	qApp->processEvents();
	QTest::qSleep(500);
	loadVideo(QFINDTESTDATA("blumeYuv420_planar_176x144.yuv"));
	//we skip pressing the "Add video" button and use the UndoStack instead
	GUI::AnalysisBoxContainer* boxCon = mw->findChildren<GUI::AnalysisBoxContainer*>().first();
	QVERIFY2(boxCon != NULL, "Could not find AnalysisBoxContainer");
	UndoRedo::AddVideo* addVideo = new UndoRedo::AddVideo(boxCon,QFINDTESTDATA("blume.mp4"));
	UndoRedo::UndoStack::getUndoStack().push(addVideo);
	QCoreApplication::processEvents();
	QTest::qSleep(2000);
	QCoreApplication::processEvents();
	QVERIFY2(mw->getMemento()->getAnalysisTabMemento()->getAnalysisBoxContainerMemento()->getAnalysisBoxList().size()
	         == 1,"Could not add video");
	//test UndoRedo
	TestMainWindow::triggerAction("Undo");
	QCoreApplication::processEvents();
	QTest::qSleep(2000);
	QVERIFY2(mw->getMemento()->getAnalysisTabMemento()->getAnalysisBoxContainerMemento()->getAnalysisBoxList().size()
	         == 0,"Could not undo the adding of a video");
	TestMainWindow::triggerAction("Redo");
	QCoreApplication::processEvents();
	QTest::qSleep(2000);
	QVERIFY2(mw->getMemento()->getAnalysisTabMemento()->getAnalysisBoxContainerMemento()->getAnalysisBoxList().size()
	         == 1,"Could not redo the adding of a video");
}
void TestAnalysisTab::testGraphs() {
	//Add yuc and decoded video
	QTabWidget* tabWidget = mw->findChildren<QTabWidget*>().first();
	tabWidget->setCurrentIndex(1);
	qApp->processEvents();
	QTest::qSleep(500);
	loadVideo(QFINDTESTDATA("blumeYuv420_planar_176x144.yuv"));
	//we skip pressing the "Add video" button and use the UndoStack instead
	GUI::AnalysisBoxContainer* boxCon = mw->findChildren<GUI::AnalysisBoxContainer*>().first();
	QVERIFY2(boxCon != NULL, "Could not find AnalysisBoxContainer");
	UndoRedo::AddVideo* addVideo = new UndoRedo::AddVideo(boxCon,QFINDTESTDATA("blume.mp4"));
	UndoRedo::UndoStack::getUndoStack().push(addVideo);
	QCoreApplication::processEvents();
	QTest::qSleep(2000);
	QCoreApplication::processEvents();

	TestMainWindow::clickButton("Red histogram");
	QTest::qSleep(1000);
	//raw vid
	QVERIFY2(qGray(mw->grab().toImage().pixel(600,110))==255 , "Failed clicking Red histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(360,250))!=255 , "Failed clicking Red histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(525,260))==255 , "Failed clicking Red histogramm");
	//encoded vid
	QVERIFY2(qGray(mw->grab().toImage().pixel(570,500))==255 , "Failed clicking Red histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(330,600))!=255 , "Failed clicking Red histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(470,600))==255 , "Failed clicking Red histogramm");

	TestMainWindow::clickButton("Green histogram");
	QTest::qSleep(1000);
	//raw vid
	QVERIFY2(qGray(mw->grab().toImage().pixel(600,110))==255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(360,250))!=255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(525,260))!=255 , "Failed clicking Green histogramm");
	//encoded vid
	QVERIFY2(qGray(mw->grab().toImage().pixel(570,500))==255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(330,600))!=255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(470,630))!=255 , "Failed clicking Green histogramm");

	TestMainWindow::clickButton("Blue histogram");
	QTest::qSleep(1000);
	//raw vid
	QVERIFY2(qGray(mw->grab().toImage().pixel(600,110))==255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(340,250))!=255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(525,260))==255 , "Failed clicking Green histogramm");
	//encoded vid
	QVERIFY2(qGray(mw->grab().toImage().pixel(550,500))==255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(345,600))!=255 , "Failed clicking Green histogramm");
	QVERIFY2(qGray(mw->grab().toImage().pixel(470,600))==255 , "Failed clicking Green histogramm");
}


void TestAnalysisTab::testCommentBox() {
    //Add yuc and 2 decoded videos
    QTabWidget* tabWidget = mw->findChildren<QTabWidget*>().first();
    tabWidget->setCurrentIndex(1);
    qApp->processEvents();
    QTest::qSleep(500);
    loadVideo(QFINDTESTDATA("blumeYuv420_planar_176x144.yuv"));
    //we skip pressing the "Add video" button and use the UndoStack instead
    GUI::AnalysisBoxContainer* boxCon = mw->findChildren<GUI::AnalysisBoxContainer*>().first();
    QVERIFY2(boxCon != NULL, "Could not find AnalysisBoxContainer");
    UndoRedo::AddVideo* addVideo = new UndoRedo::AddVideo(boxCon,QFINDTESTDATA("blume.mp4"));
    UndoRedo::UndoStack::getUndoStack().push(addVideo);
    QCoreApplication::processEvents();
    QTest::qSleep(2000);
    QCoreApplication::processEvents();
    addVideo = new UndoRedo::AddVideo(boxCon,QFINDTESTDATA("blume.mp4"));
    UndoRedo::UndoStack::getUndoStack().push(addVideo);
    QCoreApplication::processEvents();
    QTest::qSleep(2000);
    QCoreApplication::processEvents();
    QPlainTextEdit* lineEditBox1 = mw->findChildren<GUI::AnalysisBox*>().first()->findChildren<QPlainTextEdit*>().first();
    QPlainTextEdit* lineEditBox2 = mw->findChildren<GUI::AnalysisBox*>().at(1)->findChildren<QPlainTextEdit*>().first();

    tabWidget = mw->findChildren<GUI::AnalysisBox*>().first()->findChildren<QTabWidget*>().first();
    tabWidget->setCurrentIndex(1);
    qApp->processEvents();
    tabWidget = mw->findChildren<GUI::AnalysisBox*>().at(1)->findChildren<QTabWidget*>().first();
    tabWidget->setCurrentIndex(1);
    qApp->processEvents();
    lineEditBox1->selectAll();
    QApplication::postEvent(lineEditBox1,new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,"test 1"));
    TestMainWindow::waitForWindow(300);
    QVERIFY2(lineEditBox1->toPlainText() == "test 1", "Error writing comment");
    TestMainWindow::triggerAction("Undo");
    TestMainWindow::waitForWindow(300);
    QVERIFY2(lineEditBox1->toPlainText() != "test 1", "Error undoing the writing of a comment");
    TestMainWindow::triggerAction("Redo");
    TestMainWindow::waitForWindow(300);
    QVERIFY2(lineEditBox1->toPlainText() == "test 1", "Error redoing the writing of a comment");
    lineEditBox2->selectAll();
    QApplication::postEvent(lineEditBox2,new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,"test 2"));
    TestMainWindow::waitForWindow(300);
    QApplication::postEvent(lineEditBox1,new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,"continue writing"));
    TestMainWindow::waitForWindow(300);
    QApplication::postEvent(lineEditBox2,new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier," more"));
    TestMainWindow::waitForWindow(300);
    QVERIFY2(lineEditBox1->toPlainText() == "test 1continue writing", "Error writing comment");
    QVERIFY2(lineEditBox2->toPlainText() == "test 2 more", "Error writing comment");
    TestMainWindow::triggerAction("Undo");
    TestMainWindow::waitForWindow(300);
    QVERIFY2(lineEditBox1->toPlainText() == "test 1continue writing", "Error writing comment");
    QVERIFY2(lineEditBox2->toPlainText() != "test 2 more", "Error undoing writing a comment");
    TestMainWindow::triggerAction("Redo");
    TestMainWindow::waitForWindow(300);
    QVERIFY2(lineEditBox1->toPlainText() == "test 1continue writing", "Error writing comment");
    QVERIFY2(lineEditBox2->toPlainText() == "test 2 more", "Error undoing writing a comment");
}








