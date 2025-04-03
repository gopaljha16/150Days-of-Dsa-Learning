#include <iostream>
#include <vector>
using namespace std;

int ParticularIndex(int arr[] , int index ){
    if(index==-1)
    return 0;

    cout<<arr[index]<<" ";
   return ParticularIndex(arr , index-1);
}

int main(){

    int arr[] = {3,7,6,2,8};
    ParticularIndex(arr , 4);
}