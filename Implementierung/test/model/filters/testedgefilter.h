#ifndef TESTEDGEFILTER_H
#define TESTEDGEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/EdgeFilter.h"

class TestEdgeFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testGetName();

    void testGetFilterDescription();

private:
    Model::EdgeFilter   filter_;
};

#endif // TESTEDGEFILTER_H
