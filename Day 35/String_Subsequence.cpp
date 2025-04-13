#include <iostream>
#include <vector>
using namespace std; 

void StringSub(string str, int index , int n , vector<string>&ans, string &temp){
      
    // base case
    if(index==n){
        ans.push_back(temp);
        return;
    }

    // not includes 
    StringSub(str , index+1 , n , ans , temp);
    // included 
    temp.push_back(str[index]);
    StringSub(str , index+1 , n , ans , temp);
    temp.pop_back();
}

int main(){
    string str = "gopal";
    vector<string>ans; // final ans;
    string temp;
    StringSub(str , 0 , 5, ans , temp);

    // print the subsequence which is stored in the ans 
    for(int i=0  ; i<ans.size() ; i++){
        cout<<ans[i]<<endl;
    }
}