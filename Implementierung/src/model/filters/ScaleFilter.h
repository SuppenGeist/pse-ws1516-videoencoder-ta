#include <exception>
#include <QString>
//NOT FINISHED

#ifndef __ScaleFilter_h__
#define __ScaleFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Scales the video.
*/
class ScaleFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief ZoomFilter Constructor.
	 */
  public:
	ScaleFilter();


	/**
	 * @brief Whether the ration is preserved.
	 * @return True if the ration is preserved.
	 */
	bool getKeepRatio();

	/**
	 * @brief Whether the ration is preserved.
	 * @param True if the ration is preserved.
	 */
	void setKeepRatio(bool keepRatio);


	/**
	 * @brief Returns the new width.
	 * @return The new width.
	 */
	int getWidth();

	/**
	 * @brief Returns the new width.
	 * @param The new width.
	 */
	void setWidth(int width);

	/**
	 * @brief Returns the new height.
	 * @param The new height.
	 */
	int getHeight();

	/**
	 * @brief Sets the new height.
	 * @param The new height.
	 */
	void setHeight(int height);

	/**
	 * @brief Returns the ration of the scaling.
	 * @return The ratio.
	 */
	int getRatio();

	/**
	 * @brief Sets the ration of the scaling.
	 * @param The ratio.
	 */
	void setRatio(int ratio);

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


	bool keepRatio_;
	int width_;
	int height_;
	int ratio_;
};
}

#endif


