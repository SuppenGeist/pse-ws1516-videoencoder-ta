#ifndef TESTRGBFILTER_H
#define TESTRGBFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/RGBFilter.h"

class TestRGBFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testRestore();

    void testGetSaveString();

    void testGetFilterDescription();

    void testFilterCopy();

private:
    Model::RGBFilter   filter_;
};

#endif // TESTRGBFILTER_H
