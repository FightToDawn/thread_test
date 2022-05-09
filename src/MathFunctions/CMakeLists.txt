# 生成动态库
add_library(MathFunctions mysqrt.cpp)

# 安装动态库
install(TARGETS MathFunctions DESTINATION lib)
install(FILES mysqrt.h DESTINATION include)
