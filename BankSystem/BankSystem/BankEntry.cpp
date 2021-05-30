// this is the entry point to the bank system
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
#include "BankSystem.h"
#include "BankTeller.h"

int main()
{   
    // create Bank
    Bank Bank;

    // pass Bank to BankTeller by pointer
    BankTeller Amy(&Bank);  // dereference: &Bank is saved as a pointer member of Amy(Bank *pBank)

    // do normal bank service
    Amy.executeBankService();

    // flirt with Amy 
    Amy.respondFlirt();
    return 0;
}