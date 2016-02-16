#ifndef __AnalysisBoxMemento_h__
#define __AnalysisBoxMemento_h__

#include "../model/Graph.h"
#include <QString>

namespace GUI {
class Video;
}
namespace Memento {
class AnalysisBoxMemento;
}
namespace Model {
class Graph;
class Video;
}

namespace Memento {
/**
 * This class is the memento for the AnalysisBox.
 */
class AnalysisBoxMemento {

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	AnalysisBoxMemento();

	/// <summary>
	/// Returns the path to the video.
	/// </summary>
	/// <returns>Absolute path to the video.</returns>
	QString getVideoPath();

	/// <summary>
	/// Sets the path to the video.
	/// </summary>
	/// <param name="videoPath">Absolute path to the video.</param>
	void setVideoPath(QString videoPath);

	/// <summary>
	/// Returns the user comment.
	/// </summary>
	/// <returns>The user comment.</returns>
	QString getComment();

	/// <summary>
	/// Sets the user comment.
	/// </summary>
	/// <param name="comment">The user comment.</param>
	void setComment(QString comment);

	/// <summary>
	/// Returns the macroblock video.
	/// </summary>
	/// <returns>The macroblock video.</returns>
	Model::Video* getMacroVideo();

	/// <summary>
	/// Sets the macroblock video.
	/// </summary>
	/// <param name="macroVideo">The macroblock video.</param>
	void setMacroVideo(Model::Video* macroVideo);

	/// <summary>
	/// Returns the rgb difference video.
	/// </summary>
	/// <returns>The rgb difference video.</returns>
	Model::Video* getRgbDiffVideo();

	/// <summary>
	/// Sets the rgb difference video.
	/// </summary>
	/// <param name="rgbDiffVideo">The rgb difference video.</param>
	void setRgbDiffVideo(Model::Video* rgbDiffVideo);

	/// <summary>
	/// Returns the psnr graph.
	/// </summary>
	/// <returns>The psnr graph.</returns>
	Model::Graph getPsnr();

	/// <summary>
	/// Sets the the psnr graph.
	/// </summary>
	/// <param name="psnr">The psnr graph.</param>
	void setPsnr(Model::Graph psnr);

	/// <summary>
	/// Returns the bitrate graph.
	/// </summary>
	/// <returns>The bitrate graph.</returns>
	Model::Graph getBitrate();

	/// <summary>
	/// Sets the bitrate graph.
	/// </summary>
	/// <param name="bitrate">The bitrate gaph.</param>
	void setBitrate(Model::Graph bitrate);

    private:
        QString videoPath_;
        QString comment_;
        Model::Video* macroVideo_;
        Model::Video* rgbDiffVideo_;
        Model::Graph psnr_;
        Model::Graph bitrate_;
};
}

#endif
