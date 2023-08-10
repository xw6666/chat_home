cmake_minimum_required(VERSION 3.0)
project(main)

# 配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置C++版本
set(CMAKE_CXX_STANDARD 11)

# 指定搜索的子目录
# add_subdirectory(test_muduo)

# 配置头文件搜索路径
# include_directories()
# 配置库文件搜索路径
# link_directories()

# 设置需要编译的源文件列表
set(SRC_LIST ./muduo_server.cc)

# 把.下的源文件放入SRC_LIST中
# aux_source_directory(. SRC_LIST)

# 设置可执行文件最终存储路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(muduo_server ${SRC_LIST})
# 表示server目标程序需要链接这些库文件
target_link_libraries(muduo_server muduo_net muduo_base pthread)


