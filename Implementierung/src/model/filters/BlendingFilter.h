#ifndef __BlendingFilter_h__
#define __BlendingFilter_h__

#include <QString>

#include <string>

#include "Filter.h"

namespace Model {
/**
 * Inserts black blending into the video
*/
class BlendingFilter: public Filter {
  public:
    static const QString FILTERNAME;

    /**
     * @brief BlendingFilter Constructor.
     */
	BlendingFilter();

    /**
     * @brief getInBlend Whether it is an in blending.
     * @return true if it is an in blending.
     */
	bool getInBlend();

    /**
     * @brief setInBlend Sets whether it is an in blending.
     * @param inBlend True if it is an in blending.
     */
	void setInBlend(bool inBlend);

    /**
     * @brief getStartFrame Returns the start frame of the blending.
     * @return The start frame of the blending.
     */
	int getStartFrame();

    /**
     * @brief setStartFrame Sets the start frame of the blending.
     * @param startFrame The start frame.
     */
	void setStartFrame(int startFrame);

    /**
     * @brief getEndFrame Returns the end frame of the blending.
     * @return The end frame.
     */
	int getEndFrame();

    /**
     * @brief setEndFrame Sets the end frame of the blending.
     * @param endFrame The end frame.
     */
	void setEndFrame(int endFrame);

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
    bool    inBlend_;
    int     startFrame_;
    int     endFrame_;
};
}

#endif

