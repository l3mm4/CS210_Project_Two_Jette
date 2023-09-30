/*
 * Author: Sean Jette
 * Date: 01OCT2023
 * AirgeadBankingApp.h
 */

#ifndef AIRGEAD_BANKING_APP_H
#define AIRGEAD_BANKING_APP_H

class InvestmentData
{
public:
    // Setters for initial investment, monthly deposit, annual interest, and number of years
    void setInitialInvestment(double initialInvestment);
    void setMonthlyDeposit(double monthlyDeposit);
    void setAnnualInterest(double annualInterest);
    void setNumOfYears(int numOfYears);

    // Getters for initial investment, monthly deposit, annual interest, and number of years
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumOfYears() const;

private:
    double m_initialInvestment;     // Initial investment amount
    double m_monthlyDeposit;        // Monthly deposit amount
    double m_annualInterest;        // Annual interest rate
    int m_numOfYears;               // Number of years for investment
};

class UserDataCalculations
{
public:
    // Calculate investment data without monthly deposits
    void dataWithoutDeposits(const InvestmentData& userInvestment);

    // Calculate investment data with monthly deposits
    void dataWithDeposits(const InvestmentData& userInvestment);
};

class AirgeadBankingFunctions
{
public:
    // Display the screen
    void displayScreen();

    // Get input values from the user
    void getInputValues(double& initialInvestment, double& interestRate, int& numberOfYears, double& monthlyDeposit);

    // Print details for a specific year
    void printDetails(int year, double yearEndBalance, double interestEarned);

    // Calculate balance without monthly deposit
    double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);

    // Calculate balance with monthly deposit
    double calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);

    // Calculate and print balances for all years
    void calculateAndPrintBalances(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
};

#endif
