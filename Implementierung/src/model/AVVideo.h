
#include <exception>
#include <vector>
using namespace std;

#ifndef __AVVideo_h__
#define __AVVideo_h__

// #include "EncodedVideo.h"

namespace Model
{
	class EncodedVideo;
	class AVVideo;
}

namespace Model
{
	/**
	 * This class contains AVFrames from the ffmpeg library and manages them.
	 */
	class AVVideo
	{
		private: std::vector<std::unique_ptr<AVFrame> > video;
		private: int fps;
		private: int width;
		private: int height;
		public: Model::EncodedVideo* avVideo;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="fps">The fps the video should be played at.</param>
		/// <param name="width">The width of the video.</param>
		/// <param name="height">The height of the video.</param>
		public: AVVideo(int fps, int width, int height);

		/// <summary>
		/// Returns the width of the video.
		/// </summary>
		/// <returns>The width of the video.</returns>
		public: int getWidth();

		/// <summary>
		/// Returns the height of the video.
		/// </summary>
		/// <returns>The height of the video.</returns>
		public: int getHeight();

		/// <summary>
		/// Returns the fps of the video.
		/// </summary>
		/// <returns>Fps of the video.</returns>
		public: int getFps();

		/// <summary>
		/// Returns the frame at the given index.
		/// If the index is invalid nullptr is returned.
		/// </summary>
		/// <param name="index">the index of the frame to return</param>
		/// <returns>The frame at the given index.</returns>
		public: AVFrame* getFrame(int index);

		/// <summary>
		/// Inserts a frame at the given index.
		/// If index < 0 then the frame gets pushed to the back.
		/// If the index is greater than getNumberOfFrames() the frames gets pushed to the back.
		/// </summary>
		/// <param name="index">The index to insert the frame at.</param>
		/// <param name="frame:std:">The frame to insert.</param>
		public: void insertFrame(int index = -1, unique_ptr<AVFrame> frame:std:);

		/// <summary>
		/// Removes the frame at the given index.
		/// If the index is invalid nothing happens.
		/// </summary>
		/// <param name="index">The index of the frame to remove.</param>
		public: void removeFrame(int index);

		/// <summary>
		/// Inserts a vector of frames at the given index.
		/// If the index<0 or index is greater than getNumberOfFrames() then the frames are pushed to the back.
		/// </summary>
		/// <param name="index">The index to insert the frames at.</param>
		/// <param name="frames:std:">The frames to insert.</param>
		public: void insertFrames(int index = -1, vector<std::unique_ptr<AVFrame> >& frames:std:);

		/// <summary>
		/// Returns the number of frames in the video.
		/// </summary>
		/// <returns>The number of frames in the video.</returns>
		public: int getNumberOfFrames();
	};
}

#endif
