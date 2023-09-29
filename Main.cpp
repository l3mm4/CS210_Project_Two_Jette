#include <iostream>
#include <iomanip>
#include "AirgeadBankingApp.h"

int main() {
    double initialInvestment, interestRate, monthlyDeposit;
    int numberOfYears;
    char choice;

    do {
        displayScreen();
        getInputValues(initialInvestment, interestRate, numberOfYears, monthlyDeposit);
        calculateAndPrintBalances(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

        std::cout << "Do you want to continue? (Y/N): ";
        std::cin >> choice;

        // Validate input
        while (std::cin.fail() || (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter Y or N only." << std::endl;

            std::cout << "Do you want to continue? (Y/N): ";
            std::cin >> choice;
        }
    } while (choice == 'Y' || choice == 'y');

    return 0;
}