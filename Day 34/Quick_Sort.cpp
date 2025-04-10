#include <iostream>
using namespace std;


int Partition(int arr[] , int start , int end){
     int pos = start;

    //  iterating to all element and checking small or not if small then swap into the pos the small element of the pivot 
    for(int i=start ; i<=end; i++){

        // if small than pivot element then swap to pos and increase
        if(arr[i]<=arr[end]){
            swap(arr[i] , arr[pos]);
            pos++;
        }
    }

    // return the index giving the less than the element
    return pos-1;
}

void QuickSort(int arr[] , int start , int end){
    //base case
    if(start>=end)
    return;

    int pivot = Partition(arr , start , end);
    // left side
    QuickSort(arr, start  , pivot-1);
    //right side
    QuickSort(arr, pivot+1 , end);

}

int main(){
    int arr[] = {6,2,5,2,7,4,1,3};
    QuickSort(arr , 0 , 8);
    
    // sorted the array..
    for(int i=0 ; i<8;i++){
        cout<<arr[i]<<" ";
    }
}