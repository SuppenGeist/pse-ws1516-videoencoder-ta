#ifndef TESTCOLORBALANCEFILTER_H
#define TESTCOLORBALANCEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/ColorbalanceFilter.h"

class TestColorbalanceFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetIntensity();

	void testRestore();

	void testGetSaveString();

	void testFilterCopy();

	void testGetFilterDescription();

  private:
	Model::ColorbalanceFilter   filter_;
};


#endif // TESTCOLORBALANCEFILTER_H
