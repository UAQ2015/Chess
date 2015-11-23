cmake_minimum_required(VERSION 3.3)
project(Chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bishop.cpp
    bishop.h
    chessboard.cpp
    chessboard.h
    king.cpp
    king.h
    knight.cpp
    knight.h
    main.cpp
    pawn.cpp
    pawn.h
    piece.cpp
    piece.h
    queen.cpp
    queen.h
    rook.cpp
    rook.h)

add_executable(Chess ${SOURCE_FILES})