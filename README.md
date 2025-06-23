# CS210-Project-2

# Airgead Banking App

A console-based C++ application that simulates investment account growth over time. Users can enter an initial investment, monthly deposits, annual interest rate, and term length, then view year-by-year balances and earned interest—both with and without monthly deposits. Input is rigorously validated to ensure a smooth user experience. 

---

## Features

- **Robust Input Validation**  
  Ensures all numeric inputs (investment, deposit, interest rate, years) are ≥ 0 and re-prompts on invalid entry.  
- **Editable Parameters**  
  At confirmation, users can choose to edit any single parameter before running the simulation.  
- **Dual Reporting**  
  - **Without Monthly Deposits**: Year-end balance and interest earned each year.  
  - **With Monthly Deposits**: Year-end balance and interest earned when adding monthly contributions.  
- **Formatted Tables**  
  Nicely formatted ASCII tables with headers, borders, and final-term summaries.  
- **Looping Workflow**  
  After displaying results, users can run a new simulation or exit gracefully.

---

## Project Structure

- **main.cpp**  
  Sets console color, prints welcome message, and calls `InputValidation::run()`.  
- **InputValidation**  
  - **Header**: declares `run()`  
  - **Implementation**: collects and validates all user inputs; handles edit/quit logic; invokes the account and printing routines.  
- **InvestmentAccount**  
  - Encapsulates core financial calculations.  
  - Methods:  
    - `calcWithoutMonthlyDeposit()`  
    - `calcWithMonthlyDeposit()`  
    - `m_roundCents()` for cent-accurate rounding.  
- **PrintDetails**  
  - Static methods to render two tables (with/without monthly deposits) using `YearsResult` data.  
- **YearsResult (struct)**  
  Holds data for each year: `year`, `yearEndBalance`, and `interestEarned`.
