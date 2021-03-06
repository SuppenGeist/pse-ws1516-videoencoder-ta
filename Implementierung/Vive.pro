greaterThan(QT_MAJOR_VERSION, 5)

QT+= core gui widgets

QMAKE_CXXFLAGS += -std=c++14 -pthread
LIBS += -pthread

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libavcodec

unix: PKGCONFIG += libavformat
unix: PKGCONFIG += libavfilter

unix: PKGCONFIG += libavutil
unix: PKGCONFIG += libswscale

unix: LIBS += -ldl

HEADERS += \
    src/gui/AnalysisBox.h \
    src/gui/AnalysisBoxContainer.h \
    src/gui/AnalysisTab.h \
    src/gui/ControlPanel.h \
    src/gui/FilterContainerTab.h \
    src/gui/FilterTab.h \
    src/gui/FilterView.h \
    src/gui/ForwardPlayer.h \
    src/gui/FrameView.h \
    src/gui/GlobalControlPanel.h \
    src/gui/GraphWidget.h \
    src/gui/MainWindow.h \
    src/gui/Player.h \
    src/gui/PlayerControlPanel.h \
    src/gui/PreviewControlPanel.h \
    src/gui/Timer.h \
    src/gui/VideoPlayer.h \
    src/gui/YuvFileOpenDialog.h \
    src/gui/YuvInfoDialog.h \
    src/gui/filter_boxes/BlurFilterBox.h \
    src/gui/filter_boxes/BorderFilterBox.h \
    src/gui/filter_boxes/BrightnessFilterBox.h \
    src/gui/filter_boxes/ColorbalanceFilterBox.h \
    src/gui/filter_boxes/ContrastFilterBox.h \
    src/gui/filter_boxes/FilterConfigurationBox.h \
    src/gui/filter_boxes/GridFilterBox.h \
    src/gui/filter_boxes/MirrorFilterBox.h \
    src/gui/filter_boxes/NoiseFilterBox.h \
    src/gui/filter_boxes/PlainFilterBox.h \
    src/gui/filter_boxes/PosterFilterBox.h \
    src/gui/filter_boxes/RectangleFilterBox.h \
    src/gui/filter_boxes/RGBFilterBox.h \
    src/gui/filter_boxes/RotationFilterBox.h \
    src/gui/filter_boxes/SaturationFilterBox.h \
    src/gui/filter_boxes/ScaleFilterBox.h \
    src/gui/filter_boxes/SharpnessFilterBox.h \
    src/memento/AnalysisBoxContainerMemento.h \
    src/memento/AnalysisBoxMemento.h \
    src/memento/AnalysisTabMemento.h \
    src/memento/FilterTabMemento.h \
    src/memento/MainWindowMemento.h \
    src/model/AVVideo.h \
    src/model/EncodedVideo.h \
    src/model/FilterList.h \
    src/model/Graph.h \
    src/model/MirrorMode.h \
    src/model/NoiseMode.h \
    src/model/Project.h \
    src/model/Video.h \
    src/model/YuvVideo.h \
    src/model/filters/BlurFilter.h \
    src/model/filters/BorderFilter.h \
    src/model/filters/BrightnessFilter.h \
    src/model/filters/ColorbalanceFilter.h \
    src/model/filters/ContrastFilter.h \
    src/model/filters/EdgeFilter.h \
    src/model/filters/Filter.h \
    src/model/filters/GridFilter.h \
    src/model/filters/MirrorFilter.h \
    src/model/filters/NegativeFilter.h \
    src/model/filters/NoiseFilter.h \
    src/model/filters/PosterFilter.h \
    src/model/filters/RectangleFilter.h \
    src/model/filters/RGBFilter.h \
    src/model/filters/RotationFilter.h \
    src/model/filters/SaturationFilter.h \
    src/model/filters/ScaleFilter.h \
    src/model/filters/SepiaFilter.h \
    src/model/filters/SharpnessFilter.h \
    src/model/filters/VintageFilter.h \
    src/undo_framework/AddFilter.h \
    src/undo_framework/AddVideo.h \
    src/undo_framework/FilterReset.h \
    src/undo_framework/LoadAnalysisVideo.h \
    src/undo_framework/LoadFilterconfig.h \
    src/undo_framework/LoadFilterVideo.h \
    src/undo_framework/MoveFilterDown.h \
    src/undo_framework/MoveFilterUp.h \
    src/undo_framework/RemoveFilter.h \
    src/undo_framework/RemoveVideo.h \
    src/undo_framework/UndoStack.h \
    src/undo_framework/WriteComment.h \
    src/utility/BasicColor.h \
    src/utility/BitrateCalculator.h \
    src/utility/Compression.h \
    src/utility/FilterApplier.h \
    src/utility/FilterConfigurationLoader.h \
    src/utility/FilterConfigurationSaver.h \
    src/utility/ProjectReader.h \
    src/utility/ProjectWriter.h \
    src/utility/PsnrCalculator.h \
    src/utility/RGBDifferenceCalculator.h \
    src/utility/RGBHistogramCalculator.h \
    src/utility/VideoConverter.h \
    src/utility/VideoLoader.h \
    src/utility/Yuv411FileReader.h \
    src/utility/Yuv411FileSaver.h \
    src/utility/Yuv411Vector.h \
    src/utility/Yuv420FileSaver.h \
    src/utility/Yuv422FileReader.h \
    src/utility/Yuv422FileSaver.h \
    src/utility/Yuv422Vector.h \
    src/utility/Yuv444FileReader.h \
    src/utility/Yuv444FileSaver.h \
    src/utility/Yuv444Vector.h \
    src/utility/YuvFileReader.h \
    src/utility/YuvFileSaver.h \
    src/utility/YuvType.h \
    src/utility/Yuv420FileReader.h \
    src/model/filters/GrayscaleFilter.h \
    src/undo_framework/changefilter.h \
    src/model/graphvideo.h \
    src/gui/graphplayer.h \
    src/utility/VideoSaver.h \
    src/utility/resultsaver.h \
    src/gui/graphcalculator.h \
    src/gui/analysisvideo.h \
    src/gui/analysisgraph.h

SOURCES += \
    src/gui/AnalysisBox.cpp \
    src/gui/AnalysisBoxContainer.cpp \
    src/gui/AnalysisTab.cpp \
    src/gui/ControlPanel.cpp \
    src/gui/FilterContainerTab.cpp \
    src/gui/FilterTab.cpp \
    src/gui/FilterView.cpp \
    src/gui/ForwardPlayer.cpp \
    src/gui/FrameView.cpp \
    src/gui/GlobalControlPanel.cpp \
    src/gui/GraphWidget.cpp \
    src/gui/MainWindow.cpp \
    src/gui/PlayerControlPanel.cpp \
    src/gui/PreviewControlPanel.cpp \
    src/gui/Timer.cpp \
    src/gui/VideoPlayer.cpp \
    src/gui/YuvFileOpenDialog.cpp \
    src/gui/YuvInfoDialog.cpp \
    src/gui/filter_boxes/BlurFilterBox.cpp \
    src/gui/filter_boxes/BorderFilterBox.cpp \
    src/gui/filter_boxes/BrightnessFilterBox.cpp \
    src/gui/filter_boxes/ColorbalanceFilterBox.cpp \
    src/gui/filter_boxes/ContrastFilterBox.cpp \
    src/gui/filter_boxes/FilterConfigurationBox.cpp \
    src/gui/filter_boxes/GridFilterBox.cpp \
    src/gui/filter_boxes/MirrorFilterBox.cpp \
    src/gui/filter_boxes/NoiseFilterBox.cpp \
    src/gui/filter_boxes/PlainFilterBox.cpp \
    src/gui/filter_boxes/PosterFilterBox.cpp \
    src/gui/filter_boxes/RectangleFilterBox.cpp \
    src/gui/filter_boxes/RGBFilterBox.cpp \
    src/gui/filter_boxes/RotationFilterBox.cpp \
    src/gui/filter_boxes/SaturationFilterBox.cpp \
    src/gui/filter_boxes/ScaleFilterBox.cpp \
    src/gui/filter_boxes/SharpnessFilterBox.cpp \
    src/memento/AnalysisBoxContainerMemento.cpp \
    src/memento/AnalysisBoxMemento.cpp \
    src/memento/AnalysisTabMemento.cpp \
    src/memento/FilterTabMemento.cpp \
    src/memento/MainWindowMemento.cpp \
    src/model/AVVideo.cpp \
    src/model/EncodedVideo.cpp \
    src/model/FilterList.cpp \
    src/model/Graph.cpp \
    src/model/MirrorMode.cpp \
    src/model/NoiseMode.cpp \
    src/model/Project.cpp \
    src/model/Video.cpp \
    src/model/YuvVideo.cpp \
    src/model/filters/BlurFilter.cpp \
    src/model/filters/BorderFilter.cpp \
    src/model/filters/BrightnessFilter.cpp \
    src/model/filters/ColorbalanceFilter.cpp \
    src/model/filters/ContrastFilter.cpp \
    src/model/filters/EdgeFilter.cpp \
    src/model/filters/Filter.cpp \
    src/model/filters/GridFilter.cpp \
    src/model/filters/MirrorFilter.cpp \
    src/model/filters/NegativeFilter.cpp \
    src/model/filters/NoiseFilter.cpp \
    src/model/filters/PosterFilter.cpp \
    src/model/filters/RectangleFilter.cpp \
    src/model/filters/RGBFilter.cpp \
    src/model/filters/RotationFilter.cpp \
    src/model/filters/SaturationFilter.cpp \
    src/model/filters/ScaleFilter.cpp \
    src/model/filters/SepiaFilter.cpp \
    src/model/filters/SharpnessFilter.cpp \
    src/model/filters/VintageFilter.cpp \
    src/undo_framework/AddFilter.cpp \
    src/undo_framework/AddVideo.cpp \
    src/undo_framework/FilterReset.cpp \
    src/undo_framework/LoadAnalysisVideo.cpp \
    src/undo_framework/LoadFilterconfig.cpp \
    src/undo_framework/LoadFilterVideo.cpp \
    src/undo_framework/MoveFilterDown.cpp \
    src/undo_framework/MoveFilterUp.cpp \
    src/undo_framework/RemoveFilter.cpp \
    src/undo_framework/RemoveVideo.cpp \
    src/undo_framework/UndoStack.cpp \
    src/undo_framework/WriteComment.cpp \
    src/utility/BitrateCalculator.cpp \
    src/utility/FilterApplier.cpp \
    src/utility/FilterConfigurationLoader.cpp \
    src/utility/FilterConfigurationSaver.cpp \
    src/utility/ProjectReader.cpp \
    src/utility/ProjectWriter.cpp \
    src/utility/PsnrCalculator.cpp \
    src/utility/RGBDifferenceCalculator.cpp \
    src/utility/RGBHistogramCalculator.cpp \
    src/utility/VideoConverter.cpp \
    src/utility/VideoLoader.cpp \
    src/utility/Yuv411FileReader.cpp \
    src/utility/Yuv411FileSaver.cpp \
    src/utility/Yuv420FileSaver.cpp \
    src/utility/Yuv422FileReader.cpp \
    src/utility/Yuv422FileSaver.cpp \
    src/utility/Yuv444FileReader.cpp \
    src/utility/Yuv444FileSaver.cpp \
    src/utility/Yuv444Vector.cpp \
    src/utility/YuvFileReader.cpp \
    src/utility/YuvFileSaver.cpp \
    src/main.cpp \
    src/utility/Yuv422Vector.cpp \
    src/utility/Yuv420FileReader.cpp \
    src/utility/Yuv411Vector.cpp \
    src/model/filters/GrayscaleFilter.cpp \
    src/undo_framework/changefilter.cpp \
    src/model/graphvideo.cpp \
    src/gui/graphplayer.cpp \
    src/utility/BasicColor.cpp \
    src/utility/VideoSaver.cpp \
    src/utility/resultsaver.cpp \
    src/gui/graphcalculator.cpp

RESOURCES += \
    resources.qrc \

FORMS += \
    resources/forms/mainwindow.ui \
    resources/forms/analysistab.ui \
    resources/forms/analysisbox.ui \
    resources/forms/analysisboxcontainer.ui
