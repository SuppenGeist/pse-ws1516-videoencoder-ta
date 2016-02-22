#ifndef __AnalysisBoxMemento_h__
#define __AnalysisBoxMemento_h__

#include <QString>
#include <QImage>

#include "../model/Video.h"
#include "../model/Graph.h"


namespace Memento {
/**
 * This class is the memento for the AnalysisBox.
 */
class AnalysisBoxMemento {

  public:
	/**
	 * @brief AnalysisBoxMemento Constructor.
	 */
	AnalysisBoxMemento();

	QString getPath();

    void setPath(QString path);

	QString getComment();

	void setComment(QString comment);

    void setMacroBlockVideo(Model::Video* macroblockVideo);

    Model::Video* getMacroBlockVideo();

    void setRgbDiffVideo(Model::Video* rgbDiffVideo);

    Model::Video* getRgbDiffVideo();

    void setPsnrGraph(QImage graph);

    QImage getPsnrGraph();

    void setBitrateGraph(QImage graph);

    QImage getBitrateGraph();

    void setEncoder(QString encoder);

    QString getEncoder();

    void setAverageBitrate(QString bitrate);

    QString getAverageBitrate();

    void setFilename(QString filename);

    QString getFilename();

    void setFilesize(QString size);

    QString getFilesize();

  private:
	QString path_;
	QString comment_;
    Model::Video* macroblockVideo_;
    Model::Video* rgbDiffVideo_;
    QImage psnrGraph_;
    QImage bitrateGraph_;
    QString encoder_;
    QString avergaeBitrate_;
    QString filename_;
    QString filesize_;
};
}

#endif
