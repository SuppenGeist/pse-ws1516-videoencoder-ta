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
    Yuv444Vector(char y, char u, char v);

    /**
     * @brief getY Returns y value.
     * @return
     */
    char getY();

    /**
     * @brief getU Returns u value.
     * @return
     */
    char getU();

    /**
     * @brief getV Returns v value.
     * @return
     */
    char getV();

    /**
     * @brief setY Sets the y value.
     * @param y
     */
    void setY(char y);

    /**
     * @brief setU Sets the u value.
     * @param u
     */
    void setU(char u);

    /**
     * @brief setV Sets the v value.
     * @param v
     */
    void setV(char v);

private:
    char y_;
    char u_;
    char v_;
};
}

#endif

