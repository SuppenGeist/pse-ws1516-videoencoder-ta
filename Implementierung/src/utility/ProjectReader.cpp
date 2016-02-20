#include "ProjectReader.h"

#include <stdexcept>
#include <memory>

#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QStringList>
#include <QString>

#include "../model/Project.h"
#include "../model/YuvVideo.h"
#include "../model/FilterList.h"

#include "../memento/MainWindowMemento.h"
#include "../memento/AnalysisTabMemento.h"
#include "../memento/AnalysisBoxContainerMemento.h"
#include "../memento/AnalysisBoxMemento.h"

#include "../utility/Compression.h"
#include "../utility/YuvType.h"

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
    QStringList esplit=everything.split("|");

	auto mainWindow=std::make_unique<Memento::MainWindowMemento>();
	if(esplit.size()>=1) {
		bool successful=false;
		int index=esplit[0].toInt(&successful);
		if(successful) {
			mainWindow->setSelectedTab(index);
		}
	}

	auto filterTab=std::make_unique<Memento::FilterTabMemento>();

    if(esplit.size()>=2) {
            parseFilterTab(filterTab.get(),esplit[1]);
    }

	auto analysisTab=std::make_unique<Memento::AnalysisTabMemento>();

	mainWindow->setFilterTabMemento(std::move(filterTab));
	mainWindow->setAnalysisTabMemento(std::move(analysisTab));

	project->setMemento(std::move(mainWindow));

    return std::move(project);
}

void Utility::ProjectReader::parseFilterTab(Memento::FilterTabMemento *memento, QString line)
{
    if(!memento)
        return;

    QStringList filtert=line.split(",");

    if(filtert.size()!=10)
        return;

    QFile f(filtert[0]);
    QFileInfo info(f);
    if(!info.exists()&&info.isFile())
        return;

    auto path=f.fileName();

    Utility::Compression compression;
    if(filtert[1]=="planar") {
        compression=Utility::Compression::PLANAR;
    }else if(filtert[1]=="packed") {
        compression=Utility::Compression::PACKED;
    }
    else {
        return;
    }

    Utility::YuvType type;
    if(filtert[2]=="411") {
        type=Utility::YuvType::YUV411;
    } else if(filtert[2]=="420") {
        type=Utility::YuvType::YUV420;
    } else if(filtert[2]=="444") {
        type=Utility::YuvType::YUV444;
    } else if(filtert[2]=="422") {
        type=Utility::YuvType::YUV422;
    } else {
        return;
    }

    bool success=false;

    int width=filtert[3].toInt(&success);
    if(!success)
        return;

    int height=filtert[4].toInt(&success);
    if(!success)
        return;

    int selectedFilter=0;
    selectedFilter=filtert[5].toInt(&success);

    int fps=30;
    fps=filtert[6].toInt(&success);
    if(!success)
        fps=30;

    bool isFilterVideoShown=false;
    isFilterVideoShown=filtert[7].toInt(&success);

    bool isPreviewShown=false;
    isPreviewShown=filtert[8].toInt(&success);

    auto filterlist=std::make_unique<Model::FilterList>();
    QStringList filters=filtert[9].split("#");
    for(auto filterstr:filters) {
        auto filtername=filterstr.section(";",0,0);
        try {
            auto filter=filterlist->appendFilter(filtername);
            auto restorestring=filterstr.right(filterstr.length()-filtername.length()-1);
            filter->restore(restorestring);
        } catch(std::invalid_argument& ex) {
            continue;
        }
    }

    auto video=std::make_unique<Model::YuvVideo>(path,type,compression,width,height,fps);
    video->getVideo();

    memento->setRawVideo(std::move(video));
    memento->setCurrentlySelectedFilter(selectedFilter);
    memento->setIsFilteredVideoShown(isFilterVideoShown);
    memento->setIsPreviewShown(isPreviewShown);
    memento->setFilterList(std::move(filterlist));
}


