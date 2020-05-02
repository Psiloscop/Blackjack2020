cmake_minimum_required(VERSION 3.5)
project(BlackJack2020)

set(CMAKE_CXX_STANDARD 14)

include(cmake/main.cmake)
include(cmake/libs.cmake)
include(cmake/tests.cmake)

add_executable(BlackJack2020
        ${BJ2020_INCLUDE_DIR}/Application.h
        ${BJ2020_INCLUDE_DIR}/AppTypes.h
        ${BJ2020_INCLUDE_DIR}/AbstractBlackjack.h
        ${BJ2020_SOURCE_DIR}/AbstractBlackjack.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractBlackjackAction.h
        ${BJ2020_INCLUDE_DIR}/AbstractDisplayEntity.h
        ${BJ2020_INCLUDE_DIR}/AbstractDisplayHandler.h
        ${BJ2020_INCLUDE_DIR}/AbstractInputHandler.h
        ${BJ2020_SOURCE_DIR}/AbstractInputHandler.cpp
        ${BJ2020_INCLUDE_DIR}/ConsoleInputHandler.h
        ${BJ2020_SOURCE_DIR}/ConsoleInputHandler.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractInputValidator.h
        ${BJ2020_SOURCE_DIR}/AbstractInputValidator.cpp
        ${BJ2020_INCLUDE_DIR}/Card.h
        ${BJ2020_INCLUDE_DIR}/Box.h
        ${BJ2020_INCLUDE_DIR}/Player.h
        ${BJ2020_SOURCE_DIR}/Player.cpp
        ${BJ2020_SOURCE_DIR}/Card.cpp
        ${BJ2020_SOURCE_DIR}/main.cpp src/Application.cpp)