#ifndef STUDENT_INVESTMENT_H
#define STUDENT_INVESTMENT_H

class StudentInvestment {
private:
	// Private variables.
	double m_InitInvestAmount = 1.00;
	double m_monthlyDeposit = 0.00;
	double m_annualInterest = 0.00;
	int m_numYears = 0;
	double m_yearEndInterest = 0.00;

public:
	// Default constructor.
	StudentInvestment();

	// Set initializers.
	void SetMonthlyDeposit(double monthlyDeposit);
	void SetAnnualInterest(double annualInterest);
	void SetNumberYears(int numYears);

	// Print menu and reports.
	void PrintMenu();
	void PrintWithReport();
	void PrintWithoutReport();

	// Calculates interest of the month.
	double CalculateInterest();
	// Used to calculate balance at end of every year and interest.
	void CalculateYearEndBalance();

	//Resets items variables.
	void ResetRecords();
};
#endif // !STUDENT_INVESTMENT_H

