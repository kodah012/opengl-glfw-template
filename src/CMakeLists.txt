# add source files
set(SOURCES
    main.cpp
)

# add subdirectories for libraries
add_subdirectory(window)

# create executable target
add_executable(${TARGET_NAME} ${SOURCES})

# link libraries
target_link_libraries(${TARGET_NAME} PRIVATE
    window
)