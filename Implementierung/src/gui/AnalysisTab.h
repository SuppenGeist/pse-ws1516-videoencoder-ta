/*
#include <exception>
using namespace std;

#ifndef __AnalysisTab_h__
#define __AnalysisTab_h__

// #include "VideoPlayer.h"
// #include "FrameView.h"
// #include "PlayerControlPanel.h"
// #include "Timer.h"
// #include "AnalysisBoxContainer.h"
// #include "GlobalControlPanel.h"
// #include "QWidget.h"
#include "QFrame.h"
#include "AnalysisTabMemento.h"
#include "YuvVideo.h"
// #include "LoadAnalysisVideo.h"

namespace GUI
{
	class VideoPlayer;
	class FrameView;
	class PlayerControlPanel;
	class Timer;
	class AnalysisBoxContainer;
	class GlobalControlPanel;
	class QWidget;
	// class QFrame;
	class AnalysisTab;
}
namespace Memento
{
	class AnalysisTabMemento;
}
namespace Model
{
	class YuvVideo;
}
namespace UndoRedo
{
	class LoadAnalysisVideo;
}

namespace GUI
{
	/**
	 * The tab that shows videos and analyses them.

	class AnalysisTab: public GUI::QFrame
	{
		private: QPushButton* button_save;
		private: QComboBox* comboBox_analyseTyp;
		private: QScrollArea* scrollArea_analyseVideos;
		private: QLabel* label_rawVideo;
		private: QPushButton* button_addRawVideo;
		private: QTabWidget* tab_properties;
		private: QPushButton* button_addVideo;
		public: UndoRedo::LoadAnalysisVideo* anaTab;
		private: GUI::VideoPlayer* player;
		public: GUI::FrameView* rawVideoView;
		private: GUI::PlayerControlPanel* controlPanel;
		private: GUI::Timer* playerTimer;
		private: GUI::AnalysisBoxContainer* analysisBoxContainer;
		private: Model::YuvVideo* rawVideo;
		private: GUI::GlobalControlPanel* globalControlPanel;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: AnalysisTab(GUI::QWidget* parent);

		/// <summary>
		/// Creates a memento which contains the state of this tab.
		/// </summary>
		/// <returns>The created memento.</returns>
		public: Memento::AnalysisTabMemento getMemento();

		/// <summary>
		/// Restores the tab based on the memento.
		/// </summary>
		/// <param name="memento">The memento which contains the state of the tab.</param>
		public: void restore(Memento::AnalysisTabMemento memento);

		/// <summary>
		/// Slot: connected to comboBox_analyseTyp.currentIndexChanged(index : int)
		/// tells AnalysisBox to showMacroBlocks() or showRGBDiff()
		/// </summary>
		/// <param name="index">The new type.</param>
		private: void analyseTypChanged(int index);

		/// <summary>
		/// Slot: connected to button_addVideo.pressed()
		/// opens QFIleDialog, and gives string to AnalysisBoxContainer
		/// </summary>
		private: void addVideo();

		/// <summary>
		/// Slot: connected to button_addRawVideo.pressed()
		/// opens YuvFileOpenDialog and gives the video to AnalysisBoxContainer
		/// </summary>
		private: void loadRawVideo();

		/// <summary>
		/// Opens QFIleDialog and saves relevant data in the path.
		/// </summary>
		private: void saveResults();

		/// <summary>
		/// Sets the raw video for the analysis. This operation resets the tab completely.
		/// </summary>
		/// <param name="video">The new raw video.</param>
		public: void setRawVideo(Model::YuvVideo video);
	};
}

#endif
*/
