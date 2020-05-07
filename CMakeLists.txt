cmake_minimum_required(VERSION 3.5)
project(Blackjack2020)

set(CMAKE_CXX_STANDARD 17)

include(cmake/main.cmake)
include(cmake/libs.cmake)
include(cmake/tests.cmake)

# Setting up output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BJ2020_BIN_DIR})

add_executable(Blackjack2020
        ${BJ2020_INCLUDE_DIR}/BaseApplication.h
        ${BJ2020_SOURCE_DIR}/BaseApplication.cpp
        ${BJ2020_INCLUDE_DIR}/Application.h
        ${BJ2020_SOURCE_DIR}/Application.cpp
        ${BJ2020_INCLUDE_DIR}/AppTypes.h
        ${BJ2020_INCLUDE_DIR}/AbstractBlackjack.h
        ${BJ2020_SOURCE_DIR}/AbstractBlackjack.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractBlackjackAction.h
        ${BJ2020_INCLUDE_DIR}/BaseDisplayHandler.h
        ${BJ2020_INCLUDE_DIR}/AbstractDisplayHandler.h
        ${BJ2020_SOURCE_DIR}/AbstractDisplayHandler.cpp
        ${BJ2020_INCLUDE_DIR}/ConsoleDisplayHandler.h
        ${BJ2020_SOURCE_DIR}/ConsoleDisplayHandler.cpp
        ${BJ2020_INCLUDE_DIR}/BaseDisplayEntity.h
        ${BJ2020_INCLUDE_DIR}/AbstractDisplayEntity.h
        ${BJ2020_INCLUDE_DIR}/ConsoleDisplayEntity.h
        ${BJ2020_SOURCE_DIR}/ConsoleDisplayEntity.cpp
        ${BJ2020_INCLUDE_DIR}/BaseInputAdapter.h
        ${BJ2020_INCLUDE_DIR}/AbstractInputAdapter.h
        ${BJ2020_SOURCE_DIR}/AbstractInputAdapter.cpp
        ${BJ2020_INCLUDE_DIR}/ConsoleInputAdapter.h
        ${BJ2020_SOURCE_DIR}/ConsoleInputAdapter.cpp
        ${BJ2020_INCLUDE_DIR}/InputHandler.h
        ${BJ2020_SOURCE_DIR}/InputHandler.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractInputValidator.h
        ${BJ2020_SOURCE_DIR}/AbstractInputValidator.cpp
        ${BJ2020_INCLUDE_DIR}/PlayerNameInputValidator.h
        ${BJ2020_SOURCE_DIR}/PlayerNameInputValidator.cpp
        ${BJ2020_INCLUDE_DIR}/Card.h
        ${BJ2020_INCLUDE_DIR}/Box.h
        ${BJ2020_SOURCE_DIR}/Box.cpp
        ${BJ2020_INCLUDE_DIR}/Player.h
        ${BJ2020_SOURCE_DIR}/Player.cpp
        ${BJ2020_SOURCE_DIR}/Card.cpp
        ${BJ2020_SOURCE_DIR}/main.cpp)