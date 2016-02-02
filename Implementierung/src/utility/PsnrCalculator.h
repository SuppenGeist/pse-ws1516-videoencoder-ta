#ifndef __PsnrCalculator_h__
#define __PsnrCalculator_h__

namespace Model
{
    class Video;
	class Graph;
}

namespace Utility
{
	/**
	 * This class calculates the psnr-graph of a video.
     */
	class PsnrCalculator
    {
        public:
        /**
         * @brief PsnrCalculator Constructor.
         * @param referenceVideo The reference video for the psnr calculation.
         * @param compareVideo The video that is compared to the reference video.
         */
        PsnrCalculator(Model::Video& referenceVideo, Model::Video& compareVideo);

        /**
         * @brief calculate Calculates the psnr graph.
         * @return The calculated psnr graph.
         */
        Model::Graph calculate();

        private:

        Model::Video* referenceVideo_;
        Model::Video* video_;

	};
}

#endif
