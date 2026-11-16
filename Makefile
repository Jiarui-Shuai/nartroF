# 编译器与基础参数
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP
LDFLAGS  :=

PROJECT  := nartroF

# 目录定义
SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin

# 目标可执行文件名
TARGET   := $(PROJECT)

# 自动获取所有源文件和目标文件
SRCS     := $(wildcard $(SRC_DIR)/*.cpp)
OBJS     := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS     := $(OBJS:.o=.d)

# 默认目标
all: $(BIN_DIR)/$(TARGET)

# 链接规则
$(BIN_DIR)/$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# 编译规则
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 创建必要的目录
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# 清理编译产物
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# 包含自动生成的依赖文件
-include $(DEPS)

.PHONY: all clean