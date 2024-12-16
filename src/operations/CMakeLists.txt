set(OPERATIONS_LIB_SRCS)
list(APPEND OPERATIONS_LIB_SRCS
    add_new_patient.cpp)

add_library(operationslib SHARED ${OPERATIONS_LIB_SRCS})

target_link_libraries(operationslib PRIVATE typeslib)
