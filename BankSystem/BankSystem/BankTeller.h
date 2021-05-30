
class BankTeller {
public:

    BankTeller(Bank *pBank);

    // execute SOP when being asked for bank service
    void executeBankService();

    // response when someone flirts the teller
    void respondFlirt();

private:
    Bank* m_pbank;
    enum EBankServiceOption {
        Opt_OpenAccount = 1,
        Opt_login,
        Opt_BalanceInquiry,
        Opt_Deposit,
        Opt_Withdraw,
        Opt_CloseAccount,
        Opt_Quit = 0
    };
};