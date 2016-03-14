#ifndef TESTANALYSISTAB_H
#define TESTANALYSISTAB_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/gui/MainWindow.h"
#include "../../src/utility/YuvType.h"
#include "../../src/utility/Compression.h"

class TestAnalysisTab : public QObject
{
    Q_OBJECT
public:
    static void loadVideo(QString path, int width = 176, int height = 144, int fps = 30,
                          Utility::Compression compression = Utility::Compression::PACKED, Utility::YuvType type = Utility::YuvType::YUV420);
private slots:
    void init();
    void testAddVideo();
    void testGraphs();
private:
    GUI::MainWindow* mw;
};

#endif // TESTANALYSISTAB_H
