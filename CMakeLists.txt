cmake_minimum_required(VERSION 3.16)

project(Challenge_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Challenge_2 main.cpp
    rednacional.h rednacional.cpp
    estacionservicio.h estacionservicio.cpp
    surtidor.h surtidor.cpp)

include(GNUInstallDirs)
install(TARGETS Challenge_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
