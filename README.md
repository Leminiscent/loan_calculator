# Loan Calculator

**Author**: Lemuel Nogueira

This program is a comprehensive loan calculator that allows users to calculate the details of a loan, including monthly payments and an amortization schedule. It is written in C++ and demonstrates object-oriented programming principles. 

## Features

- **Loan Calculation**: Calculates monthly payments and amortization schedules for loans based on user input.
- **Amortization Schedule**: Provides a detailed breakdown of each payment throughout the loan term, showing how much is going towards principal and interest each month.
- **Total Payment Calculation**: Calculates the total amount paid over the course of the loan, including both principal and interest.
- **File Output**: The program saves the loan details and amortization schedule to a file for record-keeping and easy reference.

## Components

The program consists of three main files:

- `loan_calculator.hpp`: This header file contains the class definition for `loan` and declarations of all the functions used in the program.
- `loan_calculator.cpp`: This source file contains the implementation of the `loan` class and its member functions.
- `main.cpp`: The entry point of the program, handling user input, creation of `loan` objects, and the main program loop.

## Usage

1. **Input Loan Details**: The user is prompted to enter the principal amount, annual percentage rate (APR), and duration of the loan in months.
2. **Calculating Loan Details**: The program calculates monthly payments, total payment amount, and total interest paid over the life of the loan.
3. **Display and Save Output**: Loan details, along with the amortization schedule, are displayed to the user and saved to an output file.
4. **Rerun Option**: Users have the option to rerun the program to calculate another loan without restarting the program.

## Installation

To use this program, you need a C++ compiler. Compile the source files (`loan_calculator.cpp` and `main.cpp`) with the header file (`loan_calculator.hpp`) in the same directory.

## Running the Program

Execute the compiled binary to start the program. Follow the on-screen prompts to input loan details.

## Limitations and Improvements

- Currently, the program does not handle variable interest rates.
- The file output is appended to the same file; a feature to specify output files could be added.
- Exception handling for file operations could be more robust.

## Conclusion

This Loan Calculator program is a useful tool for anyone needing to calculate loan payments and understand the distribution of payments over the term of a loan. Its simplicity and functionality make it ideal for educational purposes or personal use.
