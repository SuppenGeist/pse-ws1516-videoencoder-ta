
#include <exception>
using namespace std;

#ifndef __PreviewControlPanel_h__
#define __PreviewControlPanel_h__

// #include "QWidget.h"
#include "QFrame.h"
#include "ControlPanel.h"

namespace GUI
{
	class QWidget;
	// class QFrame;
	// class ControlPanel;
	class PreviewControlPanel;
}

namespace GUI
{
	/**
	 * This class is the control panel for the frame preview.
	 */
	class PreviewControlPanel: public GUI::QFrame, public GUI::ControlPanel
	{
		private: QPushButton* button_nextFrame;
		private: QPushButton* button_previousFrame;
		private: QLabel* label_position;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: PreviewControlPanel(GUI::QWidget* parent = 0);

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
		/// Slot for button_nextFrame.clicked() signal.
		/// </summary>
		private: void nextFrame();

		/// <summary>
		/// Slot for button_previousFrame.clicked() signal.
		/// </summary>
		private: void previousFrame();

		/// <summary>
		/// Updates the label that shows the current position.
		/// </summary>
		private: void updateLabel();
	};
}

#endif
