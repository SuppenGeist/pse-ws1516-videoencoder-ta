#include "ProjectWriter.h"

#include <QDataStream>

#include "../gui/AnalysisTab.h"

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
		dataStream_<<filtermemento->getRawVideo()->getWidth()
		           <<","<<filtermemento->getRawVideo()->getHeight()<<",";
		dataStream_<<filtermemento->getCurrentlySelectedFilter()
		           <<","<<filtermemento->getRawVideo()->getFps()<<",";
		dataStream_<<filtermemento->isFilteredVideoShown()<<","<<filtermemento->isPreviewShow()<<",";

		auto filterlist=filtermemento->getFilterList();
		for(std::size_t i=0; i<filterlist->getSize(); i++) {
			dataStream_<<filterlist->getFilter(i)->getName()<<";"<<filterlist->getFilter(
			               i)->getSaveString()<<"#";
		}
		dataStream_<<"|";
	} else {
		dataStream_<<"NULL|";
	}

	if(anamemento&&anamemento->getRawVideo()) {
		dataStream_<<anamemento->getRawVideo()->getPath()<<",";
		switch(anamemento->getRawVideo()->getCompression()) {
		case Compression::PLANAR:
			dataStream_<<"planar,";
			break;
		case Compression::PACKED:
			dataStream_<<"packed,";
			break;
		}
		switch(anamemento->getRawVideo()->getYuvType()) {
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
		dataStream_<<anamemento->getRawVideo()->getWidth()<<","<<anamemento->getRawVideo()->getHeight()
		           <<",";
		dataStream_<<anamemento->getRawVideo()->getFps()<<",";

		switch(anamemento->getAnalysisGraph()) {
		case GUI::AnalysisGraph::BITRATE:
			dataStream_<<"bitrate,";
			break;
		case GUI::AnalysisGraph::PSNR:
			dataStream_<<"psnr,";
			break;
		case GUI::AnalysisGraph::BLUE_HISTOGRAM:
			dataStream_<<"blueh,";
			break;
		case GUI::AnalysisGraph::RED_HISTOGRAM:
			dataStream_<<"redh,";
			break;
		case GUI::AnalysisGraph::GREEN_HISTOGRAM:
			dataStream_<<"greenh,";
			break;
		}

		switch(anamemento->getAnalysisVideo()) {
		case GUI::AnalysisVideo::MACROBLOCK:
			dataStream_<<"macro,";
			break;
		case GUI::AnalysisVideo::RGB_DIFFERENCE:
			dataStream_<<"diff,";
			break;
		}

		auto conmem=anamemento->getAnalysisBoxContainerMemento();
		for(auto& box:conmem->getAnalysisBoxList()) {
			dataStream_<<box->getPath()<<";"<<box->getComment()<<"#";
		}
	} else {
		dataStream_<<"NULL";
	}
}
