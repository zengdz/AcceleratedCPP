#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	int i = 0;
	int num;
	while(i < 16){
		num = 10- i;
		++i;
		cout << num << endl;
	}
	cout << endl;
	
	// loop invariant: have output 10 - j rows, num is j
	// so output (10 - -6 = 16)rows, as first output 10, then output from 10 to -5
	for(int j = 10; j > -6; --j){
		cout << j << endl;
	}
	
	return 0; 
}
