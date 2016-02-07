#ifndef __LoadFilterVideo_h__
#define __LoadFilterVideo_h__

#include <QUndoCommand>

#include <memory>

#include "../model/YuvVideo.h"
#include "../memento/FilterTabMemento.h"

namespace GUI {
class FilterTab;
}

namespace UndoRedo {
/**
 * This class is the undo command for loading a raw video in the filtertab.
 */
class LoadFilterVideo: public QUndoCommand {
  public:
	/**
	 * @brief LoadFilterVideo Constuctor.
	 * @param filterTab The filtertab to operate on.
	 * @param video The video to use.
	 * @param memento The memento before the new video is loaded.
	 */
	LoadFilterVideo(GUI::FilterTab& filterTab, std::unique_ptr<Model::YuvVideo> video,
                    Memento::FilterTabMemento memento);

	/**
	 * @brief undo Removes current video to which filters can be applied and loads previous video.
	 */
	void undo();

	/**
	 * @brief redo Loads video to which filter can be applied.
	 */
	void redo();


  private:
    Memento::FilterTabMemento                   memento_;
	GUI::FilterTab*                             filterTab_;
	std::unique_ptr<Model::YuvVideo>            video_;
};
}

#endif
