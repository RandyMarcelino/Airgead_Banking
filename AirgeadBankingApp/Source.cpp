#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "StudentInvestment.h"

void getUserInput(StudentInvestment& t_student) {
	// Establish temporary variables.
	double tempMonthlyDeposit;
	double tempAnnualInterest;
	int tempNumYears;

	try {
		//Loops until user inputs valid monthly deposit.
		do {
			cin.clear(); // Reset the error flags.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input.
			// Prompts user for monthly deposit amount.
			cout << "Enter monthly deposit amount to be invested: " << endl;
			cin >> tempMonthlyDeposit; // Stores input in temp value.
		} while (tempMonthlyDeposit <= 0 || isnan(tempMonthlyDeposit));
		// Stores value in class item.
		t_student.SetMonthlyDeposit(tempMonthlyDeposit);

		// Prompts user until valid interest rate is entered.
		do {
			cin.clear(); // Reset the error flags.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input.
			// Prompts user for annual interest rate amount.
			cout << "Enter annual interest rate: " << endl;
			cin >> tempAnnualInterest; // Stores it in temp val.
		} while (tempAnnualInterest <= 0 || isnan(tempAnnualInterest));
		// Stores value in class.
		t_student.SetAnnualInterest(tempAnnualInterest);

		// Loops until user enters valid year.
		do {
			cin.clear(); // Reset the error flags.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input.
			// Prompts user for amount of years to invest.
			cout << "Enter number of years to invest: " << endl;
			cin >> tempNumYears; // Store value in temp val.
		}while (tempNumYears <= 0 || isnan((double)tempNumYears));
		// Stores value in class item.
		t_student.SetNumberYears(tempNumYears);
	}
	catch (runtime_error ex) {
		cout << "Caught error: " << ex.what() << endl;
	}
}

char askUserToRepeat(char userInput) {
	bool retry = true;
	try {
		do {
			// Prompts user if they wish to continue.
			cout << "Would you like to calculate again [Y,n]?" << endl;
			cin >> userInput;

			// If any of the below inputs are put in the loop will end by returning said input to main.
			switch (userInput) {
			case 'Y':
				return userInput;
			case 'y':
				return userInput;
			case 'N':
				return userInput;
			case 'n':
				return userInput;
			}
		} while (retry);
	}
	catch (runtime_error ex) {
		cout << "Caught error: " << ex.what() << endl;
	}

}

int main(){
	// Creates new instance of student finances.
	StudentInvestment newStudent;
	char userInput = 'Y';

	try {
		while (userInput == 'Y' || userInput == 'y') {
			newStudent.ResetRecords();
			system("CLS");

			// Displays blank menu.
			newStudent.PrintMenu();
			// Gets user data to update menu.
			getUserInput(newStudent);
			// Clears screan to display new data.
			system("CLS");
			// Displays menu with new user input.
			newStudent.PrintMenu();


			system("CLS");
			// Shower the balance and interest calculations with monthly deposit.
			newStudent.PrintWithReport();
			// And this shows balance and interest without a monthly deposit.
			newStudent.PrintWithoutReport();

			// Ask the user if they wish to calculate investment again.
			userInput = askUserToRepeat(userInput);
		}
	}
	catch (runtime_error ex) {
		// Catches runtime error and displays them.
		cout << "Caught error: " << ex.what() << endl;
	}

	return 0;
}