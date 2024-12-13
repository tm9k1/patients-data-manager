set(CORE_LIB_SRCS)
list(APPEND CORE_LIB_SRCS
    application.cpp
    date.cpp
    patient.cpp)


add_library(corelib SHARED ${CORE_LIB_SRCS})
