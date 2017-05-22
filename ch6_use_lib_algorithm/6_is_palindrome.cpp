#include <iostream>
#include <vector>
#include <algorithm> // find_if
#include <string> // getline
#include <cctype> // isspace

using namespace std; 

bool is_palindrome(const string& s)
{
	// equal函数前两个参数为迭代器指定了一个序列
	// 第三个参数是第二个序列的起点，假定两序列长度相同，所以不需要第二序列的终点
	return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
	string s;
	cin >> s;
	if (is_palindrome(s)) {
		cout << s << " is palindrome" <<endl;
	}
	else {
		cout << s << " is not palindrome" << endl;
	}
	
	return 0;
}
