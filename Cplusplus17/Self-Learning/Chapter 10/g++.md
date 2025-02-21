## **GCC/g++ 编译命令详细讲解**

在使用 GCC（C 语言）或 g++（C++ 语言）编译代码时，常用的编译命令格式如下：
```sh
g++ [选项] 文件名... [目标文件]
```
例如：
```sh
g++ -Wall -g -std=c++17 main.cpp -o main
```
这条命令会：
- `-Wall`：启用警告
- `-g`：生成调试信息（用于 gdb）
- `-std=c++17`：使用 C++17 标准
- `main.cpp`：编译的源文件
- `-o main`：指定输出的可执行文件名为 `main`

---

## **1. 编译选项讲解**

### **1.1 基本选项**
| 选项 | 作用 |
|------|------|
| `-o <文件名>` | 指定输出文件名称 |
| `-c` | 仅编译，不进行链接（生成 `.o` 目标文件） |
| `-E` | 仅进行预处理（输出预处理后的代码） |
| `-S` | 仅进行编译，不进行汇编（输出汇编代码 `.s` 文件） |
| `-g` | 生成调试信息（用于 gdb） |
| `-Wall` | 启用大多数警告信息 |
| `-Wextra` | 启用额外警告信息 |
| `-Werror` | 把所有警告视为错误 |
| `-v` | 显示编译过程的详细信息 |
| `-static` | 静态编译，避免使用动态库 |
| `-shared` | 生成共享库（`.so` 文件） |
| `-fPIC` | 生成位置无关代码（用于共享库） |

---

### **1.2 语言标准选项**
| 选项 | 作用 |
|------|------|
| `-std=c99` | 使用 C99 标准 |
| `-std=c11` | 使用 C11 标准 |
| `-std=c++11` | 使用 C++11 标准 |
| `-std=c++14` | 使用 C++14 标准 |
| `-std=c++17` | 使用 C++17 标准 |
| `-std=c++20` | 使用 C++20 标准 |

---

### **1.3 代码优化选项**
| 选项 | 作用 |
|------|------|
| `-O0` | 关闭优化（默认） |
| `-O1` | 开启基本优化 |
| `-O2` | 进行更高级优化（推荐用于生产环境） |
| `-O3` | 进行最高级优化（可能增加编译时间） |
| `-Ofast` | 在 `-O3` 的基础上进行激进优化（可能不遵循标准） |
| `-Os` | 优化代码大小，减少可执行文件体积 |

---

### **1.4 头文件 & 库路径**
| 选项 | 作用 |
|------|------|
| `-I<目录>` | 指定头文件搜索路径 |
| `-L<目录>` | 指定库文件搜索路径 |
| `-l<库名>` | 链接指定的库，如 `-lm` 代表链接数学库 |
| `-Wl,-rpath=<路径>` | 运行时指定共享库路径 |

---

### **1.5 并行编译**
| 选项 | 作用 |
|------|------|
| `-j<N>` | 指定并行编译的线程数，例如 `make -j4` 使用 4 个线程 |

---

## **2. 编译流程解析**
完整的 C/C++ 编译过程包括 **4 个阶段**：
1. **预处理**（Preprocessing）`-E`
2. **编译**（Compilation）`-S`
3. **汇编**（Assembly）`-c`
4. **链接**（Linking）

---

### **2.1 仅进行预处理**
使用 `-E` 选项：
```sh
g++ -E main.cpp -o main.i
```
- 预处理后，`main.i` 文件包含展开的宏和 `#include` 头文件内容。

---

### **2.2 仅进行编译**
使用 `-S` 选项：
```sh
g++ -S main.cpp -o main.s
```
- `main.s` 是生成的汇编代码。

---

### **2.3 仅进行汇编**
使用 `-c` 选项：
```sh
g++ -c main.cpp -o main.o
```
- `main.o` 是目标文件（未链接）。

---

### **2.4 手动链接**
如果已经有多个目标文件，可以手动链接：
```sh
g++ main.o utils.o -o program
```
- `program` 是最终可执行文件。

---

## **3. 具体编译示例**

### **3.1 编译单个 C++ 文件**
```sh
g++ main.cpp -o main
```

### **3.2 编译多个文件**
```sh
g++ main.cpp utils.cpp -o program
```

### **3.3 先编译成目标文件，再手动链接**
```sh
g++ -c main.cpp -o main.o
g++ -c utils.cpp -o utils.o
g++ main.o utils.o -o program
```

---

## **4. 编译静态库和动态库**

### **4.1 生成静态库（`.a`）**
```sh
g++ -c utils.cpp -o utils.o
ar rcs libutils.a utils.o
```
使用静态库：
```sh
g++ main.cpp -L. -lutils -o program
```

---

### **4.2 生成动态库（`.so`）**
```sh
g++ -shared -fPIC utils.cpp -o libutils.so
```
使用动态库：
```sh
g++ main.cpp -L. -lutils -o program
export LD_LIBRARY_PATH=.
./program
```

---

## **5. Makefile 示例**
```makefile
CXX = g++
CXXFLAGS = -Wall -g -std=c++17
OBJ = main.o utils.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
```
使用：
```sh
make
./program
make clean
```

---

## **6. 使用 gdb 调试**
编译时加 `-g`：
```sh
g++ -g main.cpp -o main
gdb ./main
```
常用 gdb 命令：
```sh
break main   # 设置断点
run         # 运行程序
next        # 执行下一行
step        # 进入函数
print x     # 查看变量 x
quit        # 退出 gdb
```

---

## **总结**
| 任务 | 命令 |
|------|------|
| **编译单个文件** | `g++ main.cpp -o main` |
| **编译多个文件** | `g++ main.cpp utils.cpp -o program` |
| **仅编译，不链接** | `g++ -c main.cpp -o main.o` |
| **链接目标文件** | `g++ main.o utils.o -o program` |
| **使用静态库** | `g++ main.cpp -L. -lutils -o program` |
| **使用动态库** | `g++ main.cpp -L. -lutils -o program` |
| **生成动态库** | `g++ -shared -fPIC utils.cpp -o libutils.so` |
| **开启 C++17 标准** | `g++ -std=c++17 main.cpp -o main` |
| **开启优化** | `g++ -O2 main.cpp -o main` |