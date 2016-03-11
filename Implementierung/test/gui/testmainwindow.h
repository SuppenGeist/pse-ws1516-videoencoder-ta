#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QObject>
#include <QtTest/QtTest>
#include <memory>
#include <QDebug>
#include <QThread>
#include <QLineEdit>
#include <QKeyEvent>
#include <QApplication>

#include "../../src/gui/MainWindow.h"
#include "../../src/memento/MainWindowMemento.h"
#include "../../src/utility/Compression.h"
#include "../../src/gui/YuvFileOpenDialog.h"
#include "../../src/gui/YuvInfoDialog.h"
#include "../../src/utility/YuvType.h"
class TestMainWindow : public QObject {
    Q_OBJECT
public:
    /**
     * @brief getMainWindow returns the m
     * @return
     */
    static GUI::MainWindow* getMainWindow();
    /**
     * @brief waitForWindow waits the given time in ms and calls qApp->processEvents() after two third of the time;
     * @param time the total waiting time in ms
     */
    static void waitForWindow(int time = 1500);

    /**
     * @brief clickButton clicks a button
     * @param text the button with this text
     * @param parent and is a child (direct or not) of this parent
     */
    static void clickButton(QString text,QObject* parent = mainWindow);
    /**
     * @brief triggerAction triggers a action
     * @param text the action with this text
     * @param parent and is a child (direct or not) of this parent
     */
    static void triggerAction(QString text,QObject* parent = mainWindow);

    /**
     * @brief getCurrentMainWindow returns the MainWindow without restting it
     * @return the MainWindow
     */
    static GUI::MainWindow* getCurrentMainWindow();
 private slots:
    void init();
    void testSwitchTab();
 private:
    GUI::MainWindow* mw;
    static std::unique_ptr<Memento::MainWindowMemento> originMemento;
    static GUI::MainWindow* mainWindow;
};
class WriteYuvFilePath : public QThread {
    Q_OBJECT
public:
    void setPath(QString path) {path_ = path;}
    void setThread(QThread* thread) {mainThread_ = thread;}
    void setHeight(int height) {height_ = QString::number(height);}
    void setWidth(int width) {width_ = QString::number(width);}
    void setCompression(Utility::Compression compression) {compression_ = compression;}
    void setYuvType(Utility::YuvType type) { type_ = type;}
    void setFps(int fps) { fps_=QString::number(fps);}
private:
    void run() {
        QTest::qSleep(500);
        QList<QWidget*> list = qApp->allWidgets();
        GUI::YuvFileOpenDialog* fileDialog;
        fileDialog = (GUI::YuvFileOpenDialog*) qApp->activeWindow();
        QList<QLineEdit*> lineEditList = fileDialog->findChildren<QLineEdit*>();
        QLineEdit* lineEdit = lineEditList.first();

        QApplication::postEvent(lineEdit,new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,path_));

        QList<QPushButton*> buttonList = fileDialog->findChildren<QPushButton*>();
        QPushButton* okButton;
        for(int i = 0; i < buttonList.length() ; i++) {
            if(buttonList.at(i)->text() == "OK") {
                okButton = buttonList.at(i);
            }
        }
        QTest::qSleep(500);
        QApplication::postEvent(okButton, new QMouseEvent(QEvent::MouseButtonPress,QPoint(1,1),Qt::LeftButton,Qt::LeftButton,Qt::KeyboardModifier::NoModifier));
        QApplication::postEvent(okButton, new QMouseEvent(QEvent::MouseButtonRelease,QPoint(1,1),Qt::LeftButton,Qt::LeftButton,Qt::KeyboardModifier::NoModifier));

        QTest::qSleep(1000);
        GUI::YuvInfoDialog* infoDialog;
        infoDialog = (GUI::YuvInfoDialog*) qApp->activeWindow();
        lineEditList = infoDialog->findChildren<QLineEdit*>();
        for(int i = 0; i < lineEditList.length();i++){
            QTest::qSleep(500);
            if(lineEditList.at(i)->objectName() == QString("lineEdit_width_") ) {
                QApplication::postEvent(lineEditList.at(i),new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,width_));
            } else if(lineEditList.at(i)->objectName()== QString("lineEdit_height_")) {
                QApplication::postEvent(lineEditList.at(i),new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,height_));
            } else  if(lineEditList.at(i)->objectName()==QString("lineEdit_fps_")) {
                QApplication::postEvent(lineEditList.at(i),new QMouseEvent(QEvent::MouseButtonDblClick,QPoint(5,5),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier));
                QApplication::postEvent(lineEditList.at(i),new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,fps_));
            }
        }
        QTest::qSleep(500);
        QComboBox* comboBox= infoDialog->findChild<QComboBox*>("comboBox_pixelSheme_");
        QVERIFY2(comboBox != NULL, "Error: pixelSheme comboBox not found");
        QApplication::postEvent(comboBox,new QFocusEvent(QEvent::FocusIn));
        switch (type_) {
                case Utility::YuvType::YUV444 : QApplication::postEvent(comboBox,new QKeyEvent(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier));
                case Utility::YuvType::YUV422 : QApplication::postEvent(comboBox,new QKeyEvent(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier));
                case Utility::YuvType::YUV411 : QApplication::postEvent(comboBox,new QKeyEvent(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier));break;
                default:
                    break;
                }
        QTest::qSleep(500);
        comboBox = infoDialog->findChild<QComboBox*>("comboBox_compression_");
        QVERIFY2(comboBox != NULL, "Error: compression comboBox not found");
        if(type_ != Utility::YuvType::YUV420 && compression_ == Utility::Compression::PACKED) {
                    QApplication::postEvent(comboBox,new QKeyEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier));
                    QTest::qSleep(500);
            }

        QTest::qSleep(500);
        buttonList = infoDialog->findChildren<QPushButton*>();
        for(int i = 0; i < buttonList.length() ; i++) {
               if(buttonList.at(i)->text() == "OK") {
                   okButton = buttonList.at(i);
                }
        }
        QApplication::postEvent(okButton, new QMouseEvent(QEvent::MouseButtonPress,QPoint(1,1),Qt::LeftButton,Qt::LeftButton,Qt::KeyboardModifier::NoModifier));
        QApplication::postEvent(okButton, new QMouseEvent(QEvent::MouseButtonRelease,QPoint(1,1),Qt::LeftButton,Qt::LeftButton,Qt::KeyboardModifier::NoModifier));

    }
    QThread* mainThread_;
    QString path_;
    QString width_ = "176";
    QString height_ = "144";
    QString fps_ = "30";
    Utility::YuvType type_ = Utility::YuvType::YUV420;
    Utility::Compression compression_ = Utility::Compression::PLANAR;

};
#endif // TESTMAINWINDOW_H
