#ifndef __ForwardPlayer_h__
#define __ForwardPlayer_h__

#include "Player.h"

namespace GUI
{
    class GlobalControlPanel;
}

namespace GUI
{
	/**
     * This player forwards its input to a GlobalControlPanel.
     * Since this is a Proxy to another class type not all methods can be meaningfully
     * implemented. So dont call these methods.
     */
    class ForwardPlayer: public Player
    {
    public:
        /**
         * @brief ForwardPlayer Constructor.
         */
        ForwardPlayer() noexcept;

        /**
         * @brief setForwardControlPanel Sets the global control panel that the player forwards its input to.
         * @param panel The panel to forward to.
         */
        void setForwardControlPanel(GlobalControlPanel *panel) noexcept;

        /**
         * If no GlobalControlPanel is set nothing happens.
         *
         * @brief play Plays the video.
         */
        void play() override;
\
        /**
         * If no GlobalControlPanel is set nothing happens.
         *
         * @brief pause Pauses the video.
         */
        void pause() override;

        /**
         * If no GlobalControlPanel is set nothing happens.
         *
         * @brief stop Stops the video.
         */
        void stop() override;

        /**
         * If no GlobalControlPanel is set nothing happens.
         *
         * @brief nextFrame Shows the next frame.
         */
        void nextFrame() override;

        /**
         * If no GlobalControlPanel is set nothing happens.
         *
         * @brief previousFrame Shows the previous frame.
         */
        void previousFrame() override;

        /**
         * @brief setSpeed Sets the speed.
         * @param speed The new speed.
         */
        void setSpeed(float speed) override;

        /**
         * @brief setSpeed Sets the position.
         * @param speed The new position.
         */
        void setPosition(std::size_t position) override;

        /**
         * Dont call this method.
         * On a call a std::logic_error exception is thrown.
         */
        std::size_t getPosition() const override;

        /**
         * Dont call this method.
         * On a call a std::logic_error exception is thrown.
         */
        float getSpeed() const override;

        /**
         * Dont call this method.
         * On a call a std::logic_error exception is thrown.
         */
        bool isPlaying() const override;

        /**
         * Dont call this method.
         * On a call a std::logic_error exception is thrown.
         */
        bool isStopped() const override;

        /**
         * Dont call this method.
         * On a call a std::logic_error exception is thrown.
         */
        void reset() override;

        /**
         * Dont call this method.
         * On a call a std::logic_error exception is thrown.
         */
        std::size_t getNumberOfFrames() const override;

    private:
        GlobalControlPanel* forwardPanel_;
	};
}

#endif
