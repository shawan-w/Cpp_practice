#include <iostream>
using namespace std;
void Fibonacci(int *pFibo, int length);

int main()
{
    int N = 0;
    cout << "Enter number of elements:" << endl;
    cin >> N;

  	int *pFibo = 0;
  	pFibo = new int[N];
  
  	printf("%x\n", pFibo);

    Fibonacci(pFibo, N);
    
    for (int i = 0; i < N; i++){
        cout << pFibo[i] << ' ';
    }
  
  	delete [] pFibo;
}


void Fibonacci(int *pFibo, int length)
{
    
    pFibo[0] = 1;
    pFibo[1] = 1;
    
    for (int i = 2; i < length; i++){

        pFibo[i] = pFibo[i-1] + pFibo[i-2];
    }
}


}