#ifndef TESTGRIDFILTER_H
#define TESTGRIDFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/GridFilter.h"

class TestGridFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testSetOpacity();

    void testRestore();

    void testFilterCopy();

    void testGetFilterDescription();

private:
    Model::GridFilter   filter_;
};

#endif // TESTGRIDFILTER_H
