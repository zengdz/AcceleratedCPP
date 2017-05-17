/* 输入多个学生名字和各项成绩，保存每个学生的名字和最终成绩
	版本1，家庭作业成绩只能输入固定数量，本程序为3个 */
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector <string> vec_str;
	vector <double> vec_dob;

	// 一个string向量保存名字，一个double向量保存总成绩
	// 任何cin输入如果使用Ctrl+Z，那么这个字符停留在输入缓冲
	// 由于是while(1)死循环，碰到cout就输出，碰到cin全都失效(因为里面是Ctrl+Z)
	// 最后出现的情况就是死循环打印输出cout信息
	while (1){
		cout << "Please enter your name: ";
		string name;
		cin >> name;
		vec_str.push_back(name);

		cout << "Please enter your midterm and final: ";
		double midterm, final;
		cin >> midterm >> final;

		cout << "Enter your homework grades: ";
		// homework的成绩个数固定为3
		int count = 3;
		double sum = 0;
		double x;
		while (count--) {
			cin >> x;
			sum += x;
		}
		double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * sum / 3;
		vec_dob.push_back(final_grade);

		string flag;
		cout << ">>Continue? Y/N: ";
		cin >> flag;
		// 判断是否继续，输入N结束，任意非N的字符继续
		if (flag == "N")
			break;
	}

	// 这个判断没有作用，在while循环如果Ctrl+Z
	// 或者其他原因导致cin读取失败，程序循环输出cout信息
	if (vec_dob.empty() || vec_str.empty()) {
		cout << "It's empty, Please try again!" << endl;
		return 1;
	}

	typedef vector <string>::size_type vec_sz;
	streamsize prec = cout.precision();
	cout << "The names and final grades are: " << endl;
	for (vec_sz i = 0; i < vec_str.size(); ++i)
		cout << setprecision(3) << vec_str[i] << " : " << vec_dob[i] 
		<< setprecision(prec) << endl;
	return 0;
}
