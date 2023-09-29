### config

cmake_minimum_required (VERSION 2.8)
project (Demo)

### compile

aux_source_directory(. DIR_SRCS)
add_executable(Demo ${DIR_SRCS})

### static link library

# test
aux_source_directory(test DIR_TEST_SRCS)
add_library(test STATIC ${DIR_TEST_SRCS})
target_link_libraries(Demo test)

# test1
aux_source_directory(test1 DIR_TEST1_SRCS)
add_library(test1 STATIC ${DIR_TEST1_SRCS})
target_link_libraries(Demo test1)

# test1/test2
aux_source_directory(test1/test2 DIR_TEST2_SRCS)
add_library(test2 STATIC ${DIR_TEST2_SRCS})
target_link_libraries(Demo test2)

# eigen
include_directories(/usr/local/Cellar/eigen/3.4.0_1/include)
add_library(eigen INTERFACE)
target_include_directories(eigen INTERFACE /usr/local/Cellar/eigen/3.4.0_1/include)
target_link_libraries(Demo eigen)

# opencv
include_directories(/usr/local/Cellar/opencv@3/3.4.16_10/include)
file(GLOB OpenCV_LIBS /usr/local/Cellar/opencv@3/3.4.16_10/lib/*.dylib)
target_link_libraries(Demo ${OpenCV_LIBS})
