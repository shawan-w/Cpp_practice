#include <iostream>
#include <string.h>
#include "Bank.hpp"




void openAccount(std::map<std::string, TAccount> &accList)
{
    TAccount TempAcc;
    std::string strInput;
    std::string accName;

    printf("welcome, your account name?\n");
    std::cin >> accName;

    printf("your password?\n");
    std::cin >> TempAcc.szPassword;

    printf("how much do you have?\n");
    std::cin >> strInput;

    sscanf(strInput.c_str(), "%lf", &TempAcc.Balance);
    printf("Your acc: %s, password: %s, money: %lf\n", accName.c_str(), TempAcc.szPassword.c_str(), TempAcc.Balance);
  
  	// put new acc into accList 
  	accList[accName] = TempAcc;

}

void loginAccount(std::map<std::string, TAccount> &accList)
{   
    TAccount TempAcc;
    std::string LoginName;
    bool MatchedPassword = false; 

    while (MatchedPassword == false){
    printf("welcome, your account name?\n");
    std::cin >> LoginName;
    printf("your password?\n");
    std::cin >> TempAcc.szPassword;
        if (accList.find(LoginName) == accList.end() || TempAcc.szPassword != accList[LoginName].szPassword){
            printf("Wrong account name or password!\n");
        }
        else {
            MatchedPassword = true;
        }


    }

    printf("Your account balance: %lf\n", accList[LoginName].Balance);
}

int main()
{
  std::map<std::string, TAccount> accList;
  
  int choice;
  bool quit = false;

  while (quit == false) {
      printf("your choice: 1,2,3\n");
      printf("1. open account\n");
      printf("2. login\n");
      printf("3. quit\n");

      std::cin >> choice;

      switch (choice) {
      case 1: 
          openAccount(accList);
          break;
      case 2:
          loginAccount(accList);
          break;
      case 3:
          quit = true;
          break;
      default:
          printf("wrong input!\n");
          break;
      }
  }

  printf("BYE!\n");
}
