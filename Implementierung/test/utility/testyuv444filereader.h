#ifndef TESTYUV444FILEREADER_H
#define TESTYUV444FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv444FileReader.h"

class TestYuv444FileReader : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testParseNextFrame();

	void testReadNextVectorPacked();

	void testReadNextVectorPlanar();

  private:
	Utility::Yuv444FileReader fileReader_;
};

#endif // TESTYUV444FILEREADER_H
