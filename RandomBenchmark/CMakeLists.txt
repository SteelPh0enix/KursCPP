cmake_minimum_required(VERSION 3.0)

project(RandomGenBenchmark)
set(CMAKE_CXX_STANDARD 14)

set(GOOGLE_BENCHMARK_INCLUDE_DIR "/usr/include" CACHE PATH "Google benchmark include path")
set(GOOGLE_BENCHMARK_LIB_DIR "/usr/lib" CACHE PATH "Google benchmark lib path")

include_directories(${GOOGLE_BENCHMARK_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})
file(GLOB SOURCES *.cpp)
link_directories(${GOOGLE_BENCHMARK_LIB_DIR})
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
if(WIN32)
    target_link_libraries(${PROJECT_NAME} benchmark Shlwapi)
else()
    target_link_libraries(${PROJECT_NAME} benchmark)
endif()