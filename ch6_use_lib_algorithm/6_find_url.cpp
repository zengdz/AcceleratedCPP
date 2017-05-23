#include <iostream>
#include <vector>
#include <algorithm> // find_if,find
#include <string> // getline
#include <cctype> // isspace,isalnum

using namespace std; 

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// find函数和find_if类似，只不过第三个参数是特定字符
	// 找到则返回第一次指向该值的迭代器，否则返回第二个参数
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	// 在迭代器[b, e)之间匹配not_url_char，如果找到返回指向该位置的迭代器
	// 否则返回第二个参数，即序列的末尾迭代器
	return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;

	// i 标记了查找到分隔符的位置
	iter i = b;

	// search函数两对参数，第一对是要查找的序列
	// 第二对是希望被定位的序列，如果失败返回第二个参数
	while((i = search(i, e, sep.begin(), sep.end())) != e){
		// 确保分隔符不是在字符串序列的开头和末尾
		if(i != b && i + sep.size() != e){
			// beg标记协议名称的开始，比如http
			iter beg = i;
			while(beg != b && isalpha(beg[-1]))
				--beg;
			// 在sep两边是否至少有一个合法字符
			if(beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		// 找到的sep不是URL的一部分，更新i的指向
		i += sep.size();
	}
	return e;
}

vector<string> find_urls(const string& s)
{
	vector <string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	// 检查整个输入，只要开始迭代没到结尾迭代
	while (b != e) {
		// 查找一个或多个紧跟着 :// 的字母
		b = url_beg(b, e);
		// 如果查找成功，url_beg如果查找失败返回的是第二个参数e
		if (b != e) {
			// 获取此URL的其余部分，after是指向当前URL结尾的迭代器
			iter after = url_end(b, e);
			// 把定位到的URL的迭代器的首尾作为string构造，把网址字符串保存
			ret.push_back(string(b, after));
			// 把起始位置推进，查找其他URL
			b = after;
		}
	}
	return ret;
}

int main()
{
	// 包含网址的测试字符串
	string str_with_urls = "hehe http://www.163.com haha http://www.google.com search website";
	vector<string> urls = find_urls(str_with_urls);

	for(vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it){
		cout << *it << endl;
	}

	return 0;
}
