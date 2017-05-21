/* 把两个字符串向量横向连接，就是一个在左，一个在右边添加
   刚好使用上一个例子的字符串向量和加框的字符串向量进行连接 */
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

// 横向连接两个字符串向量，返回新的字符串向量
vector <string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// 在左右两个字符串向量之间留一个空格
	string::size_type width1 = width(left) + 1;

	vector<string>::size_type i = 0, j = 0;
	
	// 直到两边字符串全都处理完才结束
	while (i != left.size() || j != right.size()) {
		string s; // 局部变量，每次生成新的一行字符串
		// 如果左边还有待处理字符串
		if (i != left.size())
			s = left[i++]; // 从left向量取一个字符串
		s += string(width1 - s.size(), ' '); // 补空格对齐字符串
		// 如果右边还有待处理字符串
		if (j != right.size())
			s += right[j++]; // 再取right的一个字符串组成一行字符串
		ret.push_back(s);
	}
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

	vector<string> hori_cat;
	hori_cat = hcat(sentences, framed_str);

	cout << "Horizon join vector strings: " << endl;
	// 使用迭代器输出
	for (vector<string>::const_iterator iter = hori_cat.begin();
		iter != hori_cat.end(); ++iter) {
		cout << *iter << endl;
	}
	
	return 0;
}
