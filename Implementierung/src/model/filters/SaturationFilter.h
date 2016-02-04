#include <exception>
#include <string>


#ifndef __SaturationFilter_h__
#define __SaturationFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class SaturationFilter;
}

namespace Model {
/**
 * Adjusts the saturation of the video.
*/
class SaturationFilter: public Model::Filter {
  private:
	int intensity;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	SaturationFilter();

  public:
	std::string getFilterDescription();

	/// <summary>
	/// Returns the intensity of the saturation.
	/// </summary>
	/// <returns>The intensity.</returns>
  public:
	int getIntensity();

  public:
	std::string getName();

	/// <summary>
	/// Sets the intensity of the saturation.
	/// </summary>
	/// <param name="intensity">The new intensity,</param>
  public:
	void setIntensity(int intensity);

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif

