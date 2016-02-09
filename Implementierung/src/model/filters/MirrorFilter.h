#ifndef __MirrorFilter_h__
#define __MirrorFilter_h__

#include "../MirrorMode.h"
#include "Filter.h"

namespace Model {
/**
 * Mirrors the video horizontally or vertically.
*/
class MirrorFilter: public Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief MirrorFilter Constructor.
	 */
	MirrorFilter();

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
	 * @brief getMode Returns the MirrorMode.
	 * @return The MirrorMode.
	 */
	Model::MirrorMode getMode();

	/**
	 * @brief setMode Sets the MirrorMode.
	 * @param mode The MirrorMode.
	 */
	void setMode(Model::MirrorMode mode);

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
  private:
	MirrorMode   mode_;
};
}

#endif


