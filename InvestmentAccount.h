#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

#include <vector>
using namespace std;

// Holds the results for each year of investment.
class YearsResult {
public:
    int year; // Year number, starting at 1.
    double yearEndBalance; // Balance at the end of the year.
    double interestEarned; // Interest earned during that year.
};

class InvestmentAccount {
private:
    double m_initialInvestment; // Initial principal amount
    double m_monthlyDeposit; // Monthly deposit amount
    double m_annualInterestRate; // Annual interest rate percentage.
    int m_numberOfYears; // Durations of years to simulate.
    double m_roundCents(double m_amount); // Rounds monetary amount to two decimals.


public: // Initializes the account parameters.
    InvestmentAccount(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numberOfYears);
    vector<YearsResult> calcWithoutMonthlyDeposit(); // Calculates yearly balances and interest without additional monthly deposits
    vector<YearsResult> calcWithMonthlyDeposit(); // Calculates yearly balances and interest with additional monthly deposits
};

#endif //INVESTMENTACCOUNT_H
