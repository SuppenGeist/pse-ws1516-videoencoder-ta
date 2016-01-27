
#include <exception>
using namespace std;

#ifndef __EncodedVideo_h__
#define __EncodedVideo_h__

//#include "AnalysisBox.h"
#include "Video.h"
#include "AVVideo.h"
#include "Graph.h"

namespace GUI
{
	class AnalysisBox;
	class Video;
}
namespace Model
{
	class AVVideo;
	class Graph;
	class EncodedVideo;
}

namespace Model
{
	/**
	 * This class contains all analysis info of an encoded video.
         */

	class EncodedVideo
	{
		private: QString path;
		private: int fileSize;
		private: int numberOfColors;
		private: QString codec;
		public: GUI::AnalysisBox* video;
		public: Model::AVVideo* avVideo;
		public: GUI::Video* displayVideo;
		public: GUI::Video* macroblockVideo;
		public: GUI::Video* rgbDiffVideo;
		public: Model::Graph* bitrate;
		public: Model::Graph* psnr;
		public: Model::Graph* redHisto;
		public: Model::Graph* greenHisto;
		public: Model::Graph* blueHiso;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="path">Path to the video.</param>
		public: EncodedVideo(QString path);

		/// <summary>
		/// Returns the path to the video.
		/// </summary>
		/// <returns>The path to the video.</returns>
		public: QString getPath();

		/// <summary>
		/// Returns the size of the video file.
		/// </summary>
		/// <returns>the file size.</returns>
		public: int getFileSize();

		/// <summary>
		/// Returns the number of colors that appear in the whole video.
		/// </summary>
		/// <returns>The number of colors in the video.</returns>
		public: int getNumberOfColors();

		/// <summary>
		/// Returns the codec used in the video file.
		/// </summary>
		/// <returns>The used codec.</returns>
		public: QString getCodec();

		/// <summary>
		/// Returns the bitrate graph.
		/// </summary>
		/// <returns>The bitrate graph.</returns>
		public: Model::Graph& getBitrate();

		/// <summary>
		/// Returns the psnr graph.
		/// </summary>
		/// <returns>The psnr graph.</returns>
		public: Model::Graph& getPsnr();

		/// <summary>
		/// Returns the red histogramm graph.
		/// </summary>
		/// <returns>The red histogramm.</returns>
		public: Model::Graph& getRedHistogramm();

		/// <summary>
		/// Returns the blue histogramm graph.
		/// </summary>
		/// <returns>The blue histogramm.</returns>
		public: Model::Graph& getBlueHistogramm();

		/// <summary>
		/// Returns the green histogramm graph.
		/// </summary>
		/// <returns>The green histogramm.</returns>
		public: Model::Graph& getGreenHistogramm();

		/// <summary>
		/// Returns the AVVideo.
		/// </summary>
		/// <returns>The AVVideo.</returns>
		public: Model::AVVideo& getAvVideo();

		/// <summary>
		/// Returns the video which shows the macroblocks.
		/// </summary>
		/// <returns>The macroblock video.</returns>
		public: GUI::Video& getMacroBlockVideo();

		/// <summary>
		/// Returns the video which shows the rgb difference to another video.
		/// </summary>
		/// <param name="reference">The video to compare to.</param>
		/// <returns>The rgb diff video.</returns>
		public: GUI::Video& getRgbDiffVideo(GUI::Video* reference = 0);

		/// <summary>
		/// Returns the Video.
		/// </summary>
		/// <returns>The Video.</returns>
		public: GUI::Video& getVideo();

		/// <summary>
		/// Loads the video from the file.
		/// </summary>
		private: void loadVideo();

		/// <summary>
		/// Sets the bitrate graph.
		/// </summary>
		/// <param name="graph">The bitrate graph.</param>
		public: void setBitrate(Model::Graph graph);

		/// <summary>
		/// Sets the psnr graph.
		/// </summary>
		/// <param name="graph">The psnr graph.</param>
		public: void setPsnr(Model::Graph graph);

		/// <summary>
		/// Sets the red histogramm graph.
		/// </summary>
		/// <param name="graph">The red histogramm.</param>
		public: void setRedHistogramm(Model::Graph graph);

		/// <summary>
		/// Sets the green histogramm graph.
		/// </summary>
		/// <param name="graph">The green histogramm.</param>
		public: void setGreenHistogramm(Model::Graph graph);

		/// <summary>
		/// Sets the blue histogramm graph.
		/// </summary>
		/// <param name="graph">The blue histogramm.</param>
		public: void setBlueHistogramm(Model::Graph graph);

		/// <summary>
		/// Sets the video that shows the macroblocks.
		/// </summary>
		/// <param name="video">The macroblcok video.</param>
		public: void setMacroblockVideo(GUI::Video video);

		/// <summary>
		/// Sets the video that shows a rgb differenece to another video.
		/// </summary>
		/// <param name="video">The rgb diff video.</param>
		public: void setRgbDiffVideo(GUI::Video video);
	};
}

#endif


