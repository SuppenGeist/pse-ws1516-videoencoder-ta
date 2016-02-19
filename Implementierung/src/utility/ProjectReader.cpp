#include "ProjectReader.h"

#include <stdexcept>

#include <QFileInfo>
#include <QStringList>
#include <QString>

#include "../model/Project.h"

#include "../memento/MainWindowMemento.h"
#include "../memento/AnalysisTabMemento.h"
#include "../memento/AnalysisBoxContainerMemento.h"
#include "../memento/AnalysisBoxMemento.h"

Utility::ProjectReader::ProjectReader(QString path):file_(path) {
	if(!file_.open(QIODevice::ReadOnly)) {
		throw std::invalid_argument("File does not exist");
	}
	dataStream_.setDevice(&file_);
}

Utility::ProjectReader::~ProjectReader() {
	file_.close();
}

std::unique_ptr<Model::Project> Utility::ProjectReader::readProject() {
	QFileInfo info(file_);

	auto project=std::make_unique<Model::Project>(info.fileName());
	project->setPath(file_.fileName());

	auto everything=dataStream_.readLine();
	QStringList esplit=everything.split(";");

	auto mainWindow=std::make_unique<Memento::MainWindowMemento>();
	if(esplit.size()>=1) {
		bool successful=false;
		int index=esplit[0].toInt(&successful);
		if(successful) {
			mainWindow->setSelectedTab(index);
		}
	}

	auto filterTab=std::make_unique<Memento::FilterTabMemento>();
	auto analysisTab=std::make_unique<Memento::AnalysisTabMemento>();

	mainWindow->setFilterTabMemento(std::move(filterTab));
	mainWindow->setAnalysisTabMemento(std::move(analysisTab));

	project->setMemento(std::move(mainWindow));

	return std::move(project);
}


