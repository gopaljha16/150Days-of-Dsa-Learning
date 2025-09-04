// Alien Dictionary gfg hard level question 

// class Solution {
//   public:
//     string findOrder(vector<string> &words) {
//        int N = words.size();  // number of words

//         // find all unique characters to determine K
//         unordered_set<char> uniqueChars;
//         for (string &w : words) {
//             for (char c : w) {
//                 uniqueChars.insert(c);
//             }
//         }

//         int K = uniqueChars.size(); // number of unique characters


//         ///create the adj 
//         vector<int>adj[26];
//         vector<int>Indeg(26, 0);
        
//          for(int i=0 ; i<N-1 ; i++){
//             string str1 = words[i] , str2 = words[i+1];
//             int j = 0 , k = 0; 
//             bool foundMismatch = false;
            
//             // compare until first mismatch
//             while (j < str1.size() && k < str2.size() && str1[j] == str2[k]) {
//                 j++; k++;
//             }
             
//             if (j < str1.size() && k < str2.size()) {
//                 adj[str1[j] - 'a'].push_back(str2[k] - 'a');
//                 Indeg[str2[k] - 'a']++;
//                 foundMismatch = true;
//             }

//             // prefix invalid case
//             if (!foundMismatch && str1.size() > str2.size()) {
//                 return "";
//             }
//         }
        
        
//         //now the Kahn's algo
//         queue<int>q;
//          for (char c : uniqueChars) {
//           if (Indeg[c - 'a'] == 0)
//          q.push(c - 'a');
//        }
//         string ans;
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             //now add that to the string
//             char c = 'a'+node;
//             ans+=c;
            
//             //now all the adjaceent compare and decrement if becomes zero then addd to the queue
//             for(int j= 0 ;j<adj[node].size() ; j++){
//                 Indeg[adj[node][j]]--;
//                 if(!Indeg[adj[node][j]]) //if it becomes zero then 
//                     q.push(adj[node][j]);
//             }
//         }
        
//         if (ans.size() < K) return "";
        
//         return ans;
//     }
// };