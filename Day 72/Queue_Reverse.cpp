#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//first approch
int main(){
    vector<int>ans;
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }

    //enter element from stack
    for(int i=ans.size()-1 ; i>=0 ; i--){
        q.push(ans[i]);
    }

    //print queue element
    int n = q.size();
    while(n--){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}

//second approch.
// function Template for C++

// class Solution {
//   public:
//     queue<int> reverseQueue(queue<int> &q) {
//        stack<int>st;
       
//        //insert the queue element into stack
//        while(!q.empty()){
//            st.push(q.front());
//            q.pop();
//        }
       
//        //from stack insert it into the queue
//        while(!st.empty()){
//            q.push(st.top());
//            st.pop();
//        }
       
//        return q;
//     }
// };