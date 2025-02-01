#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Divide(vector<int> arr)
{
    int prefix = 0, total_sum = 0, n = arr.size();
    // total sum
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        // int ans = total_sum-prefix;
        if (total_sum == 2 * prefix)
            return 1;
    }
    return 0;
}

int main()
{
   
    int n;
    cout << "Enter the size of array :- ";
    cin >> n;
    cout << "Enter the elements in the array :- ";
     vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << Divide(v);
}