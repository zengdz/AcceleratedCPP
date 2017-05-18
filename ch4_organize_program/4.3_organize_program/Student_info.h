#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

// 定义一个学生信息的结构体，含4个数据成员
// Student_info是一种学生信息的类型
// 那么vector <Student_info> 就能保存任意数量的学生信息
struct Student_info {
	std::string name;
	double midterm, final;
	std::vector <double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector <double>&);
std::istream& read(std::istream&, Student_info&);

#endif