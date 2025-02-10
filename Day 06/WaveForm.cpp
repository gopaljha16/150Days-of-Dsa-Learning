#include <iostream>


//this prints the codein wave form..
void WaveForm(int arr[][4], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < row; i++)
            std::cout<< arr[i][j] << " ";
        }
        else
        {
            for (int i = row-1; i >= 0; i--)
            std::cout << arr[i][j] << " ";
        }
    }
}

int main()
{
    int arr[3][4] = {3, 4, 5, 6, 8, 2, 3, 4, 9, 3, 2, 1};

    WaveForm(arr, 3, 4);
}