#ifndef VIDEOSAVER_H
#define VIDEOSAVER_H

#include <memory>
#include <thread>

#include <QString>

extern "C" {
#include <libavformat/avformat.h>
}

namespace Model {
class Video;
}

namespace Utility {
class VideoSaver {
  public:
	VideoSaver(Model::Video* video,QString filename);

	~VideoSaver();


	/**
	 * @brief saveVideo Saves a video in the given file.
	 * @param video The video to save.
	 * @param filename The path to save the video.
	 */
	void save();

	void join();


  private:
	Model::Video* video_;
	QString filename_;

	std::thread saver_;
	bool isRunning_;

	void saveP();

};

}

#endif // VIDEOSAVER_H
