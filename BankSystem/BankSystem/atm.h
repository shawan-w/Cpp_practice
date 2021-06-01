#pragma once
#include "IBankService.h"

class ATM : public IBankService
{
public:

    ATM(Bank* pBank);

    // execute SOP when being asked for bank service
    void executeBankService();

    // response when someone flirts the teller
    void respondFlirt();

private:
    Bank* m_pbank;
    enum EBankServiceOption {
        Opt_BalanceInquiry = 1,
        Opt_Deposit,
        Opt_Withdraw,
        Opt_Quit = 0
    };
};