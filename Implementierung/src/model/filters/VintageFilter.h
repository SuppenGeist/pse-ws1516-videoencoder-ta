#include <exception>
#include <string>


#ifndef __VintageFilter_h__
#define __VintageFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Adjusts the colors of the video to make it look vintage.
*/
class VintageFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief VintageFilter Constructor.
	 */
	VintageFilter();

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
};
}

#endif


