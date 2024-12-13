include(FetchContent)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz DOWNLOAD_EXTRACT_TIMESTAMP)
FetchContent_MakeAvailable(json)

set(IO_LIB_SRCS)
list(APPEND IO_LIB_SRCS
    io.cpp
    adapters/patient-json-adapter.cpp)

add_library(iolib SHARED ${IO_LIB_SRCS})

target_link_libraries(iolib PRIVATE nlohmann_json::nlohmann_json)
