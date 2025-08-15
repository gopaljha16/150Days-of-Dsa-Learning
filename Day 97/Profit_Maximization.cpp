//Profit Maximization easy levelquestion


// int Solution::solve(vector<int> &A, int B) {
//     int sum = 0;
//     priority_queue<int>p;
    
//     //insert element
//     for(int i=0 ; i<A.size() ; i++){
//         p.push(A[i]);
//     }
    
//     //ticket selling to the B people
//     while(B&&!p.empty()){
//         //maximum ticket
//         sum+=p.top();
//         if(p.top()-1){
//             p.push(p.top()-1);
//         }
//         p.pop();
//         B--;//decrease tickets
//     }
    
//     return sum;
// }
