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

#include "Compression.h"
#include "YuvType.h"

#include "../gui/AnalysisTab.h"

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

    if(esplit.size()>=3) {
        parseAnalysisTab(analysisTab.get(),esplit[2]);
    }

	mainWindow->setFilterTabMemento(std::move(filterTab));
	mainWindow->setAnalysisTabMemento(std::move(analysisTab));

	project->setMemento(std::move(mainWindow));

    return std::move(project);
}

void Utility::ProjectReader::parseFilterTab(Memento::FilterTabMemento *memento, QString line)
{
    if(!memento)
        return;

    if(line=="NULL")
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

void Utility::ProjectReader::parseAnalysisTab(Memento::AnalysisTabMemento *memento, QString line)
{
    if(!memento)
        return;

    if(line=="NULL")
        return;

    QStringList anat=line.split(",");

    if(anat.size()!=9)
        return;

    QFile f(anat[0]);
    QFileInfo info(f);
    if(!info.exists()&&info.isFile())
        return;

    auto path=f.fileName();

    Utility::Compression compression;
    if(anat[1]=="planar") {
        compression=Utility::Compression::PLANAR;
    }else if(anat[1]=="packed") {
        compression=Utility::Compression::PACKED;
    }
    else {
        return;
    }

    Utility::YuvType type;
    if(anat[2]=="411") {
        type=Utility::YuvType::YUV411;
    } else if(anat[2]=="420") {
        type=Utility::YuvType::YUV420;
    } else if(anat[2]=="444") {
        type=Utility::YuvType::YUV444;
    } else if(anat[2]=="422") {
        type=Utility::YuvType::YUV422;
    } else {
        return;
    }

    bool success=false;

    int width=anat[3].toInt(&success);
    if(!success)
        return;

    int height=anat[4].toInt(&success);
    if(!success)
        return;

    int fps=30;
    fps=anat[5].toInt(&success);
    if(!success)
        fps=30;

    GUI::AnalysisGraph graph=GUI::AnalysisGraph::BITRATE;
    if(anat[6]=="bitrate") {
        graph=GUI::AnalysisGraph::BITRATE;
    } else if(anat[6]=="psnr") {
        graph=GUI::AnalysisGraph::PSNR;
    }else if(anat[6]=="redh") {
        graph=GUI::AnalysisGraph::RED_HISTOGRAMM;
    }else if(anat[6]=="blueh") {
        graph=GUI::AnalysisGraph::BLUE_HISTOGRAMM;
    }else if(anat[6]=="green") {
        graph=GUI::AnalysisGraph::GREEN_HISTOGRAMM;
    }

    GUI::AnalysisVideo video=GUI::AnalysisVideo::MACROBLOCK;
    if(anat[7]=="macro") {
        video=GUI::AnalysisVideo::MACROBLOCK;
    }else if(anat[7]=="diff") {
        video=GUI::AnalysisVideo::RGB_DIFFERENCE;
    }

    QStringList boxes=anat[8].split("#");

    auto conmem=std::make_unique<Memento::AnalysisBoxContainerMemento>();
    for(auto box:boxes) {
        QStringList data=box.split(";");

        if(data.size()!=2)
            continue;

        QFile file(data[0]);
        QFileInfo info(file);

        if(!(info.exists()&&info.isFile()))
            continue;

        auto boxmem=std::make_unique<Memento::AnalysisBoxMemento>();
        boxmem->setPath(file.fileName());
        boxmem->setComment(data[1]);
        conmem->addMemento(std::move(boxmem));
    }

    auto yuvvideo=std::make_unique<Model::YuvVideo>(path,type,compression,width,height,fps);
    yuvvideo->getVideo();

    memento->setRawVideo(std::move(yuvvideo));
    memento->setAnalysisGraph(graph);
    memento->setAnalysisVideo(video);
    memento->setAnalysisBoxContainerMemento(std::move(conmem));
}


