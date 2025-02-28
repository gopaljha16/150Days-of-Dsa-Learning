#include <iostream>
using namespace std;

void printNum(int num, int n)
{

    // base condition
    if (num == n)
    {
        cout<<num<<" ";
        return;
    }

    cout << num << " ";
    printNum(num + 1, n);
}

int main()
{

    // 2: Print all numbers from 10 to n using recursion, where n will be greater than 10.
    int n;
    cout << "Enter n value :- ";
    cin >> n;

    printNum(10, n);

    return 0;
}