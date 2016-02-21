#ifndef RESULTSAVER_H
#define RESULTSAVER_H

#include <QString>

#include <memory>
#include <thread>

#include "../memento/AnalysisBoxContainerMemento.h"

#include "VideoSaver.h"

namespace GUI{
class AnalysisTab;
}

namespace Utility {

class ResultSaver
{
public:
    ResultSaver(GUI::AnalysisTab* tab,std::unique_ptr<Memento::AnalysisBoxContainerMemento> memento,QString folder);

    ~ResultSaver();

    void save();


private:
    GUI::AnalysisTab* tab_;
    std::unique_ptr<Memento::AnalysisBoxContainerMemento>   memento_;
    QString path_;

    std::vector<std::unique_ptr<VideoSaver>>    videoSavers_;

    std::thread saver_;
    bool isRunning_;

    void saveP();
};

}

#endif // RESULTSAVER_H
