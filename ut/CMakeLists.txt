set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(UNIT_TEST_LIB_HOME "${PROJECT_SOURCE_DIR}/vendor/UnitTest++")

aux_source_directory(. TEST_SOURCES)
set(SOURCES ../src/scs.c ../src/stomp.c ../src/stomp_frame.c ../src/stomp_protocol.c)

include_directories(${UNIT_TEST_LIB_HOME}/include)
link_directories(${UNIT_TEST_LIB_HOME})

add_executable(unittest ${TEST_SOURCES} ${SOURCES})
target_link_libraries(unittest UnitTest++)
