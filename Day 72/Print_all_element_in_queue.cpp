#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  queue<int>q;
  q.push(20);
  q.push(40);
  q.push(30);
  q.push(60);
  q.push(70);

//   print all element
//Approch -1 o(n)
// while(!q.empty()){
//     cout<<q.front()<<" ";
//     q.pop();
// }

// approch -2 without deleting the value from the queue print all the element o(n) space complexity
// vector<int>ans;
// while(!q.empty()){
//     ans.push_back(q.front());
//     cout<<q.front()<<" ";
//     q.pop();
// }

// //remove from the vector and put into the queue.
// for(int i=0;i<ans.size();i++){
//     q.push(ans[i]);
// }

// cout<<q.size();


//approch - 3 without deleting the value from queue all the element 0(1) space complexity.
int n = q.size();
while(n--){
    cout<<q.front()<<" ";
    q.push(q.front());
    q.pop();
}

cout<<q.size();

}