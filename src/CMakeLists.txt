
# 用开关来控制是否加载某个动态库
add_subdirectory(thread)
list(APPEND EXTRA_LIBS thread)
list(APPEND EXTRA_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/thread")

# 创建可执行文件
add_executable(thread_test main.cpp)

# 添加动态链接库的路径
target_link_libraries(thread_test PUBLIC ${EXTRA_LIBS})

# 添加路径到包含头文件目录  如果注释掉下面一行 那就会提示找不到thread_config.h 以为这个文件 cmake 是生成到PROJECT_BINARY_DIR下的
target_include_directories(thread_test PUBLIC 
                        "${PROJECT_BINARY_DIR}"
                        ${EXTRA_INCLUDES})

#输出目录
message(STATUS "PROJECT_BINARY_DIR  ${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_SOURCE_DIR  ${PROJECT_SOURCE_DIR}")
message(STATUS "EXTRA_INCLUDES  ${EXTRA_INCLUDES}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "${EXTRA_LIBS}")