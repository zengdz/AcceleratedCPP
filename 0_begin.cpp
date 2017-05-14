// 注释：一个小的C++程序
#include<iostream> // 标准头文件

int main(){
	//1,下面表达式结果是 std::cout, 但分号丢弃了该结果。副作用是把字符串输出以及换行
	//2, std是名字空间，属于一个作用域。所以用里面的名字要加::作用域运算符 
	std::cout << "Hello, world!" << std::endl;
	//3, 运算符的作用取决于操作数。第一个 <<左操作数是cout属于ostream类型，右操作数是字符串 
	return 0;
} 
