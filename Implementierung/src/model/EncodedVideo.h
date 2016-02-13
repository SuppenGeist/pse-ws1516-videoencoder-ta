#ifndef __EncodedVideo_h__
#define __EncodedVideo_h__

#include "Video.h"
#include "AVVideo.h"
#include "Graph.h"
#include "../utility/VideoLoader.h"
#include "../utility/VideoConverter.h"
#include "../utility/RGBDifferenceCalculator.h"
#include "../utility/RGBHistogrammCalculator.h"
#include "../utility/PsnrCalculator.h"
#include "../utility/BitrateCalculator.h"

namespace Model {
class AVVideo;
class Graph;
class Video;
}

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

    /**
     * @brief getPath Returns the path to the video.
     * @return The path to the video.
     */
	QString getPath();

    /**
     * @brief getFileSize Returns the size of the video file.
     * @return The file size.
     */
	int getFileSize();

    /**
     * @brief getNumberOfColors Returns the number of colors that appear in the whole video.
     * @return The number of colors in the video.
     */
	int getNumberOfColors();

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
	Model::Graph& getPsnr(Model::Video* reference = 0);

    /**
     * @brief getRedHistogramm Returns the red histogramm graph.
     * @return The red histogramm.
     */
	Model::Graph& getRedHistogramm();

    /**
     * @brief getBlueHistogramm Returns the blue histogramm graph.
     * @return The blue histogramm.
     */
	Model::Graph& getBlueHistogramm();

    /**
     * @brief getGreenHistogramm Returns the green histogramm graph.
     * @return The green histogramm.
     */
	Model::Graph& getGreenHistogramm();

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
	Model::Video& getRgbDiffVideo(Model::Video* reference = 0);

    /**
     * @brief getVideo Returns the Video.
     * @return The Video.
     */
	Model::Video& getVideo();

    /**
     * @brief setBitrate Sets the bitrate graph.
     * @param graph The bitrate graph.
     */
	void setBitrate(Model::Graph graph);

    /**
     * @brief setPsnr Sets the psnr graph.
     * @param graph The psnr graph.
     */
	void setPsnr(Model::Graph graph);

    /**
     * @brief setRedHistogramm Sets the red histogramm graph.
     * @param graph The red histogramm.
     */
	void setRedHistogramm(Model::Graph graph);

    /**
     * @brief setGreenHistogramm Sets the green histogramm graph.
     * @param graph The green histogramm.
     */
	void setGreenHistogramm(Model::Graph graph);

    /**
     * @brief setBlueHistogramm Sets the blue histogramm graph.
     * @param graph The blue histogramm.
     */
	void setBlueHistogramm(Model::Graph graph);

    /**
     * @brief setMacroblockVideo Sets the video that shows the macroblocks.
     * @param video The macroblcok video.
     */
	void setMacroblockVideo(Model::Video video);

    /**
     * @brief setRgbDiffVideo Sets the video that shows a rgb differenece to another video.
     * @param video The rgb diff video.
     */
    void setRgbDiffVideo(Model::Video video);

private:
    /**
     * @brief calculateHistogramms Calculates the Histogramms.
     */
    void calculateHistogramms();

    /**
     * @brief loadVideo Loads the video from the file.
     */
    void loadVideo();
private:
    QString path;
    int fileSize;
    int numberOfColors;
    QString codec;
    Model::Video* video;
    Model::AVVideo* avVideo;
    Model::Video* displayVideo;
    Model::Video* macroblockVideo;
    Model::Video* rgbDiffVideo;
    Model::Graph* bitrate;
    Model::Graph* psnr;
    Model::Graph* redHisto;
    Model::Graph* greenHisto;
    Model::Graph* blueHisto;
};
}

#endif


