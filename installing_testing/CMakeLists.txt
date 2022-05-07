cmake_minimum_required(VERSION 3.16.3)

project(optional_lib)

# specify main executable
add_executable(main main.cpp)

# Make libCollatz optional
option(USE_COLLATZ "Use the Collatz lib" ON)
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/stage")

# configure a header file to pass some of the CMake settings to the source code
configure_file(libCollatzConfig.h.in libCollatzConfig.h)

# include_directories(${CMAKE_SOURCE_DIR}/inc)
# link_directories(libcollatz)
# add_subdirectory(libcollatz)

if(USE_COLLATZ)
  # if use: add subdir, append lib to list of libs/includes to use below
  add_subdirectory(libcollatz)
  list(APPEND EXTRA_LIBS libcollatz)

  # lib properties
  set_target_properties(libcollatz PROPERTIES LINKER_LANGUAGE CXX)
endif()

# link to optional libs
target_link_libraries(main PUBLIC ${EXTRA_LIBS}) # libbar.so is found in ${CMAKE_SOURCE_DIR}/lib

# add the binary tree to the search path for include files so that we will find ilbCollatzConfig.h
target_include_directories(main PUBLIC
                            "${PROJECT_BINARY_DIR}"
                          )

# set compiler flags
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic -g")
SET(GCC_COVERAGE_LINK_FLAGS    "-v")

# add compiler flags
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# properties
set_property(TARGET main PROPERTY CXX_STANDARD 17)

# installation
install(TARGETS main DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/stage/include/libcollatz.h" DESTINATION include)

# Testing!
enable_testing()

# does the application run?
add_test(NAME Runs COMMAND main)

# define a function to simplify adding tests - end to end test
# function (do_test target arg result)