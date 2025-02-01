#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Prefix(vector<int>arr){
    int prefix =0 , n = arr.size();
    for(int i=0 ;i<n; i++){
        prefix+=arr[i];
    }

    return prefix;
}

int main(){
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n;i++)
    cin>>v[i];

    // prefix it basically count or do total from front
    cout<<Prefix(v)<<endl;
}