#ifndef __FilterTabMemento_h__
#define __FilterTabMemento_h__

#include <string>

#include "../model/FilterList.h"

namespace Model
{
	class FilterList;
}

namespace Memento
{
	/**
	 * This class is the memento for the FilterTab.
     */
	class FilterTabMemento
	{
		private: Model::FilterList filterList;
		private: bool wasApplied;
		private: int displayedFrame;
    private: std::string loadedFile;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FilterTabMemento();

		/// <summary>
		/// Returns the list of the currently selected  filters.
		/// </summary>
		/// <returns>List of the selected filters.</returns>
		public: Model::FilterList getFilterList();

		/// <summary>
		/// Sets the list of the currently selected filters.
		/// </summary>
		/// <param name="filterList">List of the selected filters.</param>
		public: void setFilterList(Model::FilterList filterList);

		/// <summary>
		/// Whether the filter were already applied.
		/// </summary>
		/// <returns>True if the filter wre already applied.</returns>
		public: bool getWasApplied();

		/// <summary>
		/// Sets whether the filters were already aplied.
		/// </summary>
		/// <param name="wasApplied">True if the filter were already applied.</param>
		public: void setWasApplied(bool wasApplied);

		/// <summary>
		/// Returns the currently displayed frame in the frame preview.
		/// </summary>
		/// <returns>The currently displayed frame.</returns>
		public: int getDisplayedFrame();

		/// <summary>
		/// Sets the currently displayed frame in the frame preview.
		/// </summary>
		/// <param name="displayedFrame">The currently displayed frame.</param>
		public: void setDisplayedFrame(int displayedFrame);

		/// <summary>
		/// Returns the path to the currently loaded yuv file.
		/// </summary>
		/// <returns>Absolute path to the currently loaded yuv file.</returns>
    public: std::string getLoadedFile();

		/// <summary>
		/// Sets the path to the currently loaded yuv file.
		/// </summary>
		/// <param name="loadedFile">Absolute path to the loaded yuv file.</param>
    public: void setLoadedFile(std::string loadedFile);
	};
}

#endif

