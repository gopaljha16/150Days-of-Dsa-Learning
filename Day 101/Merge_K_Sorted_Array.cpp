// //  Merge k Sorted Arrays gfg medium level question..


// Matrix Apporch
// class Solution {
//   public:
//     // Function to merge k sorted arrays.
//     vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
      
//       vector<pair<int , pair<int, int>>>temp;
      
//       //insert k eleemnts
//       for(int i=0 ; i<K ; i++){
//           temp.push_back(make_pair(arr[i][0], make_pair(i,0))); 
//       }
      
//       //minheap
//       priority_queue<pair<int , pair<int, int>> , vector<pair<int , pair<int, int>>> , greater<pair<int , pair<int, int>>>>p(temp.begin() , temp.end());
    
//       vector<int>ans; //vector which will store the sorted array
      
//        pair<int , pair<int, int>>element;
//        int i , j;
      
//        while(!p.empty()){ //condition till break when queue is empty
//            element = p.top();// storing the top element
//            p.pop();//pop from the queue
//            ans.push_back(element.first); // sorted pushing..
//            i = element.second.first; //row;
//            j = element.second.second ; //column
           
//            if(j+1<K)
//             p.push(make_pair(arr[i][j+1] , make_pair(i , j+1)));
//        }
       
//        return ans;
//     }
// };

//Another Apporch using merge  sort portion approch
// class Solution {
//   public:
  
  
  
//   void Merge(vector<int> &arr , int start , int mid , int end){
//     vector<int>temp(end-start+1);
//     int index=0 , left = start , right = mid+1;

//     while(left<=mid && right<=end){
//         if(arr[left]<arr[right]){
//             temp[index] = arr[left];
//             index++, left++;
//         }else{
//            temp[index] = arr[right];
//             index++, right++;
//         }
//     }

//     // left out side left and right
//     while(left<=mid){
//       temp[index] = arr[left];
//       index++ , left++;
//     }

//     // right side
//     while(right<=end){
//         temp[index]= arr[right];
//         index++, right++;
//     }

//     // adding to the original array
//     index =0;
//     while(start<=end){
//         arr[start] = temp[index];
//         start++ , index++;
//     }
//   }


//    void MergeSort(vector<int>&arr , int start , int end , int portion , int K){
//     //    base case 
//     if(start==end)
//      return;
     
//     //portion less than 1 then return 
//     if(portion<2)
//      return;

//      int mid = start +(portion/2)*K-1; //odd cases handling 
//     MergeSort(arr, start , mid , portion/2 , K); //left side
//     MergeSort(arr,mid+1 , end, portion-portion/2 , K); //right side
//     Merge(arr, start , mid , end);
//    }
  
//     vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
       
//         vector<int>ans;
//         for(int i=0 ; i<K ; i++)
//          for(int j=0; j<K ; j++){
//              ans.push_back(arr[i][j]);
//          }
         
//          MergeSort(ans , 0 , ans.size()-1, K , K); //passing start , end , protion , k
//          return ans;
//     }
// };
