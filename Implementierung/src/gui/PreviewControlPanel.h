#ifndef __PreviewControlPanel_h__
#define __PreviewControlPanel_h__

#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include "ControlPanel.h"


namespace GUI
{
	/**
	 * This class is the control panel for the frame preview.
     */
    class PreviewControlPanel: public QFrame, public GUI::ControlPanel
	{
        Q_OBJECT

    public:
        /**
         * @brief PreviewControlPanel Constructor.
         * @param parent
         */
        PreviewControlPanel(QWidget* parent = 0);

        /**
         * @brief updateUi Updates the ui of the control panel.
         */
        void updateUi() override;

    private slots:
        /**
         * @brief nextFrame Slot for button_nextFrame.clicked() signal.
         */
        void nextFrame();

        /**
         * @brief previousFrame Slot for button_previousFrame.clicked() signal.
         */
        void previousFrame();

    private:
        QPushButton* button_nextFrame;
        QPushButton* button_previousFrame;
        QLabel* label_position;

        /**
         * @brief createUi Creates the ui.
         */
        void createUi();
	};
}

#endif

