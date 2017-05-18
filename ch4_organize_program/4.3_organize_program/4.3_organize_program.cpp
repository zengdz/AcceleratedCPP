/* 使用数据结构结合函数处理多位学生的成绩 */
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <algorithm> // sort
#include <stdexcept> // domain_error
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
	vector <Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; // 最长名字的长度

	while (read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	// 以学生名字的字母顺序排序
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		// 输出名字，并在后面填充空格使得所有名字一样长
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
