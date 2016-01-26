/*
#include <exception>
#include <vector>
using namespace std;

#ifndef __Video_h__
#define __Video_h__

// #include "EncodedVideo.h"

namespace GUI
{
	class Video;
}
namespace Model
{
	class EncodedVideo;
}

namespace GUI
{
	/**
	 * This class represents a video.
	 * It provides a basic interface to comfortly handle a vector of frames.

	class Video
	{
		private: std::vector<std::unique_ptr<QImage> > frames;
		private: int fps;
		private: int width;
		private: int height;
		public: Model::EncodedVideo* displayVideo;
		public: Model::EncodedVideo* macroblockVideo;
		public: Model::EncodedVideo* rgbDiffVideo;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="fps">The fps the video should be played at.</param>
		/// <param name="width">The width of the video.</param>
		/// <param name="height">The height of the video.</param>
		public: Video(int fps, int width, int height);

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
		/// <param name="index">The index of the frame to return.</param>
		public: QImage* getFrame(int index);

		/// <summary>
		/// Inserts a frame at the given index.
		/// If index < 0 then the frame gets pushed to the back.
		/// If the index is greater than getNumberOfFrames() the frames gets pushed to the back.
		/// </summary>
		/// <param name="index">The index to insert the frame at.</param>
		/// <param name="frame">The frame to insert.</param>
		public: void insertFrame(int index = -1, unique_ptr<QImage> frame);

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
		/// <param name="frames">The frames to insert.</param>
		public: void insertFrames(int index = -1, vector<unique_ptr<QImage> >& frames);

		/// <summary>
		/// Returns the number of frames in the video.
		/// </summary>
		/// <returns>The number of frames in the video.</returns>
		public: int getNumberOfFrames();
	};
}

#endif
*/
