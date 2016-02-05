#include <exception>
#include <string>


#ifndef __NegativeFilter_h__
#define __NegativeFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class NegativeFilter;
}

namespace Model {
/**
 * Converts the video into it's negative.
*/
class NegativeFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	NegativeFilter();

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
