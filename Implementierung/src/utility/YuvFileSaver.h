#ifndef __YuvFileSaver_h__
#define __YuvFileSaver_h__

#include <QFile>
#include <QDataStream>
#include <QColor>

namespace Model {
class Video;
}

namespace Utility {
/**
 * This is the base class for yuv savers.
 */
class YuvFileSaver {
  public:
	/**
	 * @brief YuvFileSaver Constructor.
	 * @param filename Absolute path to the file to save to.
	 * @param video The video to save.
	 */
	YuvFileSaver(QString filename, Model::Video& video);

	/**
	 * @brief ~YuvFileSaver Destructor.
	 */
	virtual ~YuvFileSaver();

	/**
	 * @brief save Saves the video to the file.
	 */
	virtual void save() = 0;

  protected:
	int             width_;
	int             height_;
	Model::Video*   video_;
	QFile           file_;
	QDataStream     dataStream_;

    static int RgbToY(QRgb pixel);
    static int RgbToU(QRgb pixel);
    static int RgbToV(QRgb pixel);
};
}

#endif
