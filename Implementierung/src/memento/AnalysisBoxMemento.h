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
  private:
	QString videoPath;
  private:
	QString comment;
  private:
    Model::Video* macroVideo;
  private:
    Model::Video* rgbDiffVideo;
  private:
	Model::Graph psnr;
  private:
	Model::Graph bitrate;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	AnalysisBoxMemento();

	/// <summary>
	/// Returns the path to the video.
	/// </summary>
	/// <returns>Absolute path to the video.</returns>
  public:
	QString getVideoPath();

	/// <summary>
	/// Sets the path to the video.
	/// </summary>
	/// <param name="videoPath">Absolute path to the video.</param>
  public:
	void setVideoPath(QString videoPath);

	/// <summary>
	/// Returns the user comment.
	/// </summary>
	/// <returns>The user comment.</returns>
  public:
	QString getComment();

	/// <summary>
	/// Sets the user comment.
	/// </summary>
	/// <param name="comment">The user comment.</param>
  public:
	void setComment(QString comment);

	/// <summary>
	/// Returns the macroblock video.
	/// </summary>
	/// <returns>The macroblock video.</returns>
  public:
    Model::Video* getMacroVideo();

	/// <summary>
	/// Sets the macroblock video.
	/// </summary>
	/// <param name="macroVideo">The macroblock video.</param>
  public:
    void setMacroVideo(Model::Video* macroVideo);

	/// <summary>
	/// Returns the rgb difference video.
	/// </summary>
	/// <returns>The rgb difference video.</returns>
  public:
    Model::Video* getRgbDiffVideo();

	/// <summary>
	/// Sets the rgb difference video.
	/// </summary>
	/// <param name="rgbDiffVideo">The rgb difference video.</param>
  public:
    void setRgbDiffVideo(Model::Video* rgbDiffVideo);

	/// <summary>
	/// Returns the psnr graph.
	/// </summary>
	/// <returns>The psnr graph.</returns>
  public:
	Model::Graph getPsnr();

	/// <summary>
	/// Sets the the psnr graph.
	/// </summary>
	/// <param name="psnr">The psnr graph.</param>
  public:
	void setPsnr(Model::Graph psnr);

	/// <summary>
	/// Returns the bitrate graph.
	/// </summary>
	/// <returns>The bitrate graph.</returns>
  public:
	Model::Graph getBitrate();

	/// <summary>
	/// Sets the bitrate graph.
	/// </summary>
	/// <param name="bitrate">The bitrate gaph.</param>
  public:
	void setBitrate(Model::Graph bitrate);
};
}

#endif
