cmake_minimum_required(VERSION 2.8)

project(toaster-lib CXX)

find_package(Boost REQUIRED COMPONENTS)# system)
include_directories(${Boost_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/Tools)

file(GLOB toaster_src ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/Tools/*.cpp)
add_library(toaster SHARED ${toaster_src})

install(TARGETS toaster LIBRARY DESTINATION lib)
file(GLOB toaster_headers ${PROJECT_SOURCE_DIR}/include/*.h ${PROJECT_SOURCE_DIR}/include/Tools/*.h)
install(FILES ${toaster_headers} DESTINATION include/toaster-lib)
