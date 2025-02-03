//  Geeks for geeks question Four Elements
// ```
// bool find4Numbers(int A[], int n, int X)  
// { 
//     // sorting bubble sort
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(A[j]>A[j+1])
//             swap(A[j],A[j+1]);
//         }
//     }
    
//     //main logic
//     for(int i=0;i<n-3;i++){
//         for(int j=i+1; j<n-2;j++){
//            int ans = X-(A[i]+A[j]);
//            int start =j+1 , end=n-1;
//            while(start<end){
//             if(A[start]+A[end]==ans){
//                 return 1;
//             }
//             else if(A[start]+A[end]>ans)
//             end--;
//             else 
//             start++;
//     }
        
//     }
       
//     }
//     return 0;
// }