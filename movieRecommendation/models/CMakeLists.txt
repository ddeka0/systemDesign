cmake_minimum_required(VERSION 3.5)

include_directories(inc/)
include_directories(${PROJECT_SOURCE_DIR}/common/)
#include_directories(../)

file(GLOB MODEL_SRC src/*.cpp)

add_library(MODEL SHARED ${MODEL_SRC})

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -g")
# set(CRYPTO_LIBRARIES  "-lssl -lcrypto")