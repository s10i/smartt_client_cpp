cmake_minimum_required(VERSION 2.6)

project("Smartt TCP API C++ Client")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

find_package(OpenSSL REQUIRED)
find_package(JsonCpp REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11")

add_library(smartt_client
            src/smartt_client.cpp
            src/smartt_simple_connection.cpp
            src/smartt_simple_protocol.cpp
            src/smartt_socket.cpp
            src/smartt_term.cpp
            src/parameter_list.cpp)

add_executable(smartt_client_test.run src/test_main.cpp)

target_link_libraries(smartt_client_test.run smartt_client ${JSONCPP_LIBRARY} ssl crypto)
