#include <iostream>
using namespace std;

void PrintDiagonal(int arr[][3], int row, int col)
{
    //  first digonal
    int first = 0,i,j;
     i = 0;
    while(i<row){
        first+=arr[i][i];
        i++;
    }

     i=0,j = col - 1;
    int second = 0;
    while (j >= 0)
    {second+=arr[i][j];
    i++;
    j--;
    }

    cout<<"First dig sum : "<<first<<endl;
    cout<<"Second dig sum : "<<second<<endl;

    // both sum
    cout<<first+second-5; 
    // -5 because both two 5 are present..
}

int main()
{
    //  Given a matrix of size n*n, Print sum of diagonal element.
    //  Ex:   1 2 3
    //           4 5 6
    //           7 8 9

    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    PrintDiagonal(arr, 3, 3);
}