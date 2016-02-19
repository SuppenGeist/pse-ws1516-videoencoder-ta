#ifndef TESTNOISEFILTER_H
#define TESTNOISEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/NoiseFilter.h"

class TestNoiseFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetIntensity();

	void testRestore();

	void testGetDescription();

	void testFilterCopy();

  private:
	Model::NoiseFilter   filter_;
};

#endif // TESTNOISEFILTER_H
