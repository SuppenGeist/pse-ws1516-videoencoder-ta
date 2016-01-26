
#include <exception>
using namespace std;

#ifndef __RGBHistogrammCalculator_h__
#define __RGBHistogrammCalculator_h__

#include "Video.h"
#include "Graph.h"

namespace GUI
{
	class Video;
}
namespace Model
{
	class Graph;
}
namespace Utility
{
	class RGBHistogrammCalculator;
}

namespace Utility
{
	/**
	 * This class calculates the RGB histogramm for a video.
	 */
	class RGBHistogrammCalculator
	{
		private: GUI::Video* video;
		private: Model::Graph redHistogramm;
		private: Model::Graph greenHistogramm;
		private: Model::Graph blueHistogramm;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="video">the video that is analyzed.</param>
		public: void RGBHistorgrammCalculator(GUI::Video& video);

		/// <summary>
		/// Calculates the red, green and blue components of a video.
		/// </summary>
		public: void calculate();

		/// <summary>
		/// Returns the red components of a video.
		/// </summary>
		public: Model::Graph getRedHistogramm();

		/// <summary>
		/// Returns the green components of a video.
		/// </summary>
		public: Model::Graph getGreenHistogramm();

		/// <summary>
		/// Returns the blue components of a video.
		/// </summary>
		public: Model::Graph getBlueHistogramm();
	};
}

#endif
