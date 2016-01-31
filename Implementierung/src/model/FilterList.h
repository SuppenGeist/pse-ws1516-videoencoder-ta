#ifndef __FilterList_h__
#define __FilterList_h__

#include <string>
#include <vector>

namespace Model {
class Filter;
}

namespace Model {
/**
 * This class contains a filter configuration. Every filter can only be once in this list.
 */
class FilterList {
  private:
	std::vector<Model::Filter*> filters;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	FilterList();

	/// <summary>
	/// Returns a filter by its name.
	/// </summary>
	/// <param name="name">The name of the filter.</param>
	/// <returns>The filter.</returns>
  public:
	Model::Filter* getFilterByName(std::string name);

	/// <summary>
	/// Removes a filter.
	/// </summary>
	/// <param name="name">Name of the filter to remove.</param>
  public:
	void removeFilter(std::string name);

	/// <summary>
	/// Moves a filter to another position.
	/// </summary>
	/// <param name="oldPosition">The old position.</param>
	/// <param name="newPosition">The new position.</param>
  public:
	void moveFilter(int oldPosition, int newPosition);

	/// <summary>
	/// Removes a filter.
	/// </summary>
	/// <param name="position">Position of the filter to remove.</param>
  public:
	void removeFilter(int position);

	/// <summary>
	/// Inserts a filter to the end.
	/// </summary>
	/// <param name="name">Name of the filter to add.</param>
  public:
	void addFilter(std::string name);

	/// <summary>
	/// Returns the filter at the given index.
	/// </summary>
	/// <param name="index">Index of the filter.</param>
	/// <returns>The filter at the given index.</returns>
  public:
	Model::Filter* getFilterByIndex(int index);

	/// <summary>
	/// Returns the index of a filter.
	/// </summary>
	/// <param name="name">The name of the filter.</param>
	/// <returns>The index.</returns>
  public:
	int getIndex(std::string name);
};
}

#endif

