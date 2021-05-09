// this is the entry point to the bank system

#include "BankTeller.h"
int main()
{
    // create a bankteller who helps you with the bank service
    BankTeller Amy;

    // do normal bank service
    Amy.executeBankService();

    // flirt with Amy
    Amy.respondFlirt();
    return 0;
}