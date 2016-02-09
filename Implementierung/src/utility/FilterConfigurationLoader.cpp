#include "FilterConfigurationLoader.h"

#include <memory>

#include <QTextStream>
#include <QFile>
#include <QDebug>

#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

Utility::FilterConfigurationLoader::FilterConfigurationLoader(QString path):file_(path) {

}

std::unique_ptr<Model::FilterList> Utility::FilterConfigurationLoader::getConfiguration() {
    auto filterconf=std::make_unique<Model::FilterList>();

    if( !file_.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        filterconf.release();
        return std::move(filterconf);
    }

    QTextStream stream( &file_ );

	while( !stream.atEnd() ) {
		QString line = stream.readLine();
        auto filtername=line.section(";",0,0);
        auto filter=filterconf->appendFilter(filtername);
        auto restorestring=line.right(line.length()-filtername.length()-1);
        filter->restore(restorestring);

	}

    file_.close();

    return std::move(filterconf);
}



