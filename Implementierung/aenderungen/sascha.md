##YUVFileReader
added QFile, reason: Needed to open and read yuv file
added QByteArray, reason: needed as a buffer to read file
added std::unique_ptr<QImage> image, reason: needed to parse frames

##YUV444Vector
added getters to make attributes accessible 
added constructor


##YUV411Vector
added setters and getters 
made attributes private
added constructors

##YUV444Saver
add compression to attributes
make rgb888ToYuv444(QRgb pixel1) not static 

##YUV420Saver
remove saveFrame funtion 

##YUVFileSave
add static conversion methods, so they are in one place 
