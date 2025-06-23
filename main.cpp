#include <iostream>
#include "InputValidation.h"
using namespace std;
int main() {

    // Sets terminal text color to green using ANSI escape code. Used to show green text across different terminals. (Cross platform compatible)
    cout << "\033[32m";

    cout << "Welcome to the Airgead Banking App!\n" << endl; // Welcome message.

    InputValidation::run(); // Start the input validation as well as main program logic.

    return 0; // Exit program with success status.
}