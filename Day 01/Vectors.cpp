#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // create or declare
    // vector<int>v;
    // v.push_back(10);
    // v.push_back(1);
    // v.push_back(4);
    // // size and capacity
    // cout<<"vector size :- "<<v.size()<<endl;
    // cout<<"vector capacity :- "<<v.capacity();
    // //update
    // v[1]=5;

    // initization of vectors
    // vector<int> v1(5, 1); // when we initialize the element by giving and 5 and all 1 then we will get the size and capacity same 5 and 5
    //                       //  size and capacity
    // cout << "vector size :- " << v1.size() << endl;
    // cout << "vector capacity :- " << v1.capacity()<<endl;
    // // then we insert the element
    // v1.push_back(20);
    // // size and capacity
    // cout << "vector size :- " << v1.size() << endl;
    // cout << "vector capacity :- " << v1.capacity()<<endl; // the size will become 6 and capacity will become 10 double of 5..

    // another type of initilization
    // vector<int>v3 = {1,2,3,4,5};
    // cout<<v3.size()<<endl; //initialized..

    // delete value from vector..
    // vector<int> v4;
    // v4.push_back(10);
    // v4.push_back(11);
    // v4.push_back(12);
    // v4.push_back(13);
    // v4.push_back(14);
    // // delete the value from back
    // v4.pop_back();
    // // size and capacity
    // cout << "vector size :- " << v4.size() << endl;
    // cout << "vector capacity :- " << v4.capacity() << endl;
    // // print the exact array..
    // for (int i = 0; i < v4.size(); i++)
    // {
    //     cout << v4[i] << " ";
    // }
    // cout << endl;
    // // delete an particular element
    // v4.erase(v4.begin() + 2);
    // // printing the vector array;
    // for (int i = 0; i < v4.size(); i++)
    // {
    //     cout << v4[i] << " ";
    // }
    // cout << endl;

    // // inserting the value in particular index
    // v4.insert(v4.begin() + 2, 20); // 20 is element im inserting..
    // for (int i = 0; i < v4.size(); i++)
    // {
    //     cout << v4[i] << " ";
    // }
    // cout << endl;

    // // update in index
    // v4[1] = 15;
    // for (int i = 0; i < v4.size(); i++)
    // {
    //     cout << v4[i] << " ";
    // }

    // cout << endl;

    // // clearing the element from the vector array
    // v4.clear();
    //  cout << "vector size :- " << v4.size() << endl;
    // cout << "vector capacity :- " << v4.capacity() << endl;

    // first and last element print
    vector<int> v5;
    v5.push_back(10);
    v5.push_back(20);
    v5.push_back(30);
    v5.push_back(40);
    v5.push_back(50);
    // first way to print first element
    cout << v5[0] << endl;
    // another way by front();
    cout << v5.front() << endl;
    // last value print
    cout << v5[v5.size() - 1] << endl;
    // another way
    cout << v5.back() << endl;

    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5[i] << " ";
    }
    cout << endl;
    // copying the one vector to another vector
    vector<int> arr;

    arr = v5;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
  cout<<endl;

    //another way to print the vector
    for(auto i=arr.begin();i!=arr.end();i++){
        cout<<*i<<" ";
    }

    cout<<endl;

    //another way to print
    for(auto i: arr)
    cout<<i<<" ";
}