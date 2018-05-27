/*
Header file
A class for calculating mortgage payments and others
*/

#ifndef MortgageCalculator_HPP
#define MortgageCalculator_HPP

#include <cstring>
using std::string;

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
	string getAmortisation();

private:
	double principal;
	double interest_rate;
	double life_in_year;
	double life_in_month;
	double month_payment;
	double monthly_interest;

	double current_interest_payment;
	double current_principal_payment;
	double current_balance;
	int current_loan_month;

	void findMonthPayment();
};

#endif	// !MortgageCalculator_HPP
