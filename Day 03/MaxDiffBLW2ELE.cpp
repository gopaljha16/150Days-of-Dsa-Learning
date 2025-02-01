// Maximum Diffrence betweek 2 element;
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxDifference(vector<int> &arr) {
    int min_element = INT_MAX;
    int max_diff = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        min_element = min(min_element, arr[i]); // Keep track of the minimum element
        max_diff = max(max_diff, arr[i] - min_element); // Update max difference
    }

    return max_diff;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Maximum difference: " << maxDifference(v) << endl;
    return 0;
}
