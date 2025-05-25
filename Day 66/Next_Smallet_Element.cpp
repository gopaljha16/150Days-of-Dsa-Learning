// coding nijas 

// from backward solving 
// #include <stack>
// #include <vector>

// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//    stack<int>st;
//    vector<int>ans(n , -1);

//    for(int i=n-1 ; i>=0 ; i--){
       
//        while(!st.empty() && arr[st.top()]>=arr[i]){
//              st.pop();
//        }

//        if(!st.empty()){
//           ans[i] = arr[st.top()];
//        }

//        st.push(i);
//    }

//    return ans;
// }

// from front way 

// #include <stack>
// #include <vector>

// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//    stack<int>st;
//    vector<int>ans(n , -1);

//    for(int i=0 ; i<n ; i++){
       
//        while(!st.empty() && arr[st.top()]>arr[i]){
//           ans[st.top()] = arr[i];
//           st.pop();
//        }

//        st.push(i);
    
//    }

//    return ans;
// }