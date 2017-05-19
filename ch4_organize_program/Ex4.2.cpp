/*  计算1-100整数值对应的平方
	输出分两列并且对齐排列 */
#include <iostream> // cin,cout,endl
#include <iomanip> //setw
#include <ios> //streamsize
#include <vector>

using namespace std;

int main()
{ 
	cout << "The numbers 1-100 squares are: " << endl;
	streamsize wh = cout.width();
	for (int i = 1; i < 101; ++i) {
		// 1-100最大三位数，其平方最大五位数
		cout << setw(3) << i << " : " 
			 << setw(5) << i * i << setw(wh) << endl;
	}

	return 0;
}

