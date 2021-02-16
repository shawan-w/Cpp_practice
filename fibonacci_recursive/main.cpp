#include <iostream>
using namespace std;
int Fibonacci(int num);


int N = 20;

int main()
{
 for (int num = 1; num <= N; num++){
     cout << Fibonacci(num) << ' ';
 }

}


int Fibonacci(int num)
{
    return num <= 2 ? 1 : Fibonacci(num - 2) + Fibonacci(num - 1); 
}