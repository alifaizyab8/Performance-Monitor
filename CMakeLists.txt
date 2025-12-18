cmake_minimum_required(VERSION 3.16)

project(Performance-Monitor VERSION 0.1 LANGUAGES CXX)

# This application uses Windows-specific APIs (pdh.h).
if(NOT WIN32)
    message(FATAL_ERROR "This project is only supported on Windows.")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    monitor.cpp
    monitor.h
)

qt_add_executable(Performance-Monitor
    MANUAL_FINALIZATION
    WIN32
    ${PROJECT_SOURCES}
)

target_link_libraries(Performance-Monitor
    PRIVATE
    Qt6::Widgets
    Qt6::Charts
    Pdh
)

include(GNUInstallDirs)
install(TARGETS Performance-Monitor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(Performance-Monitor)
