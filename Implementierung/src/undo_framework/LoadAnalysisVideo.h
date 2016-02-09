#ifndef __LoadAnalysisVideo_h__
#define __LoadAnalysisVideo_h__

#include <QUndoCommand>
#include <memory>

namespace GUI
{
	class AnalysisTab;
}
namespace Model
{
	class YuvVideo;
}


namespace UndoRedo
{
	/**
	 * This class is the undo command for loading the raw video on the analysis tab.
    */
    class LoadAnalysisVideo: public QUndoCommand
    {
    public:

        /**
         * @brief LoadAnalysisVideo Constructor.
         * @param anaTab The AnalyseTab to operate on.
         * @param video The new raw video.
         */
        LoadAnalysisVideo(GUI::AnalysisTab* anaTab, std::unique_ptr<Model::YuvVideo> video);

		/// <summary>
        ///
		/// </summary>
        /**
         * @brief undo Restores the anlysis tab to the state before the new video was loaded.
         */
        void undo();

		/// <summary>
        /// Loads a new raw video in the analysis tab.
		/// </summary>
        /**
         * @brief redo
         */
        void redo();

    private:
        GUI::AnalysisTab* anaTab_;
        std::unique_ptr<Model::YuvVideo> video_;
	};
}

#endif
