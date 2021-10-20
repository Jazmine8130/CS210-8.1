#ifndef AIRGEARBANKING_INVESTMENTAMOUNT_H
#define AIRGEARBANKING_INVESTMENTAMOUNT_H


#include <string>
using namespace std;

class InvestmentAmount {
public:						// setters, getters and functions
	InvestmentAmount();		
	InvestmentAmount(double m_initialAmount, double m_monthlyDeposit, double m_annualPercent, int m_years);
	void SetInitialAmount(double m_initialAmount);
	void SetMonthlyDeposit(double m_monthlyDeposit);
	void SetAnnualPercent(double m_annualPercent);
	void SetYears(int m_years);
	double GetInitialAmount() const;
	double GetMonthlyDeposit() const;
	double GetAnnualPercent() const;
	int GetYears() const;
	double FindMonthlyInterest(double& t_initialInvestment, double t_annualPercent, double t_monthlyDeposit);
	double FindYearlyBalance(double t_initialInvestment, double t_annualPercent, double t_monthlyDeposit);
	void Print(double amount, double deposit, double percent, int year);
	double BalanceBoardNoDeposits(int year, double investment, double percent);
	double BalanceBoardWithDeposits(int year, double investment, double percent, double deposit);
private:							// private data members
	double m_initialAmount;
	double m_monthlyDeposit;
	double m_annualPercent;
	int m_years;

};


#endif /* AIRGEARBANKING_INVESTMENTAMOUNT_H */

