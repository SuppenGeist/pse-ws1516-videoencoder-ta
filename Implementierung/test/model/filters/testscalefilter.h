#ifndef TESTSCALEFILTER_H
#define TESTSCALEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/ScaleFilter.h"

class TestScaleFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testRestore();

	void testFilterCopy();

	void testGetFilterDescription();

  private:
	Model::ScaleFilter   filter_;
};

#endif // TESTSCALEFILTER_H
