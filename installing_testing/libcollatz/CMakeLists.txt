add_library(libcollatz libcollatz.h)
target_include_directories(libcollatz INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS libcollatz DESTINATION lib)
install(FILES libcollatz.h DESTINATION include)