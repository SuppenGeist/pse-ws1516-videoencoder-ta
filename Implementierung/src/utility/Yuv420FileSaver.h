#ifndef __Yuv420FileSaver_h__
#define __Yuv420FileSaver_h__

#include <exception>
#include "../model/Video.h"
#include "YuvFileSaver.h"

using namespace std;

namespace Model {
class Video;
}
namespace Utility {
class YuvFileSaver;
class Yuv420FileSaver;
}

namespace Utility {

//This class can save videos in the yuv 420 format.

class Yuv420FileSaver: public Utility::YuvFileSaver {

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="filename">Absolute path to the file to save to.</param>
	/// <param name="video">The video to save.</param>
  public:
	Yuv420FileSaver(QString filename, Model::Video& video);

  public:
	void save();

	/*	/// <summary>
		/// saves the ith frame.
		/// If the index is invalid nothing happens.
		/// </summary>
		/// <param name="index">index of the frame to safe</param>
	  private:
		void saveFrame(int index);
	*/
};
}

#endif

