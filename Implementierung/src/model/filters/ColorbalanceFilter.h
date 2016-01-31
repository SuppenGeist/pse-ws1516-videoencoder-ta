#include <exception>
#include <string>
using namespace std;

#ifndef __ColorbalanceFilter_h__
#define __ColorbalanceFilter_h__

#include "../../Utility/BasicColor.h"
#include "Filter.h"

namespace Model
{
	// enum BasicColor;
	// class Filter;
	class ColorbalanceFilter;
}

namespace Model
{
	/**
	 * Adjusts the colorbalance of the video for the 3 basic colors.
    */
	class ColorbalanceFilter: public Model::Filter
	{
		private: int intensity;
		private: bool brightPixels;
		private: bool mediumPixels;
		private: bool darkPixels;
		private: Model::BasicColor* color;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ColorbalanceFilter();

		/// <summary>
		/// Returns the color whose balance is to be changed.
		/// </summary>
		/// <returns>The color to change.</returns>
		public: Model::BasicColor getColor();

		/// <summary>
		/// Sets the color whose balance shall be changed.
		/// </summary>
		/// <param name="color">The color to change.</param>
		public: void setColor(Model::BasicColor color);

		/// <summary>
		/// Returns the intensity of the change,
		/// </summary>
		/// <returns>The intensity.</returns>
		public: int getIntensity();

		/// <summary>
		/// Sets the intensity of the change.
		/// </summary>
		/// <param name="intensity">The intensity.</param>
		public: void setIntensity(int intensity);

		/// <summary>
		/// Whether the bright pixels shall be changed.
		/// </summary>
		/// <returns>True if the bright pixels are changed.</returns>
		public: bool getBrightPixels();

		/// <summary>
		/// Sets whether the bright pixels shall be changed.
		/// </summary>
		/// <param name="brightPixels">True if the bright pixels shall be changed.</param>
		public: void setBrightPixels(bool brightPixels);

		/// <summary>
		/// Whether the medium pixels shall be changed.
		/// </summary>
		/// <returns>True if the medium pixels are changed.</returns>
		public: bool getMediumPixels();

		/// <summary>
		/// Sets whether the medium pixels shall be changed.
		/// </summary>
		/// <param name="mediumPixels">True if the medium pixels are changed.</param>
		public: void setMediumPixels(bool mediumPixels);

		public: string getFilterDescription();

		public: string getName();

		/// <summary>
		/// Whether the drak pixels shall be changed.
		/// </summary>
		/// <returns>True if the dark pixels are changed.</returns>
		public: bool getDarkPixels();

		/// <summary>
		/// Sets whether the dark pixels shall be changed.
		/// </summary>
		/// <param name="darkPixels">True if the dark pixels are changed.</param>
		public: void setDarkPixels(bool darkPixels);
	};
}

#endif


