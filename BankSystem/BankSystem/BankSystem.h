
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

class InsufficientBalnce {};

class Account {

private:
    int accNumber;
    string firstName;
    string lastName;
    float balance;
    static int nextAccNumber;   // counter

public:
    // Constructors
    Account(){}
    Account(string firstName, string lastName, float balance); 

    // Accessors
    int getAccNumber() {
        return accNumber;
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    float getBalance() {
        return balance;
    }

    // Member functions
    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(int accNumber);
    static int getLastAccountNumber();

    // Using Friend Function operator overloading
    friend ofstream& operator << (ofstream& ofs, Account& acc);
    friend ifstream& operator >> (ifstream& ifs, Account& acc);
    friend ostream& operator << (ostream& os, Account& acc);


};
int Account::nextAccNumber = 0; // Scope resolution

class Bank {
private:
    map<int, Account> accounts;
public:
    Bank();

    // Member functions
    Account OpenAccount(string firstName, string lastName, float balance);
    Account BanlanceCheck(int accNumber);
    Account Deposit(int accNumber, float amount);
    Account Withdraw(int accNumber, float amount);
    void CloseAccount(int accNumber);
    void ShowAllAccounts();
    ~Bank();    //destructor
};

int main()
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

    return 0;
}



// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

Account::Account(string firstName, string lastName, float balance)
{
    nextAccNumber++;
    this->accNumber = nextAccNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->balance = balance;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::Withdraw(float amount)
{
    if (balance < amount) {
        cout << "Insufficient balance!" << endl;
        throw InsufficientBalnce(); 
    }
    balance -= amount;
}

void Account::setLastAccountNumber(int accNumber)
{
    nextAccNumber = accNumber;
}

int Account::getLastAccountNumber()
{
    return nextAccNumber;
}

ofstream & operator << (ofstream& ofs, Account& acc)
{
    ofs << acc.accNumber << endl;
    ofs << acc.firstName << endl;
    ofs << acc.lastName << endl;
    ofs << acc.balance << endl;
    return ofs;
}

ifstream& operator >> (ifstream& ifs, Account& acc)
{
    ifs >> acc.accNumber;
    ifs >> acc.firstName;
    ifs >> acc.lastName;
    ifs >> acc.balance;
    return ifs;
}

ostream& operator << (ostream& os, Account& acc)    // similart to std::cout
{
    os << "Account number: " << acc.getAccNumber() << endl;
    os << "First Name: " << acc.getFirstName() << endl;
    os << "Last Name: " << acc.getLastName() << endl;
    os << "Balance: " << acc.getBalance() << endl;
    return os;
}

Bank::Bank() {
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if (!infile) 
    {
        cout << "File not found!" << endl;
        return;
    }
    while(!infile.eof())
    { 
        infile >> account;
        accounts.insert(pair<int, Account>(account.getAccNumber(), account));
    }
    Account::setLastAccountNumber(account.getAccNumber());

    infile.close();
}   



Account Bank::OpenAccount(string firstName, string lastName, float balance) {
    
    ofstream outfile;
    Account account(firstName, lastName, balance);
    accounts.insert(pair<int, Account>(account.getAccNumber(), account));

    outfile.open("Bank.data", ios::trunc);
    
    map<int, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
    return account;
}
Account Bank::BanlanceCheck(int accNumber) {

    map<int, Account>::iterator itr = accounts.find(accNumber);
    return itr->second;
}

Account Bank::Deposit(int accNumber, float amount) {
    
    map<int, Account>::iterator itr = accounts.find(accNumber);
    itr->second.Deposit(amount);
    return itr->second;

}
Account Bank::Withdraw(int accNumber, float amount) {
   
    map<int, Account>::iterator itr = accounts.find(accNumber);
    itr->second.Withdraw(amount);
    return itr->second;

}
void Bank::CloseAccount(int accNumber) {

    map<int, Account>::iterator itr = accounts.find(accNumber);
    cout << itr->second << endl;
    accounts.erase(accNumber);
}
void Bank::ShowAllAccounts() {

    map<int, Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        cout << itr->second << endl;
    }

}

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);

    map<int, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
}