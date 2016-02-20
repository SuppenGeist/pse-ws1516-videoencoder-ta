#include "ProjectWriter.h"

#include <QDataStream>

#include "../model/Project.h"

#include "../memento/MainWindowMemento.h"

#include "Compression.h"
#include "YuvType.h"

Utility::ProjectWriter::ProjectWriter(Model::Project *project):project_(project) {
	if(project) {
		file_=std::make_unique<QFile>(project->getPath());
		file_->open(QIODevice::WriteOnly);
		dataStream_.setDevice(file_.get());
	}
}

Utility::ProjectWriter::~ProjectWriter() {
	file_->flush();
	file_->close();
}

void Utility::ProjectWriter::saveProject() {
	if(!project_)
		return;

	auto& memento=project_->getMemento();
    auto filtermemento=memento.getFilterTabMemento();
    auto anamemento=memento.getAnalysisTabMemento();

    dataStream_<<memento.getSelectedTab()<<"|";

    if(filtermemento&&filtermemento->getRawVideo()) {
        dataStream_<<filtermemento->getRawVideo()->getPath()<<",";
        switch(filtermemento->getRawVideo()->getCompression()) {
        case Compression::PLANAR:
            dataStream_<<"planar,";
            break;
        case Compression::PACKED:
            dataStream_<<"packed,";
            break;
        }
        switch(filtermemento->getRawVideo()->getYuvType()) {
        case YuvType::YUV411:
            dataStream_<<"411,";
            break;
        case YuvType::YUV422:
            dataStream_<<"42,";
            break;
        case YuvType::YUV444:
            dataStream_<<"444,";
            break;
        case YuvType::YUV420:
            dataStream_<<"420,";
            break;
        }
        dataStream_<<filtermemento->getRawVideo()->getWidth()<<","<<filtermemento->getRawVideo()->getHeight()<<",";
        dataStream_<<filtermemento->getCurrentlySelectedFilter()<<","<<filtermemento->getRawVideo()->getFps()<<",";
        dataStream_<<filtermemento->isFilteredVideoShown()<<","<<filtermemento->isPreviewShow()<<",";

        auto filterlist=filtermemento->getFilterList();
        for(int i=0;i<filterlist->getSize();i++) {
            dataStream_<<filterlist->getFilter(i)->getName()<<";"<<filterlist->getFilter(i)->getSaveString()<<"#";
        }
        dataStream_<<"|";
    }else {
        dataStream_<<"NULL|";
    }
}

void Utility::ProjectWriter::saveResults() {
}
