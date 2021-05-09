#include "BankSystem.h"

class BankTeller {
public:
    // execute SOP when being asked for bank service
    void executeBankService();

    // response when someone flirts the teller
    void respondFlirt();
};

void BankTeller::executeBankService()
{
    int choice;

    Bank bank;
    Account acc;
    string firstName, lastName;
    int accNumber;
    float balance, amount;
    char ans; // Case 5 confirmation
    
    cout << "/// BANKING SYSTEM ///\n";
    do {
        cout << "\nSelect one option below: \n";
        cout << "1) Open an account\n";
        cout << "2) Balance inquiry\n";
        cout << "3) Deposit\n";
        cout << "4) Withdraw\n";
        cout << "5) Close an account\n";
        cout << "6) Show all acocunts\n";
        cout << "7) Quit\n\n";
        cout << "Enter your option: \n";
        cin >> choice;
        switch(choice)
        {
        case 1:     // Open an account
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter initial balance: ";
            cin >> balance;
            acc = bank.OpenAccount(firstName, lastName, balance);
            cout << "\nAccount is created." << endl;
            cout << acc << endl;
            break;

        case 2:     // Balance inquiry
            cout << "Enter your account number: " << endl;
            cin >> accNumber;
            acc = bank.BanlanceCheck(accNumber);
            cout << "\n Your account details" << endl;
            cout << acc << endl;
            break;

        case 3:     // Deposit
            cout << "Enter your account number: " << endl;
            cin >> accNumber;
            cout << "Enter amount of deposit: " << endl;
            cin >> amount;
            acc = bank.Deposit(accNumber, amount);
            cout << "\n Your account details" << endl;
            cout << acc << endl;
            break;

        case 4:     // Withdraw
            cout << "Enter your account number: " << endl;
            cin >> accNumber;
            cout << "Enter amount of withdrawl: " << endl;
            cin >> amount;
            acc = bank.Withdraw(accNumber, amount);
            cout << "\nYour account details: " << endl;
            cout << acc << endl;
            break;

        case 5:     // Close an account
            cout << "Enter your account number: " << endl;
            cin >> accNumber;
            cout << "\nYour account details:" << endl;
            acc = bank.BanlanceCheck(accNumber);
            cout << acc << endl;
            cout << "Are you sure you want to close this account? (Y/N)" << endl;
            cin >> ans;
            if (ans == 'Y' || ans == 'y') {
                bank.CloseAccount(accNumber);
                cout << " --- account deleted ---" << endl;
            }
            else
                cout << " --- cancelled ---" << endl;
            break;

        case 6:     // Show all accounts
            bank.ShowAllAccounts();
            break;

        case 7: break;
        default:
            cout << "\nPlease enter a correct choice! " << endl;
            break;
        } 
    }
    while (choice != 7);    // repeat the do{} loop as long as the condition is true

    cout << "Bye! See you again." << endl;
}

void BankTeller::respondFlirt()
{
    printf( "\nSorry I have a boyfriend\n" );
}