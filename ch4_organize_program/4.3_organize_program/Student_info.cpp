// 在源文件引用对应的头文件可用于检查声明与定义是否一致
#include "Student_info.h"

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector <double>& hw)
{
	if (in) {
		// 不确定hw引用的向量是否有数据，先清空
		hw.clear();
		double x;

		while (in >> x) {
			hw.push_back(x);
		}
		// clear不是清空输入缓存，而且清除错误标记，使输入可以正常继续！
		in.clear();
	}
	return in;
}

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}