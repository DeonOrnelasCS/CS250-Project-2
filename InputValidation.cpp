// InputValidation.cpp
#include "InputValidation.h"
#include "InvestmentAccount.h"
#include "PrintDetails.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

// Main execution for collecting and validating user input.
void InputValidation::run() {
    string redoLoop; // Stores input to determine if program should repeat or exit.
    do {
        // Declare all variables.
        double initialInvestment;
        double monthlyDeposit;
        double annualInterestRate;
        int numberOfYears;
        char choice;

        while (true) { // Prompt and validate all investment inputs.
            cout << "Enter initial investment: $";
            if (!(cin >> initialInvestment) || initialInvestment < 0) { // Validates input (User enters number >= 0.
                cout << "Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Used to discard invalid input.
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter monthly deposit: $";
            if (!(cin >> monthlyDeposit) || monthlyDeposit < 0) { // Validates input (User enters number >= 0.
                cout << "Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Used to discard invalid input.
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter annual interest rate: ";
            if (!(cin >> annualInterestRate) || annualInterestRate < 0) { // Validates input (User enters number >= 0.
                cout << "Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Used to discard invalid input.
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter number of years: ";
            if (!(cin >> numberOfYears) || numberOfYears < 0) { // Validates input (User enters number >= 0.
                cout << "Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Used to discard invalid input.
                continue;
            }
            break;
        }
        // Display all user input values for confirmation.
        cout << "\nYou entered:\n"
             << "Initial Investment: $" << fixed << setprecision(2) << initialInvestment << "\n"
             << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDeposit << "\n"
             << "Annual Interest: " << fixed << setprecision(2) << annualInterestRate << "%\n"
             << "Number of Years: " << numberOfYears << "\n\n";

        // Prompt user for next action.
        cout << "Type 'e' to edit a value: \n"
                "Type 'q' to quit: \n"
                "Or enter anything else to continue: \n";
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
            case 'q': // Quits program, display goodbye message.
                cout << "\nExiting Airgead Banking App, Goodbye!\n";
                exit(0); // Terminate program.
                break;

            case 'e': { // Option to edit a single specified value.
                int innerChoice;
                // Repeats until valid input.
                while (true) {
                    cout << "\nEnter '1' to edit Initial Investment\n"
                         << "Enter '2' to edit monthly deposit\n"
                         << "Enter '3' to edit annual interest rate\n"
                         << "Enter '4' to edit number of years\n";
                    cout << "Your choice: ";

                    if (!(cin >> innerChoice)) {
                        // Validate input.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input.
                        continue;
                    }
                    // Used to edit user designated field.
                    switch (innerChoice) {
                        case 1:
                            cout << "Enter new initial investment: $";
                            cin >> initialInvestment;
                            break;
                        case 2:
                            cout << "Enter new monthly deposit: $";
                            cin >> monthlyDeposit;
                            break;
                        case 3:
                            cout << "Enter new annual interest rate: ";
                            cin >> annualInterestRate;
                            break;
                        case 4:
                            cout << "Enter new number of years: ";
                            cin >> numberOfYears;
                            break;
                        default:
                            cout << "Please enter a valid choice (1–4).\n\n";
                            continue;   // Goes back to top of inner loop until valid entry.
                    }
                    break;  // If valid choice is handled, exit inner loop
                }
                break;  // Used to prevent fall-through
            }
            default:
                break;
        }

        //vCreate account object with validated or edited input.
        InvestmentAccount account(initialInvestment, monthlyDeposit, annualInterestRate, numberOfYears);

        // Calculate and store results with and without monthly deposits.
        auto resultsNoDeposit  = account.calcWithoutMonthlyDeposit();
        auto resultsWithDeposit = account.calcWithMonthlyDeposit();

        cout << "\n\n";
        PrintDetails::printTableWithoutMonthlyDeposit(resultsNoDeposit);
        PrintDetails::printTableWithMonthlyDeposit(resultsWithDeposit);

        // Prompts user to enter new numbers for next simulation or to exit program.
        cout << "Run again with new values? Enter anything to try again or 'no' to quit.\n";
        cin  >> redoLoop;
        // Converts input to lowercase for loop.
        transform(redoLoop.begin(), redoLoop.end(), redoLoop.begin(), ::tolower);
    } while (redoLoop != "no");
    cout << "Exiting Airgead Banking App, Goodbye!" << endl;
}