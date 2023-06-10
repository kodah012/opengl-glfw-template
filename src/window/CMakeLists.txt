add_library(window STATIC)

target_sources(window PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lib.cpp
)

target_include_directories(window PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lib.hpp
)