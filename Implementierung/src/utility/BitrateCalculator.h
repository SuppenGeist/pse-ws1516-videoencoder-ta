#ifndef __BitrateCalculator_h__
#define __BitrateCalculator_h__

namespace Model
{
	class AVVideo;
	class Graph;
}

namespace Utility
{
	/**
	 * This class calculates the bitrate of a video.
     */
	class BitrateCalculator
    {
        public:
        /**
         * @brief BitrateCalculator Constructor.
         * @param video The video of which the bitrate is calculated.
         */
        BitrateCalculator(Model::AVVideo& video);

        /**
         * @brief calculate Calculates the bitrate graph.
         * Calculates kb per frame.
         * @return The calculated bitrate graph.
         */
        Model::Graph calculate();

        private:
        Model::AVVideo* video_;
	};
}

#endif
