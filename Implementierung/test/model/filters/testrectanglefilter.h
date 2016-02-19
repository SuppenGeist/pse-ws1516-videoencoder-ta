#ifndef TESTRECTANGLEFILTER_H
#define TESTRECTANGLEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/RectangleFilter.h"

class TestRectangleFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetOpacity();

	void testRestore();

	void testGetFilterDescription();

	void testFilterCopy();

  private:
	Model::RectangleFilter   filter_;
};

#endif // TESTRECTANGLEFILTER_H
