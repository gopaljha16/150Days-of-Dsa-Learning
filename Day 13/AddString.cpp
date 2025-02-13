// Add String (leetcode easy level question 415)


// string add(string num1 , string num2){
//     int index1= num1.size()-1, index2 = num2.size()-1;
//       int carry= 0, sum;
//       string ans;
//       // condition is index2>=0
//       while(index2>=0){
//           sum=(num1[index1]-'0')+(num2[index2]-'0') + carry;
//           carry = sum/10;
//           char c = '0' + sum%10;
//           ans+=c;
//           index2--, index1--;
//       }

//       // second condtion is index1>0
//       while(index1>=0){
//        sum= (num1[index1]-'0')+carry;
//        carry = sum/10;
//        char c = '0' + sum%10;
//        ans+=c;
//        index1--;
//       }
    
//       // if carry exist at the end idnex = -1 then
//       if(carry){
//           ans+='1';
//       }

//       // ans came in reverse type so reverse it for correct way printing
//       reverse(ans.begin() , ans.end());
//       return ans;
//    }

//   string addStrings(string num1, string num2) {
//    //handlining if the num1  is smallest than num2 by using add function calling it..
//       if(num1.size()<num2.size())
//       return add(num2, num1);
//       else
//       return add(num1, num2);
//   }