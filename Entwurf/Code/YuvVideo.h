
#include <exception>
using namespace std;

#ifndef __YuvVideo_h__
#define __YuvVideo_h__

#include "Video.h"
#include "PixelSheme.h"
#include "AVVideo.h"
// #include "LoadFilterVideo.h"
#include "Compression.h"
#include "YuvType.h"

namespace GUI
{
	class Video;
	// enum PixelSheme;
}
namespace Model
{
	class AVVideo;
	class YuvVideo;
}
namespace UndoRedo
{
	class LoadFilterVideo;
}
namespace Utility
{
	// enum Compression;
	// enum YuvType;
}

namespace Model
{
	/**
	 * This class holds a yuv video with all its properties.
	 */
	class YuvVideo
	{
		private: QString path;
		private: int height;
		private: int width;
		private: int fps;
		public: UndoRedo::LoadFilterVideo* video;
		public: Utility::Compression* compression;
		public: GUI::Video* displayVideo;
		public: Model::AVVideo* avVideo;
		private: GUI::PixelSheme* yuvType;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="path">Path to the yuv file.</param>
		/// <param name="type">Pixelsheme of the yuv video.</param>
		/// <param name="width">Width of the video.</param>
		/// <param name="height">Height of the video.</param>
		/// <param name="fps">Fps of the video.</param>
		public: YuvVideo(QString path, GUI::PixelSheme type, int width, int height, int fps);

		/// <summary>
		/// Returns the path to the video.
		/// </summary>
		/// <returns>Path to the video.</returns>
		public: QString getPath();

		/// <summary>
		/// Returns the compression of the video.
		/// </summary>
		/// <returns>The compression of the video.</returns>
		public: Utility::Compression getCompression();

		/// <summary>
		/// Returns the pixel sheme of the video.
		/// </summary>
		/// <returns>The pixel scheme.</returns>
		public: Utility::YuvType getYuvType();

		/// <summary>
		/// Returns the AVVideo.
		/// </summary>
		/// <returns>The AVVideo.</returns>
		public: Model::AVVideo& getAvVideo();

		/// <summary>
		/// Returns the Video.
		/// </summary>
		/// <returns>The Video.</returns>
		public: GUI::Video& getVideo();

		/// <summary>
		/// Loads the video from the file.
		/// </summary>
		private: void loadVideo();
	};
}

#endif
