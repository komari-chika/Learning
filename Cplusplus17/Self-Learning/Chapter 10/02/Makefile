# 指定编译器
CXX = g++

# 编译选项
CXXFLAGS = -Wall -Wextra -std=c++17

# 目标文件
TARGET = 01

# 源文件及生成的目标文件
SRCS = Power.cpp Range.cpp 01.cpp
OBJS = $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)
	@$(MAKE) clean-objects

# 链接目标
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译规则
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理中间目标文件（保留 .exe）
clean-objects:
	rm -f $(OBJS)

# 清理所有文件
clean:
	rm -f $(OBJS) $(TARGET)

# 重建所有
rebuild: clean all