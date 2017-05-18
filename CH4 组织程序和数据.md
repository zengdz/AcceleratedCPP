# 第 4 章：组织程序和数据

>  函数返回多个参数的方法

> 传值调用和引用(非常量引用，常量引用)

> cin.clear() VS vec.clear()含义不同

> 异常的抛出与获取

> 经验规则：保证一条语句的副作用不超过一个 (P62 CHN)

> 一旦有了除main函数外的其他函数，就要考虑函数的声明(函数必须在使用前定义)

> 头文件.h使用标准库名字应该使用std::X的方式，而不是using，因为该文件影响的是全局；
而在.CPP文件中使用using来使用标准库名字，因为该文件的影响是局部的。

头文件.h中函数声明只需提供类型不用形参名，因为声明只检查类型是否一致。

> s.width(n) 类似 s.precision(n)
streamsize pre = cout.precision(n) //把输出格式精度设置为n,返回之前的精度给prec
/* 输出语句 */
cout.precision(prec) //结束输出后，把精度设置回原来的

> setw(n) 类似 setprecision(n)
streamsize pre = cout.precision() //返回默认精度给prec
cout << setprecision(n) << "输出内容" << setprecision(prec);
