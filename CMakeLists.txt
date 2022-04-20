cmake_minimum_required(VERSION 3.20)
project(my_gas)

set(CMAKE_CXX_STANDARD 17)


set(SFML_DIR C:/SFML/SFML-2.5.1)
set(SFML_ROOT ${SFML_DIR})
set(CMAKE_MODULE_PATH "${SFML_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/SFML-2.5.1/include)
add_executable(my_gas
        main.cpp particle.h vector.h vector.cpp particle.cpp molecule.cpp molecule.h point.cpp point.h gas_cube.cpp gas_cube.h main_cube.cpp main_cube.h parser.cpp parser.h)
target_link_libraries(my_gas sfml-graphics sfml-system sfml-window)