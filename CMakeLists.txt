cmake_minimum_required(VERSION 3.24)
project(QtImageProcess)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
include_directories(QtImageProcess headers)
set(CMAKE_PREFIX_PATH C:\\Qt\\6.6.0\\mingw_64\\bin)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)
set(OpenCV_DIR C:\\development_tools\\opencv\\cmake-build-release-mingw\\install)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QtImageProcess sources/main.cpp
        headers/globe_define_words.h
        headers/based.hpp
        ui/icons/resources.qrc
        sources/based.cpp
        headers/ui_mainwindow.h
        headers/mainWindow.h
        sources/mainWindow.cpp
        headers/manipulator.hpp
        headers/util.hpp
        headers/ui_histogramdialog.h
        headers/HistogramDialog.hpp
        sources/util.cpp
        sources/histogram_dialog.cpp
        headers/segmentation_manipulator.hpp
        sources/segmentation_manipulator.cpp
        sources/manipulator.cpp
        headers/frequency_manipulator.hpp
        sources/frequency_manipulator.cpp
        headers/dimension_manipulator.hpp
        sources/dimension_manipulator.cpp
        headers/morphology_manipulator.hpp
        sources/morphology_manipulator.cpp
        headers/ui_add_noise_dialog.h
        headers/noise_dialog.hpp
        sources/noise_dialog.cpp
        headers/license_recognition_dialog.hpp
        sources/licence_recognition_dialog.cpp
        headers/ui_licence_recognition_dialog.h
        headers/licence_recognition_util.hpp
        sources/licence_recognition_util.cpp
        headers/arts_manipulator.hpp
        sources/arts_manipulator.cpp
)

target_link_libraries(QtImageProcess
        Qt::Core
        Qt::Gui
        Qt::Widgets
        ${OpenCV_LIBS}
        winmm
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
