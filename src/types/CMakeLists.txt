set(TYPES_LIB_SRCS)
list(APPEND TYPES_LIB_SRCS
    date.cpp
    patient.cpp)

add_library(typeslib SHARED ${TYPES_LIB_SRCS})
