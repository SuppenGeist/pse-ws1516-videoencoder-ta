
#include <exception>
#include <string>
using namespace std;

#ifndef __RotationFilter_h__
#define __RotationFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class RotationFilter;
}

namespace Model
{
	/**
	 * Rotates the video.
	 */
	class RotationFilter: public Model::Filter
	{
		private: int angle;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: RotationFilter();

		public: string getFilterDescription();

		/// <summary>
		/// Returns the angle of the rotation.
		/// </summary>
		/// <returns>The rotation angle.</returns>
		public: int getAngle();

		public: string getName();

		/// <summary>
		/// Sets the angle of the rotation.
		/// </summary>
		/// <param name="angle">The new rotation angle.</param>
		public: void setAngle(int angle);
	};
}

#endif
