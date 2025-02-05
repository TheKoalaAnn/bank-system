#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void createAccount(string& name, int& accountNumber, double& balance);
void depositMoney(double& balance);
void withdrawMoney(double& balance);
void checkBalance(const double& balance);
void displayAccountDetails(const string& name, const int& accountNumber, const double& balance);

int main() {
    string name;
    int accountNumber;
    double balance = 0.0;
    bool accountCreated = false;

    int choice;
    do {
        cout << "\n---> Bank Account Management System <---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!accountCreated) {
                createAccount(name, accountNumber, balance);
                accountCreated = true;
            }
            else {
                cout << "Account already created.\n";
            }
            break;
        case 2:
            if (accountCreated) {
                depositMoney(balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 3:
            if (accountCreated) {
                withdrawMoney(balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 4:
            if (accountCreated) {
                checkBalance(balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 5:
            if (accountCreated) {
                displayAccountDetails(name, accountNumber, balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 6:
            cout << "Exiting the system. Thank you and have a good day!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}

// Function definitions

void createAccount(string& name, int& accountNumber, double& balance) {
    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Please enter your account number: ";
    cin >> accountNumber;

    do {
        cout << "Enter initial deposit (must be greater than 0): R ";
        cin >> balance;
        if (balance <= 0) {
            cout << "Initial deposit must be greater than 0. Try again.\n";
        }
    } while (balance <= 0);

    cout << "Account created successfully!\n";
}

void depositMoney(double& balance) {
    double deposit;
    do {
        cout << "Enter amount to deposit (must be greater than 0): R ";
        cin >> deposit;
        if (deposit <= 0) {
            cout << "Deposit amount must be greater than 0. Try again.\n";
        }
    } while (deposit <= 0);

    balance += deposit;
    cout << "Deposit successful! New balance: " << balance << "\n";
}

void withdrawMoney(double& balance) {
    double withdrawal;
    do {
        cout << "Enter amount to withdraw (must be greater than 0 and not exceed balance): R ";
        cin >> withdrawal;
        if (withdrawal <= 0) {
            cout << "Withdrawal amount must be greater than 0. Try again.\n";
        }
        else if (withdrawal > balance) {
            cout << "Withdrawal amount exceeds balance. Try again.\n";
        }
    } while (withdrawal <= 0 || withdrawal > balance);

    balance -= withdrawal;
    cout << "Withdrawal successful! New balance: R " << balance << "\n";
}

void checkBalance(const double& balance) {
    cout << "Current balance: " << balance << "\n";
}
void displayAccountDetails(const string& name, const int& accountNumber, const double& balance) {
    cout << "\n---> Account Details <---\n";
    cout << "Account Holder: " << name << "\n";
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Balance:  R " << balance << "\n";
}
