/* Exercise 2-1 create a framed greeting program with no padding */
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string; 

int main()
{
	cout << "Please enter your name: ";
	string name;
	cin >> name;
	
	string greeting = "Hello, " + name + "!";
	const int pad = 0;
	const int rows = pad + 3;
	const string::size_type cols = pad + greeting.size() + 2;
	
	cout << endl;
	
	// loop invariant: output r rows so far 
	for(int r = 0; r != rows; ++r){
		string::size_type c = 0;
		
		// loop invariant: output c cols so far 
		// update of c changes by condition, so use while-loop instead of for-loop
		while(c != cols){
			if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
				cout << "*";
				// update c to maintain loop invariant
				++c; 
			}
			else{
//				if(r == pad + 1 && c == pad + 1){
					cout << greeting;
					// update c to maintain loop invariant
					c += greeting.size(); 
//				}
//				else{
//					cout << " ";
//					++c;
//				}
			}
		}
		
		cout << endl;
	}
	
	return 0; 
}
