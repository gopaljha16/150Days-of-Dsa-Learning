// Implement stakc using queue leetcode easy level 

// class MyStack {
// public:
//     queue<int>q1;
// queue<int>q2;
//     MyStack() {    
//     }

//      bool empty() {
//         return q1.empty() && q2.empty();
//     }
    
//     void push(int x) {
//         //base case q1 and q2
//         if(empty()){
//             q1.push(x);
//         }else if(q1.empty()){ //if q1 is empty then q2 has element push 
//             q2.push(x);
//         }else{ // same q2 is empty and q1 has element push
//             q1.push(x);
//         }
//     }
    
//     int pop() {
//         if(empty()){
//             return 0;
//         }else if(q1.empty()){
//             //get elemet form q2
//             while(q2.size()>1){
//                 q1.push(q2.front());
//                 q2.pop();
//             }
//             int ele = q2.front();
//             q2.pop();
//             return ele;
//         }else{
//              //get elemet form q2
//             while(q1.size()>1){
//                 q2.push(q1.front());
//                 q1.pop();
//             }
//             int ele = q1.front();
//             q1.pop();
//             return ele;
//         }
//     }
    
//     int top() {
//         if(empty()){
//             return 0;
//         }else if(q1.empty()){
//             return q2.back();
//         }else{
//            return  q1.back();
//         }
//     }
// };