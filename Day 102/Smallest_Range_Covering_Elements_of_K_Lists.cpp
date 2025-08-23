// Smallest Range Covering Elements of K Lists leetocode hard level question 
// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
       
//        //min heap
//        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>>p;

//        //now updating the minimum value and max val by queue insertion initally 
//        int minimum , maximun = INT_MIN;
//        for(int i=0 ; i<nums.size() ; i++){
//         p.push(make_pair(nums[i][0] , make_pair(i,0))); //pair inserting the row and column
//         maximun = max(maximun , nums[i][0]); //maximum updated
//        }

//        //minimum will be updated by the heap min heap becuase we have used that top we will get the minmium value
//        minimum = p.top().first; //first becuase pair..
//        vector<int> ans = {0, INT_MAX};// ans size 2 storing the min range 
//        int row , col , element;
//        pair<int , pair<int , int>>temp; //storing the pair...where will be comapring
//        while(p.size()==nums.size()){ // here the if the total number of size decreases then while loop will be breaking
//        temp = p.top(); //
//         p.pop();

//         //upating  the value  from value getting from temp pair..
//         element = temp.first;
//         row = temp.second.first;
//         col = temp.second.second;

//          minimum = element;  

//              //smallest range we have to update into the answer
//       if ((long long)maximun - minimum < (long long)ans[1] - ans[0] ||
//     ((long long)maximun - minimum == (long long)ans[1] - ans[0] && minimum < ans[0])) {
//     ans[0] = minimum;
//     ans[1] = maximun;
//   }


//         //next element after popping the min heap element inserting that row another element
//         if(col+1<nums[row].size()){ //checking the row eixists the elements
//            col++; //incrementing moving to the next element
//            p.push(make_pair(nums[row][col] , make_pair(row , col)));
//            //updating the element to maximum and minimum 
//            maximun = max(maximun , nums[row][col]);
//         }

//        }
 
//        return ans;

//     }
// };