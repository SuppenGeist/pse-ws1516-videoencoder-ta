#ifndef __RemoveVideo_h__
#define __RemoveVideo_h__

#include <QUndoCommand>

#include "../memento/AnalysisBoxMemento.h"
namespace GUI
{
	class AnalysisBox;
	class AnalysisBoxContainer;
}
namespace UndoRedo
{
	/**
	 * This class is the undo command for removing a encoded video in the analysis tab.
    */
    class RemoveVideo: public QUndoCommand
	{
        public:

        /**
         * @brief RemoveVideo The AnalysisBoxContainer to operate on.
         * @param container The video to remove.
         */
        RemoveVideo(GUI::AnalysisBox* box);

        /**
         * @brief undo Re adds the removed video to the analysis tab.
         */
        void undo();

        /**
         * @brief redo Removes a video from the analysis tab.
         */
        void redo();

    private:

        GUI::AnalysisBox* anaBox;
        GUI::AnalysisBoxContainer* container;
        Memento::AnalysisBoxMemento boxMemo;
        int index;
	};
}

#endif
