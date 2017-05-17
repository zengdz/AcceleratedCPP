/* 输入多个学生名字和各项成绩，保存每个学生的名字和最终成绩 
	版本2，家庭作业成绩的数量没有限制
	使用while(cin >> x)可以在输入Ctrl+Z时退出循环，但该结束字符还在输入缓冲 */
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

	// 不变式：目前已经输入n个学生的名字和总成绩
	// 一个string向量保存名字，一个double向量保存总成绩
	// 循环开始时，已经输入0个名字和总成绩，两个向量都为空，不变式为真。
	cout << "Please enter your name: ";
	string name;
	while (cin >> name){
		vec_str.push_back(name);

		cout << "Please enter your midterm and final: ";
		double midterm, final;
		cin >> midterm >> final;

		cout << "Enter your homework grades: ";
		int count;
		double sum = 0;
		double x;
		while (cin >> x) {
			++count;
			sum += x;
		}

		// 使用后面讲到的clear方法才能支持输入不限数量的homework成绩
		// 因为homework要使用Ctrl+Z来结束输入，但这个Ctrl+Z会被后面的cin读取
		// 如果后面有cin的话，就会对后面的输入造成影响，clear方法清除输入缓冲
		cin.clear();
		double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * sum / count;
		vec_dob.push_back(final_grade);

		string flag;
		cout << ">>Continue? Y/N: ";
		cin >> flag;
		if (flag == "N")
			break;
		
		// 用于下一条名字输入的提示信息
		cout << "Please enter another name: ";
	}

	if (vec_dob.empty() || vec_str.empty()) {
		cout << "It's empty, Please try again!" << endl;
		return 1;
	}

	typedef vector <string>::size_type vec_sz;
	streamsize prec = cout.precision();
	cout << endl << "The names and final grades are: " << endl;
	for (vec_sz i = 0; i < vec_str.size(); ++i)
		cout << setprecision(3) << vec_str[i] << " : " << vec_dob[i] 
		<< setprecision(prec) << endl;
	return 0;
}
