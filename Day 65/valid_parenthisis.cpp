#include <iostream>
#include <stack>
using namespace std;

// bool check(string s){
//     stack<char>st;

//     for(int i=0 ; i<s.size() ; i++){
//         if(s[i]=='('){//open bracket
//             st.push(s[i]);
//         }else{//close bracket
//             if(st.empty()){
//                 return 0;
//             }else{
//                 st.pop();
//             }
//         }
//     }

//     return st.empty();
// }

//without stack and space complexity O(n);

bool check(string s){
    int left = 0;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='('){
            left++;
        }else{
            if(left==0)
             return 0;
            else
             left--;
        }
    }

    return left==0;
}

int main(){
    string str = "((()))";
    cout<<check(str)<<endl;
    return 0;
}