#include<iostream>
#include<string> 
#define EX // EX1-EX6选择测试对应的代码
int main()
{
	// Ex1.1 Correct!
#ifdef EX1
	const std::string hello = "Hello";
	// string可以和字符串相加，并且返回string类型
	const std::string message = hello + ", world" + "!";
	std::cout << message << std::endl;
#endif

	// Ex1.2 Wrong!
#ifdef EX2
	const std::string exclam = "!";
	// 从左到右运算，字符串不能直接相加
	const std::string message = "Hello " + ", world" + exclam;
#endif

	// Ex1.3 Correct!
	// 两个string变量名字相同，但是作用域不同
#ifdef EX3
	{
		const std::string s = "a string";
		std::cout << s << std::endl;
	}

	{
		const std::string s = "another string";
		std::cout << s << std::endl;
	}
#endif

	// Ex1.4 Correct!
	// 同上
#ifdef EX4
	{
		const std::string s = "a string";
		std::cout << s << std::endl;
		{
			const std::string s = "another string";
			std::cout << s << std::endl;
		}
		; // 这是一个空语句，没有作用
	}
#endif

	//Ex1.5 Wrong!
#ifdef EX5    
	{
		std::string s = "a string";
		{
			std::string x = s + ", really"; //s is in the scope
			std::cout << s << std::endl;
		}
		std::cout << x << std::endl; // x is out of scope!
	}
#endif

	//Ex1.6 - std::cin buffer understanding 
#ifdef EX6  
	// 程序意图分别输入两个字符串名字
	// 如果在第一次就输入了两个字符串，那么第二次程序不会要求输入
	// 而是直接从输入缓冲读取第二个字符串
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
#endif

	return 0;
}
