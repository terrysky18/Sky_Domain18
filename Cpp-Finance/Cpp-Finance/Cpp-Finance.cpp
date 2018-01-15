/*
Cpp-Finance.cpp :
A collection of C++ exercises specifically in finance
*/

#include "stdafx.h"
#include <iostream>
#include "NumericIntegral.h"

using std::cout;
using std::cin;
using std::endl;

double Integral1(double x);
double Integral2(double x);
double Integral3(double x);
double Integral4(double x);

int main()
{
	const double pi = 3.1415926535897;

	int N = 5000;	// number of subdivision
	double A = 0.0;
	double B = 1.0;
	NumericIntegral nuIntg = NumericIntegral();

	double d1 = nuIntg.MidpointRuleIntegral(Integral1, A, B, N);
	cout << "Midpoint rule approximate integral 1 is: " << d1 << endl;
	double t1 = nuIntg.TanhRuleIntegral(Integral1, A, B, N);
	cout << "Tanh rule approximate integral 1 is: " << t1 << endl;
	cout << "Exact value: " << -pi*pi / 6.0 << endl << endl;
	
	double d2 = nuIntg.MidpointRuleIntegral(Integral2, A, B, N);
	cout << "Midpoint rule approximate integral 2 is: " << d2 << endl;
	double t2 = nuIntg.TanhRuleIntegral(Integral2, A, B, N);
	cout << "Tanh rule approximate integral 2 is: " << t2 << endl;
	cout << "Exact value: " << -pi*pi / 8.0 << endl << endl;

	double d3 = nuIntg.MidpointRuleIntegral(Integral3, A, B, N);
	cout << "Midpoint rule approximate integral 3 is: " << d3 << endl;
	double t3 = nuIntg.TanhRuleIntegral(Integral3, A, B, N);
	cout << "Tanh rule approximate integral 2 is: " << t3 << endl;
	cout << "Exact value: " << pi*pi / 4.0 << endl << endl;

	cout << "a = " << 5 << endl << "b = " << 2.5 << endl;
	cout << "from 0 to pi" << endl;

	double d4 = nuIntg.MidpointRuleIntegral(Integral4, 0.0, pi, N);
	cout << "Midpoint rule approximate integral 4 is: " << d4 << endl;
	double t4 = nuIntg.TanhRuleIntegral(Integral4, 0.0, pi, N);
	cout << "Tanh rule approximate integral 4 is: " << t4 << endl;
	cout << "Exact value: " << pi / (sqrt(5.0*5.0 - 2.5*2.5)) << endl << endl;

# if !_debug
	system("pause");
#endif

    return 0;
}


double Integral1(double x)
{	// log(x)/(1-x)
	return log(x) / (1.0 - x);
}

double Integral2(double x)
{	// log(x)/(1-x^2)
	return log(x) / (1.0 - x*x);
}

double Integral3(double x)
{	// log((1+x)/(1-x))
	return log((1.0 + x) / (1.0 - x)) / x;
}

double Integral4(double x)
{	// 1/(a+b*cos(x)) from 0 to pi; a>b>0
	double a = 5.0;
	double b = 2.5;
	return 1.0 / (a + b*cos(x));
}

