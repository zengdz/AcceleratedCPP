/* 如果只是计算homework平均值，那么没有必要保存每个输入的homework的成绩
   但是，如果是取中值而非平均值，那么必须把输入的homework保存下来，使用vector吧*/
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main()
{
	// ask for and read the student's name 
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	
	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	
	// ask for homework grades
	// 空格隔开的字符串可以自动拼接一起
	cout << "Enter all your homework grades, "
			"followed by end-of-file: ";
	
	// a variable into which to read
	double x;
	vector <double> homework;
	
	// invariant:
	// 目前为止，已经读入count个homework成绩
	// hit Ctrl-Z to end-of-file
	// vector.push_back(x)结果是把x添加到向量尾部
	// 副作用是把向量的长度加一
	while(cin >> x){
		homework.push_back(x);
	}

	// 检查homework输入是否为空
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}

	// 对homework成绩进行排序
	sort (homework.begin(), homework.end());

	// 计算homework成绩的中值
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

	// 计算并输出总成绩
	streamsize prec = cout.precision();
	// setprecision(3) 表示三位有效数
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;
		 
	return 0;
}
