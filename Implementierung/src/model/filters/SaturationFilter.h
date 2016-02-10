#include <exception>
#include <string>


#ifndef __SaturationFilter_h__
#define __SaturationFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Adjusts the saturation of the video.
*/
class SaturationFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief SaturationFilter Constructor.
	 */
	SaturationFilter();

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	std::string getFilterDescription();

	/**
	 * @brief Returns the intensity of the Saturation.
	 * @return The intensity.
	 */
	int getIntensity();

	/**
	 * @brief getName
	 * @return
	 */
    QString getName() const;

	/**
	 * @brief Sets the intensity of the Saturation.
	 * @param The intensity.
	 */
	void setIntensity(int intensity);

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
	int intensity_;
};
}

#endif

