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
	Yuv411Vector(unsigned char u, unsigned char y1, unsigned char y2, unsigned char v, unsigned char y3,
	             unsigned char y4);

	/**
	 * @brief getU Returns u value.
	 * @return
	 */
	unsigned char getU();

	/**
	 * @brief getY1 Returns Y1 value.
	 * @return
	 */
	unsigned char getY1();

	/**
	 * @brief getY2 Returns Y2 value.
	 * @return
	 */
	unsigned char getY2();

	/**
	 * @brief getV Returns V value.
	 * @return
	 */
	unsigned char getV();

	/**
	 * @brief getY3 Returns Y3 value.
	 * @return
	 */
	unsigned char getY3();

	/**
	 * @brief getY4 Returns Y4 value.
	 * @return
	 */
	unsigned char getY4();

	/**
	 * @brief setY Sets the u value.
	 * @param u
	 */
	void setU(unsigned char U);

	/**
	 * @brief setY1 Sets the y1 value.
	 * @param y1
	 */
	void setY1(unsigned char Y1);

	/**
	 * @brief setY2 Sets the y2 value.
	 * @param y2
	 */
	void setY2(unsigned char Y2);

	/**
	 * @brief setV Sets the v value.
	 * @param v
	 */
	void setV(unsigned char V);

	/**
	 * @brief setY3 Sets the y3 value.
	 * @param y3
	 */
	void setY3(unsigned char Y3);

	/**
	 * @brief setY4 Sets the y4 value.
	 * @param y4
	 */
	void setY4(unsigned char Y4);

  private:
	unsigned char u_;
	unsigned char y1_;
	unsigned char y2_;
	unsigned char v_;
	unsigned char y3_;
	unsigned char y4_;
};
}

#endif

