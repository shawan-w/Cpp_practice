#include <iostream>
using namespace std;



int main()
{
    int N = 6;
    int i, j, temp;
    int Numbers[N] = {98, 9, 1, 7, 7, 22};

    for (i = 0; i < N; i++){
        for (j = i+1; j < N; j++){
            if (Numbers[i] > Numbers[j]){
                temp = Numbers[j];
                Numbers[j] = Numbers[i];
                Numbers[i] = temp;
            }
        }

    }
    cout << "Sorted numbers are: ";
    for (i = 0; i < N; i++){
        cout << Numbers[i] << " ";
    }

}


