#include <iostream>
#include <iomanip>
using namespace std;

#include "InvestmentAmount.h"


InvestmentAmount::InvestmentAmount() {		// default constructor

}

InvestmentAmount::InvestmentAmount(double t_amount, double t_deposit, double t_percent, int t_year) {		// overloaded constructor
	m_initialAmount = t_amount;	
	m_monthlyDeposit = t_deposit;
	m_annualPercent = t_percent;
	m_years = t_year;
}

void InvestmentAmount::SetInitialAmount(double t_amount) {			// sets amounts, deposits, percent, and years
	m_initialAmount = t_amount;
}

void InvestmentAmount::SetMonthlyDeposit(double t_deposit) {
	m_monthlyDeposit = t_deposit;
}

void InvestmentAmount::SetAnnualPercent(double t_percent) {
	m_annualPercent = t_percent;
}

void InvestmentAmount::SetYears(int t_year) {
	m_years = t_year;
}

double InvestmentAmount::GetInitialAmount() const{					// gets amounts, deposits, percent and years
	return m_initialAmount;
}

double InvestmentAmount::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}

double InvestmentAmount::GetAnnualPercent() const {
	return m_annualPercent;
}

int InvestmentAmount::GetYears() const {
	return m_years;
}


					// finds the amount of interest added monthly with the interest rate, default for deposit is zero
double InvestmentAmount::FindMonthlyInterest(double& t_initialInvestment, double t_annualPercent, double t_monthlyDeposit = 0) {
	double monthlyInterest = (t_initialInvestment + t_monthlyDeposit) * ((t_annualPercent / 100) / 12);
	return monthlyInterest;

}


					// finds the balance at the end of the year, added together monthly with the interest rate, default for deposit is zero
double InvestmentAmount::FindYearlyBalance(double t_initialInvestment, double t_annualPercent, double t_monthlyDeposit = 0) {
	int i;

	for (i = 0; i < 12; ++i) {
		t_initialInvestment = t_initialInvestment + t_monthlyDeposit + FindMonthlyInterest(t_initialInvestment, t_annualPercent, t_monthlyDeposit);
	}
	return t_initialInvestment;

	
}


					// print screen for data values with user inputs
void InvestmentAmount::Print(double t_initialInvestment, double t_monthlyDeposit, double t_annualPercent, int t_year) {
	cout << setw(34) << setfill('*') << "" << endl;
	cout << setw(10) << setfill('*') << "";
	cout << " Data Values ";
	cout << setw(11) << setfill('*') << "" << endl;
	cout << "Initial Investment Amount: $" << t_initialInvestment << endl;
	cout << "Monthly Deposit: $" << t_monthlyDeposit << endl;
	cout << "Annual Interest: %" << t_annualPercent << endl;
	cout << "Number of years: " << t_year << endl;
	cout << "Press enter to continue . . ." << endl;
	cin.get();
}


					// prints the balance sheet with no additional deposits being made
double InvestmentAmount::BalanceBoardNoDeposits(int t_year, double t_initialInvestment, double t_annualPercent) {
	int i;

	cout << fixed << setprecision(2);		// sets double to 2 places after decimal
	cout << setw(58) << setfill(' ') << right << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setw(62) << setfill('=') << "" << endl;
	cout << setw(6) << setfill(' ') << right << "Year";
	cout << setw(23) << right << "Year End Balance";
	cout << setw(29) << right << "Year End Earned Interest" << endl;
	cout << setw(62) << setfill('-') << "" << endl;
	for (i = 1; i <= t_year; ++i) {							// loops through years then formats amounts in the bracket
		cout << setw(6) << setfill(' ') << right << i;
		cout << setw(19) << "$" << FindYearlyBalance(t_initialInvestment, t_annualPercent);
		cout << setw(25) << "$" << (FindYearlyBalance(t_initialInvestment, t_annualPercent) - t_initialInvestment) << endl;
		t_initialInvestment += (FindYearlyBalance(t_initialInvestment, t_annualPercent) - t_initialInvestment); // adds interest to the investment amount
	}
	cout << endl;
	return 0;
}

	

					// prints balance sheet with user defined deposit
double InvestmentAmount::BalanceBoardWithDeposits(int t_year, double t_initialInvestment, double t_annualPercent, double t_monthlyDeposit) {
	int i;

	cout << fixed << setprecision(2);	// sets double to 2 places after decimal
	cout << setw(57) << setfill(' ') << right << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setw(62) << setfill('=') << "" << endl;
	cout << setw(6) << setfill(' ') << right << "Year";
	cout << setw(23) << right << "Year End Balance";
	cout << setw(29) << right << "Year End Earned Interest" << endl;
	cout << setw(62) << setfill('-') << "" << endl;
	for (i = 1; i <= t_year; ++i) {							// loops through years then formats amounts in the bracket
		cout << setw(6) << setfill(' ') << right << i;
		cout << setw(17) << "$" << FindYearlyBalance(t_initialInvestment, t_annualPercent, t_monthlyDeposit);
		cout << setw(24) << "$" << (FindYearlyBalance(t_initialInvestment, t_annualPercent, t_monthlyDeposit) - t_initialInvestment - (t_monthlyDeposit * 12)) << endl;
		t_initialInvestment += (FindYearlyBalance(t_initialInvestment, t_annualPercent, t_monthlyDeposit) - t_initialInvestment); // adds interest to the investment amount
	}

	cout << endl;

	return 0;
}


