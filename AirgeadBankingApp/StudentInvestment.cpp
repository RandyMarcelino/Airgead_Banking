#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#include "StudentInvestment.h"

// Default constructor.
StudentInvestment::StudentInvestment() {
}

// Sets the monthly deposit for the student account.
void StudentInvestment::SetMonthlyDeposit(double monthlyDeposit) {
	m_monthlyDeposit = monthlyDeposit;
}

// Sets the annual interest for the student account.
void StudentInvestment::SetAnnualInterest(double annualInterest) {
	m_annualInterest = annualInterest;
}

// Sets the number of years to display for the student account.
void StudentInvestment::SetNumberYears(int numYears) {
	m_numYears = numYears;
}

// Prints initial menu with student information.
void StudentInvestment::PrintMenu() {
	cout << std::string(34, '*') << endl;
	cout << std::string(10, '*') << " DATA INPUT " << std::string(12, '*') << endl;

	//Displays a blank manu.
	if (m_annualInterest == 0.00 && m_monthlyDeposit == 0.00 && m_numYears == 0) {
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
	}
	// Displays menu with values.
	else {
		cout << setprecision(2) << fixed << "Initial Investment Amount: $" << m_InitInvestAmount << endl;
		cout << setprecision(2) << fixed << "Monthly Deposit: $" << m_monthlyDeposit << endl;
		cout << setprecision(0) << fixed << "Annual Interest: %" << m_annualInterest << endl;
		cout << "Number of years: " << m_numYears << endl;
	}
	// Waits for user to continue.
	system("PAUSE");
}

void StudentInvestment::PrintWithReport() {
	// Displays top half of menu with labels and titles.
	cout << " " <<  std::string(57, '_') << " " << endl;
	cout << "|" << std::string(2, ' ') << "Balance and Interest With Additional Monthly Deposits" << std::string(2, ' ') << "|" << endl;
	cout << "|" << std::string(57, '=') << "|" << endl;
	cout << "|Year" << std::string(8, ' ') << "Year End Balance" << std::string(5, ' ') << "Year End Earned Interest|" << endl;
	cout << "|" << std::string(57, '-') << "|" << endl;

	// Prints out every year the balance and interest gained of every year.
	for (int i = 1; i <= m_numYears; i++) {
		// Gets balance and interest for the year.
		CalculateYearEndBalance();
		// Displays data.
		cout << setprecision(2) << fixed << "|" << setw(12) << std::left << i << "$" << setw(20) << std::left << m_InitInvestAmount << "$" << setw(23) << std::left << m_yearEndInterest << "|" << endl;
		cout << "|" << std::string(57, '_') << "|" << endl;
	}
}

void StudentInvestment::PrintWithoutReport() {
	// Displays top half of menu with labels and titles.
	cout << " " << std::string(57, '_') << " " << endl;
	cout << "|" << "Balance and Interest Without Additional Monthly Deposits" << std::string(1, ' ') << "|" << endl;
	cout << "|" << std::string(57, '=') << "|" << endl;
	cout << "|Year" << std::string(8, ' ') << "Year End Balance" << std::string(5, ' ') << "Year End Earned Interest|" << endl;
	cout << "|" << std::string(57, '-') << "|" << endl;

	// Resets values to deisplay report without deposits.
	m_InitInvestAmount = 1.00;
	m_monthlyDeposit = 0.00;

	// Prints out every year the balance and interest gained of every year.
	for (int i = 1; i <= m_numYears; i++) {
		// Gets balance and interest for the year.
		CalculateYearEndBalance();
		// Displays data.
		cout << setprecision(2) << fixed << "|" << setw(12) << std::left << i << "$" << setw(20) << std::left << m_InitInvestAmount << "$" << setw(23) << std::left << m_yearEndInterest << "|" << endl;
		cout << "|" << std::string(57, '_') << "|" << endl;
	}
}

// Calculates the interest of a given month.
double StudentInvestment::CalculateInterest() {
	return (m_InitInvestAmount + m_monthlyDeposit) * ((m_annualInterest / 100) / 12);
}

void StudentInvestment::CalculateYearEndBalance() {
	// Resets interest to start counting for a new year.
	m_yearEndInterest = 0;

	for (int i = 1; i <= 12; i++){
		// Sums up the interest every month.
		m_yearEndInterest += CalculateInterest();
		// Saves the ammount made at the end of the month to Initial to have it as initial for next month.
		m_InitInvestAmount = m_InitInvestAmount + m_monthlyDeposit + CalculateInterest();
	}
}

void StudentInvestment::ResetRecords() {
	// Resets records to default.
	m_InitInvestAmount = 1.00;
	m_monthlyDeposit = 0.00;
	m_annualInterest = 0.00;
	m_numYears = 0;
}