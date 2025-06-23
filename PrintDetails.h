#ifndef PRINTDETAILS_H
#define PRINTDETAILS_H

#include "InvestmentAccount.h"
#include <vector>
using namespace std;

// Class used to format and printing investment results.
class PrintDetails {
public:
    // Prints a formatted table showing yearly balances and interest without additional monthly deposits.
    static void printTableWithoutMonthlyDeposit(vector<YearsResult>& t_results);

    // Prints a formatted table showing yearly balances and interest with additional monthly deposits included.
    static void printTableWithMonthlyDeposit(vector<YearsResult>& t_results);
};

#endif //PRINTDETAILS_H
