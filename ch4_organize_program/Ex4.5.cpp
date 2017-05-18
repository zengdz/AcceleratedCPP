/*  编写函数计算输入中每个不同的字符串出现的次数，
	比如输出 a 出现多少次，abc 出现多少次
	直接把Ex3.3的练习封装成函数*/
#include <iostream> // cin,cout,endl
#include <iomanip>
#include <ios>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef vector <string>::size_type vec_sz;

// 函数返回最长名字的长度
vec_sz read_names(istream& in, vector <string>& s, vector <int>& t)
{
	s.clear();
	string x;
	vec_sz maxlen = 0;
	while(in >> x){
		int idx = -1;
		for (vec_sz i = 0; i < s.size(); ++i){
			if (x == s[i]){
				idx = i;
				break;
			}
		}

		if(idx == -1){
			maxlen = max(maxlen, x.size());
			s.push_back(x); 
			t.push_back(1); 
		}
		else
			++t[idx]; 
	}
	return maxlen;
}

int main()
{ 
	cout << "Please enter some strings: " << endl;
	string x;
	vector <string> vec_str; // 保存不重复的字符串
	vector <int> vec_int; // 记录不同字符串出现的次数
	int max_size = 0;

	max_size = read_names(cin, vec_str, vec_int);

	if (vec_str.size() == 0) {
		cout << "It's empty! Please try again!" << endl;
		return 1;
	}

	cout << "The strings and occurrences are: " << endl;
	streamsize wh = cout.width(); // 获取默认值
	for (vec_sz i = 0; i < vec_str.size(); ++i){
		// 使用setfill配合setw使用特定字符补齐空白部分
		cout << setfill('*') << setw(max_size) << vec_str[i] << setw(wh) << " : " << vec_int[i] << endl;
	}
	return 0;
}
