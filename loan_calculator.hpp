#ifndef loan_calculator_hpp
#define loan_calculator_hpp

#include <iostream>
#include <vector>

class loan
{
private:
    double principal;
    double apr;
    double monthly_rate;
    int num_months;
    double monthly_payments;
    struct payment
    {
        int month;
        double beginning_balance;
        double interest_payment;
        double principal_payment;
        double ending_balance;
    };
    std::vector<payment> payments;

public:
    loan(double principal, double apr, int num_months);
    void calculate_monthly_rate();
    void calculate_monthly_payments();
    void calculate_amortization();
    double get_total_payments() const;
    double get_total_interest() const;
    friend std::ostream &operator<<(std::ostream &os, const loan &loan);
};
std::ostream &operator<<(std::ostream &os, const loan &loan);
void save_to_file(const loan &loan);
bool input(double &principal, double &apr, int &num_months);
bool rerun();

#endif