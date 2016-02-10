#ifndef __BrightnessFilter_h__
#define __BrightnessFilter_h__

#include "Filter.h"

namespace Model {
/**
 * Adjusts the video brightness.
*/
class BrightnessFilter: public Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief BrightnessFilter Constructor.
	 */
	BrightnessFilter();

	/**
	 * @brief getIntensity Returns the intensity of the brightness.
	 * @return The intensity.
	 */
	int getIntensity();

	/**
	 * @brief setIntensity Sets the intensity of the brightness.
	 * @param intensity The new intensity.
	 */
	void setIntensity(int intensity);

	/**
	 * @brief getName
	 * @return
	 */
    QString getName() const;

	/**
	 * @brief getFilterDescription
	 * @return
	 */
	std::string getFilterDescription();

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	void restore(QString description);

	/**
	 * @brief getSaveString
	 * @return
	 */
    QString getSaveString() const;


  private:
	int     intensity_;
};
}

#endif


