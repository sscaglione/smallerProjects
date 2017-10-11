// Samantha Scaglione
// Lab02
// 	mortgage.cpp
//	This program asks the user to
//	input 3 values: the principal,
//	the interest rate, and the desired
//	monthly payment then displays an
//	amortization table as well
//	as how long it took to pay off the
//	mortgage and the total amount of
//	payments over that time
//

//Preprocessing Directives
#include <iostream>
#include <iomanip>
using namespace std;

//Main function

int main(){
	//initialize variables
	double principal, interestRateA, interestRateM, interest, desiredMonthlyPayment, balance,  total;
	int month;
	//take user i/o
	cout << "Enter the principal: ";
	cin >> principal;
	cout << "Enter the annual interest rate (in decimal form, i.e. 5%=.05): ";
	cin >> interestRateA;
		if (interestRateA < 0){
			while (interestRateA < 0){
				cout << "Error: Invalid Interest Rate" << endl;
				cout << "Please enter a positive interest rate: ";
				cin >> interestRateA;
			}
		}
	interestRateM = interestRateA/12;
	cout << "Enter the desired monthly payment: ";
	cin >> desiredMonthlyPayment;
	if (desiredMonthlyPayment < interestRateM*balance){
		cout << "Error: Interest is higher than payment. You'll be paying this off forever" << endl;
		return 1;
	}

	//initialize variables with known values
	balance = principal; //the balance is initially the principal
	month = 0; //the month is initially 0, will become 1 during first run of the for loop
	total = 0; //the total is initially 0

	//set header
	cout << setw(20) << "Month";
	cout << setw(20) << "Payment";
	cout << setw(20) << "Interest";
	cout << setw(20) << "Balance" << endl;

	//establish while loop, while there is still money to pay off
	while (balance > 0){
		month++;
		interest = interestRateM*balance;
		balance = balance + interest;
		if (balance >= desiredMonthlyPayment){
			desiredMonthlyPayment = desiredMonthlyPayment;
			balance = balance - desiredMonthlyPayment;
			total = total + desiredMonthlyPayment;
		}
		else{
			desiredMonthlyPayment = balance;
			balance = 0;
			total = total + desiredMonthlyPayment;
		}
		for (int i = 0; i<4; i++){
			if (i == 0)
				cout << setw(20) << month;
			else if (i == 1)
				cout << setw(20) << setprecision(2) << desiredMonthlyPayment;
			else if (i ==2)
				cout << setw(20) << setprecision(2) << interest;
			else
				cout  << setw(20) << setprecision(2) << balance << endl;
		}
	}
	cout << "You paid a total of $" << total << " over " << month/12 << " years and " << month%12 << " months." << endl;
	return 0;
}
