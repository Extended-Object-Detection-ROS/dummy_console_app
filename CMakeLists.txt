cmake_minimum_required(VERSION 2.8.9)
project (dummy_console_app)

add_compile_options(-std=c++11)

find_package(OpenCV REQUIRED)  

set(igraph OFF)

set( tinyxml_srcs tinyxml/tinyxml.cpp tinyxml/tinyxmlparser.cpp tinyxml/tinyxmlerror.cpp tinyxml/tinystr.cpp )

set( eod_srcs
    src/lib/ObjectBase.cpp
    # types
    src/lib/types/ComplexObjectGraph.cpp
    src/lib/types/ComplexObject.cpp
    src/lib/types/ExtendedObjectInfo.cpp
    src/lib/types/Attribute.cpp
    src/lib/types/SimpleObject.cpp
    src/lib/types/Tracker.cpp
    src/lib/types/Relationship.cpp
    src/lib/types/Filtering.cpp
    src/lib/types/Clusterization.cpp
    # lib utils
    src/lib/utils/geometry_utils.cpp
    src/lib/utils/drawing_utils.cpp
    src/lib/utils/contour_utils.cpp
    # lib detectors
    src/lib/detectors/HsvColorDetector.cpp
    src/lib/detectors/HaarCascadeDetector.cpp
    src/lib/detectors/SizeDetector.cpp
    src/lib/detectors/HistColorDetector.cpp
    src/lib/detectors/DimentionDetector.cpp
    src/lib/detectors/HoughDetector.cpp
    src/lib/detectors/BasicMotionDetector.cpp
    src/lib/detectors/ArucoDetector.cpp
    src/lib/detectors/PoseDetector.cpp
    src/lib/detectors/TensorFlowDetector.cpp
    src/lib/detectors/FeatureDetector.cpp
    src/lib/detectors/DnnDetector.cpp
    src/lib/detectors/QrDetector.cpp
    src/lib/detectors/QrZbarDetector.cpp
    src/lib/detectors/LogicDetector.cpp
    src/lib/detectors/BlobDetector.cpp
    src/lib/detectors/DepthDetector.cpp
    src/lib/detectors/RoughDistanceDetector.cpp
    src/lib/detectors/DistanceDetector.cpp
    src/lib/detectors/FaceDlibDetector.cpp
    src/lib/detectors/ExtractedInfoIdChecker.cpp
    src/lib/detectors/ExtractedInfoStringChecker.cpp

    # lib relations
    src/lib/relations/ImageRangeRelation.cpp
    src/lib/relations/LogicRelations.cpp
    src/lib/relations/ThreeDimRangeRelation.cpp
    src/lib/relations/SpaceRelations.cpp
    src/lib/relations/SizeRelations.cpp
    )

add_executable(dummy_console_app 
    src/main.cpp
    eod_srcs
    tinyxml_srcs
    )

target_include_directories(dummy_console_app
    PRIVATE    
    src/lib/include
    src/lib/detectors/include
    src/lib/relations/include
    src/lib/utils/include
    src/lib/types/include
    ${OpenCV_INCLUDE_DIRS}
    src/tinyxml
    )
    
target_link_libraries(dummy_console_app  
    ${OpenCV_LIBRARIES}  
)
