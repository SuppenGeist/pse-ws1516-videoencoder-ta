#include "resultsaver.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

#include "../gui/AnalysisTab.h"
#include "../gui/GraphWidget.h"

#include "../model/Graph.h"

Utility::ResultSaver::ResultSaver(GUI::AnalysisTab* tab,std::unique_ptr<Memento::AnalysisBoxContainerMemento> memento, QString folder):tab_(tab),memento_(std::move(memento)),path_(folder),isRunning_(false)
{

}

Utility::ResultSaver::~ResultSaver()
{
    isRunning_=false;
    if(saver_.joinable())
        saver_.join();
}

void Utility::ResultSaver::save()
{
    if(!memento_.get())
        return;

    saver_=std::thread(&ResultSaver::saveP,this);
}

void Utility::ResultSaver::saveP()
{
    isRunning_=true;

    std::size_t size=memento_->getAnalysisBoxList().size();

    for(std::size_t i=0;i<size&&isRunning_;i++) {
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

        auto psnrPath=prefix+"_psnr.png";

        QFile psnrFile(psnrPath);
        if(!psnrFile.exists()) {

        }
    }

    for(auto& saver:videoSavers_) {
        saver->join();
    }

    if(tab_)
        tab_->resultsSaved();
    isRunning_=false;
}

