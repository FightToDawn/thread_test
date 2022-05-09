cmake_minimum_required(VERSION 3.16)

# 可以配合thread_config.h.in文件 实现传入版本号到代码中
project(thread_test VERSION 2.15)
configure_file(thread_config.h.in thread_config.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 设置库文件的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)

# 安装  使用指令 cmake --install . 时 可以把相关可执行文件 头文件等 复制到系统相关目录
install(TARGETS thread_test DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/thread_config.h"
    DESTINATION include
    )

# 测试
enable_testing()
add_test(NAME Runs COMMAND thread_test 25)

# Packaging 打包 在build目录下使用cpake命令进行打包
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)

# 给测试添加仪表盘 在build目录下使用ctest [-VV] -D Experimental 命令可以定时把测试结果推送到某个url连接
# enable dashboard scripting
include(CTest)
set(CTEST_PROJECT_NAME "CMakeTutorial")
set(CTEST_NIGHTLY_START_TIME "00:00:00 EST")
set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "localhost")
set(CTEST_DROP_LOCATION "/submit.php?project=CMakeTutorial")
set(CTEST_DROP_SITE_CDASH TRUE)