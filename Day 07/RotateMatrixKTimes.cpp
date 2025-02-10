#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Rotate90(int mat[][4] , int row ,int col){
    // transpose
    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++){
            swap(mat[i][j] , mat[j][i]);
        }
    }

    //row-wise reverse
    for(int i=0;i<row;i++){
        int start=0,end=col-1;
        while(start<end){
            swap(mat[i][start] , mat[i][end]);
            start++;
            end--;
        }
    }

}

void printMatrix(int mat[][4], int row, int col) {
    cout << "Final Rotated Matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int k;
    std::cout<<"Enter the k value :- ";
    std::cin>>k;
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    k=k%4;
    while(k--){
        Rotate90(mat,4,4);        
    }

    printMatrix(mat,4,4);
}