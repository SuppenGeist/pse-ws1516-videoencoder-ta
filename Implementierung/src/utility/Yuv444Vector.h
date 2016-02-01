#include <memory>

#ifndef __Yuv444Vector_h__
#define __Yuv444Vector_h__

namespace Utility {
class Yuv444Vector;
}

namespace Utility {

// A Yuv444Vector.

class Yuv444Vector {

    /// <summary>
    /// Constructor.
    /// </summary>
public: Yuv444Vector(char y, char u, char v);

    /// <summary>
    /// Returns y value.
    /// </summary>
    /// <returns>y value of 444vector.</returns>
public:  uint8_t getY();
    /// <summary>
    /// Returns y value.
    /// </summary>
    /// <returns>y value of 444vector.</returns>
public: uint8_t getU();
    /// <summary>
    /// Returns y value.
    /// </summary>
    /// <returns>y value of 444vector.</returns>
public: uint8_t getV();

private:
    uint8_t y;
	uint8_t u;
	uint8_t v;
};
}

#endif

