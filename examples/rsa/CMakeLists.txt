
cmake_minimum_required(VERSION 3.18)

set(APPNAME "rsatest")
set(APPRSA "generateRsa")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUE_CURRENT_DIR ON)

project(${APPNAME} LANGUAGES CXX)

set(OPENSSL_ROOT_DIR "D:/devtools/openssl.3.0.8/")
# set(OPENSSL_ROOT_DIR "D:/devtools/openssl.3.0.8/debug")

find_package(OpenSSL REQUIRED) # OPENSSL_INCLUDE_DIR,OPENSSL_LIBRARIES,OPENSSL_VERSION

set(SRCMAIN
    src/RsaTest.cc
)

set(SRCRSA
    src/GenerateRsa.cc
)

add_executable(${APPNAME}
    ${SRCMAIN}
)

add_executable( ${APPRSA}
    ${SRCRSA}
)

target_include_directories( ${APPNAME}
    PRIVATE 
        ${OPENSSL_INCLUDE_DIR}
)


target_include_directories( ${APPRSA}
    PRIVATE 
        ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries( ${APPNAME}
    PRIVATE 
        ${OPENSSL_LIBRARIES}
)

target_link_libraries( ${APPRSA}
    PRIVATE 
        ${OPENSSL_LIBRARIES}
)

message("---configure done---")
