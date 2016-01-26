
#include <exception>
#include <string>
using namespace std;

#ifndef __EdgeFilter_h__
#define __EdgeFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class EdgeFilter;
}

namespace Model
{
	/**
	 * Filters everything but the edges out of the video.
	 */
	class EdgeFilter: public Model::Filter
	{

		public: EdgeFilter();

		public: string getFilterDescription();

		public: string getName();
	};
}

#endif
