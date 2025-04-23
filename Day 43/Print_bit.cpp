
// gfg question medium level Print N-bit binary numbers having more 1s than 0s


// class Solution{
//     public:	
    
//       void printBit(int n , vector<string>&ans , string &temp , int zero , int one){
//           //base case
//           if(temp.size()==n){
//               ans.push_back(temp);
//               return;
//           }
          
//          temp.push_back('1');
//           printBit(n , ans , temp , zero , one+1);
//           temp.pop_back();
          
//           if(zero<one){
//               temp.push_back('0');
//               printBit(n , ans , temp , zero+1 , one);
//               temp.pop_back();
//           }
          
      
//       }
    
//         vector<string> NBitBinary(int n)
//         {
//             vector<string>ans;
//             string temp;
//             printBit(n , ans , temp , 0 , 0);
            
//             return ans;
//         }
//     };