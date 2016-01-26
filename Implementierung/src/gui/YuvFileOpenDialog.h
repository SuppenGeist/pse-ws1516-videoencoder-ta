
#include <exception>
using namespace std;

#ifndef __YuvFileOpenDialog_h__
#define __YuvFileOpenDialog_h__

// #include "QWidget.h"
#include "QDialog.h"

namespace GUI
{
	class QWidget;
	// class QDialog;
	class YuvFileOpenDialog;
}

namespace GUI
{
	/**
	 * This class is the dialog that gets shown when the user wants to select a yuv file to load.
	 */
	class YuvFileOpenDialog: public GUI::QDialog
	{
		private: QPushButton* button_cancel;
		private: QPushButton* button_ok;
		private: QListView* listView_redcentlyUsed;
		private: static QListViewModel* model_recentlyUsed;
		private: QLabel* label_selectedFile;
		private: QButton* button_chooseFile;
		private: QLabel* label_recentlyUsed;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: YuvFileOpenDialog(GUI::QWidget* parent = 0);

		/// <summary>
		/// Returns the absolute path to the file the user wants to open.
		/// </summary>
		/// <returns>Absolute path to the user chosen file.</returns>
		public: QString getFilename();

		/// <summary>
		/// Creates the ui.
		/// </summary>
		private: void createUi();

		/// <summary>
		/// Shows the dialog.
		/// </summary>
		public: void show();

		/// <summary>
		/// Whether the user clicked ok or cancel.
		/// </summary>
		/// <returns>True if the user clicked ok. false otherwise.</returns>
		public: bool wasSuccessfull();

		/// <summary>
		/// Loads the recently opened yuv files.
		/// </summary>
		private: static void loadRecentlyUsed() {
			throw "Not yet implemented";
		}
	};
}

#endif
