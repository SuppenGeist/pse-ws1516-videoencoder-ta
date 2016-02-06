#include <exception>
#include <string>
//NOT FINISHED

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
    static const QString FILTERNAME;

	VintageFilter();

    QString getName();

	std::string getFilterDescription();

	void restoreFilter(QString description);

	QString getSaveString();
};
}

#endif


