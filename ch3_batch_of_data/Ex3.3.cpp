/*  计算输入中每个不同的字符串出现的次数，
	比如输出 a 出现多少次，abc 出现多少次*/
#include <iostream> // cin,cout,endl
#include <algorithm>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{ 
	cout << "Please enter some strings: " << endl;
	string x;
	vector <string> vec_str; // 保存不重复的字符串
	vector <int> vec_int; // 记录不同字符串出现的次数
	typedef vector <string>::size_type vec_sz;

	// 不变式：目前输入向量个数的不重复字符串
	// 记录每个不同字符串出现的次数
	while (cin >> x) {
		
		// 不变式：x在向量的位置idx
		// 开始时x不在向量所以把idx赋值-1，不变式为真
		// 进入循环，如果x在向量的第i位置，那么更新idx使不变式为真
		// 此时不变式已经完成，所以break。如果没找到idx还是-1，不变式还是真
		int idx = -1;
		for (vec_sz i = 0; i < vec_str.size(); ++i){
			if (x == vec_str[i]){
				idx = i;
				break;
			}
		}

		// 如果为-1表示新的不同字符串
		if(idx == -1){
			vec_str.push_back(x); // 追加一个不同的字符串
			vec_int.push_back(1); // 给对应字符串追加次数记录
		}
		// 否则就是已经输入过的字符串
		else
			++vec_int[idx]; // 不用追加字符串，把对应次数记录的值自增1

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
