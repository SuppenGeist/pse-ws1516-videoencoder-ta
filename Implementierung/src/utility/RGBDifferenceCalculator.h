
#include <exception>
using namespace std;

#ifndef __RGBDifferenceCalculator_h__
#define __RGBDifferenceCalculator_h__

#include "Video.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
	class RGBDifferenceCalculator;
}

namespace Utility
{
	/**
	 * This class calculates the RGB-difference video of a video.
	 */
	class RGBDifferenceCalculator
	{
		private: GUI::Video* referenceVideo;
		private: GUI::Video* video;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="referenceVideo">The reference video.</param>
		/// <param name="video">The video that is compared to the reference video.</param>
		public: RGBDifferenceCalculator(GUI::Video& referenceVideo, GUI::Video& video);

		/// <summary>
		/// Calculates the RGB difference between two videos.
		/// </summary>
		/// <param name="target">The video the calculated frames are added to.</param>
		public: void calculateVideo(GUI::Video& target);
	};
}

#endif
