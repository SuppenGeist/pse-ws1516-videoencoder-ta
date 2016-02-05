#include <exception>
#include <string>


#ifndef __PosterFilter_h__
#define __PosterFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class PosterFilter;
}

namespace Model {
/**
 * Reduces the maximum number of colors in the video.
*/
class PosterFilter: public Model::Filter {
  private:
	int numberOfColors;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	PosterFilter();

  public:
	std::string getFilterDescription();

	/// <summary>
	/// Returns the maximum number of colors.
	/// </summary>
	/// <returns>Maximum number of colors.</returns>
  public:
	int getNumberOfColors();

  public:
    QString getName();

	/// <summary>
	/// Sets the maximum number of colors.
	/// </summary>
	/// <param name="numberOfColors">Maximum number of colors.</param>
  public:
	void setNumberOfColors(int numberOfColors);

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


