// 2558. Take Gifts From the Richest Pile gfg easy elvel question

// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
     
//      priority_queue<int>p;

//      for(int i=0 ; i<gifts.size() ; i++){
//         p.push(gifts[i]);
//      }

    

//      while(k){
//        int gift = sqrt(p.top());
//        p.pop();
//        if(gift)
//        p.push(gift);
//        k--;
//      }

//      long long sum=0; 
//      while(!p.empty()){
//         sum+=p.top();
//         p.pop();
//      }


//   return sum;
//     }
// };