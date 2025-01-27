#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // vector<int> arr;
    // arr.push_back(10);
    // arr.push_back(33);
    // arr.push_back(1);
    // arr.push_back(8);
    // arr.push_back(3);
    // // asending order
    // sort(arr.begin(), arr.end());

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;

    // // decending order.
    // sort(arr.begin(), arr.end(), greater<int>());

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;
    // // another way to decreasing order
    // sort(arr.rbegin(), arr.rend());
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;


    // seaching the element by using binary search
    vector<int>arr = { 1,2,3,4,5,22,33};
    cout<<arr.size()<<endl;
    cout<<arr.capacity()<<endl;
    
    // cout<<binary_search(arr.begin() , arr.end() , 10); 


   //finding the element index
//    cout<<find(arr.begin() , arr.end() , 2)-arr.begin();

   //another searching method..
   bool found = binary_search(arr.begin() , arr.end() , 5);
   cout<<found<<endl;

   //another by using auto  index..
   auto it = find(arr.begin() , arr.end() , 33); // first occurece
   cout<<*it<<endl;


   //count 
   int cnt = count(arr.begin() , arr.end() , 33);
   cout<<cnt<<endl;

    
}