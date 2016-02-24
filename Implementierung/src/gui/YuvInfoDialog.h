#ifndef __YuvInfoDialog_h__
#define __YuvInfoDialog_h__

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QDialog>
#include <QWidget>
#include <QStringList>


namespace Utility {
enum class Compression;
enum class YuvType;
}

namespace GUI {
/**
 * This class is the dialog that gets shown to ask the user for additional information about the yuv file he wants to load.
 */
class YuvInfoDialog: public QDialog {
	Q_OBJECT

  public:
	/**
	 * @brief YuvInfoDialog Constructor.
	 * @param parent
	 */
	YuvInfoDialog(QWidget* parent=0);

	/**
	 * @brief getFps Returns the fps the user entered.
	 * If an error occurs while parsing the user input the default value 30 is returned.
	 * @return The fps.
	 */
	int getFps();

	/**
	 * @brief getWidth Returns the width the user entered.
	 * If the user input is not valid -1 is returned.
	 * @return The width.
	 */
	int getWidth();

	/**
	 * @brief getHeight Returns the height the user entered.
	 * If the user input is not valid -1 is returned.
	 * @return The height.
	 */
	int getHeight();

	/**
	 * @brief getCompression Returns the compression the user entered.
	 * @return The compression.
	 */
	Utility::Compression getCompression();

	/**
	     * @brief getPixelSheme Returns the pixelscheme the user entered.
	     * @return The pixelscheme.
	 */
	Utility::YuvType getPixelSheme();

  private slots:

	/**
	     * @brief pixelShemeSelectionChanged Slot for comboBox_pixelSheme selectionChanged() signal.
	 * @param selection
	 */
	void pixelShemeSelectionChanged(int selection);

  private:
	QLineEdit*      lineEdit_width_;
	QLineEdit*      lineEdit_height_;
	QLineEdit*      lineEdit_fps_;
	QComboBox*      comboBox_pixelSheme_;
	QComboBox*      comboBox_compression_;
	QLabel*         label_resolution_;
	QLabel*         label_fps_;
	QLabel*         label_compression_;
	QLabel*         label_pixelSheme_;
	QLabel*         label_x_;
	QPushButton*    button_ok_;
	QPushButton*    button_cancel_;
	QStringList     compressionList_;
	QStringList     pixelShemeList_;

	/**
	 * @brief createUi Creates the gui.
	 */
	void createUi();
};
}

#endif
