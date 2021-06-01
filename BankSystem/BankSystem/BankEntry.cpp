// this is the entry point to the bank system
#include <iostream>
#include <cstdlib>
#include <map>
#include "BankSystem.h"
#include "Builder.h"

using namespace std;

int main()
{   
    int choiceNum;

    // create Bank
    Bank Bank;
    BankServiceBuilder::Type UserBankServiceType;
    IBankService *pBankService;

    cout << "Select service:\n";
    cout << "1) Bank Teller\n";
    cout << "2) ATM\n";
    cin >> choiceNum;
    UserBankServiceType = (BankServiceBuilder::Type)(choiceNum - 1);

    // builder buils a BankService object according to type
    pBankService = BankServiceBuilder::Build(UserBankServiceType, &Bank);

    assert(pBankService != nullptr);

    // do normal bank service
    pBankService->executeBankService();

    // flirt with bank service
    pBankService->respondFlirt();

    // delete objects
    delete pBankService;

    return 0;
}