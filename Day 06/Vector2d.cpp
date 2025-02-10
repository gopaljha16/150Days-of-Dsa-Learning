#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // creating vector
    // 2d vector
    // vector<vector<int>>matrix;

    // giving valuees with vector
    int n ,m;
    cout<<"Enter your rows and cols size";
    cin>>n>>m;
    vector<vector<int> >matrix(n, vector<int>(m,3)) ;//this say 3 rows and column 4 and which is intialized by 3 in all the array 

    // input 
    cout<<"Enter your elements :- ";
    for(int i=0;i<n;i++){
     for(int j=0 ; j<m ; j++){
        cin>>matrix[i][j];
     }
    }

    //printing the array 
    for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){

        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
    }

    cout<<endl;

    


    // printing how many rows and cols are there in the matrix or array 
    cout<<"Rows = "<<matrix.size()<<endl;
    cout<<"Cols = "<<matrix[0].size()<<endl;
}

