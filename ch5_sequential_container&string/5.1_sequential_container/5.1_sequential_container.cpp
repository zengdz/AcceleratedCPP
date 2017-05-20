/* 把不及格的学生分开处理，只输出及格学生(不支持输入空的homework成绩)
   迭代器适用于顺序操作的容器
   索引只适合那些支持随机操作的容器
   向量适合在向量末尾添加元素，不适合删除操作 */
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <algorithm> // sort
#include <stdexcept> // domain_error
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"

using namespace std;

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

// 把学生里面不及格的从向量移除到另一个向量，返回不及格学生的向量
vector <Student_info> extract_fails(vector <Student_info>& students)
{
	vector <Student_info> fail;
	vector <Student_info>::size_type i = 0;

	// students.size()在动态变化每次判断都要重新获取
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			// students.begin()+i 只对可随机访问的容器有效
			// erase操作会自动指向下一个位置，不用手动加1
			students.erase(students.begin() + i);
		}
		else
			++i;
	}
	return fail;
}

// 顺序获取适合使用迭代器 extract_fails_iter
vector <Student_info> extract_fails_iter(vector <Student_info>& students)
{
	vector <Student_info> fail;
	vector <Student_info>::iterator iter = students.begin();

	// students.end()在动态变化每次判断都要重新获取
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			// erase方法的参数是待删除元素的位置
			// 迭代器删除后，后面元素的迭代器就全失效
			// 但是会返回一个指向后面元素的迭代器，所以要保存返回的迭代器
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

// 优化数据结构，删除元素适合使用列表list
list <Student_info> extract_fails_list(list <Student_info>& students)
{
	list <Student_info> fail;
	list <Student_info>::iterator iter = students.begin();

	// students.end()在动态变化每次判断都要重新获取
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			// erase方法的参数是待删除元素的位置
			// 迭代器删除后，后面元素的迭代器就全失效
			// 但是会返回一个指向后面元素的迭代器，所以要保存返回的迭代器
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

void output_grade(ostream& out,vector <Student_info>& stu, string::size_type maxlen)
{
	// 输出所有名字是顺序操作，可以用迭代器代替索引students[i](随机访问)
	// 如果不会修改向量，那么使用常量迭代器 const_iterator
	for (vector<Student_info>::const_iterator iter = stu.begin();
		iter != stu.end(); ++iter) {
		// 输出名字，并在后面填充空格使得所有名字一样长
		// (*iter).name 等效于 iter -> name
		out << (*iter).name
			<< string(maxlen + 1 - (iter->name).size(), ' ');

		try {
			double final_grade = grade(*iter);
			streamsize prec = out.precision();
			out << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			out << e.what();
		}
		out << std::endl;
	}
}

// 重载函数，改变了形参类型为列表list
void output_grade(ostream& out, list <Student_info>& stu, string::size_type maxlen)
{
	// 输出所有名字是顺序操作，可以用迭代器代替索引students[i](随机访问)
	// 如果不会修改向量，那么使用常量迭代器 const_iterator
	for (list<Student_info>::const_iterator iter = stu.begin();
		iter != stu.end(); ++iter) {
		// 输出名字，并在后面填充空格使得所有名字一样长
		// (*iter).name 等效于 iter -> name
		out << (*iter).name
			<< string(maxlen + 1 - (iter->name).size(), ' ');

		try {
			double final_grade = grade(*iter);
			streamsize prec = out.precision();
			out << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			out << e.what();
		}
		out << std::endl;
	}
}

int main()
{
	list <Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; // 最长名字的长度

	while (read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	// 以字母顺序对学生名字进行排序
	//sort(students.begin(), students.end(), compare);

	// 当对list排序操作时要用自己的sort函数，因为缺少了随机访问的特性
	students.sort(compare);

	// 有三个版本的extract_fails根据需要调整
	list <Student_info> fail;
	fail = extract_fails_list(students);
	
	cout << "Students passed the course:" << endl;
	output_grade(cout, students, maxlen);
	cout << "Students failed the course:" << endl;
	output_grade(cout, fail, maxlen);

	return 0;
}
