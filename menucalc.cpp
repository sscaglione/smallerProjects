// Samantha Scaglione
// Lab 3
// Part 3: Text Menu Calculator
//	This program will act as a text menu driven
//	basic calculator for four simple arithmetic
//	operations: add, subtract, multiply, divide

//preprocessor directives
#include <iostream>
using namespace std;

//function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

//main function
int main() {

	//variable declaration
	double num1, num2, sum, difference, product, quotient;
	int choice = 0; //initializing to 0

	//while loop so calculator keeps prompting until exited
	while (choice != 5){

		//user interaction
		cout << "What would you like to do?" << endl;
		cout << "        1 for addition" << endl;
		cout << "        2 for subtraction" << endl;
		cout << "        3 for multiplication" << endl;
		cout << "        4 for division" << endl;
		cout << "        5 to exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		while ((!cin) || (choice > 5) || (choice < 1)){
			cout << "Error: Invalid Input; Enter your choice: ";
			cin >> choice;
		}
		if (choice != 5){
			cout << "Enter your first number: ";
			cin >> num1;
			while (!cin){
				cout << "Error: Invalid Input; Enter your first number: ";
				cin >> num1;
			}
			cout << "Enter your second number: ";
			cin >> num2;
			while (!cin){
				cout << "Error: Invalid Input; Enter your second number: ";
				cin >> num2;
			}
			cout << "Inputs: " << num1 << ", " << num2 << endl;
		}

		//case structure to call functions or exit calc
		switch ( choice ) {
		case 1:
			sum = add(num1, num2);
			cout << "(" << num1 << ") + (" << num2 << ") = " << sum << endl;
			break;
		case 2:
			difference = subtract(num1, num2);
			cout << "(" << num1 << ") - (" << num2 << ") = " << difference << endl;
			break;
		case 3:
			product = multiply(num1, num2);
			cout << "(" << num1 << ") x (" << num2 << ") = " << product << endl;
			break;
		case 4:
			quotient = divide(num1, num2);
			cout << "(" << num1 << ") / (" << num2 << ") = " << quotient << endl;
			break;
		case 5:
			cout << "Thank you!" << endl;
			return 0;
		}
	}
}

//function definitions
double add(double num1, double num2){
	double sum; //declaring variable
	sum = num1 + num2; //calculating sum
	return sum; //returning sum
}

double subtract(double num1, double num2){
	double difference; //declaring variable
	difference = num1 - num2; //calculating difference
	return difference; //returning difference
}

double multiply(double num1, double num2){
	double product; //declaring variable
	product = num1*num2; //calculating product
	return product; //returning product
}

double divide(double num1, double num2){
	double quotient; //declaring variable
	quotient = num1/num2; //calculating quotient
	return quotient; //returning quotient
}
