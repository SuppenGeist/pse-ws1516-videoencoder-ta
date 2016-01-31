#include <exception>
#include <string>


#ifndef __VintageFilter_h__
#define __VintageFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class VintageFilter;
}

namespace Model {
/**
 * Adjusts the colors of the video to make it look vintage.
*/
class VintageFilter: public Model::Filter {

  public:
	VintageFilter();

  public:
    std::string getName();

  public:
    std::string getFilterDescription();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


