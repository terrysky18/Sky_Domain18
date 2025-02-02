/*
Cpp-Finance.cpp :
A collection of C++ exercises specifically in finance
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "NumericIntegral.hpp"
#include "MortgageCalculator.hpp"
#include <complex>

using std::cout;
using std::cin;
using std::endl;
using std::complex;
using std::setprecision;
using std::setiosflags;
using std::ios;

double Integral1(double x);
double Integral2(double x);
double Integral3(double x);
double Integral4(double x);
void TestNumericIntegrals(double(*intg1)(double x), double(*intg2)(double x),
	double(*intg3)(double x), double(*intg4)(double x));
void TestComplexNum1();
void TestComplexNum2();

int main()
{
	int choice = 0;
	cout << "Enter 1 for numerical integration demo;" << endl;
	cout << "2 for complex number demo;" << endl;
	cout << "3 for Mortgage calculator;" << endl;
	cout << "Your selection: ";
	cin >> choice;

	if (choice == 1) {
		TestNumericIntegrals(Integral1, Integral2, Integral3, Integral4);
	}
	else if (choice == 2) {
		TestComplexNum1();
		TestComplexNum2();
	}
	else {
		MortgageCalculator my_mortgage = MortgageCalculator();

		double principal;
		cout << endl << "Enter the principal amount: ";
		cin >> principal;
		double down_payment;
		cout << "enter the down payment in percentage: ";
		cin >> down_payment;
		down_payment = down_payment / 100.00;

		double interest;
		cout << "enter the interest rate in percentage: ";
		cin >> interest;
		double years_of_loan;
		cout << "enter the years of the loan: ";
		cin >> years_of_loan;
		
		double first_down = principal * down_payment;
		principal = principal - first_down;
		my_mortgage.setInterestRate(interest);
		my_mortgage.setPrincipal(principal);
		my_mortgage.setLengthInYear(years_of_loan);
		double my_payment = my_mortgage.getMonthlyPayment();

		// Set wrappers to show 2 decimal places
		cout << endl << "Down payment: " << setiosflags(ios::fixed)
			<< setprecision(2) << first_down << endl;
		cout << endl << "Monthly payment: " << setiosflags(ios::fixed)
			<< setprecision(2) << my_payment << endl;
	}

# if !_debug
	system("pause");
#endif

    return 0;
}

void TestNumericIntegrals(double(*intg1)(double x), double(*intg2)(double x),
	double(*intg3)(double x), double(*intg4)(double x))
{
	const double pi = 3.1415926535897;

	int N = 5000;	// number of subdivision
	double A = 0.0;
	double B = 1.0;
	NumericIntegral nuIntg = NumericIntegral();

	double d1 = nuIntg.MidpointRuleIntegral(intg1, A, B, N);
	cout << "Midpoint rule approximate integral 1 is: " << d1 << endl;
	double t1 = nuIntg.TanhRuleIntegral(Integral1, A, B, N);
	cout << "Tanh rule approximate integral 1 is: " << t1 << endl;
	cout << "Exact value: " << -pi*pi / 6.0 << endl << endl;

	double d2 = nuIntg.MidpointRuleIntegral(intg2, A, B, N);
	cout << "Midpoint rule approximate integral 2 is: " << d2 << endl;
	double t2 = nuIntg.TanhRuleIntegral(Integral2, A, B, N);
	cout << "Tanh rule approximate integral 2 is: " << t2 << endl;
	cout << "Exact value: " << -pi*pi / 8.0 << endl << endl;

	double d3 = nuIntg.MidpointRuleIntegral(intg3, A, B, N);
	cout << "Midpoint rule approximate integral 3 is: " << d3 << endl;
	double t3 = nuIntg.TanhRuleIntegral(Integral3, A, B, N);
	cout << "Tanh rule approximate integral 2 is: " << t3 << endl;
	cout << "Exact value: " << pi*pi / 4.0 << endl << endl;

	cout << "a = " << 5 << endl << "b = " << 2.5 << endl;
	cout << "from 0 to pi" << endl;

	double d4 = nuIntg.MidpointRuleIntegral(intg4, 0.0, pi, N);
	cout << "Midpoint rule approximate integral 4 is: " << d4 << endl;
	double t4 = nuIntg.TanhRuleIntegral(Integral4, 0.0, pi, N);
	cout << "Tanh rule approximate integral 4 is: " << t4 << endl;
	cout << "Exact value: " << pi / (sqrt(5.0*5.0 - 2.5*2.5)) << endl << endl;
}

void TestComplexNum1()
{
	complex<double> z1(-23.0, 5.3);
	complex<double> z2(2.0, 3.0);

	complex<double> z3 = z1 * z2;
	complex<double> z4 = 2.0 * z4;
	complex<double> z5 = -z3;

	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	cout << z1 << " x " << z2 << " = " << z3 << endl;
	cout << "-z3 = " << z5 << endl;
	cout << "****\n";

	complex<double> z6 = z2 * 2.0;
	complex<double> z7 = 2.0 * z2;
	complex<double> z8 = z2 * 2.0;
	complex<double> z9 = z6 * z7;

	cout << z2 << " x 2.0 = " << z6 << endl;
	cout << "2.0 x " << z2 << " = " << z7 << endl;
	cout << z2 << " x 2.0 = " << z8 << endl;
	cout << "****\n";

	complex<double> z10 = z1 + z2;
	cout << z1 << " + " << z2 << " = " << z10 << endl;

	complex<double> z0(1.0, 2.0);
	z4 = z3 = z1 = z0;
	cout << "Chain: " << z0 << " " << z1 << " " << z3 << " " << z4 << endl;

	cout << z4;
	z4 += z1;		// Multiply z4 by z1 and modify it
	cout << " += " << z1 << " => " << z4 << endl;
}

void TestComplexNum2()
{
	complex<int> z1(12, 8);
	complex<double> z2(5.83, 22.613);

	cout << endl << "z1 = " << z1 << endl;
	cout << "sin(z1) = " << sin(z1) << endl;
	cout << "cos(z1) = " << cos(z1) << endl;
	cout << "tan(z1) = " << tan(z1) << endl;
	
	cout << endl << "z2 = " << z2 << endl;
	cout << "sin(z2) = " << sin(z2) << endl;
	cout << "cos(z2) = " << cos(z2) << endl;
	cout << "tan(z2) = " << tan(z2) << endl;
	cout << "asin(z2) = " << asin(z2) << endl;
	cout << "acos(z2) = " << acos(z2) << endl;
	cout << "atan(z2) = " << atan(z2) << endl;
	cout << "sinh(z2) = " << sinh(z2) << endl;
	cout << "cosh(z2) = " << cosh(z2) << endl;
	cout << "tanh(z2) = " << tanh(z2) << endl;
	cout << "asinh(z2) = " << asinh(z2) << endl;
	cout << "acosh(z2) = " << acosh(z2) << endl;
	cout << "atanh(z2) = " << atanh(z2) << endl;
	cout << "exp(z2) = " << exp(z2) << endl;
	cout << "ln(z2) = " << log(z2) << endl;
	cout << "log10(z2) = " << log10(z2) << endl;
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

