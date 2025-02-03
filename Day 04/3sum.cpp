//Triplet Sum in Array

// bool hasTripletSum(vector<int> &arr, int target) {
//         int n=arr.size();
//         sort(arr.begin() , arr.end());
        
//         for(int i=0;i<n-2;i++){
//             int ans = target-arr[i];
//             int start=i+1,end=n-1;
//             while(start<end){
//                 if(arr[start]+arr[end]==ans)
//                 return 1;
//                 else if(arr[start]+arr[end]>ans)
//                 end--;
//                 else 
//                 start++;
//             }
//         }
//         return 0;
//     }