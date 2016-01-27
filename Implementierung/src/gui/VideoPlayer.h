#ifndef __VideoPlayer_h__
#define __VideoPlayer_h__

#include <vector>
#include <memory>

#include "Player.h"

namespace GUI {
    class Timer;
    class ControlPanel;
    class FrameView;
}

namespace Model {
    class Video;
}

namespace GUI
{
	/**
	 * This class is a video player.
	 * It provides a basic interface for handling playback of videos.
     */
    class VideoPlayer: public Player
    {
    public:
        /**
         * @brief VideoPlayer Constructor.
         */
        VideoPlayer();

        /**
         * @brief ~VideoPlayer Destructor.
         */
        virtual ~VideoPlayer() {}

        /**
         * Multiple views can be added.
         * Is the view is already in the list nothing happens.
         *
         * @brief addView Adds a view.
         * @param view The view to add.
         */
        void addView(FrameView& view);

        /**
         * @brief removeView Removes a view.
         * @param view The view to remove.
         */
        void removeView(FrameView& view);

        /**
         * If a video was previously set the old video gets deleted.
         *
         * @brief setVideo Sets the video.
         * @param video The video to play.
         */
        void setVideo(Model::Video& video) noexcept;

        /**
         * If no video is set nullptr is returned.
         *
         * @brief getVideo Returns a pointer to the currently played video.
         * @return Pointer to the current video.
         */
        Model::Video* getVideo() noexcept;

        /**
         * This method has to be called in order to be able to play the video.
         * @brief setTimer Sets the timer for the player.
         * @param timer The timer for the player.
         */
        void setTimer(std::shared_ptr<Timer> timer) noexcept;

        /**
         * @brief clearTimer Clears the timer.
         */
        void clearTimer() noexcept;

        /**
         * If no timer is set 0 is returned.
         *
         * @brief getFps Returns the fps the player is currently playing at.
         * @return The current fps of the player.
         */
        int getFps() const noexcept;

        /**
         * This panel is the reference for video position and speed.
         *
         * @brief setMasterControlPanel Sets the MasterControlPanel.
         * @param controlPanel The master control panel.
         */
        void setMasterControlPanel(ControlPanel& controlPanel) noexcept;

        /**
         * If no timer is set nothing happens.
         *
         * @brief play Plays the video.
         */
        virtual void play() override;

        /**
         * If no timer is set nothing happens.
         *
         * @brief pause Pauses the video.
         */
        virtual void pause() override;

        /**
         * @brief stop Stops the video.
         */
        virtual void stop() override;

        /**
         * @brief nextFrame Shows the next frame.
         */
        virtual void nextFrame() override;

        /**
         * @brief previousFrame Shows the previous frame.
         */
        virtual void previousFrame() override;

        /**
         * If no timer is set nothing happens.
         *
         * @brief setSpeed Sets the speed.
         * @param speed The new speed.
         */
        virtual void setSpeed(float speed) override;

        /**
         * @brief setPosition Sets the position in the video.
         * @param position The new position.
         */
        virtual void setPosition(std::size_t position) override;

        /**
         * @brief getPosition Returns the position in the video.
         * @return The current position.
         */
        virtual std::size_t getPosition() const noexcept override;

        /**
         * If no timer is set 0 is returned.
         *
         * @brief getSpeed Returns the speed.
         * @return The current speed.
         */
        virtual float getSpeed() const noexcept override;

        /**
         * If no timer is set false is returned.
         *
         * @brief isPlaying Whether the player is currently playing.
         * @return True if the player is playing.
         */
        virtual bool isPlaying() const override;

        /**
         * @brief isStopped Whether the player is stopped.
         * @return True if the player is stopped.
         */
        virtual bool isStopped() const override;

        /**
         * @brief reset Resets the player.
         */
        virtual void reset() override;

    private:
        std::size_t             position_;
        Model::Video*           video_;
        std::vector<FrameView*> views_;
        std::shared_ptr<Timer>  timer_;
        ControlPanel*           masterPanel_;
	};
}

#endif

