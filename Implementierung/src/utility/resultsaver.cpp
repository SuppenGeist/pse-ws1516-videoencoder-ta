#include "resultsaver.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

#include "../gui/AnalysisTab.h"
#include "../gui/GraphWidget.h"
#include "../gui/graphcalculator.h"

#include "../model/Graph.h"
#include "../model/graphvideo.h"

#include "VideoConverter.h"

Utility::ResultSaver::ResultSaver(std::unique_ptr<Memento::AnalysisBoxContainerMemento> memento,
                                  QString folder):memento_(std::move(memento)),path_(folder) {

}

Utility::ResultSaver::~ResultSaver() {
}


void Utility::ResultSaver::run() {
	if(!memento_.get())
		return;

	std::size_t size=memento_->getAnalysisBoxList().size();

	for(std::size_t i=0; i<size; i++) {
		auto& memento=memento_->getAnalysisBoxList()[i];

		QFile f(memento->getPath());
		QFileInfo info(f);

		auto prefix=path_+"/"+info.fileName().section(".",0,0);

		auto macroPath=prefix+"_macroblocks.mp4";

		QFile macroFile(macroPath);
		if(!macroFile.exists()) {

			auto macroBSaver=std::make_unique<VideoSaver>(memento->getMacroBlockVideo(),macroPath);
			macroBSaver->save();

			videoSavers_.push_back(std::move(macroBSaver));
		}

		auto diffPath=prefix+"_rgbDiff.mp4";

		QFile diffFile(diffPath);
		if(!diffFile.exists()) {
			auto diffSaver=std::make_unique<VideoSaver>(memento->getRgbDiffVideo(),diffPath);
			diffSaver->save();

			videoSavers_.push_back(std::move(diffSaver));
		}

		GUI::GraphCalculator calculator;

		auto psnrPath=prefix+"_psnr.png";

		QFile psnrFile(psnrPath);
		if(!psnrFile.exists()&&memento->getPsnrGraph()&&memento->getPsnrGraph()->getSize()!=0) {
			calculator.setAxisLabels("frame","dB");
			VideoConverter::convertGraphToImage(memento->getPsnrGraph(),1500,500,&calculator)->save(psnrPath);
		}

		auto bitratePath=prefix+"_bitrate.png";

		QFile bitrateFile(bitratePath);
		if(!bitrateFile.exists()) {
			calculator.setAxisLabels("frame","kb");
			VideoConverter::convertGraphToImage(memento->getBitrateGraph(),1500,500,
			                                    &calculator)->save(bitratePath);
		}

		auto redhpath=prefix+"_redHistogram.mp4";

		QFile redhFile(redhpath);
		if(!redhFile.exists()) {
			calculator.setShowLabels(false);
			calculator.setIsFilled(true);
			QBrush filler(QColor(255,0,0));
			calculator.setFillBrush(filler);
			QPen filpen(QColor(255,0,0));
			calculator.setFillPen(filpen);
			calculator.setLinePen(filpen);
			redHistogram_=VideoConverter::convertGraphVideoToVideo(memento->getRedHistogram(),1500,500,
			              &calculator);
			auto redhSaver=std::make_unique<VideoSaver>(redHistogram_.get(),redhpath);
			redhSaver->save();

			videoSavers_.push_back(std::move(redhSaver));
		}

		auto greenhpath=prefix+"_greenHistogram.mp4";

		QFile greenhFile(greenhpath);
		if(!greenhFile.exists()) {
			calculator.setShowLabels(false);
			calculator.setIsFilled(true);
			QBrush filler(QColor(0,255,0));
			calculator.setFillBrush(filler);
			QPen filpen(QColor(0,255,0));
			calculator.setFillPen(filpen);
			calculator.setLinePen(filpen);
			greenHistogram_=VideoConverter::convertGraphVideoToVideo(memento->getGreenHistogram(),1500,500,
			                &calculator);
			auto greenhSaver=std::make_unique<VideoSaver>(greenHistogram_.get(),greenhpath);
			greenhSaver->save();

			videoSavers_.push_back(std::move(greenhSaver));
		}

		auto bluehpath=prefix+"_blueHistogram.mp4";

		QFile bluehFile(bluehpath);
		if(!bluehFile.exists()) {
			calculator.setShowLabels(false);
			calculator.setIsFilled(true);
			QBrush filler(QColor(0,0,255));
			calculator.setFillBrush(filler);
			QPen filpen(QColor(0,0,255));
			calculator.setFillPen(filpen);
			calculator.setLinePen(filpen);
			blueHistogram_=VideoConverter::convertGraphVideoToVideo(memento->getBlueHistogram(),1500,500,
			               &calculator);
			auto bluehSaver=std::make_unique<VideoSaver>(blueHistogram_.get(),bluehpath);
			bluehSaver->save();

			videoSavers_.push_back(std::move(bluehSaver));
		}

		auto attributesPath=prefix+"_attributes";

		QFile attributesFile(attributesPath);
		if(!attributesFile.exists()) {
			if(attributesFile.open(QIODevice::ReadWrite)) {
				QTextStream str(&attributesFile);
				str<<"Filename: "<<memento->getFilename()<<"\n";
				str<<"Filesize: "<<memento->getFilesize()<<"\n";
				str<<"Codec: "<<memento->getEncoder()<<"\n";
				str<<"Average bitrate: "<<memento->getAverageBitrate();

				attributesFile.close();
			}
		}
	}

	for(auto& saver:videoSavers_) {
		saver->join();
	}
}

