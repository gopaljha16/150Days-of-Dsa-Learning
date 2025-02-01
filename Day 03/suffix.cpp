#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Suffix(vector<int>arr){
  int suffix =0 , n = arr.size();
   for(int i=n-1; i>=0;i--){
    suffix+=arr[i];
   }
   return suffix;
}

int main(){
    int n;
    cout<<"Enter the size of array :- ";
    cin>>n;
    cout<<"Enter the element in array :- ";
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   
   cout<<Suffix(v)<<endl;

}