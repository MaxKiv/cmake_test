cmake_minimum_required(VERSION 3.16.3)

project(BOT)

# optional libs
option(USE_LIBTIMON "use the libtimon biglib ofcourse why not??" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(libtimonconfig.h.in libtimonconfig.h)

# optional
if(USE_LIBTIMON)
    add_subdirectory(libtimon)
    list(APPEND EXTRA_LIBS libtimon)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/libtimon")
endif()

#add exe
add_executable(main main.cpp)

# link lib
target_link_libraries(main PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )