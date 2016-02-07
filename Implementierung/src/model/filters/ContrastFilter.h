#ifndef __ContrastFilter_h__
#define __ContrastFilter_h__

#include <QString>

#include <string>

#include "Filter.h"

namespace Model {
/**
 * Adjusts the contrast of the video.
*/
class ContrastFilter: public Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief ContrastFilter Constructor.
	 */
	ContrastFilter();

	/**
	 * @brief setIntensity Sets the intensity of the contrast.
	 * @param intensity The new intensity.
	 */
	void setIntensity(int intensity);

	/**
	 * @brief getIntensity Returns the intensity of the contrast.
	 * @return The intensity.
	 */
	int getIntensity();

	/**
	 * @brief getName
	 * @return
	 */
	QString getName();

	/**
	 * @brief getFilterDescription
	 * @return
	 */
	std::string getFilterDescription();

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	void restoreFilter(QString description);

	/**
	 * @brief getSaveString
	 * @return
	 */
	QString getSaveString();

  private:
	int     intensity_;
};
}

#endif


