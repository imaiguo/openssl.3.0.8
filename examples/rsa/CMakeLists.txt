
cmake_minimum_required(VERSION 3.24)

set(APPNAME "rsatest")
set(APPRSA "generateRsa")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUE_CURRENT_DIR ON)

project(${APPNAME} LANGUAGES CXX)

find_package(OpenSSL REQUIRED) # OPENSSL_INCLUDE_DIR,OPENSSL_LIBRARIES,OPENSSL_VERSION

set(SRCMAIN
    ./rsatest.cc
)

set(SRCRSA
    ./generateRsa.cc
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