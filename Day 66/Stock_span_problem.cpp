// Stock span problem gfg medium level question

// class Solution {
//   public:
//     vector<int> calculateSpan(vector<int>& arr) {
//        int n = arr.size();
//        stack<int>st;
//        vector<int>ans(n);
       
//        for(int i=n-1 ; i>=0 ; i--){
           
//            //no empty checking if arr[i] is greater than st top then insert and pop
//            while(!st.empty() && arr[i]>arr[st.top()]){
//                ans[st.top()] = st.top()-i;//updating with stack top to -i
//                st.pop();//popp
//            }
           
//            //if not greater than push in st
//            st.push(i);
//        }
       
//        //if in stack it left and have consequetive value so update that with index+1
//        while(!st.empty()){
//            ans[st.top()] = st.top()+1;
//            st.pop();
//        }
       
//        return ans;
        
//     }