#include <iostream>
#include <queue>
using namespace std;

  void display(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
  }

int main(){
    int arr[] = {3,6,7,8,9,3,2};
    int n = 7;
    int k = 3;
    queue<int>q;
    //push k-1 element in the queue
  
    for(int i=0 ; i<k-1 ; i++){
        q.push(arr[i]);
    }

    //push from k-1 to till end of array
    for(int i=k-1 ; i<n ;i++){
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    return 0;
}