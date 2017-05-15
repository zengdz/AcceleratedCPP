#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	int i = 0;
	// loop invariant: have output i rows, num is i + 1
	// so output (10 - 0 = 10)rows, as first output 1, then output from 1 to 10
	while(i < 10){
		i += 1;
		cout << i << endl;
	}
	
	return 0; 
}
