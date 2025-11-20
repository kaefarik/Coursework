cmake_minimum_required(VERSION 3.19)
project(Coursework LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui)

add_executable(Coursework
    main.cpp
    prototypes.h
    classes.cpp
    commandlineparser.cpp
)

target_link_libraries(Coursework
    PRIVATE
        Qt::Core
        Qt::Gui
)

include(GNUInstallDirs)
install(TARGETS Coursework
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
