greaterThan(QT_MAJOR_VERSION, 5)

QT+= core gui widgets

CONFIG+=c++14

HEADERS += \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/AnalysisBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/AnalysisBoxContainer.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/AnalysisTab.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/ControlPanel.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterConfigurationBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterContainerTab.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterTab.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterView.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/ForwardPlayer.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FrameView.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/GlobalControlPanel.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/GraphWidget.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/MainWindow.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/Player.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/PlayerControlPanel.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/PreviewControlPanel.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/Timer.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/VideoPlayer.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/YuvFileOpenDialog.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/YuvInfoDialog.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BlendingFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BlurFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BorderFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BrightnessFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ColorbalanceFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ContrastFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/FilterConfigurationBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/GridFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/MirrorFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/NoiseFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/PlainFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/PosterFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/RectangleFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/RGBFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/RotationFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/SaturationFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ScaleFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/SharpnessFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ZoomFilterBox.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/AnalysisBoxContainerMemento.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/AnalysisBoxMemento.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/AnalysisTabMemento.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/FilterTabMemento.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/MainWindowMemento.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/AVVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/EncodedVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/FilterList.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/Graph.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/MirrorMode.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/NoiseMode.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/Project.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/Video.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/YuvVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BlackWhiteFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BlendingFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BlurFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BorderFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BrightnessFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ColorbalanceFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ContrastFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/EdgeFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/Filter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/GridFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/MirrorFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/NegativeFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/NoiseFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/PosterFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/RectangleFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/RGBFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/RotationFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/SaturationFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ScaleFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/SepiaFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/SharpnessFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/VintageFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ZoomFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/AddFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/AddVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/ApplyFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/FilterReset.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/LoadAnalysisVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/LoadFilterconfig.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/LoadFilterVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/MoveFilterDown.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/MoveFilterUp.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/RemoveFilter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/RemoveVideo.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/UndoStack.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/WriteComment.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/BasicColor.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/BitrateCalculator.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Compression.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/FilterApplier.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/FilterConfigurationLoader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/FilterConfigurationSaver.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/MacroblockCalculator.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/PixelSheme.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/ProjectReader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/ProjectWriter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/PsnrCalculator.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/RGBDifferenceCalculator.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/RGBHistogrammCalculator.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/VideoConverter.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/VideoLoader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv411FileReader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv411FileSaver.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv411Vector.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv420FIleReader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv420FileSaver.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv422FileReader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv422FileSaver.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv422Vector.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv444FileReader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv444FileSaver.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv444Vector.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/YuvFileReader.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/YuvFileSaver.h \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/YuvType.h

SOURCES += \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/AnalysisBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/AnalysisBoxContainer.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/AnalysisTab.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/ControlPanel.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterConfigurationBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterContainerTab.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterTab.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FilterView.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/ForwardPlayer.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/FrameView.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/GlobalControlPanel.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/GraphWidget.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/MainWindow.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/Player.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/PlayerControlPanel.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/PreviewControlPanel.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/Timer.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/VideoPlayer.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/YuvFileOpenDialog.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/YuvInfoDialog.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BlendingFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BlurFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BorderFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/BrightnessFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ColorbalanceFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ContrastFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/FilterConfigurationBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/GridFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/MirrorFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/NoiseFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/PlainFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/PosterFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/RectangleFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/RGBFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/RotationFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/SaturationFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ScaleFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/SharpnessFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/gui/filter_boxes/ZoomFilterBox.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/AnalysisBoxContainerMemento.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/AnalysisBoxMemento.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/AnalysisTabMemento.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/FilterTabMemento.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/memento/MainWindowMemento.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/AVVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/EncodedVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/FilterList.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/Graph.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/MirrorMode.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/NoiseMode.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/Project.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/Video.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/YuvVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BlackWhiteFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BlendingFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BlurFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BorderFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/BrightnessFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ColorbalanceFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ContrastFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/EdgeFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/Filter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/GridFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/MirrorFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/NegativeFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/NoiseFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/PosterFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/RectangleFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/RGBFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/RotationFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/SaturationFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ScaleFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/SepiaFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/SharpnessFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/VintageFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/model/filters/ZoomFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/AddFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/AddVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/ApplyFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/FilterReset.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/LoadAnalysisVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/LoadFilterconfig.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/LoadFilterVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/MoveFilterDown.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/MoveFilterUp.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/RemoveFilter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/RemoveVideo.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/UndoStack.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/undo_framework/WriteComment.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/BitrateCalculator.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Compression.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/FilterApplier.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/FilterConfigurationLoader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/FilterConfigurationSaver.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/MacroblockCalculator.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/PixelSheme.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/ProjectReader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/ProjectWriter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/PsnrCalculator.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/RGBDifferenceCalculator.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/RGBHistogrammCalculator.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/VideoConverter.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/VideoLoader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv411FileReader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv411FileSaver.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv411Vector.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv420FIleReader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv420FileSaver.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv422FileReader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv422FileSaver.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv422Vector.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv444FileReader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv444FileSaver.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/Yuv444Vector.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/YuvFileReader.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/YuvFileSaver.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/utility/YuvType.cpp \
    ../../PSE/pse-ws1516-videoencoder-ta/Implementierung/src/main.cc