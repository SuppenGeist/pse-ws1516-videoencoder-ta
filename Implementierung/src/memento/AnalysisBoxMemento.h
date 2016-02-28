#ifndef __AnalysisBoxMemento_h__
#define __AnalysisBoxMemento_h__

#include <QString>
#include <QImage>

#include "../model/Video.h"
#include "../model/Graph.h"
#include "../model/graphvideo.h"


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

	void setPsnrGraph(Model::Graph* graph);

	Model::Graph* getPsnrGraph();

	void setBitrateGraph(Model::Graph* graph);

	Model::Graph* getBitrateGraph();

	void setEncoder(QString encoder);

	QString getEncoder();

	void setAverageBitrate(QString bitrate);

	QString getAverageBitrate();

	void setFilename(QString filename);

	QString getFilename();

	void setFilesize(QString size);

	QString getFilesize();

	void setRedHistogram(Model::GraphVideo* video);

	Model::GraphVideo* getRedHistogram();

	void setGreenHistogram(Model::GraphVideo* video);

	Model::GraphVideo* getGreenHistogram();

	void setBlueHistogram(Model::GraphVideo* video);

    Model::GraphVideo* getBlueHistogram();

  private:
	QString path_;
	QString comment_;
	Model::Video* macroblockVideo_;
	Model::Video* rgbDiffVideo_;
	Model::Graph* psnrGraph_;
	Model::Graph* bitrateGraph_;
	QString encoder_;
	QString avergaeBitrate_;
	QString filename_;
    QString filesize_;
	Model::GraphVideo* redHistogram_;
	Model::GraphVideo* greenHistogram_;
	Model::GraphVideo* blueHistogram_;
};
}

#endif
