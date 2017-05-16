/*  计算输入中每个不同的字符串出现的次数，
	比如输出 a 出现多少次，abc 出现多少次*/
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
	cout << "Please enter some strings: " << endl;
	string x;
	vector <string> vec_str;
	vector <int> vec_int; // 记录字符串出现的次数
	typedef vector <string>::size_type vec_sz;

	// 不变式：目前输入向量个数的不重复字符串
	// 记录每个不同字符串出现的次数
	while (cin >> x) {

		// 向量第一次输入自然是不同的字符串
		// 向量不为空才能索引
		if(vec_str.empty()){
			vec_str.push_back(x); // 追加一个不同的字符串
			vec_int.push_back(1); // 给对应字符串追加次数记录
		}
		else{
			int idx = -1;
			for (vec_sz i = 0; i < vec_str.size(); ++i){
				if (x == vec_str[i])
					idx = i;
				else
					idx = -1;
			}

			// 如果为-1表示新的字符串是不同的
			if(idx == -1){
				vec_str.push_back(x); // 追加一个不同的字符串
				vec_int.push_back(1); // 给对应字符串追加次数记录
			}
			// 否则就是已经输入过的字符串
			else
				++vec_int[idx]; // 不用追加字符串，把对应次数记录的值自增1
		}
	}

	if (vec_str.size() == 0) {
		cout << "It's empty! Please try again!" << endl;
		return 1;
	}

	cout << "The strings and occurrences are: " << endl;
	for (vec_sz i = 0; i < vec_str.size(); ++i)
		cout << vec_str[i] << ":" << vec_int[i] << endl;
	
	return 0;
}
