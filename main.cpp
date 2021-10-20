/*	
*	Ariel Cabrera
*	CS 210
*	Project 2
*	AirgearBanking App
*	10/01/2021
*/



#include <iostream>
#include <iomanip>
#include "InvestmentAmount.h"		// brings header file for use in program
using namespace std;



int main() {
	InvestmentAmount amount1;		// initializes an object to use with the functions later
	double initialInvestment;		// initialized values required for functions
	double monthlyDeposit;
	double annualPercent;
	int year;

	cout << setw(34) << setfill('*') << "" << endl;		// title screen
	cout << setw(10) << setfill('*') << "";
	cout << " Data Values ";
	cout << setw(11) << setfill('*') << "" << endl;
	cout << "Initial Investment Amount: " << endl;
	cin >> initialInvestment;							// receives input from the user for initial deposit
	amount1.SetInitialAmount(initialInvestment);
	cout << "Monthly Deposit: " << endl;
	cin >> monthlyDeposit;								// receives input from the user for monthly deposit
	amount1.SetMonthlyDeposit(monthlyDeposit);
	cout << "Annual Interest: " << endl;
	cin >> annualPercent;								// receives input from the user for percentage rate
	amount1.SetAnnualPercent(annualPercent);
	cout << "Number of years: " << endl;
	cin >> year;										// receives input from the user for # of years
	amount1.SetYears(year);
	cout << "Press enter to continue . . ." << endl;
	cin.ignore();										// ignores all other input types
	cin.get();											// allows user to press enter to continue

	amount1.Print(initialInvestment, monthlyDeposit, annualPercent, year);		// prints screen with user inputs

	amount1.BalanceBoardNoDeposits(year, initialInvestment, annualPercent);		// calculates if user does not add monthly deposits

	amount1.BalanceBoardWithDeposits(year, initialInvestment, annualPercent, monthlyDeposit);	// caluculates with user input for deposits

	return 0;
}

