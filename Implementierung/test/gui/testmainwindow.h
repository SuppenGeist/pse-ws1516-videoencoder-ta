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

#include "../../src/gui/YuvFileOpenDialog.h"
#include "../../src/gui/YuvInfoDialog.h"
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
    void setPath(QString path) {
        path_ = path;
    }
    void setThread(QThread* thread) {
        mainThread_ = thread;
    }

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
            }
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

};
#endif // TESTMAINWINDOW_H
