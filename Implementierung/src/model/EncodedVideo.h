#ifndef __EncodedVideo_h__
#define __EncodedVideo_h__

#include <memory>
#include <thread>

#include "Video.h"
#include "AVVideo.h"
#include "Graph.h"
#include "graphvideo.h"

#include "../utility/VideoLoader.h"
#include "../utility/VideoConverter.h"
#include "../utility/RGBDifferenceCalculator.h"
#include "../utility/RGBHistogrammCalculator.h"
#include "../utility/PsnrCalculator.h"
#include "../utility/BitrateCalculator.h"

namespace Model {
/**
    * This class contains all analysis info of an encoded video.
    */
class EncodedVideo {

  public:
	/**
	 * @brief EncodedVideo Constructor.
	 * @param path
	 */
	EncodedVideo(QString path);

	~EncodedVideo();

	/**
	 * @brief getPath Returns the path to the video.
	 * @return The path to the video.
	 */
    QString getPath();

	/**
	 * @brief getCodec Returns the codec used in the video file.
	 * @return The used codec.
	 */
	QString getCodec();

	/**
	 * @brief getBitrate Returns the bitrate graph.
	 * @return The bitrate graph.
	 */
	Model::Graph& getBitrate();

	/**
	 * @brief getPsnr Returns the psnr graph.
	 * @param reference
	 * @return The psnr graph.
	 */
    Graph *getPsnr(Model::Video* reference = 0);

	/**
	 * @brief getRedHistogramm Returns the red histogramm graph.
	 * @return The red histogramm.
	 */
    Model::GraphVideo& getRedHistogramm();

	/**
	 * @brief getBlueHistogramm Returns the blue histogramm graph.
	 * @return The blue histogramm.
	 */
    Model::GraphVideo& getBlueHistogramm();

	/**
	 * @brief getGreenHistogramm Returns the green histogramm graph.
	 * @return The green histogramm.
	 */
    Model::GraphVideo& getGreenHistogramm();

	/**
	 * @brief getAvVideo Returns the AVVideo.
	 * @return The AVVideo.
	 */
	Model::AVVideo& getAvVideo();

	/**
	 * @brief getMacroBlockVideo Returns the video which shows the macroblocks.
	 * @return The macroblock video.
	 */
	Model::Video& getMacroBlockVideo();

	/**
	 * @brief getRgbDiffVideo Returns the video which shows the rgb difference to another video.
	 * @param reference The video to compare to.
	 * @return The rgb diff video.
	 */
    Model::Video* getRgbDiffVideo(Model::Video* reference = 0);

	/**
	 * @brief getVideo Returns the Video.
	 * @return The Video.
	 */
	Model::Video& getVideo();

    int getAverageBitrate();

  private:

    QString                     path_;
	std::unique_ptr<Video>      video_;
    std::unique_ptr<AVVideo>    avVideo_;
	std::unique_ptr<Video>      macroblockVideo_;
    std::unique_ptr<AVVideo>    macroblockAVVideo_;
	std::unique_ptr<Video>      rgbDiffVideo_;
	std::unique_ptr<Graph>      bitrate_;
	std::unique_ptr<Graph>      psnr_;
    std::unique_ptr<GraphVideo>      redHisto_;
    std::unique_ptr<GraphVideo>      greenHisto_;
    std::unique_ptr<GraphVideo>      blueHisto_;

	std::unique_ptr<Utility::VideoLoader> loader_;
	std::unique_ptr<Utility::BitrateCalculator> bitrateCalculator_;
    std::unique_ptr<Utility::RGBHistogrammCalculator> rgbHistoCalculator_;
    std::unique_ptr<Utility::PsnrCalculator>        psnrCalculator_;
    std::unique_ptr<Utility::RGBDifferenceCalculator> rgbDiffCalculator_;
	std::thread                 converter_;
    std::thread                 macroblockConverter_;
    std::unique_ptr<Utility::VideoLoader>   macroblockLoader_;
	bool                        isConverterRunning_;
    bool                        isMacroblockConverterRunnning_;


	/**
	 * @brief calculateHistogramms Calculates the Histogramms.
	 */
	void calculateHistogramms();

	/**
	 * @brief loadVideo Loads the video from the file.
	 */
	void loadVideo();

	void convertVideo();
    void convertMacroblock();
};
}

#endif


