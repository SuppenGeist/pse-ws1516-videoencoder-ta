#include <exception>
#include <string>
using namespace std;

#ifndef __NoiseFilter_h__
#define __NoiseFilter_h__

#include "../NoiseMode.h"
#include "Filter.h"

namespace Model
{
	// enum NoiseMode;
	// class Filter;
	class NoiseFilter;
}

namespace Model
{
	/**
	 * Inserts noise into the video.
    */
	class NoiseFilter: public Model::Filter
	{
		private: int intensity;
		private: Model::NoiseMode* mode;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: NoiseFilter();

		public: string getFilterDescription();

		/// <summary>
		/// Returns the NoiseMode.
		/// </summary>
		/// <returns>The NoiseMode.</returns>
		public: Model::NoiseMode getMode();

		/// <summary>
		/// Sets the NoiseMode.
		/// </summary>
		/// <param name="mode">The new NoiseMode.</param>
		public: void setMode(Model::NoiseMode mode);

		/// <summary>
		/// Returns the intensity of the noise.
		/// </summary>
		/// <returns>The noise intensity.</returns>
		public: int getIntensity();

		public: string getName();

		/// <summary>
		/// Sets the intensity of the noise.
		/// </summary>
		/// <param name="intensity">The new intensity of the noise.</param>
		public: void setIntensity(int intensity);

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
}

#endif


