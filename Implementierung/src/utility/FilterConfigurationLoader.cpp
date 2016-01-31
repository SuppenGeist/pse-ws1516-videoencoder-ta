#include <exception>
#include <QTextStream>
#include "FilterConfigurationLoader.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

Utility::FilterConfigurationLoader::FilterConfigurationLoader(QString path) {
QFile file(path);
}

Model::FilterList* Utility::FilterConfigurationLoader::getConfiguration() {
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        qFatal( "Could not open the file" );

        QTextStream stream( &file );
        Model::FilterList* filterList = new Model::FilterList();

        while( !stream.atEnd() )
        {
            QString line = stream.readLine();
            filterList->addFilter(line.section(";",0,0).toStdString());
            filterList->getFilterByName(line.section(";",0,0).toStdString())->restoreFilter(line);

        }

        file.close();

        return filterList;
     }



