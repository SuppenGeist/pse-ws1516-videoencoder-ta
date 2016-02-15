#ifndef __GlobalControlPanel_h__
#define __GlobalControlPanel_h__

#include "ControlPanel.h"

namespace GUI {
/**
 * This control panel has no gui. Instead it has functions to control the video.
 */
class GlobalControlPanel: public ControlPanel {
  public:
	/**
	 * @brief GlobalControlPanel Constructor.
	 */
	GlobalControlPanel();

	/**
	 * @brief updateUi Updates the ui of the control panel.
	 */
	void updateUi() override;

	/**
	 * @brief play Sends a play signal to the players.
	 */
	void play();

	/**
	 * @brief pause Sends a pause signal to the players.
	 */
	void pause();

	/**
	 * @brief stop Sends a stop signal to the players.
	 */
	void stop();

	/**
	 * @brief nextFrame Sends a nextFrame signal to the players.
	 */
	void nextFrame();

	/**
	 * @brief previousFrame Sends a previousFrame signal to the players.
	 */
	void previousFrame();

	/**
	 * @brief setPosition Sends a setPosition signal to the players.
	 * @param position The position to show.
	 */
	void setPosition(int position);


	/**
	 * @brief setSpeed Sets the speed to play at.
	 * @param speed The new speed.
	 */
	void setSpeed(float speed);

    int getPosition();
};
}

#endif
