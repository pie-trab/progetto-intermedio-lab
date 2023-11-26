cmake_minimum_required(VERSION 2.84 FATAL_ERROR)

#message("Compilazione eseguita con opzione -fno-elide-constructors")

set(CMAKE_CXX_STANDARD 11)

project(Bookshelf)

include_directories(include)

add_library(${PROJECT_NAME} SHARED src/Book.cpp src/BookShelf.cpp src/Date.cpp)


add_executable(main src/main.cpp)

#set(GCC_COVERAGE_COMPILE_FLAGS "-fno-elide-constructors")

#add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

target_link_libraries(main ${PROJECT_NAME})

