#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

#define INVALID_LOGINACCNUM     -1

using namespace std;

class InsufficientBalance {};

class Account {

private:
    int accNumber;
    string firstName;
    string lastName;
    string accName;
    string password;
    float balance;
    static int nextAccNumber;   // counter

public:
    // Constructors
    Account(){}
    Account(string firstName, string lastName, string accName, string password, float balance);

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

    // return true if the accname and password are matched
    bool checkAccNameAndPassword(string accName, string password) {
        if (this->accName.compare(accName) != 0) return false;
        if (this->password.compare(password) != 0) return false;

        return true;
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
    // account list
    map<int, Account> accounts;

    // this is to store the successfull logged in number, -1: not logged in
    int loginAccNumber;

    // currently logged in account
    Account loginAccount;
public:
    Bank();

    // --- Member functions ---

    // open account
    Account OpenAccount(string firstName, string lastName, string accName, string password, float balance);

    // login account by accName and password, return true if successful
    bool login(string accName, string password);

    // assign balance to argument, return false if not logged in
    bool BalanceCheck(float &balance);

    // deposit amount to account, return false if not logged in
    bool Deposit(float amount);

    // withdraw amount from account, return false if not logged in
    bool Withdraw(float amount);

    // close account, return false if not logged in
    bool CloseAccount();

    // return current account
    bool GetAccount(Account &account);

    ~Bank();    //destructor
};

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

Account::Account(string firstName, string lastName, string accName, string password, float balance)
{
    nextAccNumber++;
    this->accNumber = nextAccNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->accName = accName;
    this->password = password;
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
        throw InsufficientBalance(); 
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

ofstream& operator << (ofstream& ofs, Account& acc)
{
    ofs << acc.accNumber << endl;
    ofs << acc.firstName << endl;
    ofs << acc.lastName << endl;
    ofs << acc.accName << endl;
    ofs << acc.password << endl;
    ofs << acc.balance << endl;
    return ofs;
}

ifstream& operator >> (ifstream& ifs, Account& acc)
{
    ifs >> acc.accNumber;
    ifs >> acc.firstName;
    ifs >> acc.lastName;
    ifs >> acc.accName;
    ifs >> acc.password;
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

Account Bank::OpenAccount(string firstName, string lastName, string accName, string password, float balance) {
    
    ofstream outfile;
    Account account(firstName, lastName, accName, password, balance);
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

bool Bank::login(string accName, string password)
{
    map<int, Account>::iterator itr;
    Account currentAccount;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        currentAccount = itr->second;
        if (currentAccount.checkAccNameAndPassword(accName, password) == true) {
            // if matched, record the login account number and return true
            this->loginAccNumber = itr->first;
            return true;
        }
    }

    // if login failed, assign the loginAccNumber as invalid
    this->loginAccNumber = INVALID_LOGINACCNUM;
    return false;
}

// assign balance to argument, return false if not logged in
bool Bank::BalanceCheck(float &balance) {
    if (loginAccNumber == INVALID_LOGINACCNUM ) return false;

    map<int, Account>::iterator itr = accounts.find(loginAccNumber);
    balance = itr->second.getBalance();

    return true;
}

bool Bank::Deposit(float amount) {
    if (loginAccNumber == INVALID_LOGINACCNUM ) return false;

    map<int, Account>::iterator itr = accounts.find(loginAccNumber);
    itr->second.Deposit(amount);

    return true;
}

bool Bank::Withdraw(float amount) {
    if (loginAccNumber == INVALID_LOGINACCNUM ) return false;

    map<int, Account>::iterator itr = accounts.find(loginAccNumber);
    itr->second.Withdraw(amount);

    return true;

}

bool Bank::CloseAccount() {
    if (loginAccNumber == INVALID_LOGINACCNUM ) return false;

    map<int, Account>::iterator itr = accounts.find(loginAccNumber);
    accounts.erase(loginAccNumber);

    return true;
}

bool Bank::GetAccount(Account &account)
{
    if (loginAccNumber == INVALID_LOGINACCNUM ) return false;

    map<int, Account>::iterator itr = accounts.find(loginAccNumber);
    account = itr->second;

    return true;
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