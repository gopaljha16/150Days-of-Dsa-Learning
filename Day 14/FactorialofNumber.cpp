// Gfg Meduim level question..

// vector<int> factorial(int n) {
//     vector<int>ans(1,1);
    
//     while(n>1){
//         int carry =0 , res , size = ans.size();
//         for(int i=0 ; i<size ; i++){
//             res = ans[i] * n + carry;
//             ans[i] = res%10;
//             carry = res/10;
//         }
        
//         //carry addding in array 
//         while(carry){
//             ans.push_back(carry%10);
//             carry/=10;
//         }
        
//         n--;
//     }
    
//     // reverse it to get the correct way of answer
//     reverse(ans.begin() , ans.end());
//     return ans;
// }