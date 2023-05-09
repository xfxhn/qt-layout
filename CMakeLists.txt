cmake_minimum_required(VERSION 3.5)

project(layout VERSION 0.1 LANGUAGES CXX)


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_PREFIX_PATH D:/softwares/qt/5.15.2/msvc2019_64)
else ()
    set(CMAKE_PREFIX_PATH D:/softwares/qt/5.15.2/mingw81_64)
endif ()

#[[设置查找UI文件的路径 AUTOUIC处理]]
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/forms")

# 有些项目会动态生成头文件，项目中需要引入它，因此需要将output目录也include进来
# 等同于INCLUDE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)


#if (QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(wangyiyun)
#endif ()
