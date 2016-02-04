
#include <exception>
#include <string>


#ifndef __RGBFilter_h__
#define __RGBFilter_h__

#include "../../utility/BasicColor.h"
#include "Filter.h"

namespace Model {
// enum BasicColor;
// class Filter;
class RGBFilter;
}

namespace Model {
/**
 * Filters the video by a given channel (red, green or blue).
*/
class RGBFilter: public Model::Filter {
  private:
	Model::BasicColor* color;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	RGBFilter();

  public:
	std::string getFilterDescription();

	/// <summary>
	/// Returns the color that is not filtered out.
	/// </summary>
	/// <returns>The preserved color.</returns>
  public:
	Model::BasicColor getColor();

	/// <summary>
	/// Sets the preserved color.
	/// </summary>
	/// <param name="color">The preserved color.</param>
  public:
	void setColor(Model::BasicColor color);

  public:
	std::string getName();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif

