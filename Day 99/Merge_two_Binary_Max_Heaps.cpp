// Merge two binary max heaps gfg easy level question

// class Solution {
//   public:
  
  
//  //heapify fucntion 
//  void Heapify(vector<int>&ans , int index , int n){
//      int largest = index;
//      int left = 2*index+1;
//      int right = 2*index+2;
     
//      //comparison
//      if(left<n && ans[left]>ans[largest]){
//          largest = left;
//      }
     
//      if(right<n && ans[right]>ans[largest]){
//          largest = right;
//      }
     
//      if(largest!=index){
//          swap(ans[largest] , ans[index]);
//          Heapify(ans , largest , n);
//      }
//  }
  
//     vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
//        vector<int>ans;
       
//        for(int i=0; i<n ; i++){
//            ans.push_back(a[i]); //n elements pushing
//        }
       
//        for(int i=0; i<m ; i++){
//            ans.push_back(b[i]); //m elements pushing
//        }
       
//        //convert the vector into max heap 
//        n = ans.size();
//        for(int i=n/2-1 ; i>=0 ; i--){
//            Heapify(ans , i , n);
//        }
       
//        return ans;
        
//     }
// };