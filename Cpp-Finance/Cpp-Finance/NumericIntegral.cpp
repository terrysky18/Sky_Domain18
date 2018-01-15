#include "stdafx.h"
#include "NumericIntegral.h"
#include <math.h>

// Constructor
NumericIntegral::NumericIntegral()
{
	result = 0.0;
}

// Destructor
NumericIntegral::~NumericIntegral()
{}

// Demonstrate the use of function pointer as a parameter
double NumericIntegral::MidpointRuleIntegral(double(*func)(double x), double lower, double upper, int steps)
{	// Integrate func on the interval [lower, upper] using the midpoint rule
	double res = 0.0;
	double h = (upper - lower) / double(steps);	// integral step
	for (double x = lower + (0.5*h); x < upper; x += h)
	{
		res += func(x);	// call the function
	}
	result = res*h;
	return result;
}

double NumericIntegral::TwoMidpointRuleIntegral(double(*func)(double x, double y),
	double lower1, double upper1, double lower2, double upper2, int steps1, int steps2)
{
	double res = 0.0;
	double h1 = (upper1 - lower1) / double(steps1);
	double h2 = (upper2 - lower2) / double(steps2);
	for (double y = lower1 + (0.5*h1); y < upper1; y += h1)
	{
		for (double x = lower2 + (0.5*h2); x < upper2; x += h2)
		{
			double m1 = (upper1 + lower1) / 2.0;	// midpoint1
			double m2 = (upper2 + lower2) / 2.0;	// midpoint2
			res += h1*h2*func(m1, m2);
		}
	}
	result = res;
	return result;
}

double NumericIntegral::TanhRuleIntegral(double(*func)(double x), double lower, double upper, int steps)
{	// Integrate func on the interval [lower, upper] using the Tanh rule
	double res = 0.0;
	double h = (upper - lower) / double(steps);	// integral step
	for (double x = lower + (0.5*h); x < upper; x += h)
	{
		res += tanh((*func)(x) * 0.5 * h);
	}
	result = 2.0*res;
	return result;
}

double NumericIntegral::GetResult()
{
	return result;
}

