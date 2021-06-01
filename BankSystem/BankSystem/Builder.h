#ifndef __BUILDER_H__
#define __BUILDER_H__

#include "BankSystem.h"
#include "IBankService.h"

class BankServiceBuilder
{
public:
    enum Type
    {
        BS_BankTeller = 0,
        BS_Atm
    };

    // to build a bank service object
    static IBankService *Build(Type BankServiceType, Bank *pBank);
};
#endif // __BUILDER_H__