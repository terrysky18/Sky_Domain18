/*
Header file
A class for calculating mortgage payments and others
*/

#ifndef MortgageCalculator_HPP
#define MortgageCalculator_HPP

class MortgageCalculator
{
public:
	// Constructor and destructor
	MortgageCalculator();
	virtual ~MortgageCalculator();

	// Accessors and modifiers
	double getPrincipal();
	double getInterestRate();
	double getPaymentLengthYear();
	double getPaymentLengthMonth();
	void setPrincipal(double principal_amount);
	void setInterestRate(double interest);
	void setLengthInYear(double years_of_loan);

	double getMonthlyPayment();

private:
	double principal;
	double interest_rate;
	double life_in_year;
	double life_in_month;
	double month_payment;
	double monthly_interest;

	void findMonthPayment();
};

#endif	// !MortgageCalculator_HPP
