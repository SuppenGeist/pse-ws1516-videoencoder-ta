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

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	NegativeFilter();

<<<<<<< HEAD
        public: std::string getFilterDescription();

        public: std::string getName();
=======
  public:
	string getFilterDescription();

  public:
	string getName();
>>>>>>> origin/master

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif
