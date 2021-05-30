
class BankTeller {
public:
    // execute SOP when being asked for bank service
    void executeBankService(Bank &bank);

    // response when someone flirts the teller
    void respondFlirt();

private:
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