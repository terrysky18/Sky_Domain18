/*
Cpp-Finance.cpp :
A collection of C++ exercises specifically in finance
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

double NumCubed(double x);
double Logfunc(double x);
double MidpointRuleIntegral(double(*func)(double x), double A, double B, int N);

int main()
{
	const double pi = 3.1415926535897;

	int N = 2000;	// number of subdivision
	double A = 0.0;
	double B = 1.0;

	double d = MidpointRuleIntegral(NumCubed, A, B, N);
	cout << "Approximate integral Midpoint rule is: " << d << endl;

	double d2 = MidpointRuleIntegral(Logfunc, A, B, N);
	cout << "Approximate integral is: " << d2 << endl;
	cout << "Exact value: " << -pi*pi / 6.0 << endl;
	
# if !_debug
	system("pause");
#endif

    return 0;
}

double NumCubed(double x) { return x*x*x; }
double Logfunc(double x) { return log(x) / (1.0 - x); }

// Demonstrate the use of function pointer as a parameter
double MidpointRuleIntegral(double(*func)(double x), double A, double B, int N)
{	// Integrate func on the interval [A, B] using the midpoint rule
	double res = 0.0;
	double h = (B - A) / double(N);	// integral steps
	for (double x = A + (0.5*h); x < B; x += h)
	{
		res += func(x);	// call the function
	}
	return res*h;
}

