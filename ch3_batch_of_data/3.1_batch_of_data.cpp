#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

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
			
	// the number and sum of grades read so far
	int count = 0;
	double sum = 0;
	
	// a variable into which to read
	double x;
	
	// invariant:
	// 目前为止，已经读入count个homework成绩
	// 并且sum等于头count个成绩的总和
	// hit Ctrl-Z to end-of-file
	// cin >> x 不光是判断条件：结果是cin，可以转换为bool类型用于判断
	// 还有副作用：读入一个值到x，需考虑其对不变式的影响
	while (cin >> x){
		++count;
		sum += x;
	}
	
	// 获取cout默认的精度，在输出指定精度的内容之后恢复为默认
	streamsize prec = cout.precision();
	
	// write the result
	// setprecision(3) 表示三位有效数，改变后面输出流的格式
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		 << setprecision(prec) << endl;
		 
	return 0;
}
