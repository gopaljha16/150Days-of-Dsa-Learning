#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // unordered_map<int, int> m;
    //here it will storing unique key and it will not store the key in sorted way
    unordered_multimap<int,int>m; //it will have multiple key and it will not store the value in sorted way

    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 10));
    m.insert(make_pair(40, 110));
    m.insert(make_pair(50, 33));
    m.insert(make_pair(60, 40));
    m.insert(make_pair(20, 50));

    // printig value
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}