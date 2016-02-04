#include <exception>
using namespace std;

#ifndef __VideoConverter_h__
#define __VideoConverter_h__

#include "../model/Video.h"
#include "../model/AVVideo.h"


namespace Utility {
/**
 * Converts AVFrames to QImages and vice versa.
 */

class VideoConverter {

	/// <summary>
	/// Converts the given AVFrame to a QImage.
	/// </summary>
	/// <param name="frame">The avframe to convert.</param>
	/// <param name="width">The width of the frame.</param>
	/// <param name="height">The height of the frame.</param>
	/// <returns>The converted AVFrame.</returns>
  public:
	static unique_ptr<QImage> convertAVFrameToQImage(AVFrame& frame, int width, int height);

	/// <summary>
	/// Converts a AVVideo to a Video
	/// </summary>
	/// <param name="video">The video to convert.</param>
	/// <returns>The converted AVVideo.</returns>
  public:
	static unique_ptr<Model::Video> convertAVVideoToVideo(Model::AVVideo& video);

	/// <summary>
	/// Converts a qimage to a avframe.
	/// </summary>
	/// <param name="imgae">The qimage to convert.</param>
	/// <returns>The converted qimage.</returns>
  public:
	static unique_ptr<AVFrame> convertQImageToAVFrame(QImage& image);

	/// <summary>
	/// Converts a Video to a AVVideo.
	/// </summary>
	/// <param name="video">The video to convert.</param>
	/// <returns>The converted video.</returns>
  public:
	static unique_ptr<Model::AVVideo> convertVideoToAVVideo(Model::Video& video);
};
}

#endif

