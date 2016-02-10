#ifndef __FilterTabMemento_h__
#define __FilterTabMemento_h__

#include <string>

#include "../model/FilterList.h"

namespace Model {
class FilterList;
}
namespace Utility {
enum class Compression;
enum class YuvType;
}
namespace Memento {
/**
 * This class is the memento for the FilterTab.
 */
class FilterTabMemento {



  public:
    /**
     * @brief FilterTabMemento
     */
    FilterTabMemento();

    /**
     * @brief getFilterList Returns the list of the currently selected  filters.
     * @return List of the selected filters.
     */
    Model::FilterList *getFilterList();

    /**
     * @brief setFilterList Sets the list of the currently selected filters.
     * @param filterList List of the selected filters.
     */
	void setFilterList(Model::FilterList* filterList);

    /**
     * @brief getWasApplied Whether the filter were already applied.
     * @return True if the filter wre already applied.
     */
	bool getWasApplied();

    /**
     * @brief setWasApplied Sets whether the filters were already aplied.
     * @param wasApplied True if the filter were already applied.
     */
	void setWasApplied(bool wasApplied);

    /**
     * @brief getDisplayedFrame Returns the currently displayed frame in the frame preview.
     * @return The currently displayed frame.
     */
	int getDisplayedFrame();

    /**
     * @brief setDisplayedFrame Sets the currently displayed frame in the frame preview.
     * @param displayedFrame The currently displayed frame.
     */
	void setDisplayedFrame(int displayedFrame);

    /**
     * @brief getLoadedFile Returns the path to the currently loaded yuv file
     * @return Absolute path to the currently loaded yuv file.
     */
	std::string getLoadedFile();

    /**
     * @brief setLoadedFile Sets the path to the currently loaded yuv file.
     * @param loadedFile Absolute path to the loaded yuv file.
     */
	void setLoadedFile(std::string loadedFile);

    /**
     * @brief getFps Returns the fps.
     * @return The fps.
     */
    int getFps();

    /**
     * @brief getWidth Returns the width.
     * @return The width.
     */
    int getWidth();

    /**
     * @brief getHeight Returns the heigh.
     * @return The height.
     */
    int getHeight();

    /**
     * @brief getCompression Returns the compression.
     * @return The compression.
     */
    Utility::Compression getCompression();

    /**
     * @brief getPixelSheme Returns the pixelsheme.
     * @return The pixelsheme.
     */
    Utility::YuvType getPixelSheme();

    /**
     * @brief setFps Sets fps.
     * @param fps The fps.
     */
    void setFps(int fps);
    /**
     * @brief setWidth Sets Width.
     * @param width The Width.
     */
    void setWidth(int width);
    /**
     * @brief setHeight Sets Height.
     * @param height The Height.
     */
    void setHeight(int height);
    /**
     * @brief setCompression Sets Compression.
     * @param compThe Compression.
     */
    void setCompression(Utility::Compression comp);
    /**
     * @brief setPixelSheme Sets PixelScheme.
     * @param sheme The PixelScheme.
     */
    void setPixelSheme(Utility::YuvType sheme);

private:
  Model::FilterList* filterList_;
  bool wasApplied_;
  int displayedFrame_;
  int yuvWidth_;
  int yuvHeight_;
  int yuvFps_;
  Utility::Compression yuvCompession_;
  std::string yuvPath_;
  Utility::YuvType yuvPixelScheme_;
};
}

#endif

