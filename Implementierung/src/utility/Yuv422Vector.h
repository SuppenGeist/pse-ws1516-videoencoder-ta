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
    Yuv422Vector(uint8_t u,uint8_t y1,uint8_t v,uint8_t y2);

    /**
     * @brief getU Returns the u component.
     * @return
     */
    uint8_t getU();

    /**
     * @brief getY1 Returns the y1 component.
     * @return
     */
    uint8_t getY1();

    /**
     * @brief getV Returns the v component.
     * @return
     */
    uint8_t getV();

    /**
     * @brief getY2 Returns the y2 component.
     * @return
     */
    uint8_t getY2();

    /**
     * @brief setU Sets the u component.
     * @param u
     */
    void setU(uint8_t u);

    /**
     * @brief setY1  Sets the y1 component.
     * @param y1
     */
    void setY1(uint8_t y1);

    /**
     * @brief setV  Sets the v component.
     * @param v
     */
    void setV(uint8_t v);

    /**
     * @brief setY2  Sets the y2 component.
     * @param y2
     */
    void setY2(uint8_t y2);

  private:
    uint8_t u_;
    uint8_t y1_;
    uint8_t v_;
    uint8_t y2_;
};
}

#endif

