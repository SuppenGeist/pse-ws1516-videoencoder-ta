#ifndef __BorderFilter_h__
#define __BorderFilter_h__

#include <QColor>
#include <QString>

#include <string>

#include "Filter.h"

namespace Model {
/**
 * Inserts border into the video
*/
class BorderFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;

    /**
     * @brief BorderFilter Constructor.
     */
	BorderFilter();

    /**
     * @brief getTop Whether a border is inserted at the top.
     * @return True if a border is inserted at the top.
     */
    bool getTop();

    /**
     * @brief setTop Sets whether a border is inserted at the top.
     * @param top True if a border is inserted at the top.
     */
	void setTop(bool top);

    /**
     * @brief getBottom Whether a border is inserted at the bottom.
     * @return True if a border is inserted at the bottom.
     */
	bool getBottom();

    /**
     * @brief setBottom Sets whether a border is inserted at the bottom.
     * @param bottom True if a border is inserted at the bottom.
     */
	void setBottom(bool bottom);

    /**
     * @brief getRight Whether a border is inserted at the right.
     * @return True if a border is inserted at the right.
     */
	bool getRight();

    /**
     * @brief setRight Sets whether a border is inserted at the right.
     * @param right True if a border is inserted at the right.
     */
	void setRight(bool right);

    /**
     * @brief getLeft Whether a border is inserted at the left.
     * @return True if a border is inserted at the left.
     */
	bool getLeft();

    /**
     * @brief setLeft Sets whether a border is inserted at the left.
     * @param left True if a border is inserted at the left.
     */
	void setLeft(bool left);

    /**
     * @brief getThickness Returns the thickness of the border.
     * @return The thickness of the border.
     */
	int getThickness();

    /**
     * @brief setThickness Sets the thickness of the border.
     * @param thickness The thickness.
     */
    void setThickness(int thickness);

    /**
     * @brief getColor Returns the color of the border.
     * @return The border color.
     */
    QColor getColor();
    /**
     * @brief setColor Sets the color of the border,
     * @param color The new border color.
     */
    void setColor(QColor color);

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
    bool    top_;
    bool    bottom_;
    bool    right_;
    bool    left_;
    int     thickness_;
    QColor    color_;
};
}

#endif


