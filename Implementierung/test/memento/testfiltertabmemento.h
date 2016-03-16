#ifndef TESTFILTERTABMEMENTO_H
#define TESTFILTERTABMEMENTO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/memento/FilterTabMemento.h"

class TestFilterTabMemento : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetRawVideo();

	void testSetFilterList();

	void testSetIsPreviewShown();

	void testSetIsFilteredVideoShown();

	void testSetCurrentFrame();

	void testSetCurrentlySelectedFilter();


  private:
	Memento::FilterTabMemento memento_;

};

#endif // TESTFILTERTABMEMENTO_H
