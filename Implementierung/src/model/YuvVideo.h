#ifndef __YuvVideo_h__
#define __YuvVideo_h__

#include <memory>

#include <QString>

#include "Video.h"
#include "AVVideo.h"
#include "graphvideo.h"

#include "../utility/YuvFileReader.h"
#include "../utility/RGBHistogrammCalculator.h"

namespace Utility {
enum class Compression;
enum class YuvType;
}

namespace Model {
/**
 * This class holds a yuv video with all its properties.
 */
class YuvVideo {

  public:
	/**
	 * @brief YuvVideo Constructor.
	 * @param path Path to the yuv file.
         * @param type Pixelscheme of the yuv video.
	 * @param compression Compression mode of the video.
	 * @param width Width of the video.
	 * @param height Height of the video.
	 * @param fps Fps of the video.
	 */
	YuvVideo(QString path, Utility::YuvType type,Utility::Compression compression, int width,
	         int height, int fps);

	~YuvVideo();

	/**
	 * @brief getPath Returns the path to the video.
	 * @return Path to the video.
	 */
	QString getPath();

	/**
	 * @brief getCompression Returns the compression of the video.
	 * @return The compression of the video.
	 */
	Utility::Compression getCompression();

	/**
         * @brief getYuvType Returns the pixel scheme of the video.
	 * @return The pixel scheme.
	 */
	Utility::YuvType getYuvType();

	/**
	 * @brief getWidth Returns the width of the video.
	 * @return
	 */
	int getWidth();

	/**
	 * @brief getHeight Returns the height of the video.
	 * @return
	 */
	int getHeight();

	/**
         * @brief getFps Returns the fps of the video.
	 * @return
	 */
	int getFps();

	GraphVideo& getRedHistogramm();

	GraphVideo& getGreenHistogramm();

	GraphVideo& getBlueHistogramm();

	/**
	 * @brief getAvVideo Returns the AVVideo.
	 * @return The AVVideo.
	 */
	Model::AVVideo& getAvVideo();

	/**
	 * @brief getVideo Returns the Video.
	 * @return The Video.
	 */
	Model::Video& getVideo();

  private:
	QString                             path_;
	int                                 height_;
	int                                 width_;
	int                                 fps_;
	Utility::Compression                compression_;
	std::unique_ptr<Model::Video>       displayVideo_;
	std::unique_ptr<Model::AVVideo>     avVideo_;
	Utility::YuvType                    yuvType_;
	std::unique_ptr<Utility::YuvFileReader> fileReader_;
	bool                                isComplete_;
	std::unique_ptr<Utility::RGBHistogrammCalculator> histogrammCalculator_;
	std::unique_ptr<GraphVideo>         redHisto_;
	std::unique_ptr<GraphVideo>         greenHisto_;
	std::unique_ptr<GraphVideo>         blueHisto_;

	/**
	 * @brief loadVideo Loads the video from the file.
	 */
	void loadVideo();

	void calculateHistogramms();
};
}

#endif
