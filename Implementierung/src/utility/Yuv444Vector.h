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
	Yuv444Vector(unsigned char y, unsigned char u, unsigned char v);

	/**
	 * @brief getY Returns y value.
	 * @return
	 */
	unsigned char getY();

	/**
	 * @brief getU Returns u value.
	 * @return
	 */
	unsigned char getU();

	/**
	 * @brief getV Returns v value.
	 * @return
	 */
	unsigned char getV();

	/**
	 * @brief setY Sets the y value.
	 * @param y
	 */
	void setY(unsigned char y);

	/**
	 * @brief setU Sets the u value.
	 * @param u
	 */
	void setU(unsigned char u);

	/**
	 * @brief setV Sets the v value.
	 * @param v
	 */
	void setV(unsigned char v);

  private:
	unsigned char y_;
	unsigned char u_;
	unsigned char v_;
};
}

#endif

