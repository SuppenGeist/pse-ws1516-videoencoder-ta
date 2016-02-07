#ifndef __Filter_h__
#define __Filter_h__

#include <string>
#include <memory>

#include <QString>
//NOT FINISHED
namespace Model {
/**
 * Baseclass for Filters.
*/
class Filter {
  public:
	static std::unique_ptr<Filter> CreateFilter(QString filtername);

	Filter();

	virtual ~Filter();

	/**
	 * @brief getFilterDescription Returns the string that the ffmpeg library needs to apply the filter to a video.
	 * @return The string for the ffmpeg library.
	 */
	virtual std::string getFilterDescription() = 0;

	/**
	 * @brief getName
	 * @return
	 */
	virtual QString getName()=0;

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	virtual void restoreFilter(QString description) = 0;

	/**
	 * @brief getSaveString
	 * @return
	 */
	virtual QString getSaveString() = 0;
};
}

#endif


