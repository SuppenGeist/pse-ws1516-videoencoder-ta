#include <exception>
#include <string>
using namespace std;

#ifndef __RectangleFilter_h__
#define __RectangleFilter_h__

#include "Filter.h"

namespace Model
{
	// class Filter;
	class RectangleFilter;
}

namespace Model
{
	/**
	 * Inserts a filled rectangle with a given color into the video
    */
	class RectangleFilter: public Model::Filter
	{
		private: QRgb color;
		private: int width;
		private: int height;
		private: int x;
		private: int y;
		private: int opacity;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: RectangleFilter();

		public: string getFilterDescription();

		/// <summary>
		/// Returns the color of the rectangle.
		/// </summary>
		/// <returns>The color of the rectangle.</returns>
		public: QRgb getColor();

		/// <summary>
		/// Sets the color of the rectangle.
		/// </summary>
		/// <param name="color">The new color of the rectangle.</param>
		public: void setColor(QRgb color);

		/// <summary>
		/// Returns the width of the rectangle.
		/// </summary>
		/// <returns>The width of the rectangle.</returns>
		public: int getWidth();

		/// <summary>
		/// Sets the width of the rectangle.
		/// </summary>
		/// <param name="width">The new width of the rectangle.</param>
		public: void setWidth(int width);

		/// <summary>
		/// Returns the height of the rectangle.
		/// </summary>
		/// <returns>The height of the rectangle.</returns>
		public: int getHeight();

		/// <summary>
		/// Sets the height of the rectangle.
		/// </summary>
		/// <param name="height">The new height of the rectangle.</param>
		public: void setHeight(int height);

		/// <summary>
		/// Returns the start position on the x axis.
		/// </summary>
		/// <returns>The start position on the x axis.</returns>
		public: int getX();

		public: string getName();

		/// <summary>
		/// Sets the start position on the x axis.
		/// </summary>
		/// <param name="x">The new start position on the x axis.</param>
		public: void setX(int x);

		/// <summary>
		/// Returns the start position on the y axis.
		/// </summary>
		/// <returns>The start position on the y axis.</returns>
		public: int getY();

		/// <summary>
		/// Sets the start position on the y axis.
		/// </summary>
		/// <param name="y">The new start position on the y axis.</param>
		public: void setY(int y);

		/// <summary>
		/// Returns the opacity of the rectangle.
		/// </summary>
		/// <returns>The opacity of the rectangle.</returns>
		public: int getOpacity();

		/// <summary>
		/// Sets the opacity of the rectangle.
		/// </summary>
		/// <param name="opacity">The new opacity of the rectangle.</param>
		public: void setOpacity(int opacity);

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
}

#endif


