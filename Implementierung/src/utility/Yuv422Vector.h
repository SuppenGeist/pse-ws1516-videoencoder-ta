#ifndef __Yuv422Vector_h__
#define __Yuv422Vector_h__

#include <cstdint>

namespace Utility {

/**
 * @brief The Yuv422Vector class is a vector that holds the yuv422 values.
 */
class Yuv422Vector {
public:
    /**
     * @brief Yuv422Vector Constructor.
     */
    Yuv422Vector();

    /**
     * @brief Yuv422Vector Constructor.
     * @param u
     * @param y1
     * @param v
     * @param y2
     */
    Yuv422Vector(unsigned char u,unsigned char y1,unsigned char v,unsigned char y2);

    /**
     * @brief getU Returns the u component.
     * @return
     */
    unsigned char getU();

    /**
     * @brief getY1 Returns the y1 component.
     * @return
     */
    unsigned char getY1();

    /**
     * @brief getV Returns the v component.
     * @return
     */
    unsigned char getV();

    /**
     * @brief getY2 Returns the y2 component.
     * @return
     */
    unsigned char getY2();

    /**
     * @brief setU Sets the u component.
     * @param u
     */
    void setU(unsigned char u);

    /**
     * @brief setY1  Sets the y1 component.
     * @param y1
     */
    void setY1(unsigned char y1);

    /**
     * @brief setV  Sets the v component.
     * @param v
     */
    void setV(unsigned char v);

    /**
     * @brief setY2  Sets the y2 component.
     * @param y2
     */
    void setY2(unsigned char y2);

  private:
    unsigned char u_;
    unsigned char y1_;
    unsigned char v_;
    unsigned char y2_;
};
}

#endif

