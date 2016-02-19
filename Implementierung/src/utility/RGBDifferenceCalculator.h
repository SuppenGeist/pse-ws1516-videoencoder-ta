#ifndef __RGBDifferenceCalculator_h__
#define __RGBDifferenceCalculator_h__

#include <thread>

#include "../model/Video.h"

namespace Utility {
/**
 * This class calculates the RGB-difference video of a video.
 */
class RGBDifferenceCalculator {

  public:
	/**
	 * @brief RGBDifferenceCalculator Constructor.
	 * @param referenceVideo The reference video->
	 * @param video The video that is compared to the reference video->
	 */
	RGBDifferenceCalculator(Model::Video& referenceVideo, Model::Video& video);

	~RGBDifferenceCalculator();

	/**
	 * @brief calculateVideo Calculates the RGB difference between two videos.
	 * @param target The video the calculated frames are added to.
	 */
	void calculateVideo(Model::Video* target);

  private:
	Model::Video* referenceVideo_;
	Model::Video* video_;
	Model::Video* target_;

	std::thread calculator_;
	bool isRunning_;

	void calculateP();
};
}

#endif
