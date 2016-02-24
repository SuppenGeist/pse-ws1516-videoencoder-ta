#ifndef __EncodedVideo_h__
#define __EncodedVideo_h__

#include <memory>

#include "Video.h"
#include "AVVideo.h"
#include "Graph.h"
#include "graphvideo.h"

#include "../utility/VideoLoader.h"
#include "../utility/VideoConverter.h"
#include "../utility/RGBDifferenceCalculator.h"
#include "../utility/RGBHistogramCalculator.h"
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
	     * @brief getRedHistogram Returns the red histogram graph.
	     * @return The red histogram.
	 */
	Model::GraphVideo& getRedHistogram();

	/**
	     * @brief getBlueHistogram Returns the blue histogram graph.
	     * @return The blue histogram.
	 */
	Model::GraphVideo& getBlueHistogram();

	/**
	     * @brief getGreenHistogram Returns the green histogram graph.
	     * @return The green histogram.
	 */
	Model::GraphVideo& getGreenHistogram();

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
	std::unique_ptr<Utility::RGBHistogramCalculator> rgbHistoCalculator_;
	std::unique_ptr<Utility::PsnrCalculator>        psnrCalculator_;
	std::unique_ptr<Utility::RGBDifferenceCalculator> rgbDiffCalculator_;
	std::unique_ptr<Utility::VideoConverter>        macroblockConverter_;
	std::unique_ptr<Utility::VideoConverter>        videoConverter_;
	std::unique_ptr<Utility::VideoLoader>   macroblockLoader_;


	/**
	     * @brief calculateHistograms Calculates the Histograms.
	 */
	void calculateHistograms();

	/**
	 * @brief loadVideo Loads the video from the file.
	 */
	void loadVideo();
};
}

#endif


