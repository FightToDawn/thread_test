# 生成动态库
add_library(thread 
    Condition.cc
    CountDownLatch.cc
    CurrentThread.cc
    Exception.cc
    Thread.cc
)

target_link_libraries(thread pthread rt)

# # 安装动态库
# install(TARGETS thread DESTINATION lib)
# install(FILES mysqrt.h DESTINATION include)
