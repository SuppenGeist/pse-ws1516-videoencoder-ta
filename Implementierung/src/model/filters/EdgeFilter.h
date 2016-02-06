#ifndef __EdgeFilter_h__
#define __EdgeFilter_h__





#include "Filter.h"
//NOT FINISHED
namespace Model {
// class Filter;
class EdgeFilter;
}

namespace Model {
/**
 * Filters everything but the edges out of the video.
*/
class EdgeFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;

  public:
	EdgeFilter();

  public:
	std::string getFilterDescription();

  public:
    QString getName();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


