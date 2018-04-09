/* -----------------------------------------------------------------------------

FILE NAME:         Polynomial.cpp
DESCRIPTION:       This is the implementation file for the polynomial class.
USAGE:             This program is linkked to the driver via a .o file
COMPILER:          g++ compiler c++11 standard
NOTES:             Some cout statements are included here just to let the user know what exactly is going on

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



#include "Polynomial.h"

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial()
PURPOSE:           default constructur
RETURNS:           Nothing (void function)
NOTES:             This is the default constructor that sets al the private members to 0
----------------------------------------------------------------------------- */
Polynomial::Polynomial()
{
	degree = 0;

	for(int i = 0; i < ARRAY_SIZE(coef); i++)
		coef[i]= 0;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     ~Polynomial()
PURPOSE:           Destructor
RETURNS:           Nothing (void function)
NOTES:             This destroys the polynomial class. Because I use static memory there is nothing in this class
----------------------------------------------------------------------------- */
Polynomial::~Polynomial()
{



}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial(const Polynomial &)
PURPOSE:           copy constructor
RETURNS:           Nothing (void function)
NOTES:             This copy constructor makes a Polynomial class with the values from another class
----------------------------------------------------------------------------- */
Polynomial::Polynomial(const Polynomial& tpoly)
{
	degree = tpoly.degree;
	for(int i = 0; i < ARRAY_SIZE(coef); i++)
		coef[i]= tpoly.coef[i];

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial(int kr, int coe[9])
PURPOSE:           Overloaded (parameterized) constructor
RETURNS:           Nothing (void function)
NOTES:             This constructor takes two valules and initialized the cass with the values passed to it.
----------------------------------------------------------------------------- */
Polynomial::Polynomial(int kr, int coe[9])
{
	degree = kr;
	for (int i = 0; i < 9; i++)
		coef[i] = coe[i];

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator +(const Polynomial &)
PURPOSE:           This overloads the + operator to work with classes
RETURNS:           a polynomial class p2
NOTES:             This overloaded operator makes addition of two Polynomials with just a +
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);
	
	for (int i = degree; i >= 0; i--)
	{ p2.coef[i] = coef[i] + p1.coef[i]; }

	return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator -(const Polynomial &)
PURPOSE:           This overloads the - operator to work with classes
RETURNS:           p2
NOTES:             This overloaded operator makes subtractions of two polynomials possible with just a -
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator - (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);
	
	for (int i = degree; i >= 0; i--)
	{ p2.coef[i] = coef[i] - p1.coef[i]; }

	return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator =(const Polynomial &)
PURPOSE:           This overloads the = operator to work with classes
RETURNS:           *this
NOTES:             This overloaded operator sets one polynomial equal to another one, similar to the copy constructor. It returns *this which is the polynomial
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator = (const Polynomial &p1)
{

	degree = p1.degree;
	for (int i = p1.degree; i >= 0; i--)
	{ coef[i] = p1.coef[i]; }
	return *this;

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     friend ostream& operator << (ostream &strm, const Polynomial &p)
PURPOSE:           Streamline output of class
RETURNS:           strm with would be the stream of data to output
NOTES:             This makes output of polynomials classes possible with regular << outstream ouperator
----------------------------------------------------------------------------- */
ostream& operator << (ostream &strm, const Polynomial &p)
{

	for (int i = p.degree; i>= 0; i--)
	{
		if (i < p.degree)
		{
			if (p.coef[i] >= 0) strm << " + ";
			else strm << " ";
		}
	strm << p.coef[i];

	if (i > 1) strm << "x" << i;
	if (i==1) strm <<"x";
	} 
	return strm;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     friend ostream& operator << (ostream &strm, const Polynomial &p)
PURPOSE:           Streamline input of 
RETURNS:           istrm with would be the stream of input data
NOTES:             This makes input of polynomials classes possible with regular >> outstream ouperator
----------------------------------------------------------------------------- */
istream& operator >> (istream &istrm, Polynomial &p)
{

	cout << "\nDegree of polynomial: ";
	istrm >> p.degree;

	cout << "\n Enter " << p.degree+1 << " coefficients" << endl;
	for (int i = p.degree; i>= 0; i--){
		istrm >> p.coef[i];}
	return istrm;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator ==(const Polynomial &)
PURPOSE:           This fuctions test whether two Polynomials are equivalent
RETURNS:           Nothing
NOTES:             Just set two polynomials to the test with ==
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator ==(const Polynomial &p9)
{
	bool test = false;
	if (degree == p9.degree)
	{
	for (int i = p9.degree; i>= 0; i--)
	{
	
		if (coef[i] == p9.coef[i])
		{
		test = true;
		break;
		}
		else {test = false; break;}
	}
	
	}
	cout << "\nTrue indicates equal, false indicates inequal: " << boolalpha << test;
	
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator ()(const float &)
PURPOSE:           This function evaluates the value of a function at a certain value x
RETURNS:           Nothing
NOTES:             This mimics true mathematical evaluation, usage is polynomial_name(x)
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator ()(const float &tr)
{
	cout << "\nwith x = " << tr;
	int value = 0;
	float var = tr;
	for (int i = degree; i >= 0; i--)
	{ 
		value = value + ((pow(var, i)) * coef[i]);
	}
	cout << "\nf(x) with x = " << var << " comes to " << value;


}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator *(const Polynomial &)
PURPOSE:           Overload * operator
RETURNS:           A polynomial p5 that is a product of two polynomials
NOTES:             PThis overload operator makes the multiplication of polynomials simple with just a *
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator *(const Polynomial &p7)
{

	Polynomial p5;
	p5.degree = degree + p7.degree;
	for (int i = degree; i >= 0; i--)
	{
		for (int j = p7.degree; j >= 0; j--)
		{
			p5.coef[i+j] += coef[i] * p7.coef[j];
		}

	}
	
	return p5;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator --(int k)
PURPOSE:           Overload -- operator
RETURNS:           A polynomial p3 that is the derivative of a polynomial
NOTES:             This operator overload is accessed with -- i.e. p5 = p3--
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator --(int k)
{
	Polynomial p3;
	p3.degree = (degree - 1);
	for (int i = degree; i>= 0; i--)
	{
		p3.coef[i] = (coef[i+1] * (i+1)); 
	}
	return p3;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Polynomial operator ++(int j)
PURPOSE:           Overload ++ operator
RETURNS:           A polynomial p1 that is the integral of a polynomial
NOTES:             This operator overload is accessed with ++ i.e. p0 = p1 ++
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator ++(int j)
{
	Polynomial p1;
	p1.degree = (degree + 1);
	for (int i = degree; i>= 0; i--)
	{
		p1.coef[i+1] = (coef[i] / (i+1)); 
	}
	return p1;
}
