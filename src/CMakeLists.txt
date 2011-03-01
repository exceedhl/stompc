set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

aux_source_directory(. SOURCES)
add_executable(${PROJECT_NAME} ${SOURCES})