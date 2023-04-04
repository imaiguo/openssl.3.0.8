
cmake_minimum_required(VERSION 3.24)

set(APPNAME "rsatest")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUE_CURRENT_DIR ON)

project(${APPNAME} LANGUAGES CXX)

find_package(OpenSSL REQUIRED) # OPENSSL_INCLUDE_DIR,OPENSSL_LIBRARIES,OPENSSL_VERSION

set(SRCMAIN
    ./rsatest.cc
)

add_executable(${APPNAME}
    ${SRCMAIN}
)

target_include_directories(${APPNAME}
    PRIVATE 
        ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries( ${APPNAME}
    PRIVATE 
        ${OPENSSL_LIBRARIES}
)

message("---configure done---")