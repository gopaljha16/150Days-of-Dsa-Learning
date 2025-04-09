#include<iostream>
#include <vector>
using namespace std;

void Merge(int arr[] , int start , int mid , int end){
    // new array create
    vector<int>temp(end-start+1); //end-start+1 get the size of the array..
    int index = 0;
    int left = start , right = mid+1;

    //comparing and keeping to the temp array 
    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){ // left side comparing to right here left is smaller than right side array so here left side will be inserted to the temp array
            temp[index] = arr[left];
            index++ , left++;
        }else{
            temp[index] = arr[right]; // here right side element is smaller than the left side pointer so here right side element will be inserted into the temp array and index++ move one step and right also
            index++ , right++;
        }
    }

    // condition that if one of the side is inserted and move out of the array so here one side will copied to the temp array here basically it is sorted
    // left side left element (not empty yet)
    
    while(left<=mid){
        temp[index] = arr[left];
        index++, left++;
    }

    // same left side has out of the array the fill the right side array to the temp array  9not empty yet)
    while(right<=end){
        temp[index] = arr[right];
        index++, right++;
    }

    // then again fill to the original array which here made with the temp so here we need an referace of the array here doing the change should be refelected to the original array 
    // first index = 0 filling from the start so here index = 0
    index = 0;
    while(start<=end){
        arr[start] = temp[index];
        start++,index++;
    }

    // like this merging is done
}

void MergeSort(int arr[] , int start , int end){
    // case (stoppage condition)
    if(start==end) return; //here if it is in the single element both start and end will be equal to return from the loop if it is true..

    int mid = start + (end - start)/2;
    // here we have to call the function dividing the array until it's one
    MergeSort(arr , start , mid); // left side
     MergeSort(arr , mid+1 , end); // right right
    // divided into single element then merge it
    Merge(arr , start , mid , end); 
}

int main(){
    int arr[] = {9,10,22,4,1,6,7,11,2,3};
    MergeSort(arr, 0 , 9);
    
    //printing array
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
}