
#include <exception>
using namespace std;

#ifndef __YuvInfoDialog_h__
#define __YuvInfoDialog_h__

// #include "QWidget.h"
#include "PixelSheme.h"
#include "QDialog.h"
#include "Compression.h"

namespace GUI
{
	class QWidget;
	// enum PixelSheme;
	// class QDialog;
	class YuvInfoDialog;
}
namespace Utility
{
	// enum Compression;
}

namespace GUI
{
	/**
	 * This class is the dialog that gets shown to ask the user for additional information about the yuv file he wants to load.
	 */
	class YuvInfoDialog: public GUI::QDialog
	{
		private: QLineEdit* lineEdit_width;
		private: QLineEdit* lineEdit_height;
		private: QLineEdit* lineEdit_fps;
		private: QComboBox* comboBox_pixelSheme;
		private: QComboBox* comboBox_compression;
		private: GUI::QWidget* label_resolution;
		private: GUI::QWidget* label_fps;
		private: GUI::QWidget* label_compression;
		private: GUI::QWidget* label_pixelSheme;
		private: QPushButton* button_ok;
		private: QPushButton* button_cancel;
		private: GUI::QWidget* label_x;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: YuvInfoDialog(GUI::QWidget* parent);

		/// <summary>
		/// Returns the fps the user entered.
		/// </summary>
		/// <returns>The fps.</returns>
		public: int getFps();

		/// <summary>
		/// Returns the width the user entered.
		/// </summary>
		/// <returns>The width.</returns>
		public: int getWidth();

		/// <summary>
		/// Returns the height the user entered.
		/// </summary>
		/// <returns>The height.</returns>
		public: int getHeight();

		/// <summary>
		/// Returns the compression the user entered.
		/// </summary>
		/// <returns>The compression.</returns>
		public: Utility::Compression getCompression();

		/// <summary>
		/// Returns the pixelsheme the user entered.
		/// </summary>
		/// <returns>The pixelsheme.</returns>
		public: GUI::PixelSheme getPixelSheme();

		/// <summary>
		/// Whether the user clicked ok or cancel.
		/// </summary>
		/// <returns>True if the user clicked ok. false otherwise.</returns>
		public: bool wasSuccessful();

		/// <summary>
		/// Creates the gui.
		/// </summary>
		private: void createUi();

		/// <summary>
		/// Shows the dialog.
		/// </summary>
		public: void show();
	};
}

#endif
