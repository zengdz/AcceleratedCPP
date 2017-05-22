#include <iostream>
#include <vector>
#include <algorithm> // find_if
#include <string> // getline
#include <cctype> // isspace

using namespace std; 

// 单独定义的原因是：isspace是个重载函数(以便处理不同的字符类型)
// 如果直接传递给模板函数，编译器可能不知道所指的是哪个版本函数
bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector <string> split (const string& s)
{
	vector <string> ret;
	typedef string::const_iterator iter; // 字符串类型也有迭代器
	iter i = s.begin();

	while (i != s.end()) {
		// 忽略前端的空白字符
		// find_if 算法头两个参数是迭代器，最后一个参数是匹配模型
		// 找到第一个非空白字符，返回其位置；若没找到返回第二个参数s.end()
		i = find_if(i, s.end(), not_space);

		// 找下一个单词的结尾
		iter j = find_if(i, s.end(), space);

		// 复制在区间[i, j)内的字符
		if (i != s.end())
			// 使用string的迭代器构造字符串，而不是substr的索引
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

int main()
{
	string s;
	// 使用split函数分割字符串 
	cout << "Iterator-split method: " << endl;
	// 使用getline函数读取一整行字符串
	while(getline(cin, s)){
		vector <string> v = split(s);
		for(vector <string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	cin.clear(); // 清除错误标记，以便后续输入
	
	// 依靠cin自身特性分割字符串 
	cout << "Standard cin method: " << endl;
	while(cin >> s){
		cout << s << endl;
	}
	
	return 0;
}
