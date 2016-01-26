
#include <exception>
using namespace std;

#ifndef __FrameView_h__
#define __FrameView_h__

#include "QWidget.h"

namespace GUI
{
	// class QWidget;
	class FrameView;
}

namespace GUI
{
	/**
	 * This class is the view used by the video player.
	 * It automatically scales the frames passed to it.
	 */
	class FrameView: public GUI::QWidget
	{
		private: int xOffset;
		private: int yOffset;
		private: QImage currentFrame;
		private: QImage* originalFrame;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FrameView(QWidget* parent = 0);

		/// <summary>
		/// Sets the frame to show.
		/// </summary>
		/// <param name="frame">The frame to show.</param>
		public: void setFrame(QImage& frame);

		/// <summary>
		/// Clears the current frame so nothing is shown.
		/// </summary>
		public: void clear();

		/// <summary>
		/// This method is called when the widget got resized.
		/// </summary>
		protected: void resizeEvent(QResizeEvent* event);

		/// <summary>
		/// This method is called when the widget has to be repainted.
		/// </summary>
		protected: void repaintEvent(QPaintEvent* event);

		/// <summary>
		/// Updates the offset at which the image is drawn.
		/// </summary>
		private: void() updateOffset();
	};
}

#endif
