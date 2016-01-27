#ifndef __FrameView_h__
#define __FrameView_h__

#include <QWidget>

namespace GUI
{
/**
 * This class is the view used by the video player.
 * It automatically scales the frames passed to it.
*/
    class FrameView: public QWidget
	{
    public:
        /**
         * @brief FrameView Constructor.
         * @param parent The parent widget.
         */
        FrameView(QWidget* parent = 0);

        /**
         * @brief setFrame Sets the frame to show.
         * @param frame The frame to show.
         */
        void setFrame(QImage& frame);

        /**
         * @brief clear Clears the current frame so nothing is shown.
         */
        void clear();

    protected:
        /**
         * @brief resizeEvent This method is called when the widget got resized.
         * @param event The resize event.
         */
        void resizeEvent(QResizeEvent* event);

        /**
        * @brief repaintEvent This method is called when the widget has to be repainted.
        * @param event The paint event.
        */
         void paintEvent(QPaintEvent* event);


    private:
        int xOffset_;
        int yOffset_;

        QImage currentFrame_;
        QImage* originalFrame_;

        /**
         * @brief updateOffset Updates the offset at which the image is drawn.
         */
        void updateOffset();
	};
}

#endif

