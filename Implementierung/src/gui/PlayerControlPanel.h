#ifndef __PlayerControlPanel_h__
#define __PlayerControlPanel_h__

#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>

#include "ControlPanel.h"

namespace GUI {
/**
 * This class is the control panel to play videos.
 */
class PlayerControlPanel: public QFrame, public ControlPanel {
	Q_OBJECT
  public:
	/**
	 * @brief PlayerControlPanel Constructor.
	 * @param parent The parent widget.
	 */
	PlayerControlPanel(QWidget* parent = 0);

	/**
	 * If no master player is set the first player of the player list is taken.
	 * If this list is empty nothing happens.
	 *
	 * @brief updateUi Updates the ui of the control panel.
	 */
	void updateUi() override;

  private slots:
	/**
	 * @brief play Slot for the button_play.clicked() signal.
	 */
	void play();

	/**
	 * @brief pause Slot for button_pause.clicked() signal.
	 */
	void pause();

	/**
	 * @brief stop Slot for button_stop.clicked() signal.
	 */
	void stop();

	/**
	 * @brief nextFrame Slot for button_nextFrame.clicked() signal.
	 */
	void nextFrame();

	/**
	 * @brief previousFrame Slot for button_previousFrame.clicked() signal.
	 */
	void previousFrame();

	/**
	 * @brief changeSpeed Slot for comboBox_speed.currentIndexChanged(int) signal.
	 * @param index The entry in the speed list.
	 */
	void changeSpeed(int index);

	/**
	 * @brief changeTimeline Slot for slider_timeLine.valueChanged(int) signal.
	 * @param value The new valueof the slider.
	 */
	void changeTimeline(int value);

  private:
	QPushButton*    button_play;
	QPushButton*    button_stop;
	QPushButton*    button_nextFrame;
	QPushButton*    button_previousFrame;
	QPushButton*    button_pause;
	QComboBox*      comboBox_speed;
	QSlider*        slider_timeline;

	/**
	 * @brief createUi Creates the ui.
	 */
	void createUi();
};
}

#endif

