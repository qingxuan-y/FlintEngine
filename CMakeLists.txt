cmake_minimum_required(VERSION 3.20)
project(FlintEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源文件
set(SOURCES
    source/main.cpp
    source/core/Engine.cpp
    source/core/Application.cpp
    source/platform/Platform.cpp
)

# 头文件
set(HEADERS
    source/core/Engine.h
    source/core/Application.h
    source/core/Subsystem.h
    source/core/Log.h
    source/platform/Platform.h
)

# 可执行文件
add_executable(FlintEngine ${SOURCES} ${HEADERS})

# 包含目录
target_include_directories(FlintEngine PRIVATE source)