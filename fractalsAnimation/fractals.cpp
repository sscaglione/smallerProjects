// Samantha Scaglione
// Lab 11: Fractals
//	fractals.cpp is a program that
//	will open a window and wait for
//	user input then, when the user
//	presses any number 1 to 8, clears
//	the screen and draws the
//	corresponding fractal shape

// Preprocessor Directives
#include "gfx.h"
#include <cmath>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

// Funtion Prototypes
void drawTriangle (int, int, int, int, int, int);
void drawSquare (int, int, int, int, int, int, int, int);
void sierpinski (int, int, int, int, int, int);
void shrinkingSquares(int, int, int, int, int, int, int, int);
void spiralSquares(int, int, int, float, int);
void circLace(int, int, int);
void snowflake(int, int, int);
void tree(int, int, float, float);
void fern(int, int, float, float);
void spiralSpirals(int, int, float);

// Main Function
int main(){
	// Variable Declarations
	int windowW = 800; // initializing window width
	int windowH = 800; // initializing window height
	int xC = windowW/2; // x center point
	int yC = windowH/2; // y center point
	int loop = 1; // psuedo-boolean to loop
	char c; // choice
	float length, theta, sf; // declaring length, angle, and scaling factor
	int x1, y1, x2, y2, x3, y3, x4, y4, r; // declaring points and radius
	x1 = y1 = x2 = y2 = x3 = y3 = x4 = y4 = r = 0; // initializing all to zero
	int n; // a factor to add to points for declarations
	// Open Window
	gfx_open(windowW, windowH, "fractals.cpp");

	// Display Text Menu to User
	cout << "Welcome to Fun with Fractals!" << endl;
	cout << "1 for Sierpinski Triangle" << endl;
	cout << "2 for Shrinking Squares" << endl;
	cout << "3 for Spiral Squares" << endl;
	cout << "4 for Circular Lace" << endl;
	cout << "5 for Snowflake" << endl;
	cout << "6 for Tree" << endl;
	cout << "7 for Fern" << endl;
	cout << "8 for Spiral of Spirals" << endl;
	// Check for User Input
	while (loop) {
		c = gfx_wait();
		switch (c) {
			case '1':
				// Clear Window
				gfx_clear();
				// Set Initial Points
				n = 360;
				x1 = xC;
				y1 = yC - n/2 - 100;
				x2 = xC - n;
				y2 = yC + n - 100;
				x3 = xC + n;
				y3 = yC + n - 100;
				// Call Function
				sierpinski(x1, y1, x2, y2, x3, y3);
				// Break
				break;
			case '2':
				// Clear Window
				gfx_clear();
				// Set Initial Points
				n = 200;
				x1 = xC - n;
				y1 = yC - n;
				x2 = xC + n;
				y2 = yC - n;
				x3 = xC + n;
				y3 = yC + n;
				x4 = xC - n;
				y4 = yC + n;
				// Call Function
				shrinkingSquares(x1, y1, x2, y2, x3, y3, x4, y4);
				// Break
				break;
			case '3':
				// Clear Window
				gfx_clear();
				// Initialize Variables
				theta = M_PI/6;
				n = 5;
				length = 50;
				// Call Function
				spiralSquares(xC, yC, length, theta, n);
				// Break
				break;
			case '4':
				// Clear Screen
				gfx_clear();
				// Set Initial Points and Radius
				x1 = 400;
				y1 = 400;
				r = 250;
				// Call Function
				circLace(x1, y1, r);
				// Break
				break;
			case '5':
				// Clear Screen
				gfx_clear();
				// Initialize Variables
				r = 250;
				// Call Function
				snowflake(xC, yC, r);
				// Break
				break;
			case '6':
				// Clear Screen
				gfx_clear();
				// Initialize Variables and Draw Trunk
				x1 = 400;
				y1 = 500;
				x2 = 400;
				y2 = 700;
				length = 800;
				theta = 3*M_PI/2;
				length = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
				x3 = 400;
				y3 = 800;
				gfx_line(x1, y1, x3, y3);
				// Call Function
				tree(x1, y1, length, theta);
				// Break
				break;
			case '7':
				// Clear Screen
				gfx_clear();
				// Initialize Variables
				x1 = 400;
				y1 = 800;
				length = 400;
				theta = -M_PI/2;
				// Call Function
				fern(x1, y1, length, theta);
				// Break
				break;
			case '8':
				// Clear Screen
				gfx_clear();
				// Initialize Variables
				sf = 25;
				// Call Function
				spiralSpirals(xC, yC, sf);
				// Break
				break;
			case 'q':
				loop = 0;
				c = 0;
				break;
		}
	}
	return 0;
}

// Function Declarations
void drawTriangle (int x1, int y1, int x2, int y2, int x3, int y3){
	// Draw First Side
	gfx_line (x1, y1, x2, y2);
	// Draw Second Side
	gfx_line (x1, y1, x3, y3);
	// Draw Third Side
	gfx_line (x2, y2, x3, y3);
	// Flush to the Window
	gfx_flush();
}

void drawSquare (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	// Draw First Side
	gfx_line (x1, y1, x2, y2);
	// Draw Second Side
	gfx_line (x2, y2, x3, y3);
	// Draw Third Side
	gfx_line (x3, y3, x4, y4);
	// Draw Fourth Side
	gfx_line (x4, y4, x1, y1);
	// Flush to the Window
	gfx_flush();
}

void sierpinski (int x1, int y1, int x2, int y2, int x3, int y3){
	// Base Case
	if (abs(x2-x1) < 5)
		return;
	// Draw Triangle
	drawTriangle(x1, y1, x2, y2, x3, y3);
	// Recursive Calls
	sierpinski(x1, y1, (x1 + x2)/2, (y1 + y2)/2, (x1 + x3)/2, (y1 + y3)/2);
	sierpinski((x1 + x2)/2, (y1 + y2)/2, x2, y2, (x2 + x3)/2, (y2 + y3)/2);
	sierpinski((x1 + x3)/2, (y1 + y3)/2, (x2 + x3)/2, (y2 + y3)/2, x3, y3);
	usleep(2000);
}

void shrinkingSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	// Variable Declaration
	double length;
	// Base Case
	if (abs(x2-x1) < 2)
		return;
	// Draw Square
	drawSquare(x1, y1, x2, y2, x3, y3, x4, y4);
	// Recursive Calls
	length = 9*(x2 - x1)/20;
	shrinkingSquares(x1 - length/2, y1 - length/2, x1 + length/2, y1 - length/2, x1 + length/2, y1 + length/2, x1 - length/2, y1 + length/2);
	shrinkingSquares(x2 - length/2, y2 - length/2, x2 + length/2, y2 - length/2, x2 + length/2, y2 + length/2, x2 - length/2, y2 + length/2);
	shrinkingSquares(x3 - length/2, y3 - length/2, x3 + length/2, y3 - length/2, x3 + length/2, y3 + length/2, x3 - length/2, y3 + length/2);
	shrinkingSquares(x4 - length/2, y4 - length/2, x4 + length/2, y4 - length/2, x4 + length/2, y4 + length/2, x4 - length/2, y4 + length/2);
	usleep(2000);
}
void spiralSquares(int xC, int yC, int length, float theta, int n){
	// Variable Declaration
	int x1, x2, x3, x4, y1, y2, y3, y4;
	// Set Initial Points
	x1 = xC - n;
	y1 = yC - n;
	x2 = xC + n;
	y2 = yC - n;
	x3 = xC + n;
	y3 = yC + n;
	x4 = xC - n;
	y4 = yC + n;
	// Base Case
	if (abs(x2 - x1) > 150)
		return;
	// Draw Square
	drawSquare(x1, y1, x2, y2, x3, y3, x4, y4);
	// Recursive Calls
	theta += M_PI/3;
	n *= 1.3;
	length *= 1.25;
	spiralSquares(xC + length*cos(theta), yC + length*sin(theta), length, theta, n);
}
void circLace(int x1, int y1, int r){
	// Variable Declaration
	float theta = 0;
	int xNew, yNew, rNew;
	// Base Case
	if (abs(r) < 1)
		return;
	// Draw Circle
	gfx_circle(x1, y1, r);
	gfx_flush();
	// Recursive Call
	for (int i = 0; i < 6; i++){
		xNew = x1 + r*cos(theta);
		yNew = y1 + r*sin(theta);
		rNew = r/3;
		circLace(xNew, yNew, rNew);
		theta += M_PI/3;
	}
	usleep(2000);
}
void snowflake(int xC, int yC, int r){
	// Variable Declaration
	float theta = 2*M_PI/5;
	// Base Case
	if (abs(r) < 1)
		return;
	// Draw Snowflake and make recursive call
	for (int i = 0; i < 5; i++){
		gfx_line(xC, yC, xC + r*cos(theta*i), yC + r*sin(theta*i));
		snowflake (xC + r*cos(theta*i), yC + r*sin(theta*i), r/3);
	}
	usleep(1000);
}
void tree(int x1, int y1, float length, float theta){
	int x2 = 400, y2 = 700, x3 = 400, y3 = 800;
	// Base Case
	if (length < 1)
		return;
	// Draw
	gfx_line(x1, y1, x1 + length*cos(theta + M_PI/6), y1+length*sin(theta + M_PI/6));
	gfx_line(x1, y1, x1 + length*cos(theta - M_PI/6), y1+length*sin(theta - M_PI/6));
	// Recursive Call
	tree(x1 + length*cos(theta + M_PI/6), y1 + length*sin(theta + M_PI/6), length*.6, theta + M_PI/6);
	tree(x1 + length*cos(theta - M_PI/6), y1 + length*sin(theta - M_PI/6), length*.6, theta - M_PI/6);
	usleep(500);
}

void fern(int x1, int y1, float length, float theta){
	// Base Case
	if (length < 8)
		return;
	// Draw
	usleep(200);
	gfx_line(x1, y1, x1 + length*cos(theta), y1 + length*sin(theta));
	// Recursive Call
	for (float i = .4; i <= 1; i += .2){
		fern(x1 + length*i*cos(theta), y1+length*i*sin(theta), length * .4, theta +	M_PI/6);
		fern(x1 + length*i*cos(theta), y1+length*i*sin(theta), length * .4, theta - M_PI/6);
	}
}
void spiralSpirals(int x, int y, float a){
	// Variable Declaration
	float r, theta;
	// Base Case
	if (a < .9)
		return;
	// Call
	for (theta = 0; theta < 12*M_PI; theta += M_PI/12){
		r = a*exp(theta/6);
		gfx_point(x + r*cos(theta), y + r*sin(theta));
		spiralSpirals(x + r*cos(theta), y + r*sin(theta), a/6);
	}
}
