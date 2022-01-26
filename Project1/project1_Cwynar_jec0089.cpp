// Jack Cwynar
// jec0089
// project1_Cwynar_jec0089.cpp
// Compiler Version: Apple clang version 12.0.0 (clang-1200.0.32.28)
// Used default g++ compiler on server to compile on server.
// Used template provided on Canvas to finish Project 1.
// Used https://stackoverflow.com/questions/15674097/output-aligned-columns to
// line up columns of output with setw() and left (lines 84-85, 100-106).

// Inclusions
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()  {

    double loanAmount;
    double intRate;
    double monPay;
    double mRate; //for monthly rate
    double monInt;
    double principal = 0.0;
    double interestTotal = 0.0;

    
    // Formatting currency
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "\nLoan Amount: ";
    cin >> loanAmount;
    
    // Used stackoverflow.com for learning how to handle non-numeric input; lines 32-78
    while (!cin || loanAmount < 0)   {
        cout << "Bad value! Please enter a positive numeric value." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nLoan Amount: ";
        cin >> loanAmount;
    }
    
    cout << "Interest Rate (% per year): ";
    cin >> intRate;
    
    while (!cin || intRate < 0)   {
        cout << "Bad value! Please enter a positive numeric value." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInterest Rate (% per year): ";
        cin >> intRate;
    }
    
    intRate = intRate / 12;
    mRate = intRate / 100;
    cout << "Monthly Payments: ";
    cin >> monPay;
    monInt = (loanAmount) * (mRate);
    
    while (!cin || monPay < 0)   {
        cout << "Bad value! Please enter a positive numeric value." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nMonthly Payments: ";
        cin >> monPay;
    }
    
    if (monPay <= monInt)    {
        cout << "Monthly payment is too small! Please enter a larger monthly payment";
        cout << "\nMonthly Payments: ";
        cin >> monPay;
    }
    
    cout << endl;
    
    // AMORTIZATION TABLE
    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    int i = 0; // for month
    cout << i << setw(8)  << "$" << loanAmount << "\tN/A" << setw(8) << "N/A"
         << setw(8) << "N/A" << setw(17) << "N/A\n";
    while (loanAmount > 0)    {
        
        i++;
        
        interestTotal += monInt;
        principal = monPay - monInt;
        
        if (loanAmount < principal)    {
            principal = loanAmount;
            monPay = principal + monInt;
        }
        
        loanAmount -= principal;
        
        cout << setw(8) << left << i;
        cout << "$";
        cout << setw(15) << left << loanAmount;
        cout << setw(8) << left << monPay;
        cout << setw(8) << left << intRate;
        cout << setw(16) << left << monInt;
        cout << principal << "\n";
        
        monInt = 0.0;
        monInt = (mRate * loanAmount);
}
    cout << "****************************************************************\n";
    cout << "\nIt takes " << i << " months to pay off the loan.\n"
    << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    return 0;
}
