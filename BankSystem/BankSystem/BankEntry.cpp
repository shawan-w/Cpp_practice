// this is the entry point to the bank system
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
#include "BankSystem.h"
#include "BankTeller.h"
#include "atm.h"

int main()
{   
    int choiceNum;

    // create Bank
    Bank Bank;

    cout << "Select service:\n";
    cout << "1) Bank Teller\n";
    cout << "2) ATM\n";
    cin >> choiceNum;

    if (choiceNum == 1)
    {// pass Bank to BankTeller by pointer
        BankTeller Amy(&Bank);  // dereference: &Bank is saved as a pointer member of Amy(Bank *pBank)

        // do normal bank service
        Amy.executeBankService();

        // flirt with Amy 
        Amy.respondFlirt();
    }
    else
    {    //cout << "ATM is still under construction. Plz enter 1) or come back later :)" << endl;
        ATM atm1(&Bank);
        atm1.executeBankService();
        atm1.respondFlirt();
    }
        return 0;
}