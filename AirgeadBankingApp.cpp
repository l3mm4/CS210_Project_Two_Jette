/*
 * Author: Sean Jette
 * Date: 01OCT2023
 * AirgeadBankingApp.cpp
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "AirgeadBankingApp.h"

void InvestmentData::setInitialInvestment(double initialInvestment) 
{
    m_initialInvestment = initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double monthlyDeposit) 
{
    m_monthlyDeposit = monthlyDeposit;
}

void InvestmentData::setAnnualInterest(double annualInterest) 
{
    m_annualInterest = annualInterest;
}

void InvestmentData::setNumOfYears(int numOfYears) 
{
    m_numOfYears = numOfYears;
}

double InvestmentData::getInitialInvestment() const 
{
    return m_initialInvestment;
}

double InvestmentData::getMonthlyDeposit() const 
{
    return m_monthlyDeposit;
}

double InvestmentData::getAnnualInterest() const 
{
    return m_annualInterest;
}

int InvestmentData::getNumOfYears() const 
{
    return m_numOfYears;
}

void UserDataCalculations::dataWithoutDeposits(const InvestmentData& userInvestment) 
{
    // Get initial investment, interest rate, and number of years from user input
    double initialInvestment = userInvestment.getInitialInvestment();
    double interestRate = userInvestment.getAnnualInterest();
    int numberOfYears = userInvestment.getNumOfYears();

    // Print table header
    std::cout << std::endl;
    std::cout << " Year     Year End Balance     Interest Earned" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // Create an instance of the AirgeadBankingFunctions class
    AirgeadBankingFunctions functions;

    // Calculate and print balances without monthly deposits
    functions.calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);
}

void UserDataCalculations::dataWithDeposits(const InvestmentData& userInvestment) 
{
    // Get initial investment, monthly deposit, interest rate, and number of years from user input
    double initialInvestment = userInvestment.getInitialInvestment();
    double monthlyDeposit = userInvestment.getMonthlyDeposit();
    double interestRate = userInvestment.getAnnualInterest();
    int numberOfYears = userInvestment.getNumOfYears();

    // Print table header
    std::cout << std::endl;
    std::cout << " Year     Year End Balance     Interest Earned" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // Create an instance of the AirgeadBankingFunctions class
    AirgeadBankingFunctions functions;
    
    // Calculate and print balances with monthly deposits
    functions.calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
}

void AirgeadBankingFunctions::displayScreen() 
{
    // Display the welcome message
    std::cout << "...:::Welcome to Airgead Banking:::... \n\n"
        << "**************************************\n"
        << "*********** Investment Data **********\n" << std::endl;
}

void AirgeadBankingFunctions::printDetails(int year, double yearEndBalance, double interestEarned) 
{
    // Print details for a specific years
    std::cout << std::fixed << std::left << std::setprecision(2)
        << std::setw(15) << year << "  " << "$"
        << std::setw(25) << yearEndBalance << "$"
        << std::setw(20) << interestEarned << std::endl;
}

double AirgeadBankingFunctions::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears)
{
    // Calculate monthly interest rate
    double monthlyInterestRate = interestRate / 100.0 / 12.0;

    // Calculate number of months
    int numberOfMonths = numberOfYears * 12;

    // Initialize balance to initial investment
    double balance = initialInvestment;

    // Loop through each year
    for (int year = 1; year <= numberOfYears; year++)
    {
        // Initialize interest earned this year to 0
        double interestEarnedThisYear = 0;

        // Loop through each month
        for (int month = 1; month <= 12; month++)
        {
            // Calculate interest earned this month
            double interestEarnedThisMonth = balance * monthlyInterestRate;

            // Add interest earned this month to balance
            balance += interestEarnedThisMonth;

            // Add interest earned this month to interest earned this year
            interestEarnedThisYear += interestEarnedThisMonth;
        }

        // Round balance and interest earned this year to 2 decimal places
        balance = round(balance * 100.0) / 100.0;
        interestEarnedThisYear = round(interestEarnedThisYear * 100.0) / 100.0;

        // Print details for this year
        printDetails(year, balance, interestEarnedThisYear);
    }

    return balance;
}

double AirgeadBankingFunctions::calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears)
{
    // Calculate monthly interest rate
    double monthlyInterestRate = interestRate / 100.0 / 12.0;

    // Calculate number of months
    int numberOfMonths = numberOfYears * 12;

    // Initialize balance to initial investment
    double balance = initialInvestment;

    // Loop through each year
    for (int year = 1; year <= numberOfYears; year++)
    {
        // Initialize interest earned this year to 0
        double interestEarnedThisYear = 0;

        // Loop through each month
        for (int month = 1; month <= 12; month++)
        {
            // Add monthly deposit to balance
            balance += monthlyDeposit;

            // Calculate interest earned this month
            double interestEarnedThisMonth = balance * monthlyInterestRate;

            // Add interest earned this month to balance
            balance += interestEarnedThisMonth;

            // Add interest earned this month to interest earned this year
            interestEarnedThisYear += interestEarnedThisMonth;
        }

        // Round balance to 2 decimal places
        balance = round(balance * 100) / 100;

        // Print details for this year
        printDetails(year, balance, interestEarnedThisYear);
    }

    return balance;
}


void AirgeadBankingFunctions::calculateAndPrintBalances(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears)
{
    // Print table header for balance and interest without additional monthly deposits
    std::cout << "\n Balance and Interest Without Additional Monthly Deposits\n"
        << "=================================================================\n"
        << " Year\t\tYear End Balance\tYear End Earned Interest\n"
        << "-----------------------------------------------------------------\n";

    // Calculate balance without additional monthly deposits
    double balanceWithoutMonthlyDeposit = calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);

    // Print table header for balance and interest with additional monthly deposits
    std::cout << "\n Balance and Interest With Additional Monthly Deposits\n"
        << "=================================================================\n"
        << " Year\t\tYear End Balance\tYear End Earned Interest\n"
        << "-----------------------------------------------------------------\n";

    // Calculate balance with additional monthly deposits
    double balanceWithMonthlyDeposit = calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    std::cout << "\n";
}

void AirgeadBankingFunctions::getInputValues(double& initialInvestment, double& interestRate, int& numberOfYears, double& monthlyDeposit)
{
    // Get input values from the user
    std::cout << "Enter the initial investment amount: $";
    std::cin >> initialInvestment;

    std::cout << "Enter the monthly deposit amount: $";
    std::cin >> monthlyDeposit;

    std::cout << "Enter the annual interest rate (%): ";
    std::cin >> interestRate;

    std::cout << "Enter the number of years: ";
    std::cin >> numberOfYears;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nPress any key to continue...";
    std::cin.get();

    // Validate input
    while (std::cin.fail() || initialInvestment < 0 || monthlyDeposit < 0 || interestRate < 0 || numberOfYears < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter positive values only." << std::endl;

        std::cout << "Enter the initial investment amount: $";
        std::cin >> initialInvestment;

        std::cout << "Enter the monthly deposit amount: $";
        std::cin >> monthlyDeposit;

        std::cout << "Enter the annual interest rate (%): ";
        std::cin >> interestRate;

        std::cout << "Enter the number of years: ";
        std::cin >> numberOfYears;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\nPress any key to continue...";
        std::cin.get();
    }
}
