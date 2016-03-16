#ifndef TESTANALYSISBOXMEMENTO_H
#define TESTANALYSISBOXMEMENTO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/memento/AnalysisBoxMemento.h"

class TestAnalysisBoxMemento : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetPath();

    void testSetComment();

    void testSetMacroBlockVideo();

    void testSetRGBDiffVideo();

    void testSetPsnrGraph();

    void testSetBitrateGraph();

    void testSetEncoder();

    void testSetAverageBitrate();

    void testSetFilename();

    void testSetFilesize();

    void testSetRedHistogram();

    void testSetGreenHistogram();

    void testSetBlueHistogram();



  private:
	Memento::AnalysisBoxMemento memento_;

};

#endif // TESTANALYSISBOXMEMENTO_H
