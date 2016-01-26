
#include <exception>
#include <string>
using namespace std;

#ifndef __PosterFilter_h__
#define __PosterFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class PosterFilter;
}

namespace Model
{
	/**
	 * Reduces the maximum number of colors in the video.
	 */
	class PosterFilter: public Model::Filter
	{
		private: int numberOfColors;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: PosterFilter();

		public: string getFilterDescription();

		/// <summary>
		/// Returns the maximum number of colors.
		/// </summary>
		/// <returns>Maximum number of colors.</returns>
		public: int getNumberOfColors();

		public: string getName();

		/// <summary>
		/// Sets the maximum number of colors.
		/// </summary>
		/// <param name="numberOfColors">Maximum number of colors.</param>
		public: void setNumberOfColors(int numberOfColors);
	};
}

#endif
