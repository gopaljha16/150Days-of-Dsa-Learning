#include <iostream>
using namespace std;

int main(){
    // steps
    // First we create an array which stores the addresss
    int n,m;
    cin>>n>>m;

    int **ptr = new int *[n];

    // creating the to the address 1d array 
    // created 2d array
    for(int i =0 ; i<n; i++){
        ptr[i] = new int[m]; //m is the size of array
    }

    // assingning the values
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cin>>ptr[i][j];
        }
    }

    cout<<"The values are: "<<endl;
    // priting the values
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }

    // release the memory  like this we can release the memory 1d array release
    for(int i=0;i<n;i++){
        delete[] ptr[i]; // this will delete the array of the address
    }

    delete[] ptr;  // this will delete the ptr pointer addres
    return 0;
}