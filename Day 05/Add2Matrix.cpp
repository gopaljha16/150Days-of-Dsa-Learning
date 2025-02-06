#include <iostream>
using namespace std;

// adding 2 matrix 2d array
int main()
{

    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 25};

    //   add the to matrix
    // size row and coloum should be same then only addition will be applicable
    int ans[3][4];
    for (int i = 0; i < 3; i++)
    for(int j=0;j<4;j++)
    ans[i][j] = arr1[i][j] + arr2[i][j];

    // print the answer array
    for (int i = 0; i < 3; i++)
    for(int j=0;j<4;j++)
    cout<<ans[i][j]<<" ";
}