// Samantha Scaglione
// Lab 5
// Part 1
//	dig_vectarr.cpp
//	This program creates a new version of the in lab
//	program such that digits and freq are objects of
//	the <vector> class and <array> class respectively
//	and an iterator is used to access their contents

// Preprocessor Directives
#include <iostream>
#include <vector>
#include <array>
using namespace std;

// Function Prototypes
array<int, 10> findfreq(vector<int> digits, int size);
void results(array<int, 10> freq);

// Main Function
int main(){

	//Variable/Vector Declarations
	vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5}; //given hardcoded vector values
	array<int, 10> freq; // initialize frequency vector
    int size = digits.size(); // find the vector's size

	//Function Calls
    freq = findfreq(digits, size); // compute digits' frequencies
 	results(freq);  // display frequencies for each digit

	//Return
	return 0; // if it ran without error, it'll return a 0
}

// Function Definitions
array<int, 10> findfreq(vector<int> a, int sz){
	array<int, 10> freq = {0,0,0,0,0,0,0,0,0,0}; //initializing freq vector
	vector<int>::iterator it; // initialize iterator
	for (it = a.begin(); it < a.end(); it++) //indexing through vector a (digits)
		freq[*it]++; //categorizing each digit in the freq vector
	return freq; //returning the freq vector
}

void results(array<int, 10> freq){
	for (int i = 0; i < 10; i++)
		cout <<  "digit " << i << " occurs " << freq[i] << " times" << endl;
}
