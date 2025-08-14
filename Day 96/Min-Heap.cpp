#include <iostream>
using namespace std;


void Heapify (int arr[] , int index , int n){
    int largest = index;
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;

    if(leftChild<n&&arr[leftChild]<arr[largest]){
      largest = leftChild;
    }
    if(rightChild<n&&arr[rightChild]<arr[largest]){
      largest = rightChild;
    }


    if(largest!=index){
        swap(arr[largest] , arr[index]);
        Heapify(arr , largest , n);
    }

}


void MinHeap(int arr[] , int n){
    //step down approch so 
    for(int i=n/2-1; i>=0 ;i--){
        //heapify
        Heapify(arr , i , n);
    }
}

void print(int arr[] , int n){
    for(int i=0 ; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //using the step-down approch 
    int arr[] = {1,2,54,3,45,62,6,8,10,70};
    MinHeap(arr , 10);
    print(arr,10);
}