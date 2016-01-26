
#include <exception>
#include <string>
using namespace std;

#ifndef __BlackWhiteFilter_h__
#define __BlackWhiteFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class BlackWhiteFilter;
}

namespace Model
{
	/**
	 * Converts the video to a black and white video.
	 */
	class BlackWhiteFilter: public Model::Filter
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BlackWhiteFilter();

		public: string getName();

		public: string getFilterDescription();
	};
}

#endif
