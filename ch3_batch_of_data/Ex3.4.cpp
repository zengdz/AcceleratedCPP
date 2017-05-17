/*  判断输入字符串中最长和最短字符串的长度 */
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <algorithm>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using std::string;

int main()
{ 
	cout << "Please enter some strings: ";
	string x;
	vector <string> strs;
	typedef vector <string>::size_type vec_sz;
	int min_v, max_v;
	while (cin >> x) {
		strs.push_back(x);
		int str_size = x.size();
		// 在输入第一个字符串的时候给 min_v, max_v 赋初值
		if (strs.size() == 1)
			min_v = max_v = str_size;
		else {
			if (str_size > max_v)
				max_v = str_size;
			if (str_size < min_v)
				min_v = str_size;
		}
	}

	if (strs.size() == 0) {
		cout << "It's empty, please try again!" << endl;
		return 1;
	}

	cout << "The strings are: " << endl;
	for (vec_sz i = 0; i < strs.size(); ++i)
		cout << strs[i] << " ";
	cout << endl;
	cout << "the shortest is: " << min_v << endl 
		 << "the longest is: " << max_v << endl;
	
	return 0;
}
