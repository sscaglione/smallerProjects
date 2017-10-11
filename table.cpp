// Samantha Scaglione
// Lab 2
// table.cpp
//	This program displays an integer
//	multiplication table. It asks the
//	user for the size of the table then
//	displays a multiplication table exactly
//	that big with a top row header and a
//	left column header

//preprocessing directives
#include <iostream>
#include <iomanip>
using namespace std;

//Main function
int main() {

	//defining variables
	int nCol;
	int nRow;

	//taking user input
	cout << "This program will generate a multiplication table of the size you designate" << endl;
	cout << "Enter the number of columns: ";
		cin >> nCol;
	cout << "Enter the number of rows: ";
		cin >> nRow;


	for (int i=0; i<nRow+1; i++){ //i will represent the row
		for (int j=0; j<nCol+1; j++){ //j will represent the col
			if (i==0){
				if (j==0){
					cout << setw(4) << '*'; //make the upper left corner '*'
				}
				else {
					cout << setw (4) << j; //header
				}
			}
			else {
				if (j==0) {
					cout << setw (4) << i; //header
				}
				else {
					cout << setw (4) << i*j; //actual multiplication
				}
			}
		}
		cout << endl; //go to the next line
	}

	return 0;
}
