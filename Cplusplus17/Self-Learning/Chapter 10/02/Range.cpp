// Range.cpp

int power_range{3};

// 如果想把 power_range 修改为 const 描述，需要添加 extern 关键字
// ! 因为 const 变量默认具有 内部链接属性，不能被其他转化单元使用

// extern const int power_range{3};
// ! 此时访问该变量的另一个 转化单元 必须声明为 extern const int power_range;
