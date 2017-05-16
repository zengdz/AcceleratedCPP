/* 输入两个数，返回其中的较大值。分别使用常规判断和标准库函数max实现 */
#include <iomanip> // setprecision
#include <ios> // streamsize
#include <iostream> // cin,cout,endl
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::max;

int main()
{ 
	// 使用分支判断 if-else 或者 ?:
	cout << "Please enter two numbers: ";
	double e1, e2, e_max;
	cin >> e1 >> e2;
	e_max = e1 >= e2 ? e1 : e2;
	cout << "The larger number is: " << e_max << endl;

	// 使用标准库函数max
	cout << "Please enter two numbers: ";
	cin >> e1 >> e2;
	cout << "The larger number is: " << max(e1, e2) << endl;
	
	return 0;
}
