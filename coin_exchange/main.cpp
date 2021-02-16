#include <iostream>
using namespace std;    // namespace is a group of functions. std refers to standard library

int AskForAmount();     // declare function first
void ExchangeCoins(bool b50, bool b10, bool b5, int amount, int CoinNumber[4]);



int main()
{
    
    int amount;
    bool b50, b10, b5;
  
  	int CoinNumber[4];	// array of 4 kinds of coin number

    amount = AskForAmount();

    cout << "\n是否兌換50元硬幣? (1/0)" << endl;
    cin >> b50;
    cout << "\n是否兌換10元硬幣? (1/0)" << endl;
    cin >> b10;
    cout << "\n是否兌換5元硬幣? (1/0)" << endl;
    cin >> b5;

    ExchangeCoins(b50, b10, b5, amount, CoinNumber);
  	// input: CoinNumber -> pass by the address of CoinNumber
  	// input: CoinNumber[0] -> pass by the value
  
  	// display CoinNumber[0], CoinNumber[1], CoinNumber[2]...
    printf("You got %d NTD50 coins, %d NTD10 coins, %d NTD5 coins and %d NTD1 coins\n", CoinNumber[0],CoinNumber[1],CoinNumber[2],CoinNumber[3]);
    
}

int AskForAmount()
// to ask user key a number and print it
{
    int amount = 0;
    
    cout << "\n輸入兌換金額:\n" << endl;
    cin >> amount;
    while (amount<0) {
        printf("請輸入大於零之數字:\n");
        cin >> amount;
    }
    cout << "你的金額是: " << amount << endl;

    return amount;
}

void ExchangeCoins(bool b50, bool b10, bool b5, int amount, int CoinNumber[4])
{
    int c50 = 0, c10 = 0, c5 = 0, c1 = 0;
    
    if (b50==1){
        c50 = amount/50;
        }
    if (b10==1){
        c10 = (amount - c50*50)/10;
        }
    if (b5==1){
        c5 = (amount - c50*50 - c10*10)/5; 
        }
    
    c1 = amount - c50*50 - c10*10 - c5*5;
 
    CoinNumber[0] = c50;
    CoinNumber[1] = c10;
    CoinNumber[2] = c5;
    CoinNumber[3] = c1;

}