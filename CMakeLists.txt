cmake_minimum_required(VERSION 3.19)
project(Coursework LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui)

configure_file(
    ${CMAKE_SOURCE_DIR}/chrysuni.ttf
    ${CMAKE_BINARY_DIR}/chrysuni.ttf
    COPYONLY
)

add_executable(Coursework
    src/main.cpp
    src/prototypes.h
    src/word.cpp
    src/commandlineparse.cpp
    src/wordstats.cpp
    src/wordcloudgenerator.cpp
    src/wordplace.cpp
    src/imagerenderer.cpp
)

#поиск заголовков
target_include_directories(Coursework
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Coursework
    PRIVATE
        Qt::Core
        Qt::Gui
)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(CourseworkTests
    tests/tests.cpp
    src/prototypes.h
    src/word.cpp
    src/commandlineparse.cpp
    src/wordstats.cpp
    src/wordcloudgenerator.cpp
    src/wordplace.cpp
    src/imagerenderer.cpp
)

target_include_directories(CourseworkTests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(CourseworkTests
    PRIVATE
        Qt::Core
        Qt::Gui
        GTest::gtest
)
