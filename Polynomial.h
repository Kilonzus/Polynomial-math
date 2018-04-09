/* -----------------------------------------------------------------------------

FILE NAME:         Polynomial.h
DESCRIPTION:       This is the header file for Polynomial.cpp that contains the definition of the class as well as all the the #define and #include
USAGE:             linked to other files via .o file
COMPILER:          g++ compiler c++11 standard
NOTES:             used pragma once instead of the Def h syntax.

MODIFICATION HISTORY:

Author             Date           Modification(s)
----------------   -----------    ---------------
Peter Kilonzo      2018-03-26     Version 1
Peter Kilonzo      2018-03-28     Version 2
Peter Kilonzo      2018-03-30     Version 3
Peter Kilonzo      2018-03-30     Version 4
Peter Kilonzo      2018-04-04     Version 5
----------------------------------------------------------------------------- */
//Header file for polynomial.cpp

#pragma once
#include <iostream>
#include <cmath>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

const char PROGRAMMER_NAME[] = "Peter Kilonzo"; // Ony global constant

using namespace std;

class Polynomial
{
	friend ostream& operator << (ostream &strm, const Polynomial &p);
	friend istream& operator >> (istream &istrm, Polynomial &p);

	private:
	int degree;     //Degree of the polynomial
	int coef[9];     //Array of Coefficients

	public:
	Polynomial();
	~Polynomial();
	Polynomial(const Polynomial &);
	Polynomial(int kr, int coe[9]);
	
	Polynomial operator +(const Polynomial &); //Overloaded + operator used to add two polynomials
	Polynomial& operator =(const Polynomial &); //Overlaoded = operator used to set two polynomials equal to eachother
	Polynomial operator -(const Polynomial &); // overloaded - operator used to set a polynomial equal to another one
	Polynomial operator *(const Polynomial &);
	Polynomial operator ==(const Polynomial &);
	Polynomial operator ()(const float &);
	Polynomial operator --(int k);
	Polynomial operator ++(int j);
	
};
