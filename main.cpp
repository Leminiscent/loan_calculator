#include "loan_calculator.hpp"

int main()
{
    while (true)
    {
        double principal, apr;
        int num_months;

        if (!input(principal, apr, num_months))
        {
            std::cerr << "Invalid input. Exiting program." << std::endl;
            return 1;
        }

        loan loan(principal, apr, num_months);
        std::cout << loan;
        save_to_file(loan);

        if (!rerun())
        {
            break;
        }
    }
    return 0;
}