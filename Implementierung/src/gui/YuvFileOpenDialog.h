#ifndef __YuvFileOpenDialog_h__
#define __YuvFileOpenDialog_h__

#include <QWidget>
#include <QDialog>
#include <QListView>
#include <QStringListModel>
#include <QLabel>
#include <QPushButton>

namespace GUI
{
	/**
	 * This class is the dialog that gets shown when the user wants to select a yuv file to load.
     */
    class YuvFileOpenDialog: public QDialog
    {
        public:
        /**
         * @brief YuvFileOpenDialog Constructor.
         * @param parent
         */
        YuvFileOpenDialog(QWidget* parent = 0);

        /**
         * @brief getFilename Returns the absolute path to the file the user wants to open.
         * @return Absolute path to the user chosen file.
         */
        QString getFilename();

        /**
         * @brief show Shows the dialog.
         */
        void show();

        /**
         * @brief wasSuccessfull Whether the user clicked ok or cancel.
         * @return True if the user clicked ok. false otherwise.
         */
        bool wasSuccessfull();

    private:
    static QStringListModel*    model_recentlyUsed;

    QPushButton*                button_cancel_;
    QPushButton*                button_ok_;
    QListView*                  listView_redcentlyUsed_;
    QLabel*                     label_selectedFile_;
    QPushButton*                button_chooseFile_;
    QLabel*                     label_recentlyUsed_;
    bool                        wasSuccesfull_;

    /**
     * @brief loadRecentlyUsed Loads the recently opened yuv files.
     */
    static void loadRecentlyUsed();

    /**
     * @brief createUi Creates the ui.
     */
    void createUi();

	};
}

#endif
