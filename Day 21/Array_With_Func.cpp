#include <iostream>
using namespace std;

void doubleNum(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        // p[i] == *(p+i)  like this it will do their execution..
        ptr[i] = 2 * ptr[i];
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    doubleNum(arr); // we know that arr will assingn the address of index first..
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

// by this we can double the array using pointer 