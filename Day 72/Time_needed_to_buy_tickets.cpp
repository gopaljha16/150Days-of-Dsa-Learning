// Time Needed to buy tickets leetcode easy level question 

// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         queue<int>q;
//         int n = tickets.size();
//         //push all the index in the stack
//         for(int i=0 ; i<n ; i++){
//             q.push(i);
//         }

//         //time 
//         int time = 0;

//         //until tickets exisits of k 
//         while(tickets[k]!=0){
//             tickets[q.front()]--;

//             //until tickets exsits then push 
//             if(tickets[q.front()])
//               q.push(q.front());

//             //or else pop
//             q.pop();
//             //increase time
//             time++;
//         }

//         return time;
//     }
// };