#include <iostream>
#include <string>
using namespace std;
class BankAccount {
protected:
    double balance;
    string accountNumber;
public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
        cout << "Bank Account created with Account Number: " << accountNumber << endl;
    }
    void displayBalance() {
        cout << "Account Balance: $" << balance << endl;
    }};
class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(string accNum, double initialBalance, double rate) 
        : BankAccount(accNum, initialBalance), interestRate(rate) {
        cout << "Savings Account created" << endl;
    }
    void addInterest() {
        double interest = balance * interestRate / 100; 
        balance += interest; 
        cout << "Interest added: $" << interest << endl;
        cout << "New Balance: $" << balance << endl;
    }
    void deposit(double amount) {
        balance += amount;  
        cout << "Deposited: $" << amount << endl;
        cout << "Current Balance: $" << balance << endl;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount; 
            cout << "Withdrawn: $" << amount << endl;
            cout << "Remaining Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    void displayAccountInfo() {
        cout << "\nSavings Account Information" << endl;
        cout << "Account Number: " << accountNumber << endl; 
        cout << "Balance: $" << balance << endl; 
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }};
int main() {
    SavingsAccount myAccount("SA123456", 1000.0, 5.0);
    cout << "\nInitial Account Status" << endl;
    myAccount.displayBalance();
    cout << "\n--- Performing Transactions ---" << endl;
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.addInterest();
    cout << "\n--- Final Account Status ---" << endl;
    myAccount.displayAccountInfo();
    return 0;
}