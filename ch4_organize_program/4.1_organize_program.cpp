#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <algorithm> // sort
#include <stdexcept> // domain_error
#include <string>
#include <vector>

using namespace std;

// 计算vector <double>变量的中值
// 注意调用的时候，整个vector参数都会被复制
// 虽然整个vector会复制，但此处不希望sort改变原vector，故传值调用
double median(vector <double> vec)
{
	// 检查homework输入是否为空
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0) {
		throw domain_error("median of empty vector");
	}

	sort(vec.begin(), vec.end());

	// 计算vec的中值
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// 对grade函数进行重载
double grade(double midterm, double final, const vector <double>& hw)
{
	// 虽然在median函数也检查是否为空并抛出异常
	// 在这里抛出自己的异常会更加人性化，提供合适的错误信息
	if (hw.size() == 0)
		throw domain_error("student has no homework");
	return grade(midterm, final, median(hw));
}

// 读取函数要返回两个值：读到的数据；指示是否读取成功
// 间接实现：把要返回的数据当做形参；
// 可以使用 if(read_hw(cin,homework)) 判断是否读取成功
// 同时读取到的数据也会在homework向量中，所以使用引用
// 非常量引用要求参数必须是左值！
istream& read_hw(istream& in, vector <double>& hw)
{
	if (in) {
		// 不确定hw引用的向量是否有数据，先清空
		hw.clear();
		double x;

		// invariant:目前为止，已经读入count个homework成绩
		// hit Ctrl+Z to end-of-file
		// vector.push_back(x)结果是把x添加到向量尾部
		// 副作用是把向量的长度加一
		while (in >> x) {
			hw.push_back(x);
		}
		// clear不是清空输入缓存，而且清除错误标记，使输入可以正常继续！
		in.clear();
	}
	return in;
}

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// 空格隔开的字符串可以自动拼接一起
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	vector <double> homework;
	read_hw(cin, homework);

	try {
		// 单独定义一个final_grade而非在cout直接调用函数
		// 保证异常产生在有任何输出之前(避免无意义的信息输出)
		// 经验规则：保证一条语句的副作用不超过一个
		// cout语句副作用是输出信息，如果直接调用grade函数会增加一个副作用：抛出异常
		double final_grade = grade(midterm, final, median(homework));
		streamsize prec = cout.precision();
		// setprecision(3) 表示三位有效数
		cout << "Your final grade is " << setprecision(3) << final_grade
			<< setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}

	return 0;
}