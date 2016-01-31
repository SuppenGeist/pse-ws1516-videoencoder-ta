#include <exception>
#include <string>
#include <QColor>
using namespace std;

#ifndef __BorderFilter_h__
#define __BorderFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class BorderFilter;
}

namespace Model
{
	/**
	 * Inserts border into the video
    */
	class BorderFilter: public Model::Filter
	{
		private: bool top;
		private: bool bottom;
		private: bool right;
		private: bool left;
		private: int thickness;
		private: QRgb color;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BorderFilter();

		/// <summary>
		/// Whether a border is inserted at the top.
		/// </summary>
		/// <returns>True if a border is inserted at the top.</returns>
		public: bool getTop();

		/// <summary>
		/// Sets whether a border is inserted at the top.
		/// </summary>
		/// <param name="top">True if a border is inserted at the top.</param>
		public: void setTop(bool top);

		/// <summary>
		/// Whether a border is inserted at the bottom.
		/// </summary>
		/// <returns>True if a border is inserted at the bottom.</returns>
		public: bool getBottom();

		/// <summary>
		/// Sets whether a border is inserted at the bottom.
		/// </summary>
		/// <param name="bottom">True if a border is inserted at the bottom.</param>
		public: void setBottom(bool bottom);

		/// <summary>
		/// Whether a border is inserted at the right.
		/// </summary>
		/// <returns>True if a border is inserted at the right.</returns>
		public: bool getRight();

		/// <summary>
		/// Sets whether a border is inserted at the right.
		/// </summary>
		/// <param name="right">True if a border is inserted at the right.</param>
		public: void setRight(bool right);

		/// <summary>
		/// Whether a border is inserted at the left.
		/// </summary>
		/// <returns>True if a border is inserted at the left.</returns>
		public: bool getLeft();

		/// <summary>
		/// Sets whether a border is inserted at the left.
		/// </summary>
		/// <param name="left">True if a border is inserted at the left.</param>
		public: void setLeft(bool left);

		/// <summary>
		/// Returns the thickness of the border.
		/// </summary>
		/// <returns>The thickness of the border.</returns>
		public: int getThickness();

		/// <summary>
		/// Sets the thickness of the border.
		/// </summary>
		/// <param name="thickness">The thickness.</param>
		public: void setThickness(int thickness);

		/// <summary>
		/// Returns the color of the border,
		/// </summary>
		/// <returns>The border color.</returns>
		public: QRgb getColor();

		/// <summary>
		/// Sets the color of the border,
		/// </summary>
		/// <param name="color">The new border color.</param>
		public: void setColor(QRgb color);

		public: string getName();

		public: string getFilterDescription();

        public: void restoreFilter(string description);
	};
}

#endif


