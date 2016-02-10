#ifndef __AnalysisTabMemento_h__
#define __AnalysisTabMemento_h__

#include "AnalysisBoxContainerMemento.h"
// #include "LoadAnalysisVideo.h"

namespace Memento {
class AnalysisBoxContainerMemento;
class AnalysisTabMemento;
}
namespace UndoRedo {
class LoadAnalysisVideo;
}
namespace Utility {
enum class Compression;
enum class YuvType;
}
namespace Memento {
/**
 * This class is the memento for the analysis tab.
 */
class AnalysisTabMemento {
  public:

	/**
	 * @brief AnalysisTabMemento Constructor.
	 */
	AnalysisTabMemento();

	/**
	 * @brief getCurrentVideoPosition Returns the current position the player is at.
	 * @return The current position of the player.
	 */
	int getCurrentVideoPosition();

	/**
	 * @brief setCurrentVideoPosition Sets the current position of the player.
	 * @param currentVideoPosition The current position of the player.
	 */
	void setCurrentVideoPosition(int currentVideoPosition);

	/**
	 * @brief getCurrentlyShownAnalysisVideo Returns what analysis video is currently shown.
	            0 means rgb difference.
	            1 means macroblocks.
	 * @return The currently shown analysis video
	 */
	int getCurrentlyShownAnalysisVideo();

	/**
	 * @brief setCurrentlyShownAnalysisVideo Sets the currently shown analysis video.
	            0 means rgb difference.
	            non 0 means macroblocks.
	 * @param currentlyShownAnalysisVideo The currrently shown analysis video.
	 */
	void setCurrentlyShownAnalysisVideo(int currentlyShownAnalysisVideo);

	/**
	 * @brief getCurrentSpeed Returns the current speed of the player.
	 * @return The current speed of the player.
	 */
	float getCurrentSpeed();

	/**
	 * @brief setCurrentSpeed Sets the current speed of the player.
	 * @param currentSpeed The current speed of the player.
	 */
	void setCurrentSpeed(float currentSpeed);

	/**
	 * @brief getAnalysisBoxContainerMemento Returns the memento of the AnalysisBoxContainer.
	 * @return The memento of the AnalysisBoxContainer
	 */
	Memento::AnalysisBoxContainerMemento getAnalysisBoxContainerMemento();

	/**
	 * @brief setAnalysisBoxContainerMemento Sets the memento of the AnalysisBoxContainer.
	 * @param analysisBoxContainerMemento The memento of the AnalysisBoxContainer.
	 */
	void setAnalysisBoxContainerMemento(Memento::AnalysisBoxContainerMemento
	                                    analysisBoxContainerMemento);

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

  public:
	UndoRedo::LoadAnalysisVideo* memento_;
  private:
	int currentVideoPosition_;
	int currentlyShownAnalyseVideo_;
	float currentSpeed_;
	int yuvWidth_;
	int yuvHeight_;
	int yuvFps_;
	Utility::Compression yuvCompession_;
	std::string yuvPath_;
	Utility::YuvType yuvPixelScheme_;
	Memento::AnalysisBoxContainerMemento containerMemo_;
};
}

#endif

