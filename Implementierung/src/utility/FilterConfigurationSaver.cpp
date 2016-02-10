#include "FilterConfigurationSaver.h"

#include <QTextStream>
#include <QString>

#include "../model/FilterList.h"
#include "../model/filters/Filter.h"


Utility::FilterConfigurationSaver::FilterConfigurationSaver(QString file,
        Model::FilterList& filterList): fileout_(file),filterList_(&filterList) {

}

void Utility::FilterConfigurationSaver::save() {
	if (fileout_.open(QFile::ReadWrite | QFile::Text)) {
		QTextStream out(&fileout_);
		for(std::size_t i=0; i<filterList_->getSize(); i++) {
			out << filterList_->getFilter(i)->getName() << ";";
			out << filterList_->getFilter(i)->getSaveString() << "\n";
		}
	}
	fileout_.close();
}



