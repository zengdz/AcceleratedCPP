/*  编写函数计算输入中每个不同的单词出现的次数，
	比如输出 hehe 出现多少次，abc 出现多少次
	之前的方法是在添加元素之前判断是否已经存在，这种方法时间复杂度比较高
	可以在全部读取之后进行排序，再计算出现次数，这样时间复杂度就会下降  */
#include <iostream> // cin,cout,endl
#include <iomanip>
#include <ios>
#include <algorithm> // sort
#include <vector>
#include <string>

using namespace std;

typedef vector <string>::size_type vec_sz;

// 从输入读取单词字符串保存在向量，CTRL+Z结束输入
// 函数返回值：最长单词的长度
vec_sz read_names(istream& in, vector <string>& s)
{
	s.clear();
	string x;
	vec_sz maxlen = 0;
	while(in >> x){
		maxlen = max(maxlen, x.size());
		s.push_back(x);
	}
	return maxlen;
}

bool compare(const string& x, const string& y)
{
	return x < y;
}

int main()
{ 
	cout << "Please enter some words: " << endl;
	string x;
	vector <string> words; // 保存输入的单词字符串
	vector <int> times; // 记录不同单词字符串出现的次数
	int max_size = 0; // 所有单词字符串里面最长的长度，用于对齐输出

	max_size = read_names(cin, words);
	sort(words.begin(), words.end(), compare); // 把单词字符串向量按照字母顺序排序

	vec_sz i = 0;
	// 找出每个单词字符串出现的次数，保存在向量中
	// 变量i,j用于锁定相同单词的区间，差值就是单词出现的次数
	// 参考5.6字符串split代码
	while (i != words.size()) {
		vec_sz j = i; // j是第一个和words[i]不同的元素的索引
		while (j != words.size() && words[j] == words[i]) {
			++j; // j会指向相同元素的后一位置，使得j-i为相同元素个数
		}
		if (i != j) {
			times.push_back(j - i);
			i = j; // 更新起始索引
		}
	}

	if (words.size() == 0) {
		cout << "It's empty! Please try again!" << endl;
		return 1;
	}

	cout << "The strings and occurrences are: " << endl;
	streamsize wh = cout.width(); // 获取默认值

	// idx和j分别是单词字符串向量索引和出现次数向量索引
	// 没有修改有序单词字符串向量，仍存在相同的字符串
	// 所以输出的时候需要根据出现次数使字符串向量索引指向不同字符串
	vec_sz idx = 0, j = 0;
	while (idx < words.size()){
		// 使用setfill配合setw使用特定字符补齐空白部分
		cout << setfill('*') << setw(max_size) << words[idx] << setw(wh) << " : " << times[j] << endl;
		idx += times[j++]; // 根据出现次数指示不同字符串的位置索引
	}

	return 0;
}
