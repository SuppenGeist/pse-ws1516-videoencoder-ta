#ifndef __Yuv444Vector_h__
#define __Yuv444Vector_h__

#include <cstdint>

namespace Utility {

// A Yuv444Vector.

class Yuv444Vector {

public:

    /**
     * @brief Yuv444Vector Constructor.
     */
    Yuv444Vector();

    /**
     * @brief Yuv444Vector Constructor.
     * @param y
     * @param u
     * @param v
     */
    Yuv444Vector(uint8_t y, uint8_t u, uint8_t v);

    /**
     * @brief getY Returns y value.
     * @return
     */
    uint8_t getY();

    /**
     * @brief getU Returns u value.
     * @return
     */
    uint8_t getU();

    /**
     * @brief getV Returns v value.
     * @return
     */
    uint8_t getV();

    /**
     * @brief setY Sets the y value.
     * @param y
     */
    void setY(uint8_t y);

    /**
     * @brief setU Sets the u value.
     * @param u
     */
    void setU(uint8_t u);

    /**
     * @brief setV Sets the v value.
     * @param v
     */
    void setV(uint8_t v);

private:
    uint8_t y_;
    uint8_t u_;
    uint8_t v_;
};
}

#endif

