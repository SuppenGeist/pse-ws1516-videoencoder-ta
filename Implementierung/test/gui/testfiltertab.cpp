#include "testfiltertab.h"

#include "testmainwindow.h"
#include "QVBoxLayout"
void TestFilterTab::clickItemInFilterList(int index) {
	QList<QListView*> listViewList = TestMainWindow::getCurrentMainWindow()->findChildren<QListView*>();
	QListView* listView;
	for(int i = 0; i < listViewList.length() ; i++) {
		if(listViewList.at(i)->objectName() == "list_filterlist_") {
			listView = listViewList.at(i);
		}
	}
	QVERIFY2(listView != NULL, "listview not found");
	listView->setCurrentIndex(listView->indexAt(QPoint(10,10+index*20)));
	qApp->processEvents();
	QTest::qSleep(250);
}

void TestFilterTab::init() {
	mw = TestMainWindow::getMainWindow();

}
void TestFilterTab::loadVideo(QString path, int width, int height, int fps,
                              Utility::Compression compression, Utility::YuvType type) {
	//get LoadVideo button

	QPushButton* loadVideo;
	QList<QPushButton*> buttonList =
	    TestMainWindow::getCurrentMainWindow()->findChildren<QPushButton*>();
	for(int i = 0; i < buttonList.length() ; i++) {
		if(buttonList.at(i)->text() == "Load video") {
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
	         TestMainWindow::getCurrentMainWindow()->getMemento()->getFilterTabMemento()->getRawVideo()->getPath(),
	         "Wrong video path");
}
void TestFilterTab::testLoadVideo() {
    loadVideo(QFINDTESTDATA("akiyo_qcif.yuv"));
	loadVideo(QFINDTESTDATA("blumeYuv444_packed_176x144.yuv"),176,144,30,Utility::Compression::PACKED,
	          Utility::YuvType::YUV444);

}
void TestFilterTab::testAddFilterWithoutVid() {
	std::unique_ptr<Memento::MainWindowMemento> oldMemo = mw->getMemento();
	qApp->processEvents();
	QTest::qSleep(500);

	TestMainWindow::clickButton("Add Blur filter");
	std::unique_ptr<Memento::MainWindowMemento> newMemo = mw ->getMemento();

	QVERIFY2(oldMemo->getFilterTabMemento()->getFilterList()->getSize() ==
	         newMemo->getFilterTabMemento()->getFilterList()->getSize(),
	         "filter got added without picking a video");
	QVERIFY2(newMemo->getFilterTabMemento()->isPreviewShow() ==
	         oldMemo->getFilterTabMemento()->isPreviewShow(),"shows preview");
}
void TestFilterTab::testAddRemoveFilters() {
    //QVERIFY2(false,"Known bug in ffmpeg when using specific filters or combinations of filers");
	loadVideo(QFINDTESTDATA("akiyo_qcif.yuv"));

	TestMainWindow::clickButton("Add Blur filter");
	TestMainWindow::waitForWindow();
	TestMainWindow::clickButton("Add Colorbalance filter");
	TestMainWindow::waitForWindow();
	TestMainWindow::clickButton("Add Border filter");
	TestMainWindow::waitForWindow();
	QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 3,
	         "error adding filters");
    //TestMainWindow::triggerAction("Undo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 2,
     //        "error undoing add filter");
	clickItemInFilterList(1);
	TestMainWindow::clickButton("Remove filter");
	TestMainWindow::waitForWindow();
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 2,
	         "error pressing \"Remove filter\"");
	QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(
	             0)->getName() == "Blur", "error pressing \"Remove filter\" : wrong filter removed");
    //TestMainWindow::triggerAction("Undo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 2,
    //         "error undoing \"Remove filter\"-Press");
    //TestMainWindow::triggerAction("Redo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 1,
    //         "error redoing \"Remove filter\"-Press");
	QTest::qSleep(500);
	QRgb lastRgb = mw->grab().toImage().pixel(630,300);
	TestMainWindow::clickButton("Add Negative filter");
	TestMainWindow::waitForWindow(2000);
	QVERIFY2(lastRgb != mw->grab().toImage().pixel(630,300), "Failed applying negative filter");
	TestMainWindow::clickButton("Add Negative filter");
	TestMainWindow::waitForWindow(2000);
	QVERIFY2(lastRgb != mw->grab().toImage().pixel(630,300), "Failed applying negative filter twice");
}
void TestFilterTab::testFilterList() {
    //QVERIFY2(false,"Known bug in ffmpeg when using specific filters or combinations of filers");
	loadVideo(QFINDTESTDATA("akiyo_qcif.yuv"));

	//make a white grid filter
	TestMainWindow::clickButton("Add Negative filter");
	TestMainWindow::clickButton("Add Grid filter");
	TestMainWindow::clickButton("Add Negative filter");
	TestMainWindow::waitForWindow();
	//a pixel that should be on the grid gitter
	QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 ,
	         "Failed to apply grid and negative filter");
	//now we swap negative filter and grid filter to make the gitter black
	clickItemInFilterList(1);
	TestMainWindow::clickButton("Filter up");
	TestMainWindow::waitForWindow();
	QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==0 , "Error when clicking \"Filter up\"");
	//testing undo and redo
    //TestMainWindow::triggerAction("Undo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 , "Error undoing click on \"Filter up\"");
    //TestMainWindow::triggerAction("Redo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==0 , "Error undoing click on \"Filter up\"");
	//now everything for filter down
	//we should currently have the filterlist "grid, negative, negative"
	QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 3
	         && mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(0)->getName() == "Grid"
	         && mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(1)->getName() == "Negative"
	         && mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(2)->getName() == "Negative",
	         "Error: unkown cause");
	//now we swap negative filter and grid filter to make the gitter black
	clickItemInFilterList(0);
	TestMainWindow::clickButton("Filter down");
	TestMainWindow::waitForWindow();
	QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 , "Error when clicking \"Filter down\"");
	//testing undo and redo
    //TestMainWindow::triggerAction("Undo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==0 , "Error undoing click on \"Filter down\"");
    //TestMainWindow::triggerAction("Redo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 ,
    //        "Error undoing click on \"Filter down\"");

	//now we try filter up on the first element, where nothing should happen, and the same on the last
	//we should currently have the filterlist "negative,grid, negative"
	QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 3
	         && mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(0)->getName() == "Negative"
	         && mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(1)->getName() == "Grid"
	         && mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(2)->getName() == "Negative",
	         "Error: unkown cause");
	QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 , "Error: unkwon cause");
	clickItemInFilterList(0);
	TestMainWindow::clickButton("Filter up");
	TestMainWindow::waitForWindow();
	QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 ,
	         "Error: clicking \"Filter up\" while first filter is selected");
	clickItemInFilterList(2);
	TestMainWindow::clickButton("Filter down");
	TestMainWindow::waitForWindow();
	QVERIFY2(qGray(mw->grab().toImage().pixel(630,300))==255 ,
	         "Error: clicking \"Filter down\" while las filter is selected");
	//now we test the reset button

	//there are multiple reset buttons so we cant use clickButton()QList<QPushButton*> buttonList = parent->findChildren<QPushButton*>();

	QPushButton* button = mw->findChild<QPushButton*>("filterTab_button_reset_");
	QVERIFY2(button != NULL,  "couldnt find reset button");
	button->clicked();
	qApp->processEvents();
	QTest::qSleep(500);

	TestMainWindow::waitForWindow();
	QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 0,
	         "Failed to click \"Reset\" button");
    //TestMainWindow::triggerAction("Undo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 3,
    //         "Failed undoing click \"Reset\" button");
    //TestMainWindow::triggerAction("Redo");
    //TestMainWindow::waitForWindow();
    //QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 0,
    //         "Failed redoing click \"Reset\" button");
}
void TestFilterTab::testAddFilters(){
loadVideo(QFINDTESTDATA("akiyo_qcif.yuv"));
TestMainWindow::clickButton("Add Blur filter");
TestMainWindow::clickButton("Add Border filter");
TestMainWindow::clickButton("Add Brightness filter");
TestMainWindow::clickButton("Add Colorbalance filter");
TestMainWindow::clickButton("Add Contrast filter");
TestMainWindow::clickButton("Add Grid filter");
TestMainWindow::clickButton("Add Mirror filter");
TestMainWindow::clickButton("Add Noise filter");
TestMainWindow::clickButton("Add Negative filter");
TestMainWindow::clickButton("Add Poster filter");
TestMainWindow::clickButton("Add RGB filter");
TestMainWindow::clickButton("Add Rectangle filter");
TestMainWindow::clickButton("Add Rotation filter");
TestMainWindow::clickButton("Add Saturation filter");
TestMainWindow::clickButton("Add Scale filter");
TestMainWindow::clickButton("Add Sharpness filter");
QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 16,
         "error adding filters");
}
