/*  计算指定范围的整数值对应的平方
	输出分两列并且对齐排列，自动对齐 */
#include <iostream> // cin,cout,endl
#include <iomanip> //setw
#include <ios> //streamsize

using namespace std;

// 获取整数值的宽度，返回该宽度值
char getWidth(int num)
{
	char width = 0;
	while (num > 0) {
		++width;
		num /= 10;
	}
	return width;
}

int main()
{ 
	cout << "Please enter the begin and end number: " << endl;
	int beg, end;
	cin >> beg >> end;

	// 如果起始大于终止，则输出提示并退出
	if (beg > end) {
		cout << "Begin must less equal than end!" << endl;
		return 1;
	}

	cout << "The numbers and squares are: " << endl;
	streamsize wh = cout.width();
	for (int i = beg; i < end + 1; ++i) {
		cout << setw(getWidth(end)) << i << " : " 
			 << setw(getWidth(end * end)) << i * i << setw(wh) << endl;
	}

	return 0;
}

