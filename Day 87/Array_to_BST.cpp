//  Array to bst gfg easy level question

// class Solution {
//   public:
   
//    Node * ArrToBST(vector<int>&arr , int start , int end){
//        //base case
//        if(start>end)
//         return NULL;
        
//        //value then left then right
//        int mid = start + (end-start)/2;
//        Node * root = new Node(arr[mid]);
//       root->left =  ArrToBST(arr, start , mid-1);//left
//        root->right  = ArrToBST(arr,mid+1 , end);//right
       
//        return root;
//    }
  
//     Node* sortedArrayToBST(vector<int>& nums) {
        
//         return ArrToBST(nums , 0 , nums.size()-1);
    
        
//     }
// };