cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
# Если версия установленой программы
# старее указаной, произайдёт аварийный выход.

set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_FLAGS                "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

set (CMAKE_INCLUDE_PATH ./genecode/)

include_directories("${CMAKE_SOURCE_DIR}/genecode/" "${CMAKE_SOURCE_DIR}")

SET (HEADERS_ONLY GLOBAL_CONST.h)


        file(GLOB GENECODE_SRC
                "*.h"
                "*.cpp"
                "genecode/*.cpp"
        )


add_executable(genecode.bin ${GENECODE_SRC})		# Создает исполняемый файл с именем main

