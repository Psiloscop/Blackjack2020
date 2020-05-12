# Linking headers
include_directories(${BJ2020_INCLUDE_DIR})

# Linking sources
add_library(ABSTRACT_BLACKJACK_SOURCE ${BJ2020_SOURCE_DIR}/AbstractBlackjack.cpp)
#add_library(INPUT_HANDLER_SOURCE ${BJ2020_SOURCE_DIR}/AbstractInputHandler.cpp)
add_library(CARD_SOURCE ${BJ2020_SOURCE_DIR}/Card.cpp)
add_library(PLAYER_SOURCE ${BJ2020_SOURCE_DIR}/Player.cpp)

# Including test sources
include(cmake/tests/ApplicationUnitTest.cmake)
include(cmake/tests/AbstractBlackjackUnitTest.cmake)