/*
NumericIntegral.hpp

Header file
A class to calculate numeric integrals with different methods
*/

#ifndef NumericIntegral_HPP
#define NumericIntegral_HPP

class NumericIntegral
{
public:
	NumericIntegral();
	virtual ~NumericIntegral();
	double MidpointRuleIntegral(double (*func)(double x), double lower, double upper, int steps);
	double TwoMidpointRuleIntegral(double (*func)(double x, double y),
			double lower1, double upper1, double lower2, double upper2, int steps1, int steps2);
	double TanhRuleIntegral(double (*func)(double x), double lower, double upper, int steps);

	double GetResult();

private:
	double result;
};

#endif // !NumericIntegral_HPP
