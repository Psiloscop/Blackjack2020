# Linking headers
#include_directories(${BJ2020_TYPE_DIR})
#include_directories(${BJ2020_SYSTEM_DIR})

# Linking sources
#add_library(EXCEPTION_SOURCE ${BJ2020_SYSTEM_DIR}/CException.cpp)
#add_library(LINEAR_ALLOCATOR_SOURCE ${BJ2020_SYSTEM_DIR}/CLinearAllocator.cpp)
#add_library(STRING_SOURCE ${BJ2020_TYPE_DIR}/CString.cpp)
#add_library(ARRAY_SOURCE ${BJ2020_TYPE_DIR}/CArray.cpp)
#add_library(BASE_LINEAR_ALLOCATOR_SOURCE ${BJ2020_SYSTEM_DIR}/CBaseLinearAllocator.cpp)
add_library(ABSTRACT_BLACKJACK_SOURCE ${BJ2020_SOURCE_DIR}/AbstractBlackjack.cpp)
add_library(CARD_SOURCE ${BJ2020_SOURCE_DIR}/Card.cpp)

# Including test sources
#include(cmake/tests/CSharedPointerUnitTest.cmake)
#include(cmake/tests/CLinearAllocatorUnitTest.cmake)
#include(cmake/tests/CArrayUnitTest.cmake)
#include(cmake/tests/CStringUnitTest.cmake)
include(cmake/tests/AbstractBlackjackUnitTest.cmake)