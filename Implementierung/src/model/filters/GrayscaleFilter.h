#ifndef __BlackWhiteFilter_h__
#define __BlackWhiteFilter_h__

#include <QString>

#include <string>

#include "Filter.h"

namespace Model {

/**
 * Converts the video to a black and white video.
*/
class GrayscaleFilter: public Filter {

  public:
	static const QString FILTERNAME;

	/**
	 * @brief GrayScaleFilter Constructor.
	 */
	GrayscaleFilter();

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
	void restore(QString description);

	/**
	 * @brief getSaveString
	 * @return
	 */
	QString getSaveString();
};
}

#endif


