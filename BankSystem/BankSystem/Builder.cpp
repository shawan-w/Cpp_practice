#include <assert.h>
#include "BankSystem.h"
#include "BankTeller.h"
#include "atm.h"
#include "Builder.h"

IBankService *BankServiceBuilder::Build(Type BankServiceType, Bank *pBank)
{
    IBankService *pBankService = nullptr;
    switch (BankServiceType) {
    case BS_BankTeller:
        pBankService = new BankTeller(pBank);
        break;

    case BS_Atm:
        pBankService = new ATM(pBank);
        break;

    default:
        assert(false);
        return nullptr;
    }

    return pBankService;
}
