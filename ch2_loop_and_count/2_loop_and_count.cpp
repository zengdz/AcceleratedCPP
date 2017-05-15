#include<iostream>
#include<string> 

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	const string greeting = "Hello, " + name + "!";
	
	const int pad = 1;
	const int rows = pad * 2 + 3; 
	const string::size_type cols = greeting.size() + pad * 2 +2;
	
	cout << std::endl;
	
	// loop invariant: output r rows so far 
	for (int r = 0; r != rows; ++r){
		string::size_type c = 0;
		
		// loop invariant: output c cols so far 
		// update of c changes by condition, so use while-loop instead of for-loop
		while (c != cols){
			if( r == pad + 1 && c == pad + 1){
				cout << greeting;
				// update c to maintain loop invariant
				c += greeting.size();
			}
			else{
				if( r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				// update c to maintain loop invariant
				++c;
			}
		}
		cout << endl;
	}
	
	return 0;
} 
