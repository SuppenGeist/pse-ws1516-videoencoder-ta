
#include <exception>
using namespace std;

#ifndef __YuvFileSaver_h__
#define __YuvFileSaver_h__

#include "Video.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
	class YuvFileSaver;
}

namespace Utility
{
	/**
	 * This is the base class for yuv savers.
	 */
	__abstract class YuvFileSaver
	{
		protected: int width;
		protected: int height;
		protected: GUI::Video* video;
		protected: QFile file;
		protected: QDataStream dataStream;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to save to.</param>
		/// <param name="video">The video to save.</param>
		public: YuvFileSaver(QString filename, GUI::Video& video);

		/// <summary>
		/// Saves the video to the file.
		/// </summary>
		public: virtual void save() = 0;
	};
}

#endif
