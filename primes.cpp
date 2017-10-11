// Samantha Scaglione
// Lab 4
// Part 2: Prime Numbers
//	This program uses the sieve or Eratosthenes algorithm
//	for finding prime numbers 1-1000 then outputs the
//	prime numbers 10 per row with all columns lined up

// Preprocessor Initiatives
#include <iostream>
#include <iomanip>
using namespace std;

// Main Function
int main() {

	// Declare Variables
	int numArray[1001];
		for (int i = 0; i < 1001; i++){
			numArray[i] = 1;
		}
	int numIndex = 0; // initialized to 3 because the first multiple we use is 2
	int entry = 1; //used to track entries/row for formatting

	// Find Prime Numbers
	for (int multiple = 2; multiple < 1000; multiple++) {	//check that the relevant	multiple is within range
		for (int i = 2; i*multiple <= 1000; i++) { //check that the num index is within range
			numIndex = i*multiple;
			numArray[numIndex] = 0;
		}
	}

	// Format and Print Results
	for (int i = 1; i < 1001; i++){
		if (numArray[i] == 1){
			cout << setw(5) << i;
			entry++;
			if (entry > 10){
				cout << endl;
				entry = 1;
			}
		}
	}
	cout << endl;

	// Return 0 for no error
	return 0;
}
