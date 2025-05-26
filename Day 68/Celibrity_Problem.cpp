// Celibrity Problem on gfg medium level quesion.

// class Solution {
//   public:
//     int celebrity(vector<vector<int> >& mat) {
//         stack<int> st; // Stack to hold potential celebrities
//         int n = mat.size(); // Get the number of people

//         // Step 1: Push all people into the stack
//         for(int i = 0; i < n; i++) {
//             st.push(i); // Initially assume everyone could be a celebrity
//         }

//         // Step 2: Eliminate non-celebrities using pairwise comparison
//         while(st.size() > 1) {
//             int first = st.top();
//             st.pop();     // Pop the top person
//             int second = st.top();
//             st.pop();    // Pop the next person

//             // If first knows second, then first cannot be a celebrity
//             if(mat[first][second] == 1) {
//                 st.push(second); // second is still a possible celebrity
//             } else {
//                 // If first does not know second, then second cannot be a celebrity
//                 st.push(first); // first is still a possible celebrity
//             }
//         }

//         // Step 3: If stack is empty, no celebrity exists
//         if(st.empty()) 
//          return -1;

//         // Step 4: Validate the remaining candidate
//         int candidate = st.top(); // The only possible celebrity
//         st.pop(); 

//         // Step 5: Check if candidate knows no one and is known by everyone
//         for(int i = 0; i < n; i++) {
//             if(i != candidate) {
//                 // If candidate knows someone or someone doesn't know candidate -> not celebrity
//                 if(mat[candidate][i] == 1 || mat[i][candidate] == 0) {
//                     return -1;
//                 }
//             }
//         }

//         // If all checks pass, candidate is celebrity
//         return candidate;
//     }
// };