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
	
	cout << endl;
	
	for(int r = 0; r != rows; ++r){
		string::size_type c = 0;
		
		while(c != cols){
			if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
				cout << "*";
				++c;
			}
			else{
				if(r == pad + 1 && c == pad + 1){
					cout << greeting;
					c += greeting.size();
				}
				else{
					cout << " ";
					++c;
				}
			}
		}
		
		cout << endl;
	}
	
	return 0; 
}
