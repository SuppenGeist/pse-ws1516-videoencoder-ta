
#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __FilterTab_h__
#define __FilterTab_h__

// #include "QFrame.h"
// #include "VideoPlayer.h"
// #include "PreviewControlPanel.h"
// #include "FrameView.h"
// #include "PlayerControlPanel.h"
#include "FilterContainerTab.h"
// #include "QWidget.h"
#include "FilterTabMemento.h"
#include "FilterList.h"
#include "YuvVideo.h"
#include "Filter.h"
// #include "LoadFilterVideo.h"

namespace GUI
{
	class QFrame;
	class VideoPlayer;
	class PreviewControlPanel;
	class FrameView;
	class PlayerControlPanel;
	class FilterContainerTab;
	class QWidget;
	class FilterTab;
}
namespace Memento
{
	class FilterTabMemento;
}
namespace Model
{
	class FilterList;
	class YuvVideo;
	class Filter;
}
namespace UndoRedo
{
	class LoadFilterVideo;
}

namespace GUI
{
	/**
	 * This class is the tab to filter videos.
	 */
	class FilterTab
	{
		private: QPushButton* button_up;
		private: QPushButton* button_down;
		private: QPushButton* button_remove;
		private: QPushButton* button_load;
		private: QPushButton* button_apply;
		private: QPushButton* button_saveConf;
		private: QPushButton* button_loadConf;
		private: QPushButton* button_reset;
		private: QPushButton* button_save;
		private: QListWidget* list_filterList;
		private: QTabWidget* tab_filterTabs;
		private: QLabel* label_filterOptions;
		private: GUI::QFrame* frame_filterContainer;
		private: QStringListModel* model_list;
		public: UndoRedo::LoadFilterVideo* filterTab;
		private: GUI::VideoPlayer* player;
		private: GUI::PreviewControlPanel* previewPanel;
		private: GUI::FrameView* frameView;
		private: GUI::PlayerControlPanel* playerPanel;
		private: Model::FilterList* filterList;
		private: Model::YuvVideo* rawVideo;
		private: std::vector<GUI::FilterContainerTab*> filterContainerTab;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FilterTab(GUI::QWidget* parent);

		/// <summary>
		/// Creates a memento which contains the state of this tab.
		/// </summary>
		/// <returns>The created memento.</returns>
		public: Memento::FilterTabMemento getMemento();

		/// <summary>
		/// Restores the tab based on the memento.
		/// </summary>
		/// <param name="memento">The memento which contains the state of the tab.</param>
		public: void restore(Memento::FilterTabMemento memento);

		/// <summary>
		/// Connect the buttons to their slots in this class.
		/// </summary>
		private: void connectActions();

		/// <summary>
		/// Creates the user interface.
		/// </summary>
		private: void createUi();

		/// <summary>
		/// Slot: connected with button_up.pressed()
		/// decreases the index of a filter in the list
		/// </summary>
		private: void up();

		/// <summary>
		/// Slot: connected with button_down.pressed()
		/// increases the index of a filter in the list
		/// </summary>
		private: void down();

		/// <summary>
		/// Slot: connected with button_remove.pressed()
		/// removes a filter from the list
		/// </summary>
		private: void remove();

		/// <summary>
		/// Slot: connected with button_load.pressed()
		/// opens QFileDialog and opens the video in the selected path
		/// </summary>
		private: void load();

		/// <summary>
		/// Slot: connected with button_apply.pressed()
		/// applies the filter list on the video and shows it
		/// </summary>
		private: void apply();

		/// <summary>
		/// Slot: connected with button_saveConf.pressed()
		/// opens QFileDialog and saves the filter configuration in the selected path
		/// </summary>
		private: void saveConf();

		/// <summary>
		/// Slot: connected with button_loadConf.pressed()
		/// opens QFileDialog and loads the filter configuration in the selected path
		/// </summary>
		private: void loadConf();

		/// <summary>
		/// Slot: connected with button_reset.pressed()
		/// resets the filter list
		/// </summary>
		private: void reset();

		/// <summary>
		/// Slot: connected with button_save.pressed()
		/// opens QFileDialog and saves the video with the filters used on it.
		/// </summary>
		private: void save();

		/// <summary>
		/// Inserts a filter to the filterList. If index is -1 the the filter is added to the end.
		/// </summary>
		/// <param name="filter">The filter to add.</param>
		/// <param name="index">The index to insert the filter at.</param>
		public: void insertFilter(Model::Filter filter, int index = -1);

		/// <summary>
		/// Slot: connected with list_filterList.clicked(index : QModelIndex);
		/// updates the filterConfigurationBox that is shown
		/// </summary>
		/// <param name="index">Index of the selected item.</param>
		private: void listSelectionChanged(QModelIndex index);

		/// <summary>
		/// Removes the filter with the name filterName in the filterlist.
		/// </summary>
		/// <param name="filterName">Name of the filter to remove.</param>
		public: void removeFilter(string filterName);

		/// <summary>
		/// Shows the video with the applied filters.
		/// </summary>
		public: void showVideo();

		/// <summary>
		/// Shows the 5 frame preview.
		/// </summary>
		public: void showPreview();

		/// <summary>
		/// Resets the filterlist.
		/// </summary>
		public: void resetFilters();

		/// <summary>
		/// Sets the filterlist.
		/// </summary>
		/// <param name="list">The filterlist to use.</param>
		public: void setFilterList(Model::FilterList list);

		/// <summary>
		/// Sets the video the filters are applied to. This operation resets the whole filtertab.
		/// </summary>
		/// <param name="video">The video to apply the filters on.</param>
		public: void setRawVideo(Model::YuvVideo video);

		/// <summary>
		/// Moves a filter in the filterlist.
		/// </summary>
		/// <param name="old">Old list index.</param>
		/// <param name="new">New list index.</param>
		public: void moveFilter(int old, int new_3);
	};
}

#endif
