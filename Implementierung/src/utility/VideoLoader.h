
#include <memory>
using namespace std;
#ifndef __VideoLoader_h__
#define __VideoLoader_h__

#include "../model/AVVideo.h"

namespace Model
{
	class AVVideo;
}
namespace Utility
{
	class VideoLoader;
}

namespace Utility
{
	/**
	 * This class can load a encoded video.
     */

	class VideoLoader
	{
		private: QString path;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="path">Absolute path to the video to load.</param>
		public: VideoLoader(QString path);

		/// <summary>
		/// Loads the video and generates the AVVideo.
		/// </summary>
		/// <returns>The loaded video.</returns>
    public: unique_ptr<Model::AVVideo> loadVideo();
	};
}

#endif

