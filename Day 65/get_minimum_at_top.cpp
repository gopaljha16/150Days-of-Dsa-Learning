// Get min at pop easy level gfg
// stack<int> _push(int arr[], int n) {
   
//     stack<int>st;
//     for(int i=0 ; i<n ; i++){
      
//       if(i==0){//empty stack
//           st.push(arr[i]);
//       }else{//valuse exissts
//           st.push(min(arr[i],st.top()));
//       }
//     }
    
//     return st;
// }

// // Function to print minimum value in stack each time while popping.
// void _getMinAtPop(stack<int> s) {
    
//     //printing and popping
//     while(!s.empty()){//run till stack is empty
//         cout<<s.top()<<" ";
//         s.pop();
//     }
// }