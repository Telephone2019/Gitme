cmake_minimum_required(VERSION 3.16.3)

# 指定C/C++编译器
set(CMAKE_C_COMPILER "/bin/gcc")
set(CMAKE_CXX_COMPILER "/bin/gcc")

# 指定C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

# 指定C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# 详细的make输出
set(CMAKE_VERBOSE_MAKEFILE ON)

# 添加C++编译选项
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 添加C编译选项
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# 项目名称
project(Gitme)

# 添加可执行目标
add_executable(Gitme_main main.cpp rename_branch.h gitme_type.h)
# rename target output bin
set_target_properties(Gitme_main PROPERTIES OUTPUT_NAME gitme)

# 链接额外的静态库和动态库
# 依赖关系（如果有）要满足：前面的库依赖后面的库
# 末尾要恢复动态链接
target_link_libraries(Gitme_main PRIVATE -Wl,-Bdynamic pthread stdc++ -Wl,-Bstatic m -Wl,-Bdynamic)

# 强制所有库链接使用静态库
# target_link_libraries(Homework_main PRIVATE -static)
