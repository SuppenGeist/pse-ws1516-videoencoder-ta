#include <exception>
#include <string>
//NOT FINISHED

#ifndef __SepiaFilter_h__
#define __SepiaFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class SepiaFilter;
}

namespace Model {
/**
 * Converts the video into sepia.
*/
class SepiaFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;
    /**
     * @brief SepiaFilter Constructor.
     */
	SepiaFilter();

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


