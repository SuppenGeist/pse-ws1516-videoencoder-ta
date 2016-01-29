#include <exception>

#include "FilterConfigurationSaver.h"
#include "FilterList.h"
using namespace Utility;
using namespace Model;

FilterConfigurationSaver::FilterConfigurationSaver(QString file, FilterList& filterList) {
QFile fileout(file);
}

void FilterConfigurationSaver::save() {
        if (fileout.open(QFile::ReadWrite | QFile::Text)){
         QTextStream out(&fileout);
         for (int i; i<FilterList.size; i++){
             file << filterList.at(i).getFilterDescription();
         }
         fileout.close();
    }
}


