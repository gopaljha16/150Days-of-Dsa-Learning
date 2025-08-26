// Minium Window Substring leetcode hard level question

// unordeered_map approch 

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int total = t.size() ; 

//         //unorderlist
//         unordered_map<char , int>m; //it contains the char and count of that charater..which is present in the t string
//         //update the map with the t string
//         for(int i=0 ; i<t.size() ; i++)
//           m[t[i]]++; //updated in the map...

//         int start = 0 , end = 0 , ans = INT_MAX , index = -1; //ans contains the window minimun which is minium , index contains the start element of the ans window

//         while(end<s.size()){
//             //decrease the charater count
//             m[s[end]]--;

//             if(m[s[end]]>=0){ // only positive number should be updating the total
//                  total--; // decrement the totoal size when we got that element in he windo
//             }

//             //if the total is zero and we have to get the minium windows for that decrease the window
//             while(!total && start<=end){ // if the total is 0 and start goes to the start is less than end then decrease the window and update the total
//                if(ans > end-start+1){ // if we get the ans which is updated and get ans is greater than the window update the new window and update the index
//                  ans = end-start+1;
//                  index = start; // ans start is the index updated
//                }

//                m[s[start]]++; // increase ehc ount of the start
//                if(m[s[start]]>0){ // if start is greater(positive) than zero then update the total
//                       total++; // increment of the total
//                }
//                start++;
//             }
//             //increase the window 
//             end++;
//         }

//         if(index==-1) // if the ans is empty then returning the empty string
//          return "";

//         //if there is the answer is stored then return in the stirng
//         string str = "";
//         for(int i=index; i<index+ans ; i++){
//             str+=s[i];
//         }

//         return str;
//     }
// };

// vector approch

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int total = t.size() ; 

//         //unorderlist
//         vector<int>m(256, 0); //it contains the char and count of that charater..which is present in the t string
//         //update the map with the t string
//         for(int i=0 ; i<t.size() ; i++)
//           m[t[i]]++; //updated in the map...

//         int start = 0 , end = 0 , ans = INT_MAX , index = -1; //ans contains the window minimun which is minium , index contains the start element of the ans window

//         while(end<s.size()){
//             //decrease the charater count
//             m[s[end]]--;

//             if(m[s[end]]>=0){ // only positive number should be updating the total
//                  total--; // decrement the totoal size when we got that element in he windo
//             }

//             //if the total is zero and we have to get the minium windows for that decrease the window
//             while(!total && start<=end){ // if the total is 0 and start goes to the start is less than end then decrease the window and update the total
//                if(ans > end-start+1){ // if we get the ans which is updated and get ans is greater than the window update the new window and update the index
//                  ans = end-start+1;
//                  index = start; // ans start is the index updated
//                }

//                m[s[start]]++; // increase ehc ount of the start
//                if(m[s[start]]>0){ // if start is greater(positive) than zero then update the total
//                       total++; // increment of the total
//                }
//                start++;
//             }
//             //increase the window 
//             end++;
//         }

//         if(index==-1) // if the ans is empty then returning the empty string
//          return "";

//         //if there is the answer is stored then return in the stirng
//         string str = "";
//         for(int i=index; i<index+ans ; i++){
//             str+=s[i];
//         }

//         return str;
//     }
// };