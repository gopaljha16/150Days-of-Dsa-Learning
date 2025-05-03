#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int>arr(5);
    cout<<"Enter the input ";
    fstream fout;
    fout.open("zero.txt");
    for(int i=0 ;i<5; i++){
        cin>>arr[i];
    }
    
    fout<<"Original Data\n";
    for(int i=0 ; i<5 ;i++){
        fout<<arr[i]<<" ";
    }

  fout<<"\nSorted Data\n";
  sort(arr.begin() , arr.end());
  for(int i=0 ; i<5 ; i++){
    fout<<arr[i]<<" ";
  }

  fout.close();
 
}