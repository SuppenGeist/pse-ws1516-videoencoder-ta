#ifndef RESULTSAVER_H
#define RESULTSAVER_H

#include <QString>
#include <QObject>
#include <QThread>

#include <memory>

#include "../memento/AnalysisBoxContainerMemento.h"

#include "VideoSaver.h"

namespace GUI{
class AnalysisTab;
}

namespace Utility {

class ResultSaver:public QThread
{
    Q_OBJECT
public:
    ResultSaver(std::unique_ptr<Memento::AnalysisBoxContainerMemento> memento, QString folder);

    ~ResultSaver();

private:
    std::unique_ptr<Memento::AnalysisBoxContainerMemento>   memento_;
    QString path_;

    std::vector<std::unique_ptr<VideoSaver>>    videoSavers_;

    std::unique_ptr<Model::Video>  redHistogram_;
    std::unique_ptr<Model::Video>  greenHistogram_;
    std::unique_ptr<Model::Video>  blueHistogram_;

    void run();
};

}

#endif // RESULTSAVER_H
