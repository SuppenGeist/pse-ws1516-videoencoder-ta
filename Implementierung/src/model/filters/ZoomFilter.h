#include <exception>
#include <string>
using namespace std;

#ifndef __ZoomFilter_h__
#define __ZoomFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class ZoomFilter;
}

namespace Model {
/**
 * Zooms into the center of the video.
*/
class ZoomFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;
  private:
	int intensity;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	ZoomFilter();

  public:
    QString getName();

  public:
	string getFilterDescription();

	/// <summary>
	/// Returns the intensity of the zoom.
	/// </summary>
	/// <returns>The zoom intensity.</returns>
  public:
	int getIntensity();

	/// <summary>
	/// Sets the intensity of the zoom.
	/// </summary>
	/// <param name="intensity">The new intensity.</param>
  public:
	void setIntensity(int intensity);

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


