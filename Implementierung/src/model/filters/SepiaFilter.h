#include <exception>
#include <string>
using namespace std;

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
	SepiaFilter();

  public:
	string getName();

  public:
	string getFilterDescription();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


