#include "loan_calculator.hpp"
#include <cmath>
#include <iomanip>
#include <fstream>

loan::loan(double principal, double apr, int num_months) : principal(principal), apr(apr), num_months(num_months)
{
    calculate_monthly_rate();
    calculate_monthly_payments();
    calculate_amortization();
}

void loan::calculate_monthly_rate()
{
    monthly_rate = (apr / 100) / 12;
}

void loan::calculate_monthly_payments()
{
    monthly_payments = principal * ((monthly_rate * pow((1 + monthly_rate), num_months)) / (pow((1 + monthly_rate), num_months) - 1));
}

void loan::calculate_amortization()
{
    double balance = principal;
    for (int i = 0; i < num_months; i++)
    {
        payment p;
        p.month = i + 1;
        p.beginning_balance = balance;
        p.interest_payment = balance * monthly_rate;
        p.principal_payment = monthly_payments - p.interest_payment;
        balance -= p.principal_payment;
        if (balance < 0)
        {
            balance = 0;
        }
        p.ending_balance = balance;
        payments.emplace_back(p);
    }
}

double loan::get_total_payments() const
{
    double total = 0;
    for (const auto &p : payments)
    {
        total += (p.interest_payment + p.principal_payment);
    }
    return total;
}

double loan::get_total_interest() const
{
    double total_interest = 0;
    for (const auto &p : payments)
    {
        total_interest += p.interest_payment;
    }
    return total_interest;
}

std::ostream &operator<<(std::ostream &os, const loan &loan)
{
    os << "---------------------------------------------------------------------------" << std::endl;
    os << std::fixed << std::setprecision(2);
    os << "Principal Loan Amount: $" << loan.principal << std::endl;
    os << "Annual Percentage Rate: " << loan.apr << "%" << std::endl;
    os << "Duration of Loan: " << loan.num_months << " months" << std::endl;
    os << "---------------------------------------------------------------------------" << std::endl;
    os << "Monthly Payment: $" << loan.monthly_payments << std::endl;
    os << "Total payment over " << loan.num_months << " months: $" << loan.get_total_payments() << std::endl;
    os << "Total interest paid: $" << loan.get_total_interest() << std::endl;
    os << "---------------------------------------------------------------------------" << std::endl;
    os << std::setw(8) << std::left << "Month" << std::setw(20) << std::left << "Beginning Balance" << std::setw(11) << std::left << "Interest" << std::setw(12) << std::left << "Principal"
       << "Ending Balance" << std::endl;
    for (const auto &p : loan.payments)
    {
        os << std::setw(5) << std::right << std::fixed << std::setprecision(0) << p.month
           << std::setw(20) << std::right << std::setprecision(2) << p.beginning_balance
           << std::setw(11) << std::right << p.interest_payment
           << std::setw(12) << std::right << p.principal_payment
           << std::setw(17) << std::right << p.ending_balance << std::endl;
    }
    os << "---------------------------------------------------------------------------" << std::endl;
    return os;
}

void save_to_file(const loan &loan)
{
    std::ofstream output_file("output.txt", std::ios::app);
    if (!output_file)
    {
        std::cerr << "Error opening the output file." << std::endl;
        return;
    }
    output_file << loan;
    output_file.close();
}

bool input(double &principal, double &apr, int &num_months)
{
    std::cin.clear();
    std::cout << "Enter principal loan amount: ";
    while (!(std::cin >> principal) || principal <= 0)
    {
        std::cerr << "Error: Please enter a positive number for the principal loan amount.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter annual percentage rate (e.g. enter 5 for 5%): ";
    while (!(std::cin >> apr) || apr < 0)
    {
        std::cerr << "Error: Please enter a non-negative number for the APR.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter duration of loan (in months): ";
    while (!(std::cin >> num_months) || num_months <= 0)
    {
        std::cerr << "Error: Please enter a positive number for the duration of the loan.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return true;
}

bool rerun()
{
    char choice;
    std::cout << "Do you want to run the program again? Enter 'Y' to continue, or any other key to exit: ";
    std::cin >> choice;
    return toupper(choice) == 'Y';
}