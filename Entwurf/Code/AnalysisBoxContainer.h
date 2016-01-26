
#include <exception>
#include <vector>
using namespace std;

#ifndef __AnalysisBoxContainer_h__
#define __AnalysisBoxContainer_h__

// #include "Video.h"
#include "Timer.h"
// #include "AnalysisTab.h"
#include "AnalysisBox.h"
// #include "QWidget.h"
#include "QFrame.h"
#include "AnalysisBoxContainerMemento.h"
#include "EncodedVideo.h"
// #include "RemoveVideo.h"

namespace GUI
{
	class Video;
	class Timer;
	class AnalysisTab;
	class AnalysisBox;
	class QWidget;
	// class QFrame;
	class AnalysisBoxContainer;
}
namespace Memento
{
	class AnalysisBoxContainerMemento;
}
namespace Model
{
	class EncodedVideo;
}
namespace UndoRedo
{
	class RemoveVideo;
}

namespace GUI
{
	/**
	 * Contains and manages the AnalysisBoxes.
	 */
	class AnalysisBoxContainer: public GUI::QFrame
	{
		private: GUI::Video* rawVideo;
		private: shared_ptr<GUI::Timer> timer:std:;
		private: Player::GlobalControlPanel* controlPanel;
		private: GUI::AnalysisTab* analysisBoxContainer;
		public: UndoRedo::RemoveVideo* anaBoxContainer;
		private: std::vector<GUI::AnalysisBox*> boxes;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: AnalysisBoxContainer(GUI::QWidget* parent);

		/// <summary>
		/// Creates a memento which contains the state of the container.
		/// </summary>
		/// <returns>The created memento.</returns>
		public: Memento::AnalysisBoxContainerMemento getMemento();

		/// <summary>
		/// Restores the container based on the memento.
		/// </summary>
		/// <param name="memento">The memento which contains the state to restore.</param>
		public: void restore(Memento::AnalysisBoxContainerMemento memento);

		/// <summary>
		/// Creates a Analysis box and shows it.
		/// </summary>
		/// <param name="path">The path of the video to analyse.</param>
		public: void addVideo(QString path);

		/// <summary>
		/// Sets the rawVideo the encoded videos are compared to.
		/// </summary>
		/// <param name="video">The raw video.</param>
		public: void setRawVideo(GUI::Video* video);

		/// <summary>
		/// Sets the timer for the videoplayers.
		/// </summary>
		/// <param name="timer:std:">The timer for the videoplayers.</param>
		public: void setTimer(shared_ptr<GUI::Timer> timer:std:);

		/// <summary>
		/// Sets the GlobalControlPanel.
		/// </summary>
		/// <param name="panel">The panel.</param>
		public: void setControlPanel(Player::GlobalControlPanel* panel);

		/// <summary>
		/// Tells all AnalysisBoxes to show the macro block video.
		/// </summary>
		public: void showMacroBlockVideos();

		/// <summary>
		/// Tells all AnalysisBoxes to show the RGBDiff video.
		/// </summary>
		public: void showRGBDifferenceVideos();

		/// <summary>
		/// Removes a box from the list.
		/// </summary>
		/// <param name="box">The box to remove.</param>
		public: void removeBox(GUI::AnalysisBox& box);

		/// <summary>
		/// Adds the given video to the container.
		/// </summary>
		/// <param name="video">The video to add.</param>
		/// <returns>The box in which the video is presented.</returns>
		public: GUI::AnalysisBox* addVideo(Model::EncodedVideo video);
	};
}

#endif
