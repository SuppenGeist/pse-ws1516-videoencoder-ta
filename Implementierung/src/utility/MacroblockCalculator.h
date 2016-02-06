using namespace std;

#ifndef __MacroblockCalculator_h__
#define __MacroblockCalculator_h__

#include "../model/Video.h"
#include "../model/AVVideo.h"

namespace Model
{
    class Video;
	class AVVideo;
}
namespace Utility
{
	class MacroblockCalculator;
}

namespace Utility
{
	/**
	 * This class calculates the macroblocks of a video.
     */
	class MacroblockCalculator
	{
		private: Model::AVVideo* video;
        private: void ff_print_debug_info2(AVCodecContext *avctx, AVFrame *pict, uint8_t *mbskip_table,
                                           uint32_t *mbtype_table, int8_t *qscale_table, int16_t (*motion_val[2])[2],
                                           int *low_delay, int mb_width, int mb_height, int mb_stride, int quarter_sample);
        private: void ff_print_debug_info(MpegEncContext *s, Picture *p, AVFrame *pict);

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="video">The video to calculate the macroblocks for.</param>
        public: void MacroBlockCalculator(Model::AVVideo& video);

		/// <summary>
		/// Calculates the Video with macroblock overlay.
		/// </summary>
		/// <param name="target">The video the frames with the calculated macroblocks are added to.</param>
        public: void calculateMacroblockImages(Model::Video& target);
	};
}

#endif
