//
// Created by Deon  Ornelas on 6/4/25.
//

#include "InvestmentAccount.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

// Constructor definition using initializer list to set member variables.
InvestmentAccount::InvestmentAccount(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numberOfYears):
    m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterestRate(t_annualInterestRate), m_numberOfYears(t_numberOfYears){}

double InvestmentAccount::m_roundCents(double m_amount) { // Helper function used to round to nearest cent.
    return round(m_amount * 100) / 100;
}
// Computes annual growth without additional deposits.
vector<YearsResult> InvestmentAccount::calcWithoutMonthlyDeposit() {
    vector<YearsResult> t_results; // Vector used to store results for each year.

    double monthlyInterestRate = (m_annualInterestRate / 100.0) / 12.0; // Used to convert annual interest rate to monthly.

    double currentBalance = m_initialInvestment; // Balance at beginning of year.

    for (int year = 1; year <= m_numberOfYears; year++) // Used to loop through each year that user input.
    {
        double interestEarnedThisYear = 0.0; // Used to store value of interest earned per year.

        for (int month = 1; month <= 12; month++) // Iterate through each month in the year.
        {
            double monthlyInterest = currentBalance * monthlyInterestRate; // Calculate monthly interest

            currentBalance += monthlyInterest; // Update balance with interest earned.

            interestEarnedThisYear += monthlyInterest; // Accumulate interest earned.
        }
        YearsResult result; // Create result object for the current year.
        result.year = year;
        result.yearEndBalance = m_roundCents(currentBalance); // Store year end balance rounded to 2 decimal places.
        result.interestEarned = m_roundCents(interestEarnedThisYear); // Store total interest earned, also rounded.
        t_results.push_back(result); // Add result to results vector.
    }
    return t_results; // Return all annual results.
}
// Calculate annual balances and interest with additional deposits.
vector<YearsResult> InvestmentAccount::calcWithMonthlyDeposit() {
    vector<YearsResult> t_results; // Vector used to store results for each year.
    double monthlyInterestRate = (m_annualInterestRate / 100.0) / 12.0; // Convert annual interest rate to monthly.

    double currentBalance = m_initialInvestment; // Initial balance with initial investment.

    for (int year = 1; year <= m_numberOfYears; year++) { // Loop through each year.
        double interestEarnedThisYear = 0.0; // Stores values for interest earned annually.

        for (int month = 1; month <= 12; month++) // Iterate through each month in the year.
        {
            double principalPlusDeposit = currentBalance + m_monthlyDeposit; // Add monthly deposit to current balance.

            double monthlyInterest = principalPlusDeposit * monthlyInterestRate; // Calculate monthly interest.

            currentBalance = principalPlusDeposit + monthlyInterest; // Update balance after interest.

            interestEarnedThisYear += monthlyInterest; // Accumulate interest.
        }
        YearsResult result; // Create result object for the current year.
        result.year = year;
        result.yearEndBalance = m_roundCents(currentBalance); // Store year end balance, rounded to two decimal places.
        result.interestEarned = m_roundCents(interestEarnedThisYear); // Store total interest earned, rounded.
        t_results.push_back(result); // Add results to vector/
    }
    return t_results; // Return all annual results.
}