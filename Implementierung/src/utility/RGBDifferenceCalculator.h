using namespace std;

#ifndef __RGBDifferenceCalculator_h__
#define __RGBDifferenceCalculator_h__

#include "../model/Video.h"

namespace Model {
class Video;
}
namespace Utility {
class RGBDifferenceCalculator;
}

namespace Utility {
/**
 * This class calculates the RGB-difference video of a video.
 */
class RGBDifferenceCalculator {
  private:
	Model::Video* referenceVideo;
  private:
	Model::Video* video;

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="referenceVideo">The reference video.</param>
	/// <param name="video">The video that is compared to the reference video.</param>
  public:
	RGBDifferenceCalculator(Model::Video& referenceVideo, Model::Video& video);

	/// <summary>
	/// Calculates the RGB difference between two videos.
	/// </summary>
	/// <param name="target">The video the calculated frames are added to.</param>
  public:
	void calculateVideo(Model::Video& target);
};
}

#endif
