#ifndef __YuvFileOpenDialog_h__
#define __YuvFileOpenDialog_h__

#include <QWidget>
#include <QDialog>
#include <QListView>
#include <QStringListModel>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

namespace GUI
{
	/**
	 * This class is the dialog that gets shown when the user wants to select a yuv file to load.
     */
    class YuvFileOpenDialog: public QDialog
    {
        Q_OBJECT

        public:
        /**
         * @brief MAX_SAVED_ENTRIES Maximum number saved as recently used.
         */
        static constexpr int MAX_SAVED_ENTRIES=10;

        /**
         * @brief SAVE_FILENAME The file the receblty used files are saved in.
         */
        static const QString SAVE_FILENAME;

        /**
         * @brief YuvFileOpenDialog Constructor.
         * @param parent
         */
        YuvFileOpenDialog(QWidget* parent = 0);

        /**
         * @brief getFilename Returns the absolute path to the file the user wants to open. The path is valid or an empty string is returned.
         * @return Absolute path to the user chosen file.
         */
        QString getFilename();

    private slots:
        /**
         * @brief chooseFile Slot for button_chooseFile clicked() signal.
         */
        void chooseFile();
        /**
         * @brief selectionChanged Slot for listView_recentlyUsed selctionChanged() signal.
         * @param selection
         */
        void selectionChanged(const QItemSelection& selection);

        /**
         * @brief hasFinished Slot for the finished() slot of the dialog.
         * @param result
         */
        void hasFinished(int result);

    private:

    static QStringListModel*    model_recentlyUsed_;

    QPushButton*                button_cancel_;
    QPushButton*                button_ok_;
    QListView*                  listView_recentlyUsed_;
    QLabel*                     label_selectedFile_;
    QPushButton*                button_chooseFile_;
    QLabel*                     label_recentlyUsed_;
    QLineEdit*                  lineEdit_selectedFile_;

    /**
     * @brief getListModel Loads the recently opened yuv files and puts them in the model.
     */
    static QStringListModel* getListModel();

    /**
     * @brief saveListModel Saves the list model.
     * @param selectedFile The new file to add to the model.
     */
    static void saveListModel(QString selectedFile);

    /**
     * @brief createUi Creates the ui.
     */
    void createUi();

	};
}

#endif
