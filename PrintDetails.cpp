//
// Created by Deon  Ornelas on 6/4/25.
//

#include "PrintDetails.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "InvestmentAccount.h"

using namespace std;

// Prints a table of yearly balances and interest WITHOUT monthly deposits.
void PrintDetails::printTableWithoutMonthlyDeposit(vector<YearsResult>& t_results) {
     string withoutTitle = "Balance and Interest Without Additional Monthly Deposits";
     size_t len1 = withoutTitle.length(); // Determine length of title.
     string border1(len1, '='); // Create a border using '=' to match title length.

     cout << border1 << "\n" << withoutTitle << "\n" << border1 << "\n"; // Prints title with borders.

     // Prints table headers.
     cout << left << setw(4)  << "Year" << "\t" << setw(16) << "Year End Balance" << "\t"
      << setw(24) << "Year End Earned Interest" << "\n";

     // Prints table header underlying borders.
     cout << left << setw(4)  << "----" << "\t" << setw(16) << "----------------" << "\t"
          << setw(24) << "------------------------" << "\n";

     // Iterate through each year's result and display in formatted output. Rounds to two decimal places.
     for (auto& yr : t_results) {
          cout << left << setw(6)  << yr.year
               << "\t" << "$"  << setw(19) << fixed << setprecision(2) << yr.yearEndBalance
               << "$"  << setw(23) << fixed << setprecision(2) << yr.interestEarned  << endl;
     }
     // Display final term end balance if the result list is not empty.
     if (!t_results.empty()) {
          double finalBalance = t_results.back().yearEndBalance;
          cout << "* * * * * * * * * * \n";  // Added separator to distinguish final term ending balance.
          cout << "Final Term-End Balance: $" << fixed << setprecision(2) << finalBalance << "\n* * * * * * * * * *\n\n";
     }
}

// Prints a table of yearly balances and interest WITH monthly deposits.
void PrintDetails::printTableWithMonthlyDeposit(vector<YearsResult>& t_results) {
     string withTitle = "Balance and Interest With Additional Monthly Deposits";
     size_t len2 = withTitle.length(); // Determine length of title.
     string border2(len2, '='); // Create a border using '=' to match title length.

     cout << border2 << "\n" << withTitle << "\n" << border2 << "\n"; // Prints title with borders.

     // Same as above, the following is all formatting for each years output.
     cout << left << setw(4)  << "Year" << "\t" << setw(16) << "Year End Balance" << "\t"
          << setw(24) << "Year End Earned Interest" << "\n";

     cout << left << setw(4)  << "----" << "\t" << setw(16) << "----------------" << "\t"
          << setw(24) << "------------------------" << "\n";

     for (auto& yr : t_results) {
          cout << left << setw(6)  << yr.year
               << "\t" << "$"  << setw(19) << fixed << setprecision(2) << yr.yearEndBalance
               << "$"  << setw(23) << fixed << setprecision(2) << yr.interestEarned  << endl;
     }
     if (!t_results.empty()) {
          double finalBalance = t_results.back().yearEndBalance;
          cout << "* * * * * * * * * * \n";
          cout << "Final Term-End Balance: $" << fixed << setprecision(2) << finalBalance << "\n* * * * * * * * * * \n\n";
     }
}