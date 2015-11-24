### Yuv dateien abspielen

```
vlc --demux rawvideo --rawvid-fps 25 --rawvid-width 1920 --rawvid-height 1080 --rawvid-chroma I420 input.yuv
```
### Yuv to mp4
```
ffmpeg -f rawvideo -vcodec rawvideo -s 352x288 -r 25 -pix_fmt yuv420p -i akiyo_cif.yuv -c:v libx264 -preset ultrafast -qp 0 output.mp4
```
###  mp4 to yuv
```
ffmpeg -i input.mp4 -f rawvideo -vcodec rawvideo -pix_fmt yuv420p -s 1920x1080 -r 25 rawvideo.yuv
```
