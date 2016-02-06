#ifndef __BlackWhiteFilter_h__
#define __BlackWhiteFilter_h__

#include <QString>

#include <string>

#include "Filter.h"
//NOT FINISHED
namespace Model {
/**
 * Converts the video to a black and white video.
*/
class Grayscale: public Filter {

public:
  static const QString FILTERNAME;

    /**
     * @brief BlackWhiteFilter Constructor.
     */
    Grayscale();

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


