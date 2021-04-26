cmake_minimum_required(VERSION 3.17)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

project(the_plazza
        LANGUAGES CXX
        DESCRIPTION "The plazza is a multiprocess, multithreading restaurant"
        )

set(MY_SRC_DIR ${PROJECT_SOURCE_DIR}/src/)
set(MY_PLAZZA_DIR ${MY_SRC_DIR}/Plazza/)
set(MY_UTILS_DIR ${MY_SRC_DIR}/Utils/)
set(MY_ENCAPSULATION_DIR ${MY_UTILS_DIR}Encapsulations/)
set(MY_ERROR_DIR ${MY_UTILS_DIR}Error/)
set(MY_SERIALIZER_DIR ${MY_UTILS_DIR}Serializer/)
set(MY_COMMUNICATION_DIR ${MY_UTILS_DIR}Communication/)
set(MY_PIZZA_DIR ${MY_PLAZZA_DIR}Pizza/)
set(MY_PIZZATYPE_DIR ${MY_PIZZA_DIR}PizzaType/)
set(MY_FACTORY_DIR ${MY_PIZZA_DIR}Factory/)

set(MY_SRC
        ${MY_ENCAPSULATION_DIR}ConditionalVariables/ConditionalVariables.cpp
        ${MY_ENCAPSULATION_DIR}Mutex/Mutex.cpp
        ${MY_ENCAPSULATION_DIR}Processes/Processes.cpp
        ${MY_ENCAPSULATION_DIR}Threads/Threads.cpp
        ${MY_ERROR_DIR}Error.cpp
        ${MY_SERIALIZER_DIR}Serializer.cpp
        ${MY_COMMUNICATION_DIR}Communication.cpp
        ${MY_PIZZA_DIR}Pizza.cpp
        ${MY_PIZZATYPE_DIR}Americana/Americana.cpp
        ${MY_PIZZATYPE_DIR}Fantasia/Fantasia.cpp
        ${MY_PIZZATYPE_DIR}Margarita/Margarita.cpp
        ${MY_PIZZATYPE_DIR}Regina/Regina.cpp
        ${MY_FACTORY_DIR}Factory.cpp
        )

set(MY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(MY_INCLUDE
        ${MY_INCLUDE_DIR}
        ${MY_SRC_DIR}/Plazza
        ${MY_SRC_DIR}/Utils
        )

set(MY_DEPENDENCIES
        pthread)

set(MY_BINARY plazza)

add_executable(${MY_BINARY}
        ${MY_SRC_DIR}main.cpp
        ${MY_SRC}
        )

set_target_properties(${MY_BINARY}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )

target_compile_features(${MY_BINARY} PRIVATE cxx_std_17)

target_link_libraries(${MY_BINARY} ${MY_DEPENDENCIES})

target_include_directories(${MY_BINARY} BEFORE PUBLIC ${MY_INCLUDE})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(${MY_BINARY} PRIVATE -Wall -Wextra)
endif ()

# unit tests ###################################################################

set(MY_TESTS_DIR ${PROJECT_SOURCE_DIR}/tests/)

set(MY_SRC_TESTS
#        ${MY_TESTS_DIR}src/.cpp
        )

set(MY_INCLUDE_TESTS
        ${MY_TESTS_DIR}include
        )

set(MY_TESTS_DEPENDENCIES
        criterion
        )

set(MY_TESTS_BINARY unit_tests)

add_executable(${MY_TESTS_BINARY}
        ${MY_SRC}
        ${MY_SRC_TESTS}
        )

set_target_properties(${MY_TESTS_BINARY}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )

target_compile_features(${MY_TESTS_BINARY} PRIVATE cxx_std_14)

target_include_directories(${MY_TESTS_BINARY} BEFORE
        PUBLIC ${MY_INCLUDE}
        PUBLIC ${MY_INCLUDE_TESTS}
        )

target_link_libraries(${MY_TESTS_BINARY}
        ${MY_DEPENDENCIES}
        ${MY_TESTS_DEPENDENCIES})


if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(${MY_TESTS_BINARY} PRIVATE -Wall -Wextra)

    add_custom_target(tests_run
            COMMAND make ${MY_TESTS_BINARY}
            COMMAND ./${MY_TESTS_BINARY})
endif ()