#ifndef TESTFILTERTAB_H
#define TESTFILTERTAB_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/gui/MainWindow.h"
#include "../../src/utility/Compression.h"
#include "../../src/utility/YuvType.h"

class TestFilterTab : public QObject
{
    Q_OBJECT
public:
    static void clickItemInFilterList(int index);
    static void loadVideo(QString path, int width = 176, int height = 144, int fps = 30,
                          Utility::Compression compression = Utility::Compression::PACKED, Utility::YuvType type = Utility::YuvType::YUV420);
private:
    void clickButton(QString text);
private slots:
    void init();
    void testAddFilterWithoutVid();
    void testLoadVideo();
    void testAddRemoveFilters();
    void testFilterList();
private:
    GUI::MainWindow* mw;
};

#endif // TESTFILTERTAB_H
