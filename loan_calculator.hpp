// Prevents multiple inclusions of the header file.
#ifndef loan_calculator_hpp
#define loan_calculator_hpp

// Standard library headers for input/output and vector operations.
#include <iostream>
#include <vector>

// Class definition for 'loan'.
class loan
{
private:
    // Private data members
    double principal;        // Principal amount of the loan
    double apr;              // Annual Percentage Rate
    double monthly_rate;     // Monthly interest rate
    int num_months;          // Duration of the loan in months
    double monthly_payments; // Monthly payment amount

    // Nested struct for individual payments.
    struct payment
    {
        int month;                // Month number
        double beginning_balance; // Balance at the beginning of the month
        double interest_payment;  // Interest component of the payment
        double principal_payment; // Principal component of the payment
        double ending_balance;    // Balance at the end of the month
    };
    std::vector<payment> payments; // Vector of payments for amortization

public:
    // Public member functions
    loan(double principal, double apr, int num_months); // Constructor
    void calculate_monthly_rate();                      // Calculates the monthly interest rate
    void calculate_monthly_payments();                  // Calculates the monthly payments
    void calculate_amortization();                      // Creates the amortization schedule
    double get_total_payments() const;                  // Returns the total amount paid over the loan
    double get_total_interest() const;                  // Returns the total interest paid

    // Overload of the stream insertion operator for displaying loan details
    friend std::ostream &operator<<(std::ostream &os, const loan &loan);
};

// Declaration of the overloaded stream insertion operator
std::ostream &operator<<(std::ostream &os, const loan &loan);

// Function declaration for saving loan details to a file
void save_to_file(const loan &loan);

// Function declarations for user input and rerun prompt
bool input(double &principal, double &apr, int &num_months);
bool rerun();

#endif // End of header file guard
