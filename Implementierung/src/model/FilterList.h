
#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __FilterList_h__
#define __FilterList_h__

// #include "FilterApplier.h"
#include "Filter.h"
// #include "FilterReset.h"
// #include "LoadFilterconfig.h"

namespace Model
{
	class FilterApplier;
	class Filter;
	class FilterList;
}
namespace UndoRedo
{
	class FilterReset;
	class LoadFilterconfig;
}

namespace Model
{
	/**
	 * This class contains a filter configuration. Every filter can only be once in thi slist.
	 */
	class FilterList
	{
		private: vector filters:std:;
		public: Model::FilterApplier* list;
		public: UndoRedo::FilterReset* filterList;
		public: UndoRedo::LoadFilterconfig* oldList;
		public: UndoRedo::LoadFilterconfig* newList;
		private: std::vector<Model::Filter*> filters;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FilterList();

		/// <summary>
		/// Returns a filter by its name.
		/// </summary>
		/// <param name="name">The name of the filter.</param>
		/// <returns>The filter.</returns>
		public: Model::Filter* getFilterByName(string name);

		/// <summary>
		/// Removes a filter.
		/// </summary>
		/// <param name="name">Name of the filter to remove.</param>
		public: void removeFilter(string name);

		/// <summary>
		/// Moves a filter to another position.
		/// </summary>
		/// <param name="oldPosition">The old position.</param>
		/// <param name="newPosition">The new position.</param>
		public: void moveFilter(int oldPosition, int newPosition);

		/// <summary>
		/// Removes a filter.
		/// </summary>
		/// <param name="position">Position of the filter to remove.</param>
		public: void removeFilter(int position);

		/// <summary>
		/// Inserts a filter at the given index. If the index is -1 then the filter is added to the end.
		/// </summary>
		/// <param name="name">Name of the filter to add.</param>
		/// <param name="index">Index to insert the filter at.</param>
		public: void addFilter(string name, int index = -1);

		/// <summary>
		/// Returns the filter at the given index.
		/// </summary>
		/// <param name="index">Index of the filter.</param>
		/// <returns>The filter at the given index.</returns>
		public: Model::Filter* getFIlterByIndex(int index);

		/// <summary>
		/// Returns the index of a filter.
		/// </summary>
		/// <param name="name">The name of the filter.</param>
		/// <returns>The index.</returns>
		public: int getIndex(string name);
	};
}

#endif
