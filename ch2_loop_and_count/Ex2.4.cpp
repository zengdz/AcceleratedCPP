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
	
	cout << "Please enter the pad: ";
	int pad;
	cin >> pad;
	
	const int rows = pad * 2 + 3;
	const string::size_type cols = pad * 2 + greeting.size() + 2;
	string spaces(pad, ' '); // spaces between boundry and greeting in row
	string blanks(cols - 2, ' '); // spaces in row without greeting
	
	cout << endl;
	
	for(int r = 0; r != rows; ++r){
		string::size_type c = 0;
		
		while(c != cols){
			if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
				cout << "*";
				++c;
			}
			else{
				// if only c == 1, begin output the greeting row
				if(r == pad + 1 && c == 1){
					cout << spaces;
					cout << greeting;
					cout << spaces;
					//c += cols -2;
				}
				else{
					cout << blanks;
					//c += cols -2;
				}
				c += cols -2; // merge to one statement
			}
		}
		
		cout << endl;
	}
	
	return 0; 
}
