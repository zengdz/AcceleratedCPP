/* 使用数据结构结合函数处理多位学生的成绩 */
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <algorithm> // sort
#include <stdexcept> // domain_error
#include <string>
#include <vector>

using namespace std;

// 定义一个学生信息的结构体，含4个数据成员
// Student_info是一种学生信息的类型
// 那么vector <Student_info> 就能保存任意数量的学生信息
struct Student_info {
	string name;
	double midterm, final;
	vector <double> homework;
};

// sort函数不能直接比较结构体向量，需要指定比较规则
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

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

// 再次重载，使用重载完成同种功能的不同实现
// 都是求总成绩，但是有平均值，中值，数据格式的不同，体现在形参的不同
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
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

		while (in >> x) {
			hw.push_back(x);
		}
		// clear不是清空输入缓存，而且清除错误标记，使输入可以正常继续！
		in.clear();
	}
	return in;
}

// 不用担心read函数会重名，第二个参数的存在会构成重载
istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

int main()
{
	vector <Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name
			<< string(maxlen+1-students[i].name.size(), ' ');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
