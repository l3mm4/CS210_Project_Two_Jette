#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "AirgeadBankingApp.h"

void InvestmentData::setInitialInvestment(double initialInvestment) {
    m_initialInvestment = initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double monthlyDeposit) {
    m_monthlyDeposit = monthlyDeposit;
}

void InvestmentData::setAnnualInterest(double annualInterest) {
    m_annualInterest = annualInterest;
}

void InvestmentData::setNumOfYears(int numOfYears) {
    m_numOfYears = numOfYears;
}

double InvestmentData::getInitialInvestment() const {
    return m_initialInvestment;
}

double InvestmentData::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double InvestmentData::getAnnualInterest() const {
    return m_annualInterest;
}

int InvestmentData::getNumOfYears() const {
    return m_numOfYears;
}

void UserDataCalculations::dataWithoutDeposits(const InvestmentData& userInvestment) {
    double initialInvestment = userInvestment.getInitialInvestment();
    double interestRate = userInvestment.getAnnualInterest();
    int numberOfYears = userInvestment.getNumOfYears();

    std::cout << std::endl;
    std::cout << " Year     Year End Balance     Interest Earned" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);
}

void UserDataCalculations::dataWithDeposits(const InvestmentData& userInvestment) {
    double initialInvestment = userInvestment.getInitialInvestment();
    double monthlyDeposit = userInvestment.getMonthlyDeposit();
    double interestRate = userInvestment.getAnnualInterest();
    int numberOfYears = userInvestment.getNumOfYears();

    std::cout << std::endl;
    std::cout << " Year     Year End Balance     Interest Earned" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
}

void displayScreen() {
    std::cout << "...:::Welcome to Airgead Banking:::... \n\n"
        << "**************************************\n"
        << "*********** Investment Data **********\n" << std::endl;
}

void printDetails(int year, double yearEndBalance, double interestEarned) {
    std::cout << std::fixed << std::left << std::setprecision(2)
        << std::setw(15) << year << "  " << "$"
        << std::setw(25) << yearEndBalance << "$"
        << std::setw(20) << interestEarned << std::endl;
}

double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
    double monthlyInterestRate = interestRate / 100.0 / 12.0;
    int numberOfMonths = numberOfYears * 12;
    double balance = initialInvestment;

    for (int year = 1; year <= numberOfYears; year++) {
        double interestEarnedThisYear = 0;
        for (int month = 1; month <= 12; month++) {
            double interestEarnedThisMonth = balance * monthlyInterestRate;
            balance += interestEarnedThisMonth;
            interestEarnedThisYear += interestEarnedThisMonth;
        }

        balance = round(balance * 100) / 100;
        printDetails(year, balance, interestEarnedThisYear);
    }

    return balance;
}

double calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    double monthlyInterestRate = interestRate / 100.0 / 12.0;
    int numberOfMonths = numberOfYears * 12;
    double balance = initialInvestment;

    for (int year = 1; year <= numberOfYears; year++) {
        double interestEarnedThisYear = 0;
        for (int month = 1; month <= 12; month++) {
            balance += monthlyDeposit;
            double interestEarnedThisMonth = balance * monthlyInterestRate;
            balance += interestEarnedThisMonth;
            interestEarnedThisYear += interestEarnedThisMonth;
        }

        balance = round(balance * 100) / 100;
        printDetails(year, balance, interestEarnedThisYear);
    }

    return balance;
}

void calculateAndPrintBalances(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    std::cout << "\n Balance and Interest Without Additional Monthly Deposits\n"
        << "=================================================================\n"
        << " Year\t\tYear End Balance\tYear End Earned Interest\n"
        << "-----------------------------------------------------------------\n";
    double balanceWithoutMonthlyDeposit = calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);
    std::cout << "\n";

    std::cout << "\n Balance and Interest With Additional Monthly Deposits\n"
        << "=================================================================\n"
        << " Year\t\tYear End Balance\tYear End Earned Interest\n"
        << "-----------------------------------------------------------------\n";
    double balanceWithMonthlyDeposit = calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
    std::cout << "\n";
}

void getInputValues(double& initialInvestment, double& interestRate, int& numberOfYears, double& monthlyDeposit) {
    std::cout << "Enter the initial investment amount: ";
    std::cin >> initialInvestment;

    std::cout << "Enter the monthly deposit amount: ";
    std::cin >> monthlyDeposit;

    std::cout << "Enter the annual interest rate (%): ";
    std::cin >> interestRate;

    std::cout << "Enter the number of years: ";
    std::cin >> numberOfYears;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nPress any key to continue...";
    std::cin.get();

    // Validate input
    while (std::cin.fail() || initialInvestment < 0 || monthlyDeposit < 0 || interestRate < 0 || numberOfYears < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter positive numbers only." << std::endl;

        std::cout << "Enter the initial investment amount: ";
        std::cin >> initialInvestment;

        std::cout << "Enter the monthly deposit amount: ";
        std::cin >> monthlyDeposit;

        std::cout << "Enter the annual interest rate (%): ";
        std::cin >> interestRate;

        std::cout << "Enter the number of years: ";
        std::cin >> numberOfYears;
    }
}