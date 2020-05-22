cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

set(BJ2020_PROJECT_NAME Blackjack2020)
project(${BJ2020_PROJECT_NAME})

# Include cmake configs
include(cmake/main.cmake)
include(cmake/libs.cmake)
include(cmake/tests.cmake)

# Setting up macro var for test build
if (CMAKE_BUILD_TYPE MATCHES Test)
    add_compile_definitions(BJ2020_TEST_MODE=TRUE)
endif()

# Setting up output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BJ2020_BIN_DIR})

# Linking headers
include_directories(${BJ2020_INCLUDE_DIR})

add_executable(${BJ2020_PROJECT_NAME}
        ${BJ2020_INCLUDE_DIR}/Application.h
        ${BJ2020_SOURCE_DIR}/Application.cpp
        ${BJ2020_INCLUDE_DIR}/AppTypes.h
        ${BJ2020_INCLUDE_DIR}/AppAliases.h
        ${BJ2020_INCLUDE_DIR}/AbstractBlackjack.h
        ${BJ2020_INCLUDE_DIR}/MockAbstractBlackjack.h
        ${BJ2020_SOURCE_DIR}/AbstractBlackjack.cpp
        ${BJ2020_INCLUDE_DIR}/AmericanBlackjack.h
        ${BJ2020_SOURCE_DIR}/AmericanBlackjack.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractBlackjackAction.h
        ${BJ2020_INCLUDE_DIR}/HitBlackjackAction.h
        ${BJ2020_SOURCE_DIR}/HitBlackjackAction.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractDisplayHandler.h
        ${BJ2020_INCLUDE_DIR}/MockDisplayHandler.h
        ${BJ2020_INCLUDE_DIR}/ConsoleDisplayHandler.h
        ${BJ2020_SOURCE_DIR}/ConsoleDisplayHandler.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractDisplayEntity.h
        ${BJ2020_INCLUDE_DIR}/MockDisplayEntity.h
        ${BJ2020_INCLUDE_DIR}/ConsoleDisplayEntity.h
        ${BJ2020_SOURCE_DIR}/ConsoleDisplayEntity.cpp
        ${BJ2020_INCLUDE_DIR}/AbstractInputAdapter.h
        ${BJ2020_INCLUDE_DIR}/MockInputAdapter.h
        ${BJ2020_INCLUDE_DIR}/ConsoleInputAdapter.h
        ${BJ2020_SOURCE_DIR}/ConsoleInputAdapter.cpp
        ${BJ2020_INCLUDE_DIR}/TemplateInputHandler.h
        ${BJ2020_INCLUDE_DIR}/MockInputHandler.h
        ${BJ2020_INCLUDE_DIR}/ConsoleInputHandler.h
        ${BJ2020_INCLUDE_DIR}/AbstractInputValidator.h
        ${BJ2020_INCLUDE_DIR}/TemplateInputValidator.h
        ${BJ2020_INCLUDE_DIR}/PlayerNameInputValidator.h
        ${BJ2020_INCLUDE_DIR}/PlayerStartCashInputValidator.h
        ${BJ2020_INCLUDE_DIR}/PlayerBetInputValidator.h
        ${BJ2020_INCLUDE_DIR}/ActionInputValidator.h
        ${BJ2020_INCLUDE_DIR}/Box.h
        ${BJ2020_SOURCE_DIR}/Box.cpp
        ${BJ2020_INCLUDE_DIR}/Player.h
        ${BJ2020_SOURCE_DIR}/Player.cpp
        ${BJ2020_INCLUDE_DIR}/Dealer.h
        ${BJ2020_SOURCE_DIR}/Dealer.cpp
        ${BJ2020_INCLUDE_DIR}/Card.h
        ${BJ2020_SOURCE_DIR}/Card.cpp
        ${BJ2020_SOURCE_DIR}/main.cpp src/HitBlackjackAction.cpp)