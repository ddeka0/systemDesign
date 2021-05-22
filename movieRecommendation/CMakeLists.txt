cmake_minimum_required (VERSION 3.5)
set(CMAKE_BUILD_TYPE Debug)

# set project name and C++ compiler version
project(movieRecommend)
message(STATUS "Compiling Project : ${PROJECT_NAME}")
set (CMAKE_CXX_STANDARD 17)

message(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

#set(LIB_FILE ${CMAKE_CURRENT_SOURCE_DIR}/protocol/libmylib.a)

# add all necessary libs
add_subdirectory(models bin_model)
add_subdirectory(core bin_core)
add_subdirectory(apis bin_apis)

# add all include paths
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/common/)
include_directories(${PROJECT_SOURCE_DIR}/models/inc/)
include_directories(${PROJECT_SOURCE_DIR}/core/inc/)
include_directories(${PROJECT_SOURCE_DIR}/apis/inc/)
include_directories(${PROJECT_SOURCE_DIR}/test/inc/)


# add all src files
file(GLOB TEST_FILES test/src/*.cpp)

# add all config files
# configure_file(<source_location>/file_name.json
# 		${PROJECT_SOURCE_DIR}/<file_name>.json COPYONLY)


add_executable(${PROJECT_NAME}
    ${TEST_FILES}
)

# add_definitions(-DBOOST_LOG_DYN_LINK)

#set(BASIC_LIBRARIES "-lpthread -lcrypto")
#set(REST_LIBRARIES "-lcpprest -lyaml-cpp")
#set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -g  -fsanitize=address")
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -g -ftime-report -fsanitize=address -fsanitize=leak")
#set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -g")
#set(CMAKE_LINK_WHAT_YOU_USE ON)

#set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "time -v")
#set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "time -v")

#find_library(proto_location NAMES protobuf PATHS ${LIBDIR})
#find_library(grpc_location NAMES grpc++ PATHS ${LIBDIR})
#find_library(grpc_reflection_location NAMES grpc++_reflection PATHS ${LIBDIR})
#find_library(dl_location NAMES dl PATHS ${LIBDIR})
#find_library(grpc_location2 NAMES grpc PATHS ${LIBDIR})

# if(proto_location)
#   message(STATUS "protobuf library found at " ${proto_location})
# endif()
# if(grpc_location)
#   message(STATUS "grpc++ found at " ${grpc_location})
# endif()
# if(grpc_reflection_location)
#   message(STATUS "grpc_reflection found at " ${grpc_reflection_location})
# endif()
# if(dl_location)
#   message(STATUS "dl found at " ${dl_location})
# endif()
# if(grpc_location2)
#   message(STATUS "grpc found at " ${grpc_location2})
# endif()

target_link_libraries(${PROJECT_NAME}
                        libAPI
                        libCORE
                        libMODEL
)

# target_link_libraries(${PROJECT_NAME}  
#                         libNODE
#                         libSERVICES
#                         libAUTH 
#                         libSERVER
#                         libCLIENT
#                         libNODE # dont remove two times !!!
#                         ${proto_location}
#                         ${LIB_FILE}
#                         ${grpc_location}
#                         ${grpc_reflection_location}
#                         ${dl_location}
#                         ${grpc_location2}
#                         ${BASIC_LIBRARIES}
# )