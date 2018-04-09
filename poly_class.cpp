/* -----------------------------------------------------------------------------

FILE NAME:         poly_class.cpp
DESCRIPTION:       This is a test driver for my polynomial class. It test the class functions to ensure that they are all working
USAGE:             all that has to be done is to compile the code and run the program. no user interface due to this being a test drive file. Test script named test.sh is available 
COMPILER:          g++ compiler c++11 standard
NOTES:             

MODIFICATION HISTORY:

Author             Date           Modification(s)
----------------   -----------    ---------------
Peter Kilonzo      2018-03-26     Version 1
Peter Kilonzo      2018-03-28     Version 2
Peter Kilonzo      2018-03-30     Version 3
Peter Kilonzo      2018-03-30     Version 4
Peter Kilonzo      2018-04-04     Version 5
Peter Kilonzo      2018-04-05     Version 6
----------------------------------------------------------------------------- */

#include "Polynomial.h"    //Specification file



int main(int argc, char* argv[])
{
	Polynomial poly[3];
	

	for(int n = 0; n < 2; ++n)
	{
		cin >> poly[n];
		cout << poly[n];
	}
	cout << "\nTesting addition:       ";
	poly[2] = (poly[0] + poly[1]);

	cout << poly[2];

	cout << "\nTesting subtraction:    ";
	//Polynomial sub;
	poly[2] = (poly[0] - poly[1]);

	cout << poly[2];
	cout << "\nTesting multiplication: ";
	poly[2] = (poly[0] * poly[1]);
	cout << poly[2];
	cout << endl;
	cout << endl;

	Polynomial te, mt;

	te = poly[0] = poly[1];
	cout << "\nTesting assignment";
	cout << "\noriginal: ";
	cout << poly[1];
	cout << "\ncopy: ";
	cout << te;

	cout << "\nTesting equivalency operator";
	cout << "\nTest for " << te << " equal to " << poly[1];
	te == poly[1];
	cout << "\nTest for " << te << " equal to " << poly[2];
	te == poly[2]; 

	cout << "\nTesting function evaluation for\n" << te;
	te(5);
	cout << "\nTesting function differentiation: ";
	mt = te--;
	cout <<"\n" << mt;
	cout << "\nTesting function integration: ";
	mt = te++;
	cout <<"\n" << mt;

	
	
	cout << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	return 0;
}
