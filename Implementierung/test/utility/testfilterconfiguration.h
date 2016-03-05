#ifndef TESTFILTERCONFIGURATION_H
#define TESTFILTERCONFIGURATION_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/FilterConfigurationLoader.h"
#include "../../src/utility/FilterConfigurationSaver.h"
class TestFilterConfiguration : public QObject
{
    Q_OBJECT
private slots:
  void init();
  void testSaverLoader();
private:
  Utility::FilterConfigurationSaver* configSaver_;
  Utility::FilterConfigurationLoader* configLoader_;
};

#endif // TESTFILTERCONFIGURATION_H
