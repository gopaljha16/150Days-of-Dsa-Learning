// Construct Target array with multiple sum leetcode hard level question 


// class Solution {
// public:
//     bool isPossible(vector<int>& target) {
//         //max_heap
//         priority_queue<long long>p; 
//         long long sum = 0;

//         //inserting the values in the queue
//         for(int i=0 ; i<target.size() ; i++){
//             p.push(target[i]);
//             sum+=target[i];
//         }

//         long long maxElement , remSum , Ele;
//         while(p.top()!=1){ // if the top value comes to 1 then it will breaking the loop
//                maxElement = p.top(); //max heap top element
//                p.pop();

//                remSum = sum - maxElement; //reamaining sum

//                //edge case
//                if(remSum<=0 || remSum>=maxElement){
//                 return 0;
//                }

//                Ele = maxElement%remSum;
//                //more edgecases
//                if(Ele==0){
//                 if(remSum!=1){
//                     return 0;
//                 }else{
//                     return 1;
//                 }
//                }
//                sum = remSum+Ele;
//                p.push(Ele); 
//         }

//         return 1;
//     }
// };