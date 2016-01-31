#include <exception>
#include <QTextStream>
#include "FilterConfigurationLoader.h"
#include "../model/FilterList.h"

using namespace Utility;

FilterConfigurationLoader::FilterConfigurationLoader(QString path) {
QFile file(path);
}

Model::FilterList* FilterConfigurationLoader::getConfiguration() {
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        qFatal( "Could not open the file" );

        QTextStream stream( &file );
        filterList = new Model::FilterList();

        while( !stream.atEnd() )
        {
            QString line = stream.readLine();
            QList<QString> lstLine = line.split("=");
            filterList->addFilter(lstLine[0].toStdString());
        }

        file.close();

        return filterList;
     }



