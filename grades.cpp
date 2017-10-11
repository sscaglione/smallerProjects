// Samantha Scaglione
// Lab 4
//	Part 1: A Simple Array and Input Redirection
//	This program reads integer grade values from
//	a data file into an array then computes their
//	average and their standard deviation

//Preprocessor Directives
#include <iostream>
#include <math.h>
using namespace std;

//Function Prototypes
float faverage(float [], int);
float fstdDev(float [], int, float);

//Main Function
int main() {

	//Variable Declarations
	float grades[50] = { 0.0 };
	float average, stdDev; //making float because int would truncate values
	int i = 0;

	//User Input
	cin >> grades[i];
	while (grades[i] != -1){
		i++;
		cin >> grades[i];
	}

	//Call Functions
	average = faverage(grades, i);
	stdDev = fstdDev(grades, i, average);

	//Output Results
	cout << "The average of the grades is " << average << "." << endl;
	cout << "The standard deviation of the grades is " << stdDev << "." << endl;

	//if it ran through without errors, return 0
	return 0;
}

//Function Definitions
float faverage(float grades[], int numGrades){
	float total = 0;
	float average;
	for (int i = 0; i < numGrades; i++){
		total = total + grades[i];
	}
	average = total / (float)(numGrades);
	return average;
}

float fstdDev(float grades[], int numGrades, float average){
	float stdDev, total;
	for (int i = 0; i < numGrades; i++){
		total = total + (grades[i] - average);
	}
	stdDev = total / (float)(numGrades - 1);
	stdDev = sqrt(stdDev);
	return stdDev;
}
