#include <exception>
#include <string>
using namespace std;

#ifndef __BlendingFilter_h__
#define __BlendingFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class BlendingFilter;
}

namespace Model
{
	/**
	 * Inserts black blending into the video
    */
	class BlendingFilter: public Model::Filter
	{
		private: bool inBlend;
		private: int startFrame;
		private: int endFrame;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BlendingFilter();

		/// <summary>
		/// Whether it is an in blending.
		/// </summary>
		/// <returns>true if it is an in blending.</returns>
		public: bool getInBlend();

		/// <summary>
		/// Sets whether it is an in blending.
		/// </summary>
		/// <param name="inBlend">True if it is an in blending.</param>
		public: void setInBlend(bool inBlend);

		/// <summary>
		/// Returns the start frame of the blending.
		/// </summary>
		/// <returns>The start frame of the blending.</returns>
		public: int getStartFrame();

		/// <summary>
		/// Sets the start frame of the blending.
		/// </summary>
		/// <param name="startFrame">The start frame.</param>
		public: void setStartFrame(int startFrame);

		/// <summary>
		/// Returns the end frame of the blending.
		/// </summary>
		/// <returns>The end frame.</returns>
		public: int getEndFrame();

		/// <summary>
		/// Sets the end frame of the blending.
		/// </summary>
		/// <param name="endFrame">The end frame.</param>
		public: void setEndFrame(int endFrame);

		public: string getName();

		public: string getFilterDescription();

        public: void restoreFilter(string description);
	};
}

#endif

