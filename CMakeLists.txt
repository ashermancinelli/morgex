cmake_minimum_required (VERSION 3.15)

project(morgex C)

# Configure API endpoint to be used
if(NOT EXISTS ${PROJECT_SOURCE_DIR}/key)
  message(FATAL_ERROR "Could not find api key!"
    "\n\tPlease add key to a file named `${PROJECT_SOURCE_DIR}/key`.")
endif()
file(READ "key" key)
string(REPLACE "\n" "" key ${key})
set(API_ENDPOINT_URL "http://data.fixer.io/api/latest?access_key=${key}")
set(API_ARGS "access_key=${key}&format=1")
message("Got API ${API_ENDPOINT_URL}")

# Configure config header with global settings
configure_file(config.h.in ${PROJECT_BINARY_DIR}/config.h)
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(src)

# Find CURL package and link against it
find_package(CURL REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CURL_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${CURL_LIBRARIES})
