#include <exception>
#include <string>

#ifndef __BlackWhiteFilter_h__
#define __BlackWhiteFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class BlackWhiteFilter;
}

namespace Model {
/**
 * Converts the video to a black and white video.
*/
class BlackWhiteFilter: public Model::Filter {

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	BlackWhiteFilter();

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


