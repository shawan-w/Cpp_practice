#include <iostream>
#include <cstdlib>
#include <map>
#include "BankSystem.h"
#include "atm.h"

using namespace std;

ATM::ATM(Bank* pBank)
{
	m_pbank = pBank;
}

void ATM::executeBankService()
{
    char choiceChar;
    int choiceNum, flag_loginFail = 0;

    Account acc;
    string firstName, lastName, accName, password;
    float balance, amount;

    cout << "/// ATM login page ///" << endl;
    do {
        cout << "\nEnter your account name: ";
        cin >> accName;
        cout << "Enter your password: ";
        cin >> password;
        if (m_pbank->login(accName, password) == true)
        {
            flag_loginFail = 0;
            cout << "......Login successful." << endl;

            do {
                cout << "1) Balance inquiry\n";
                cout << "2) Deposit\n";
                cout << "3) Withdraw\n";
                cout << "0) Quit\n";
                cout << "Enter your option: \n";
                cin >> choiceChar;
                choiceNum = (int)(choiceChar - '0');

                switch (choiceNum)
                {
                case Opt_BalanceInquiry:     // Balance inquiry
                    m_pbank->BalanceCheck(balance);
                    cout << "\n Your balance:" << endl;
                    cout << balance << endl;
                    break;

                case Opt_Deposit:     // Deposit
                    cout << "Enter amount of deposit: " << endl;
                    cin >> amount;
                    m_pbank->Deposit(amount);
                    m_pbank->BalanceCheck(balance);
                    cout << "\n......Deposit successful" << endl;
                    cout << "Your balance:" << endl;
                    cout << balance << endl;
                    break;

                case Opt_Withdraw:     // Withdraw
                    cout << "Enter amount of withdrawl: " << endl;
                    cin >> amount;
                    m_pbank->Withdraw(amount);
                    m_pbank->BalanceCheck(balance);
                    cout << "\n......Withdraw successful" << endl;
                    cout << "\nYour balance:" << endl;
                    cout << balance << endl;
                    break;

                case Opt_Quit:
                    break;
                }
            }             while (choiceNum != Opt_Quit);
        }
        else
        {
            flag_loginFail = 1;
            cout << "......Invalid account or password." << endl;
        }

    } while (flag_loginFail == 1);  // Repeatedly ask for correct accName & password 

    cout << "Bye! See you again." << endl;
}

void ATM::respondFlirt()
{
    printf("\nSorry I am just a machine.\n");
}
