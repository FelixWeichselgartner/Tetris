cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES Tetris_en_US.ts)

if(ANDROID)
  add_library(Tetris SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    mainwindow2.cpp
    mainwindow2.h
    mainwindow2.ui
    mainwindow3.cpp
    mainwindow3.h
    mainwindow3.ui
    Highscore.hpp
    Highscore.cpp
    highscoreausgabe.cpp
    highscoreausgabe.h
    highscoreausgabe.ui
    Event.hpp
    Tetris.cpp
    Tetris.hpp
    Tetromino.cpp
    Tetromino.hpp
    Node.hpp
    Field.hpp
    ProtectedInt.hpp
    output_playing_field.cpp
    output_playing_field.h
    ${TS_FILES}
  )
else()
  add_executable(Tetris
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    mainwindow2.cpp
    mainwindow2.h
    mainwindow2.ui
    mainwindow3.cpp
    mainwindow3.h
    mainwindow3.ui
    Highscore.hpp
    Highscore.cpp
    highscoreausgabe.cpp
    highscoreausgabe.h
    highscoreausgabe.ui
    Event.hpp
    Tetris.cpp
    Tetris.hpp
    Tetromino.cpp
    Tetromino.hpp
    Node.hpp
    Field.hpp
    ProtectedInt.hpp
    output_playing_field.cpp
    output_playing_field.h
    ${TS_FILES}
  )
endif()

if(WIN32)
    target_link_libraries(Tetris PRIVATE Qt5::Widgets)
else()
    target_link_libraries(Tetris PRIVATE Qt5::Widgets libpthread.so.0)
endif()

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
