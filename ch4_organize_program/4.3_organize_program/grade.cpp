#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::vector;
using std::domain_error;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector <double>& hw)
{
	// 虽然在median函数也检查是否为空并抛出异常
	// 在这里抛出自己的异常会更加人性化，提供合适的错误信息
	if (hw.size() == 0)
		throw domain_error("student has no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}