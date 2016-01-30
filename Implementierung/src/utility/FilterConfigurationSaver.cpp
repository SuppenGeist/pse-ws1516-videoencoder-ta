#include <exception>
#include <QTextStream>
#include <QString>
#include "FilterConfigurationSaver.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"


Utility::FilterConfigurationSaver::FilterConfigurationSaver(QString file, Model::FilterList& filterList) {
QFile fileout(file);
}

void Utility::FilterConfigurationSaver::save() {
    if (fileout.open(QFile::ReadWrite | QFile::Text)){
     QTextStream out(&fileout);
     int i;
     while (filterList.getFilterByIndex(i)!= 0){
         QString str = QString::fromStdString(filterList.getFilterByIndex(i)->getFilterDescription());
         out << str;
         i++;
     }
     fileout.close();
    }
}



