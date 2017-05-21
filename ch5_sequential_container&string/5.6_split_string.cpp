#include <iostream>
#include <vector>
#include <string> // getline
#include <cctype> // isspace

using namespace std; 

vector <string> split (const string& s)
{
	vector <string> ret;
	typedef vector <string>::size_type string_size;
	string_size i = 0;

	// 不变式：已经处理了在索引域[之前索引i，当前索引i)中的字符
	while(i != s.size()){
		// 忽略前端的空白字符
		// 不变式：索引域[之前索引i，当前索引i)中都是空格
		while(i != s.size() && isspace(s[i]))
			++i;
		// 找下一个单词的终结点
		string_size j = i;
		// 不变式：索引域[之前索引j，当前索引j)中都不是空格
		while(j != s.size() && !isspace(s[j]))
			++j;
		// 如果找到了非空白字符(i和j不相等说明找到了)
		if(i != j){
			ret.push_back(s.substr(i, j - i));
			// 处理完一个单词要更新i的值，使不变式为真
			i = j;
		}
	}
	return ret;
}

int main()
{
	string s;
	// 使用split函数分割字符串 
	cout << "Self-made split method" << endl;
	// 使用getline函数读取一整行字符串
	while(getline(cin, s)){
		vector <string> v = split(s);
		for(vector <string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	cin.clear(); // 清楚错误标记，以便后续输入
	
	// 依靠cin自身特性分割字符串 
	cout << "Standard cin method" << endl;
	while(cin >> s){
		cout << s << endl;
	}
	
	return 0;
}
