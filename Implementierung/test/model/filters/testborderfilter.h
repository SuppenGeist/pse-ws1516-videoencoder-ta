#ifndef TESTBORDERFILTER_H
#define TESTBORDERFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/BorderFilter.h"

class TestBorderFilter: public QObject {
	Q_OBJECT
  private slots:
	void init();

	void testSetThickness();

	void testRestore();

	void testGetSaveString();

	void testFilterCopy();

  private:
	Model::BorderFilter filter_;

};

#endif // TESTBORDERFILTER_H
