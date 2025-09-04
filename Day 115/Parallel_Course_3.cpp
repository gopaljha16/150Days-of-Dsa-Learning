// Parallel Course 3 leetcode hard level question 

// class Solution {
// public:
//     int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
//         // create adjacency list
//         vector<vector<int>> adj(n);
//         for (int i = 0; i < relations.size(); i++) {
//             adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
//         }

//         // Kahn's algorithm 
//         vector<int> Indeg(n, 0);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < adj[i].size(); j++) {
//                 Indeg[adj[i][j]]++; 
//             }
//         }

//         // queue
//         queue<int> q;
//         vector<int> CourseTime(n, 0);

//         // update queue
//         for (int i = 0; i < n; i++) {
//             if (!Indeg[i])
//                 q.push(i);
//         }

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             // all neighbours
//             for (int j = 0; j < adj[node].size(); j++) {
//                 Indeg[adj[node][j]]--;

//                 // maximum course time update means prev + present time 
//                 CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]], CourseTime[node] + time[node]);

//                 // if indegree 0 then push to queue
//                 if (!Indeg[adj[node][j]])
//                     q.push(adj[node][j]);
//             }
//         }

//         // now iteration course time then get the answer
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             ans = max(ans, CourseTime[i] + time[i]);
//         }

//         return ans;
//     }
// };
