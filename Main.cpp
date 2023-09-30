/*
 * Author: Sean Jette
 * Date: 01OCT2023
 * Main.cpp
 */

#include <iostream>
#include <iomanip>
#include "AirgeadBankingApp.h"

int main()
{
    // Declare variables for initial investment, interest rate, monthly deposit, number of years, and user choice
    double initialInvestment, interestRate, monthlyDeposit;
    int numberOfYears;
    char choice;

    // Create an instance of the AirgeadBankingFunctions class
    AirgeadBankingFunctions functions;

    do
    {
        // Display the screen
        functions.displayScreen();

        // Get input values from the user
        functions.getInputValues(initialInvestment, interestRate, numberOfYears, monthlyDeposit);

        // Calculate and print balances
        functions.calculateAndPrintBalances(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

        // Prompt the user to continue or exit
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

    // Exit the program
    std::cout << "\nExiting program..." << std::endl;

    return 0;
}