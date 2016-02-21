#ifndef __YuvFileReader_h__
#define __YuvFileReader_h__

#include <memory>
#include <thread>

#include <QFile>
#include <QDataStream>

#include "../model/Video.h"

namespace Utility {

// This is the base class for all different yuv file readers.
class YuvFileReader {

  public:
	/**
	 * @brief YuvFileReader Constructor.
	 * @param filename The absolute path to the file to load.
	 * @param width The width of the video.
	 * @param height The height of the video.
	 */
	YuvFileReader(QString filename, int width, int height,int frameSize);

	~YuvFileReader();

	/**
	 * @brief read Reads the file in.
	 * @return The complete video.
	 */
	void read(Model::Video* target);

	void stopReading();

	bool isRunning();

  protected:
	virtual std::unique_ptr<QImage> parseNextFrame()=0;

	/**
	 * @brief clamp Clamps the given value to the range [0,255].
	 * @param value <param name="value">The value to clamp.</param>
	 * @return The clamped value.
	 */
	static int clamp(int value);

  protected:
	unsigned char*   binaryData_;
	QDataStream                    dataStream_;
    QFile                          file_;
	int                            width_;
	int                            height_;
	Model::Video*                  video_;
	int                            frameSize_;
	bool*                          complete_;

  private:
	bool                           isRunning_;
	std::thread                     reader_;

	void readP();

};
}

#endif

