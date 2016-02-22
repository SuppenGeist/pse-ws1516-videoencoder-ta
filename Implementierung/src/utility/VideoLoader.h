#ifndef __VideoLoader_h__
#define __VideoLoader_h__

#include <thread>

#include <QString>

#include "../model/AVVideo.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

namespace Utility {
/**
 * This class can load an encoded video.
 */

class VideoLoader {

  public:
	/**
	 * @brief VideoLoader Constructor.
	 * @param path Absolute path to the video to load.
	 * @param dict Optional pointer to dictionary
	 */
	VideoLoader(QString path, AVDictionary *dict = NULL);

	~VideoLoader();

	/**
	 * @brief loadVideo Loads the video and generates the AVVideo.
	 * @return  The loaded video.
	 */
	void loadVideo(Model::AVVideo *target);

	QString getCodec();

	int getAverageBitrate();

  private:
	QString     path_;
	std::thread loader_;
	Model::AVVideo* target_;
	bool isRunning_;
	AVDictionary *dict_;
	QString codec_;
	int averageBitrate_;

	void loadP();
};
}

#endif

