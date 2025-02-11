// Missing And Repeating Question gfg (easy level)


// vector<int> findTwoElement(vector<int>& arr) {
//     int n = arr.size();
    
//     for(int i=0;i<n;i++){
//         arr[i]--;
//     }
    
//     for(int i=0;i<n;i++){
//         arr[arr[i]%n]+=n;
//     }
    
//      //vector of size 2
//     vector<int>ans(2);
    
//     //occurence
//     for(int i=0;i<n;i++){
        
//         if(arr[i]/n==2)  // repeating number
//         ans[0]=i+1;
//         else if(arr[i]/n==0)  //missing number
//         ans[1]=i+1;
//     }
    
    
//     return ans;
// }