#include <iostream>
using namespace std;

//  void printTable(int num , int  n){

//      if(num==10){
//         cout<<num*n;
//         return;
//      }

//     cout<<num*n<<endl;
//     printTable(num+1 , n);
//  }

// reverse method
void printTable(int num, int n)
{

    if (num == 1)
    {
        cout << num * n << endl;
        return;
    }
    printTable(num - 1, n);
    cout << num * n << endl;
}

int main()
{

    // 3: Write a Table program using recursion. Take input number n, and print its table.
    // iterative method
    // int n =2
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << n * i << endl;
    // }

    int n;
    cout << "Enter the n value :- ";
    cin >> n;
    printTable(10, n);

    return 0;
}