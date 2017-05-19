# 第 4 章：组织程序和数据

>  函数返回多个参数的方法

> 传值调用和引用(非常量引用，常量引用)

> cin.clear() vs vec.clear()含义不同

> 异常的抛出throw与获取catch

> 经验规则：保证一条语句的副作用不超过一个，尤其是输入输出语句，因为它们必然有一个副作用(P62 CHN)

> 头文件.h使用标准库名字应该使用std::X的方式，而不是using; 而在.cpp文件中可以使用using来使用标准库名字

因为.h文件影响的是全局，而.cpp文件影响是局部的。
头文件.h中函数声明只需提供类型不用提供形参名，因为声明只检查类型是否一致。

> s.width(n) 类似 s.precision(n)

streamsize pre = cout.precision(n) //把输出格式精度设置为n,返回之前的精度给prec
/* 输出语句 */
cout.precision(prec) //结束输出后，把精度设置回原来的

> setw(n) 类似 setprecision(n)

streamsize pre = cout.precision() //返回默认精度给prec
cout << setprecision(n) << "输出内容" << setprecision(prec);

> 库定义的一些异常类

logic_error		domain_error 	invalid_argument
length_error	out_of_range	runtime_error
range_error		overflow_error	underflow_error

