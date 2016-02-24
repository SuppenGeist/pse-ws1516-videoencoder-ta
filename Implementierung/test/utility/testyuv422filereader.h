#ifndef TESTYUV422FILEREADER_H
#define TESTYUV422FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv422FileReader.h"

class TestYuv422FileReader : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testParseNextFrame();

	void testReadNextVectorPacked();

	void testReadNextVectorPlanar();

  private:
	Utility::Yuv422FileReader fileReader_;

};

#endif // TESTYUV422FILEREADER_H
