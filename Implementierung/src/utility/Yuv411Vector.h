#ifndef __Yuv411Vector_h__
#define __Yuv411Vector_h__
#include <cstdint>

namespace Utility {

/**
 * @brief The Yuv411Vector class is a vector holding yuv411 values.
 */
class Yuv411Vector {
public:

    /**
     * @brief Yuv411Vector Constructor.
     */
    Yuv411Vector();

    /**
     * @brief Yuv411Vector Constructor.
     * @param u
     * @param y1
     * @param y2
     * @param v
     * @param y3
     * @param y3
     */
    Yuv411Vector(char u, char y1, char y2, char v, char y3, char y4);

    /**
     * @brief getU Returns u value.
     * @return
     */
    char getU();

    /**
     * @brief getY1 Returns Y1 value.
     * @return
     */
    char getY1();

    /**
     * @brief getY2 Returns Y2 value.
     * @return
     */
    char getY2();

    /**
     * @brief getV Returns V value.
     * @return
     */
    char getV();

    /**
     * @brief getY3 Returns Y3 value.
     * @return
     */
    char getY3();

    /**
     * @brief getY4 Returns Y4 value.
     * @return
     */
    char getY4();

    /**
     * @brief setY Sets the u value.
     * @param u
     */
    void setU(char U);

    /**
     * @brief setY1 Sets the y1 value.
     * @param y1
     */
    void setY1(char Y1);

    /**
     * @brief setY2 Sets the y2 value.
     * @param y2
     */
    void setY2(char Y2);

    /**
     * @brief setV Sets the v value.
     * @param v
     */
    void setV(char V);

    /**
     * @brief setY3 Sets the y3 value.
     * @param y3
     */
    void setY3(char Y3);

    /**
     * @brief setY4 Sets the y4 value.
     * @param y4
     */
    void setY4(char Y4);

private:
    char u_;
    char y1_;
    char y2_;
    char v_;
    char y3_;
    char y4_;
};
}

#endif

