#ifndef FILTERCONFIGURATIONTEST_H
#define FILTERCONFIGURATIONTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/FilterConfigurationLoader.h"
#include "../../src/utility/FilterConfigurationSaver.h"
class FilterConfigurationTest : public QObject
{
    Q_OBJECT
private slots:
  void init();
  void testSaverLoader();
private:
  Utility::FilterConfigurationSaver* configSaver_;
  Utility::FilterConfigurationLoader* configLoader_;
};

#endif // FILTERCONFIGURATIONTEST_H
