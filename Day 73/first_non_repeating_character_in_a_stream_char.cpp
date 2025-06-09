//  First Non Repeating character in a stream of character (interview bit medium level question)
// string Solution::solve(string A) {
//     string B = "";
//     vector<int>repeated(26 , 0);
//     queue<char>q;
    
//     for(int i=0 ; i<A.size() ; i++){
//         //repeated
//         if(repeated[A[i]-'a']>=1){
//             repeated[A[i]-'a']++;
//             //check empty or not and front element is greater then pop
//             while(!q.empty()&& repeated[q.front()-'a']>1){
//                 q.pop();
//             }
            
//             //if queue is empty
//             if(q.empty()){
//                 B+="#";
//             }else{//if queue is not empty
//                 B+=q.front();
//             }
            
//         }//non repeated 
//         else{
//             repeated[A[i]-'a']++;
//             q.push(A[i]);
//             //check queue front is non repeating
//      while (!q.empty() && repeated[q.front() - 'a'] > 1) {
//     q.pop();
// }

            
//             B+=q.front();
//         }
        
//     }
    
//     return B;
// }
