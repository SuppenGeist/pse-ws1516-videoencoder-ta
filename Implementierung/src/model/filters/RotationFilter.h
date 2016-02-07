#include <exception>
#include <string>
//NOT FINISHED

#ifndef __RotationFilter_h__
#define __RotationFilter_h__

#include "Filter.h"



namespace Model {
/**
 * Rotates the video.
*/
class RotationFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief RotationFilter Constructor.
	 */
  public:
	RotationFilter();


	/**
	 * @brief Returns the angle of the rotation.
	 * @return The new rotation angle.
	 */
  public:
	int getAngle();

	/**
	 * @brief Sets the angle of the rotation.
	 * @param The new rotation angle.
	 */
	void setAngle(int angle);

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
	int angle;
};
}

#endif


