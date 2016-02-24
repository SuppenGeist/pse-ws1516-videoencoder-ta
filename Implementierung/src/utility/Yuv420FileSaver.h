#ifndef __Yuv420FileSaver_h__
#define __Yuv420FileSaver_h__

#include <thread>

#include "../model/Video.h"
#include "YuvFileSaver.h"
#include "../gui/FilterTab.h"

namespace Model {
class Video;
}
namespace Utility {
class YuvFileSaver;
class Yuv420FileSaver;
}

namespace Utility {

//This class can save videos in the yuv 420 format.

class Yuv420FileSaver: public YuvFileSaver {

  public:
	/**
	 * @brief Yuv420FileSaver Constructor.
	 * @param filename Absolute path to the file to save to.
	 * @param video The video to save.
	 */
	Yuv420FileSaver(QString filename, Model::Video& video);

	~Yuv420FileSaver();

  public:
	void save();

  private:
	std::thread     safer_;
	bool            isRunning_;

	void saveP();
};
}

#endif

