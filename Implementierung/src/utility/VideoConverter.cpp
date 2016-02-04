#include "VideoConverter.h"

static unique_ptr<QImage> convertAVFrameToQImage(AVFrame& frame, int width, int height) {

}

static unique_ptr<Model::Video> convertAVVideoToVideo(Model::AVVideo& avvideo) {
	unique_ptr<Model::Video> video = make_unique<Model::Video>(avvideo.getFps(), avvideo.getWidth(),
	                                 avvideo.getHeight());
	for(int i = 0; i < avvideo.getNumberOfFrames(); i++) {
		video->appendFrame(convertAVFrameToQImage(*avvideo.getFrame(i), avvideo.getWidth(),
		                   avvideo.getHeight()));
	}
	return video;
}

static unique_ptr<AVFrame> convertQImageToAVFrame(QImage& image) {

}

static unique_ptr<Model::AVVideo> convertVideoToAVVideo(Model::Video& video) {
	unique_ptr<Model::AVVideo> avvideo = make_unique<Model::AVVideo>(video.getFps(), video.getWidth(),
	                                     video.getHeight());
	for(int i = 0; i < video.getNumberOfFrames(); i++) {
		avvideo->insertFrame(convertQImageToAVFrame(*video.getFrame(i)), avvideo->getNumberOfFrames());
	}
	return avvideo;
}
