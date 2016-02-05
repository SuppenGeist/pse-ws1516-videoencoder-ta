#include <exception>
#include <string>


#ifndef __SepiaFilter_h__
#define __SepiaFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class SepiaFilter;
}

namespace Model {
/**
 * Converts the video into sepia.
*/
class SepiaFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;

  public:
	SepiaFilter();

  public:
    QString getName();

  public:
	std::string getFilterDescription();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


