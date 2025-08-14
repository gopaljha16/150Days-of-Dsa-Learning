#include <iostream>
using namespace std;


void Heapify (int arr[] , int index , int n){
    int largest = index;
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;

    if(leftChild<n&&arr[leftChild]>arr[largest]){
      largest = leftChild;
    }
    if(rightChild<n&&arr[rightChild]>arr[largest]){
      largest = rightChild;
    }


    if(largest!=index){
        swap(arr[largest] , arr[index]);
        Heapify(arr , largest , n);
    }

}


void MaxHeap(int arr[] , int n){
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

void sortArray(int arr[] , int n){

    for(int i=n-1; i>0; i--){
        swap(arr[i] , arr[0]);//first and last
        Heapify(arr, 0 , i); // arr index size.
    }
}

int main(){
    //using the step-down approch 
    int arr[] = {1,2,54,3,45,62,6,8,10,70};
    MaxHeap(arr , 10);
    sortArray(arr , 10);
    print(arr,10);
}