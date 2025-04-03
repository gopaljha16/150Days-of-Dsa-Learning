#include <iostream>
using namespace std;

int  ReversePrint(int arr[], int index)
{
    //    base case
    if (index == -1)
        return 0;

    return ReversePrint(arr, index - 1);
    cout << arr[index] << " ";
}

int main()
{
    int arr[] = {3, 7, 6, 2, 8};
    ReversePrint(arr, 4);
}