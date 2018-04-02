cmake_minimum_required(VERSION 3.10)

project(traysample)

find_package(Qt5Widgets REQUIRED)

if (Qt5Widgets_FOUND)
    if (Qt5Widgets_VERSION VERSION_LESS 5.7.0)
        message(STATUS "Qt version ${Qt5Widgets_VERSION}")
        message(WARNING "Minimum supported Qt5 version is 5.7!")
    endif()
endif(Qt5Widgets_FOUND)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

set(SRC_FILES
    # Sources
    src/mainwindow.cpp
    src/main.cpp

    # Headers
    src/mainwindow.h
)
qt5_wrap_ui(UI_HEADERS
    # Dialogs
    src/mainwindow.ui)

qt5_add_resources(QRES
    resources/traysample.qrc)

set(APP_DEPS
    ${SRC_FILES}
    ${UI_HEADERS}
    ${MOC_HEADERS}
    ${QRES})

set(QT_LIBS
    Qt5::Widgets)

add_executable(traysample ${APP_DEPS})
target_link_libraries(traysample ${QT_LIBS})
