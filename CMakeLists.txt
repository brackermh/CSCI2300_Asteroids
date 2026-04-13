cmake_minimum_required(VERSION 3.21)
project(QtHello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(app
    src/main.cpp
)

target_link_libraries(app PRIVATE Qt6::Widgets)

#--------------
cmake_minimum_required(VERSION 3.20)
project(oosd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

# ---- App always builds ----
add_executable(app src/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# ---- Student library sources (add .cpp files here as you create them) ----
set(STUDENT_SOURCES
  src/player.cpp
  src/bullet_player.cpp
  src/bullet_ufo.cpp
  src/bullet.cpp
  src/ufo.cpp
#add more sources here
)

target_link_libraries(app PRIVATE Qt6::Widgets)

# Only create/link the library once there is at least one source file listed.
list(LENGTH STUDENT_SOURCES STUDENT_SOURCE_COUNT)
if(STUDENT_SOURCE_COUNT GREATER 0)
  add_library(student_lib STATIC ${STUDENT_SOURCES})
  target_include_directories(student_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
  target_link_libraries(app PRIVATE student_lib)
else()
  message(STATUS "No student .cpp files listed yet. Building app with main.cpp only.")
endif()