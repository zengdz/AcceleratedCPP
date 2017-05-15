#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Please enter the rows and cols: ";
	int rows, cols;
	cin >> rows >> cols;
	cout << endl;
	
	// output solid Square: r = c = rows
	for(int r = 0; r != rows; ++r){
		for(int c = 0; c != rows; ++c){
				cout << "*";
			}
		cout << endl;
	}
	cout << endl;
	
	// output solid Retangle
	for(int r = 0; r != rows; ++r){
		for(int c = 0; c != cols; ++c){
				cout << "*";
			}
		cout << endl;
	}
	cout << endl;
	
	// output hollow Retangle(empty inside)
	for(int r = 0; r != rows; ++r){
		for(int c = 0; c != cols; ++c){
			if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				cout << "*";
			else
				cout << " ";
			}
		cout << endl;
	}
	cout << endl;
	
	// output solid Triangle
	cols = rows * 2 - 1; // To form a triangle, the cols is fixed
	int mid = (cols - 1) / 2; // find middle position, count from zero!
	for (int r = 0; r != rows; ++r){
		int c = 0;
		// can replace with for loop, see next function
		while (c != cols){ 
			// 2*r + 1 stars(*) each row
			if (c >= mid - r && c < mid + 1 + r){ 
				cout << "*";
			}
			else
				cout << " ";
			++c;
		}
		cout << endl;
	}
	cout << endl;
	
	// output hollow Triangle(empty inside)
	for (int r = 0; r != rows; ++r){
		for (int c = 0; c != cols; ++c){
			// in hollow mode, deal with boundry condition
			if (c == mid - r || c == mid + r || r == rows - 1){
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	
	return 0; 
}
