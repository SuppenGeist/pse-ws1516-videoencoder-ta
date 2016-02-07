#ifndef __FilterList_h__
#define __FilterList_h__

#include <memory>
#include <vector>

#include <QString>

namespace Model {
class Filter;
}

namespace Model {

/**
 * This class contains a filter configuration. Every filter can only be once in this list.
 */
class FilterList {

  public:
	/**
	 * @brief FilterList Constructor.
	 */
	FilterList();

	/**
	 * @brief moveFilter Moves a filter to another position.
	 * @param oldPosition The old position.
	 * @param newPosition The new position.
	 */
	void moveFilter(std::size_t oldPosition, std::size_t newPosition);

	/**
	 * @brief removeFilter Removes a filter.
	 * @param position Position of the filter to remove.
	 */
	std::unique_ptr<Filter> removeFilter(std::size_t position);

	void insertFilter(std::unique_ptr<Filter> filter, std::size_t index);

	/**
	 * @brief addFilter Inserts a filter to the end.
	 * @param name Name of the filter to add.
	 */
	void appendFilter(QString name);

	/**
	 * @brief getFilter Returns the filter at the given index.
	 * @param index Index of the filter.
	 * @return The filter at the given index.
	 */
	Model::Filter* getFilter(std::size_t index);

	std::size_t getSize();

  private:
	std::vector<std::unique_ptr<Filter>> filters_;
};
}

#endif

