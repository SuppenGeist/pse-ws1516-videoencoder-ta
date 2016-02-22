#ifndef __RGBHistogramCalculator_h__
#define __RGBHistogramCalculator_h__

#include <thread>

#include "../model/Video.h"
#include "../model/Graph.h"
#include "../model/graphvideo.h"


namespace Utility {
/**
 * This class calculates the RGB histogram for a video.
 */
class RGBHistogramCalculator {

  public:
	/**
         * @brief RGBHistogramCalculator Constructor.
         * @param video The video that is analyzed.
	 */
        RGBHistogramCalculator(Model::Video& video);

        ~RGBHistogramCalculator();

	/**
	 * @brief calculate Calculates the red, green and blue components of a video.
	 */
	void calculate(Model::GraphVideo* targetRed,Model::GraphVideo* targetGreen,
	               Model::GraphVideo* targetBlue);


  private:
	Model::Video*         video_;
	Model::GraphVideo*    red_;
	Model::GraphVideo*    green_;
	Model::GraphVideo*    blue_;

	std::thread           calculator_;
	bool                  isRunning_;

	void calculateP();
};
}

#endif
