
#include <exception>
using namespace std;

#ifndef __AnalysisBox_h__
#define __AnalysisBox_h__

// #include "Video.h"
// #include "AnalysisBoxContainer.h"
// #include "VideoPlayer.h"
// #include "GraphWidget.h"
// #include "QWidget.h"
#include "Timer.h"
#include "QFrame.h"
#include "AnalysisBoxMemento.h"
#include "EncodedVideo.h"
// #include "RemoveVideo.h"

namespace GUI
{
	class Video;
	class AnalysisBoxContainer;
	class VideoPlayer;
	class GraphWidget;
	class QWidget;
	class Timer;
	// class QFrame;
	class AnalysisBox;
}
namespace Memento
{
	class AnalysisBoxMemento;
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
	 * Shows the Analysis of a single encoded video.
	 */
	class AnalysisBox: public GUI::QFrame
	{
		private: GUI::Video* rawVideo;
		private: int currentlyPlayedVideo;
		private: QTabWidget* tabs;
		private: QPushButton* button_close;
		private: QTextEdit* textEdit_comment;
		private: GloablControlPanel* controlPanel;
		private: GUI::AnalysisBoxContainer* boxes;
		public: UndoRedo::RemoveVideo* anaBox;
		private: GUI::VideoPlayer* plainVideoPlayer;
		private: GUI::VideoPlayer* analysisVideoPlayer;
		private: GUI::GraphWidget* psnrGraph;
		private: GUI::GraphWidget* bitrateGraph;
		private: GUI::GraphWidget* redHistogramm;
		private: GUI::GraphWidget* blueHistogramm;
		private: GUI::GraphWidget* greenHistogramm;
		private: Model::EncodedVideo* video;

		public: AnalysisBox(GUI::QWidget* parent);

		/// <summary>
		/// Creates a memento which contains the state of the box.
		/// </summary>
		/// <returns>The created memento.</returns>
		public: Memento::AnalysisBoxMemento getMemento();

		/// <summary>
		/// Restores the box based on the memento.
		/// </summary>
		/// <param name="memento">The memento which contains the state of the box.</param>
		public: void restore(Memento::AnalysisBoxMemento memento);

		/// <summary>
		/// Sets the timer for the videoplayer.
		/// </summary>
		/// <param name="timer:std:">The timer for the videoplayer.</param>
		public: void setTimer(shared_ptr<GUI::Timer> timer:std:);

		/// <summary>
		/// Sets the rawvideo the encoded video is compared to.
		/// </summary>
		/// <param name="video">The rawvideo.</param>
		public: void setRawVideo(GUI::Video* video);

		/// <summary>
		/// Sets the GlobalControlPanel.
		/// </summary>
		/// <param name="panel">The GlobalControlPanel.</param>
		public: void setControlPanel(Player::GlobalControlPanel* panel);

		/// <summary>
		/// Shows the macroblock video. The rgb difference video is no longer shown.
		/// </summary>
		public: void showMacroBlockVideo();

		/// <summary>
		/// Shows the rgb difference video. The macroblock video is no longer shown.
		/// </summary>
		public: void showRGBDifferenceVideo();

		/// <summary>
		/// Slot: connected to button_close.pressed()
		/// removes this box from AnalysisBoxContainer
		/// </summary>
		private: void close();

		/// <summary>
		/// Slot: connected with textEdit_comment
		/// updates QUndoStack
		/// </summary>
		private: void textChanged();

		/// <summary>
		/// Sets the video this box shall present.
		/// </summary>
		/// <param name="video">The video to present.</param>
		public: void setAnalyseVideo(Model::EncodedVideo video);
	};
}

#endif
