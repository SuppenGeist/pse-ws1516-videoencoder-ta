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
	SepiaFilter();

<<<<<<< HEAD
        public: std::string getName();

        public: std::string getFilterDescription();
=======
  public:
	string getName();

  public:
	string getFilterDescription();
>>>>>>> origin/master

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


