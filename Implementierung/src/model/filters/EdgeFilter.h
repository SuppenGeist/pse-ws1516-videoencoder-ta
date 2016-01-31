#ifndef __EdgeFilter_h__
#define __EdgeFilter_h__


#include <string>



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

    public: std::string getFilterDescription();

    public: std::string getName();

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
}

#endif


