set(CORE_LIB_SRCS)
list(APPEND CORE_LIB_SRCS
    application.cpp)

add_library(corelib SHARED ${CORE_LIB_SRCS})

target_link_libraries(corelib PRIVATE typeslib iolib)
