
#include <exception>
#include <string>
using namespace std;

#ifndef __ContrastFilter_h__
#define __ContrastFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class ContrastFilter;
}

namespace Model
{
	/**
	 * Adjusts the contrast of the video.
	 */
	class ContrastFilter: public Model::Filter
	{
		private: int intensity;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ContrastFilter();

		/// <summary>
		/// Sets the intensity of the contrast.
		/// </summary>
		/// <param name="intensity">The new intensity.</param>
		public: void setIntensity(int intensity);

		/// <summary>
		/// Returns the intensity of the contrast.
		/// </summary>
		/// <returns>The intensity.</returns>
		public: int getIntensity();

		public: string getName();

		public: string getFilterDescription();
	};
}

#endif
