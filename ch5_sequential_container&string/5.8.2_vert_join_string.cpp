/* 把两个字符串向量纵向连接，就是一个在上，一个在下面添加
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

vector <string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;
	for (vector<string>::const_iterator iter = bottom.begin();
		iter != bottom.end(); ++iter) {
		ret.push_back(*iter);
	}
	// 上面向量的操作可以使用向量的insert方法完成
	//ret.insert(top.end(), bottom.begin(), bottom.emd());
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

	vector<string> vert_cat;
	vert_cat = vcat(sentences, framed_str);

	cout << "Vertical join vector strings: " << endl;
	// 使用迭代器输出
	for (vector<string>::const_iterator iter = vert_cat.begin();
		iter != vert_cat.end(); ++iter) {
		cout << *iter << endl;
	}
	
	return 0;
}
