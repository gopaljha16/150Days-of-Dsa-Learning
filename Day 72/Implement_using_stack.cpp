// implement queue using stack leetcode easy level question 

// class MyQueue {
//     stack<int>st1;
//     stack<int>st2;
// public:
//     MyQueue() {
        
//     }

//      bool empty() {
//         return st1.empty() && st2.empty();
//     }

    
//     void push(int x) {
//          st1.push(x);
//     }
    
//     int pop() {
//          if(empty())
//          return 0;
        
//         //if stack2 is not empty
//        else if(!st2.empty()){
//             int ele = st2.top();
//             st2.pop();
//             return ele;
//         }else{ // stack is empty
//             //then push from st1
//             while(!st1.empty()){
//                 st2.push(st1.top());
//                 st1.pop();
//             }

//             int ele = st2.top();
//             st2.pop();
//             return ele;
//         }
//     }
    
//     int peek() {
//           if(empty())
//          return 0;
        
//         else if(!st2.empty()){ //stack 2 not empty
//         return st2.top();
//         }else{ //empty
//          //get all ele from st1 and push in stack2 
//          while(!st1.empty()){
//             st2.push(st1.top());
//             st1.pop();
//          }

//          return st2.top();
//         }
//     }
       
// };