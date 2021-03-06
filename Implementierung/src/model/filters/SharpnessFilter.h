#include <exception>
#include <string>


#ifndef __SharpnessFilter_h__
#define __SharpnessFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Sharpens the video.
*/
class SharpnessFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief SharpnessFilter Constructor.
	 */
	SharpnessFilter();

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	std::string getFilterDescription();

	/**
	 * @brief Returns the intensity of the Sharpness.
	 * @param The intensity.
	 */
	int getIntensity();

	/**
	 * @brief getName
	 * @return
	 */
	QString getName() const;

	/**
	 * @brief Sets the intensity of the Sharpness.
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


