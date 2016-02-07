#ifndef __EdgeFilter_h__
#define __EdgeFilter_h__





#include "Filter.h"


namespace Model {
/**
 * Filters everything but the edges out of the video.
*/
class EdgeFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief EdgeFilter Constructor.
	 */
	EdgeFilter();

	/**
	 * @brief getFilterDescription
	 * @return
	 */
	std::string getFilterDescription();

	/**
	 * @brief getName
	 * @return
	 */
	QString getName();

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


