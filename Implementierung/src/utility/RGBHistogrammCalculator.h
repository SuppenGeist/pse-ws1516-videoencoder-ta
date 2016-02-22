#ifndef __RGBHistogrammCalculator_h__
#define __RGBHistogrammCalculator_h__

#include <thread>

#include "../model/Video.h"
#include "../model/Graph.h"
#include "../model/graphvideo.h"


namespace Utility {
/**
 * This class calculates the RGB histogramm for a video.
 */
class RGBHistogrammCalculator {

  public:
	/**
	 * @brief RGBHistogrammCalculator Constructor.
         * @param video The video that is analyzed.
	 */
	RGBHistogrammCalculator(Model::Video& video);

	~RGBHistogrammCalculator();

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
