#include <iostream>
using namespace std;

void printEven(int n)
{

    if (n == 2)
    {
        cout << 2;
        return;
    }

    cout << n << " ";
    printEven(n - 2);
}

int main()
{
    // Print Even number;
    int n;
    cout << "Enter the n value :- ";
    cin >> n;

    // iterative method
    // for(int i=n; i>0;i--){
    //     if(i%2==0){
    //         cout<<i<<" ";
    //     }
    // }

    // recursive way
    printEven(n);

        return 0;
}