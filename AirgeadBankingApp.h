

#ifndef AIRGEAD_BANKING_APP_H
#define AIRGEAD_BANKING_APP_H

class InvestmentData {
public:
    void setInitialInvestment(double initialInvestment);
    void setMonthlyDeposit(double monthlyDeposit);
    void setAnnualInterest(double annualInterest);
    void setNumOfYears(int numOfYears);

    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumOfYears() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numOfYears;
};

class UserDataCalculations {
public:
    void dataWithoutDeposits(const InvestmentData& userInvestment);
    void dataWithDeposits(const InvestmentData& userInvestment);
};

void displayScreen();
void getInputValues(double& initialInvestment, double& interestRate, int& numberOfYears, double& monthlyDeposit);
void printDetails(int year, double yearEndBalance, double interestEarned);
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
double calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
void calculateAndPrintBalances(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);

#endif