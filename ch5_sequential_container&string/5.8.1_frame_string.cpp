/* 输入几句话保存到字符串向量
   把那几句话加框保存到新的字符串向量最后输出 */
#include <iostream>
#include <vector>
#include <algorithm> // max
#include <string> // getline

using namespace std; 

// 找出字符串向量里面最长字符串的长度，返回该值
string::size_type width(const vector <string>& v )
{
	string::size_type maxlen = 0;
	for (vector <string>::size_type i = 0; i != v.size(); ++i) {
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

// 给字符串向量的每条字符串加框，返回新的加框字符串向量
vector <string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');
	ret.push_back(border); // 输出上边框

	// 对每一条字符串进行处理(加边界符加空格对齐)
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}
	ret.push_back(border); // 输出下边框
	return ret;
}

int main()
{
	vector<string> sentences;
	string x;
	cout << "Please say some words: " << endl;
	// 使用getline读取一行字符串
	while (getline(cin, x)) {
		sentences.push_back(x);
	}
	vector<string> framed_str;
	framed_str = frame(sentences);

	// 使用迭代器输出
	for (vector<string>::const_iterator iter = framed_str.begin();
		iter != framed_str.end(); ++iter) {
		cout << *iter << endl;
	}
	
	return 0;
}
