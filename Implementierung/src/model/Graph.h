#ifndef __Graph_h__
#define __Graph_h__

#include <vector>

namespace Model {
/**
 * This class is a graph.
 * Only integer x values and doubley values are supported.
 * x and y values must both be greater or equal to zero.
 */
class Graph {

  public:
	/**
	 * @brief Graph Constructor.
	 */
	Graph();

	/**
	 * @brief addValue Adds a value pair.
	 * The graph is automatically to the given x extended.
	 * @param x Value on the x-axes.
	 * @param y Value on the y-axes.
	 */
	void setValue(std::size_t x, double y);

	/**
	 * @brief cut Cuts the number of vectors down up to a certain value x. x is included.
	 * @param x The last x-value in the cut down vectors.
	 */
	void cut(std::size_t x);

	/**
	 * @brief getValue Returns the y-value to a specific x-value.
	 * If x is less than 0 or greater or equal to getLength then -1 is returned.
	 * @param x The x value.
	 * @return
	 */
	double getValue(std::size_t x);

	/**
	 * @brief getLength Returns the biggest x value with a valid corresponding y value.
	 * @return The biggest x value.
	 */
	std::size_t getSize();

	/**
	 * @brief removeValue Removes the corresponding y value to -1 .
	 * @param x The x value whose y value shall be set to -1.
	 */
	void removeValue(std::size_t x);

	/**
	 * @brief getBiggestValue Returns the biggest value.
	 * @return
	 */
	double getBiggestValue();


  private:
	std::vector<double> graph_;
};
}

#endif
