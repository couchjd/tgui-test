#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(tgui-test)

include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "tgui-test.exe")
add_executable(${EXECUTABLE_NAME} main.cpp)

add_subdirectory("SFML")
add_subdirectory("TGUI-0.8")

include_directories("SFML/include")
include_directories("TGUI-0.8/include")

target_link_libraries(${EXECUTABLE_NAME} sfml-network sfml-graphics sfml-window sfml-system sfml-audio)
target_link_libraries(${EXECUTABLE_NAME} tgui)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#find_package(TGUI)
#if(TGUI_FOUND)
#    include_directories(${TGUI_INCLUDE_DIR})
#    target_link_libraries(${EXECUTABLE_NAME} tgui)
#endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
include(CPack)
