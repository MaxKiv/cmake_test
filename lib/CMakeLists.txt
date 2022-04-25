cmake_minimum_required(VERSION 3.16.3)

project(lib)


# include_directories(${CMAKE_SOURCE_DIR}/inc)
# link_directories(${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(libpower)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC libpower) # libbar.so is found in ${CMAKE_SOURCE_DIR}/lib
target_include_directories(main PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/libpower"
                          )


SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
SET(GCC_COVERAGE_LINK_FLAGS    "-v")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set_property(TARGET main PROPERTY CXX_STANDARD 17)
set_target_properties(libpower PROPERTIES LINKER_LANGUAGE CXX)
