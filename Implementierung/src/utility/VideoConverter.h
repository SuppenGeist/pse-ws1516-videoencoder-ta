#ifndef __VideoConverter_h__
#define __VideoConverter_h__

#include <QImage>

#include <memory>
#include <thread>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include "../model/Video.h"
#include "../model/AVVideo.h"
#include "../model/Graph.h"
#include "../model/graphvideo.h"

#include "../gui/graphcalculator.h"

namespace Utility {
/**
 * Converts AVFrames to QImages and vice versa.
 */

class VideoConverter {
  public:
	/**
	 * @brief convertAVFrameToQImage Converts the given AVFrame to a QImage.
	 * @param frame The avframe to convert.
	 * @param width The width of the frame.
	 * @param height The height of the frame.
	 * @return The converted AVFrame.
	 */
	static std::unique_ptr<QImage> convertAVFrameToQImage(AVFrame& frame);

	/**
	 * @brief convertQImageToAVFrame Converts a qimage to an avframe.
	 * CAUTION: An owning pointer is returned.
	 * @param image The qimage to convert.
	 * @return The converted qimage.
	 */
	static AVFrame* convertQImageToAVFrame(QImage& image);

	static std::unique_ptr<QImage> convertGraphToImage(Model::Graph* graph,int width,int height,
	        GUI::GraphCalculator* calculator=0);

	static std::unique_ptr<Model::Video> convertGraphVideoToVideo(Model::GraphVideo* video,int width,
	        int height,GUI::GraphCalculator* calculator);

	VideoConverter(Model::Video* video);

	VideoConverter(Model::AVVideo* video);

	~VideoConverter();

	/**
	 * @brief convertAVVideoToVideo Converts a AVVideo to a Video
	 * @param video The video to convert.
	 * @return The converted AVVideo.
	 */
	void convertAVVideoToVideo(Model::Video* target);


	/**
	 * @brief convertVideoToAVVideo Converts a Video to a AVVideo.
	 * @param video The video to convert.
	 * @return The converted video.
	 */
	void convertVideoToAVVideo(Model::AVVideo* target);

  private:
	Model::Video* video_;
	Model::Video* videoTarget_;
	Model::AVVideo* avvideo_;
	Model::AVVideo* avvideoTarget_;

	std::thread converter_;
	bool isRunning_;

	void convertVideoP();
	void convertAVVideoP();
};
}

#endif

