#include "loan_calculator.hpp"

int main()
{
    while (true)
    {
        double principal, apr;
        int num_months;

        // Get user input for loan details
        if (!input(principal, apr, num_months))
        {
            std::cerr << "Invalid input. Exiting program." << std::endl;
            return 1;
        }

        // Create a loan object and calculate details
        loan loan(principal, apr, num_months);
        std::cout << loan;  // Output loan details
        save_to_file(loan); // Save loan details to a file

        // Ask the user if they want to run the program again
        if (!rerun())
        {
            break; // Break out of the loop to end the program
        }
    }
    return 0; // Return 0 to indicate successful program execution
}
