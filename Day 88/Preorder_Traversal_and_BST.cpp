// Preorder Traversal and BST gfg medium level question 
// User function Template for C++
//stack method in recursiion we will be getting the segementation fault.
// class Solution {
//   public:
//     int canRepresentBST(int arr[], int N) {
//        stack<int>lower , upper;
//        lower.push(INT_MIN);
//        upper.push(INT_MAX);
//        //lower and upper bound 
//        int LowerBound , UpperBound;
       
//        for(int i=0 ; i<N; i++){
//            //1st step for the if arr[i] is < lower top then return 0;
//            if(arr[i]<lower.top())
//             return 0;
            
//            //2nd step pop
//            while(arr[i]>upper.top()){
//                upper.pop();
//                lower.pop();
//            }
          
//           //3rd step 
//           LowerBound = lower.top();
//           UpperBound = upper.top();
//           lower.pop();
//           upper.pop();
//           //stack element right then left
//           lower.push(arr[i]);
//           upper.push(UpperBound);
//           //left
//           lower.push(LowerBound);
//           upper.push(arr[i]);
//        }
       
//        return 1;
        
//     }
// };