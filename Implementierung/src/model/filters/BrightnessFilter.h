#include <exception>
#include <string>
using namespace std;

#ifndef __BrightnessFilter_h__
#define __BrightnessFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class BrightnessFilter;
}

namespace Model
{
	/**
	 * Adjusts the video brightness.
    */
	class BrightnessFilter: public Model::Filter
	{
		private: int intensity;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BrightnessFilter();

		/// <summary>
		/// Returns the intensity of the brightness.
		/// </summary>
		/// <returns>The intensity.</returns>
		public: int getIntensity();

		/// <summary>
		/// Sets the intensity of the brightness.
		/// </summary>
		/// <param name="intensity">The new intensity.</param>
		public: void setIntensity(int intensity);

		public: string getName();

		public: string getFilterDescription();

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
}

#endif


