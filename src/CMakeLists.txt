add_executable(assignment)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_sources(assignment PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_subdirectory(core)
add_subdirectory(io)
add_subdirectory(types)
add_subdirectory(operations)

target_link_libraries(assignment corelib)
