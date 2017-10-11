// Samantha Scaglione
// Lab 4
// Part 3: ND Football
//	This program stores win and loss data
//	for the notre dame football team and
//	provides the user with a menu of questions
//	on the data.

// Preprocesser Directives
#include <iostream>
using namespace std;

// Function Prototypes
void yearRecord(int [], int[], int);
void nWinYears(int [], int);
void nLossYears(int [], int);
void winningSzn(int[], int[]);
void losingSzn(int[], int[]);

// Global Variable Declaration
int wins[] =
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9, 8, 10, 4 };

int losses[] =
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4, 5, 3, 8};

// Main Function
int main(){

	// Variable Declarations
	int choice, year, nWins, nLosses;

	// While Loop so Program Keeps Prompting Until Exited
	while (choice != 6){

		// User Input
		cout << "What would you like to do?" << endl;
		cout << "		1: display the record for a given year" << endl;
		cout << "		2: display years with at least n wins" << endl;
		cout << "		3: display years with at least n losses" << endl;
		cout << "		4: display years with winning seasons" << endl;
		cout << "		5: display years with losing seasons" << endl;
		cout << "		6: exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		// Error Check User Input
		while ((!cin) || (choice > 6) || (choice < 1)){
			cout << "Error: Invalid Input; Enter your choice: ";
			cin >> choice;
		}

		// Case Structure to Call Functions
		switch ( choice ) {
		case 1:
			// Prompt User for Year
			cout << "Enter a year between 1900 and 2017: ";
			cin >> year;
			// Error Check User Input
			while ((!cin) || (year > 2017) || (year < 1900)){
				cout << "Error: Invalid Input; Enter a year within the parameters: ";
				cin >> year;
			}
			// Call Function
			yearRecord(wins, losses, year);
			break;
		case 2:
			// Prompt User for Number of Wins
			cout << "Enter minimum number of wins: ";
			cin >> nWins;
			// Error Check the User Input
			while ((!cin) || (nWins > 13) || (nWins < 0)){
				cout << "Error: Invalid Input; There are at most 13 games in a season: ";
				cin >> nWins;
			}
			// Call Function
			nWinYears(wins, nWins);
			break;

		case 3:
			// Prompt User for Number of Losses
			cout << "Enter minimum number of losses: ";
			cin >> nLosses;
			// Error Check the User Input
			while ((!cin) || (nLosses > 13) || (nLosses < 0)){
				cout << "Error: Invalid Input; There are at most 13 games in a season: ";
				cin >> nLosses;
			}
			// Call Function
			nLossYears(losses, nLosses);
			break;

		case 4:
			// Call Function
			winningSzn(wins, losses);
			break;

		case 5:
			// Call Function
			losingSzn(wins, losses);
			break;

		case 6:
			// Thank User and Exit
			cout << "Thank you!" << endl;
			return 0;
		}
	}
}

// Function Definitions
void yearRecord(int wins[], int losses[], int year){

	// Variable Declaration
	int yearIndex = year - 1900;

	// Output
	cout << "Wins: " << wins[yearIndex] << ", ";
	cout << "Losses: " << losses[yearIndex] << endl;
}

void nWinYears(int wins[], int nWins){

	// Variable Declarations
	int year;
	int counter = 0; //counts entries outputted to preserve formatting

	// Initial Output
	cout << "Years with at least " << nWins << " wins:" << endl;

	// For Loop to Check Conditions and Output
	for (int i = 0; i < 117; i++){
		if (wins[i] >= nWins){
			counter++;
			year = i + 1900;
			cout << " " << year;
			if (counter == 5){
				counter = 0;
				cout << endl;
			}
		}
	}

	// Final Output
	cout << endl;
}

void nLossYears(int losses[], int nLosses){

	// Variable Declaration
	int year;
	int counter = 0; //counts output entries to preserve formatting

	// Initial Output
	cout << "Years with at least " << nLosses << " losses:" << endl;

	// For Loop to Check Conditions and Output
	for (int i = 0; i < 117; i++){
		if (losses[i] >= nLosses){
			counter++;
			year = i + 1900;
			cout << " " << year;
			if (counter == 5){
				counter = 0;
				cout << endl;
			}
		}
	}

	// Final Output
	cout << endl;
}

void winningSzn(int wins[], int losses[]){

	// Variable Declarations
	int year;
	int counter = 0; //counts output entries to preserve formatting

	// Initial Output
	cout << "Winning seasons:" << endl;

	// For Loop to Check Conditions and Output
	for (int i = 0; i < 117; i++){
		if (wins[i] > losses[i]){
			counter++;
			year = i + 1900;
			cout << " " << year;
			if (counter == 5){
				counter = 0;
				cout << endl;
			}
		}
	}

	// Final Output
	cout << endl;
}

void losingSzn(int wins[], int losses[]){

	// Variable Declarations
	int year;
	int counter = 0; //counts output entries to preserve formatting

	// Initial Output
	cout << "Losing seasons:" << endl;

	// For Loop to Check Conditions and Output
	for (int i = 0; i < 117; i++){
		if (wins[i] < losses[i]){
			counter++;
			year = i + 1900;
			cout << " " << year;
			if (counter == 5){
				counter = 0;
				cout << endl;
			}
		}
	}

	// Final Output
	cout << endl;
}
