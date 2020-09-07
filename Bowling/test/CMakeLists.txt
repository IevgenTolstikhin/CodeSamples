find_package (GTest REQUIRED)

add_compile_definitions(UNIT_TEST)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../includes)
set (CMAKE_CXX_STANDARD 17)
set (GTEST_INCLUDE gtest gtest_main pthread)
set (UTILS_INC ../includes/Utils.h ../src/Utils.cpp)
set (FRAME_INC ${UTILS_INC} ../includes/Frame.h ../src/Frame.cpp)
set (GAME_INC ${FRAME_INC} ../includes/Game.h ../src/Game.cpp)
set (PLAYER_INC ${GAME_INC} ../includes/Player.h ../src/Player.cpp)
set (LANE_INC ${PLAYER_INC} ../includes/Lane.h ../src/Lane.cpp)

# Add test cpp file
add_executable(UtilsTest
    ${UTILS_INC}
    UtilsTest.cpp
)

add_executable (FrameTest
    ${FRAME_INC}
    FrameTest.cpp
)

add_executable (GameTest
    ${GAME_INC}
    GameTest.cpp
)

add_executable (PlayerTest
    ${PLAYER_INC}
    PlayerTest.cpp
)

add_executable (LaneTest
    ${LANE_INC}
    LaneTest.cpp
)

# Link test executable against gtest & gtest_main
target_link_libraries (UtilsTest ${GTEST_INCLUDE})
target_link_libraries (FrameTest ${GTEST_INCLUDE})
target_link_libraries (GameTest ${GTEST_INCLUDE})
target_link_libraries (PlayerTest ${GTEST_INCLUDE})
target_link_libraries (LaneTest ${GTEST_INCLUDE})
