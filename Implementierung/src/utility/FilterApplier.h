#ifndef __FilterApplier_h__
#define __FilterApplier_h__

namespace Model
{
	class FilterList;
    class AVVideo;
}
class AVFrame;

namespace Utility
{
	/**
	 * Applies filters of a given FilterList to a video.
     */
	class FilterApplier
	{
		private: Model::FilterList* list;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="list">The list with the filters to apply.</param>
		public: FilterApplier(Model::FilterList& list);

		/// <summary>
		/// Applies the given filters to the video.
		/// </summary>
		/// <param name="target">The video to which the new frames are added to.</param>
		/// <param name="video">The video to apply the filters on.</param>
		public: void applyToVideo(Model::AVVideo& target, Model::AVVideo& video);

		/// <summary>
		/// Initializes the filters.
		/// </summary>
		private: void initFilters();

		/// <summary>
		/// Applies the filters to one frame.
		/// </summary>
		/// <param name="frame">The frame to apply the filters on.</param>
		/// <returns>The filtered frame.</returns>
		private: AVFrame applyToFrame(AVFrame& frame);
	};
}

#endif
