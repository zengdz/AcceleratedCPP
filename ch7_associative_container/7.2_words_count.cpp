// 使用关联容器计算单词数量
#include <iostream>
#include <map>

using namespace std;

int main()
{
	string s;
	map<string, int> counters;

	while(cin >> s)
		// counters[s]是以字符串s为键值访问counters，返回一个和s相关的整数
		++counters[s];

		for(map<string, int>::const_iterator it = counters.begin(); 
			it != counters.end(); ++it){
			// pair数据结构可以访问映射表，有两个元素first，second
			cout << it->first << "\t" << it->second << endl;
		}

	return 0;
}
