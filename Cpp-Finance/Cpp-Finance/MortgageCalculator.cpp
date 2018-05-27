#include "stdafx.h"
#include "MortgageCalculator.hpp"
#include <cmath>
#include <iostream>
#include <cstring>

using std::string;

// Initialiser Constructor
MortgageCalculator::MortgageCalculator()
{
	principal = 0;
	interest_rate = 0.0;
	life_in_year = 0;
	life_in_month = life_in_year * 12;
	monthly_interest = interest_rate / 12;
	month_payment = 0.0;

	current_interest_payment = 0.0;
	current_principal_payment = 0.0;
	current_balance = principal;
	current_loan_month = 0;
}

// Destructor
MortgageCalculator::~MortgageCalculator()
{}

double MortgageCalculator::getPrincipal()
{
	return principal;
}

double MortgageCalculator::getInterestRate()
{
	return interest_rate;
}

double MortgageCalculator::getPaymentLengthYear()
{
	return life_in_year;
}

double MortgageCalculator::getPaymentLengthMonth()
{
	return life_in_month;
}

double MortgageCalculator::getMonthlyPayment()
{
	if (month_payment == 0.0) {
		// calculate the monthly payment if it hasn't been done
		findMonthPayment();
	}

	return month_payment;
}

string MortgageCalculator::getAmortisation()
{
	string result = "";
	for (current_loan_month = 1; current_loan_month < life_in_month; current_loan_month++) {
		result += "CM:  ";

	}
}

void MortgageCalculator::setPrincipal(double principal_amount)
{
	principal = principal_amount;
}

void MortgageCalculator::setInterestRate(double interest)
{
	// interest parameter in percentage
	interest_rate = interest / 100;
	monthly_interest = interest_rate / 12;
}

void MortgageCalculator::setLengthInYear(double years_of_loan)
{
	life_in_year = years_of_loan;
	life_in_month = life_in_year * 12;
}

void MortgageCalculator::findMonthPayment()
{
	// Calculate the fixed monthly payment
	month_payment = principal * (monthly_interest / (1.0 - (pow(1.0 + monthly_interest, -life_in_month))));
}
