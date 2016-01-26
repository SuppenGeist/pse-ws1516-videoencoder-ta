/*
#include <exception>
using namespace std;

#ifndef __PlayerControlPanel_h__
#define __PlayerControlPanel_h__

#include "QFrame.h"
#include "ControlPanel.h"

namespace GUI
{
	// class QFrame;
	// class ControlPanel;
	class PlayerControlPanel;
}

namespace GUI
{
	/**
	 * This class is the control panel to play videos.

	class PlayerControlPanel: public GUI::QFrame, public GUI::ControlPanel
	{
		private: QPushButton* button_play;
		private: QPushButton* button_stop;
		private: QPushButton* button_nextFrame;
		private: QPushButton* button_previousFrame;
		private: QComboBox* comboBox_speed;
		private: QSlider* slider_timeline;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: PlayerControlPanel(QWidget* parent = 0);

		/// <summary>
		/// Updates the ui of the control panel.
		/// </summary>
		public: void updateUi();

		/// <summary>
		/// Creates the ui.
		/// </summary>
		private: void createUi();

		/// <summary>
		/// Creates the actions.
		/// </summary>
		private: void createActions();

		/// <summary>
		/// Slot for the button_play.clicked() signal.
		/// </summary>
		private: void play();

		/// <summary>
		/// Slot for button_pause.clicked() signal.
		/// </summary>
		private: void pause();

		/// <summary>
		/// Slot for button_stop.clicked() signal.
		/// </summary>
		private: void stop();

		/// <summary>
		/// Slot for button_nextFrame.clicked() signal.
		/// </summary>
		private: void nextFrame();

		/// <summary>
		/// Slot for button_previousFrame.clicked() signal.
		/// </summary>
		private: void previousFrame();

		/// <summary>
		/// Slot for comboBox_speed.currentIndexChanged(int) signal.
		/// </summary>
		private: void changeSpeed(int index);

		/// <summary>
		/// Slot for slider_timeLine.valueChanged(int) signal.
		/// </summary>
		private: void changeTimeline(int value);
	};
}

#endif
*/
