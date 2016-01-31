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
        static const QString SAVE_FILENAME;

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
         * @brief wasSuccessfull Whether the user clicked ok or cancel.
         * @return True if the user clicked ok. false otherwise.
         */
        bool wasSuccessfull();

    private slots:
        void ok();
        void cancel();
        void chooseFile();
        void selectionChanged(const QItemSelection& selection);

    private:
    static QStringListModel*    model_recentlyUsed_;

    QPushButton*                button_cancel_;
    QPushButton*                button_ok_;
    QListView*                  listView_recentlyUsed_;
    QLabel*                     label_selectedFile_;
    QPushButton*                button_chooseFile_;
    QLabel*                     label_recentlyUsed_;
    QLineEdit*                  lineEdit_selectedFile_;

    bool                        wasSuccesfull_;

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
