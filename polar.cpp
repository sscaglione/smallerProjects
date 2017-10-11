// Samantha Scaglione
// Lab 3
// Part 2: Quadrants and Polar Coordinates
//	This program will prompt the user for x
//	and y coordinates then find and display
//	the point's corresponding polar coordinates
//	and the quadrant that the point is in (or
//	the axis or the origin if that is the case)

//preprocessor directives
#include <iostream>
#include <math.h>
using namespace std;

//function prototypes
double getPolarRadius(double x, double y);
double getPolarAngle(double x, double y);
int getQuadrant(double x, double y);

//main function
int main() {

	double x,y,polarRadius,polarAngle; //declaring double variables
	int quadrant; //declaring int variable

	cout << "Enter an x coordinate: "; //prompt user input
	cin >> x; //store user input
	while (!cin) { //error check
		cout << "Error: Invalid Entry; Enter an x coordinate: ";
		cin >> x;
	}

	cout << "Enter a y coordinate: "; //prompt user input
	cin >> y; //store user input
	while (!cin) { //error check
		cout << "Error: Invalid Entry; Enter a y coordinate: ";
		cin >> y;
	}

	polarRadius = getPolarRadius(x,y);
	polarAngle = getPolarAngle(x,y);
	quadrant = getQuadrant(x,y);

	cout << "The polar coordinates that correspond to the cartesian point (" << x << ", " << y << ") are (" << polarRadius << ", " << polarAngle << ")." << endl;
	if ((quadrant > 0) && (quadrant < 5))
		cout << "The point falls in quadrant " << quadrant << "." << endl;
	else if (quadrant == 0)
		cout << "The point falls on the origin." << endl;
	else if (quadrant == 5)
		cout << "The point falls on the y axis." << endl;
	else if (quadrant == 6)
		cout << "The point falls on the x axis." << endl;

	return 0;
}


//function definitions
double getPolarRadius(double x, double y){
	double polarRadius; //declare variable
	polarRadius = sqrt(x*x + y*y); //calculate radius
	return polarRadius; //return radius
}

double getPolarAngle(double x, double y){
	double polarAngle; //declare variable
	if (x != 0) //you can't divide by zero
		polarAngle = atan(y/x); //calculate angle
	else if (y == 0)
		polarAngle = 0;
	else if (y > 0)
		polarAngle = 90;
	else if (y < 0)
		polarAngle = 270;
	return polarAngle; //return angle
}

int getQuadrant(double x, double y){
	int quadrant; //declare variable
	// conditionals
	if ((x > 0)&&(y > 0))
		quadrant = 1;
	else if ((x < 0) && (y > 0))
		quadrant = 2;
	else if ((x < 0) && (y < 0))
		quadrant = 3;
	else if ((x > 0) && (y < 0))
		quadrant = 4;
	else {
		if ((x == 0) && (y == 0))
			quadrant = 0;
		else if (x==0)
			quadrant = 5;
		else
			quadrant = 6;
	}
	return quadrant;
}
