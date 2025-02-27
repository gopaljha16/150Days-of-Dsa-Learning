#include <iostream>
using namespace std;

int main()
{
    int L, B, H;
    cin >> L >> B >> H;

    int ***ptr = new int **[L];

    // create 2d array and store it address in ptr
    for (int i = 0; i < L; i++)
    {
        ptr[i] = new int *[B];
        for (int j = 0; j < B; j++)
        {
            ptr[i][j] = new int[H];
        }
    }

    // value filling
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < B; j++)
        {
            for (int k = 0; k < H; k++)
            {
                ptr[i][j][k] = i + j + k;
            }
        }
    }

    // print the array
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < B; j++)
        {
            for (int k = 0; k < H; k++)
            {
                cout << ptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // release the address
    for (int i = 0; i < L; i++) // Corrected: Traverse L, not B
    {
        for (int j = 0; j < B; j++)
        {
            delete[] ptr[i][j]; // Free the dynamically allocated 1D arrays
        }
        delete[] ptr[i]; // Free the dynamically allocated 2D arrays
    }
    delete[] ptr; // Finally, free the main pointer

    return 0;
}