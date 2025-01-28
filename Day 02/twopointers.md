# Notes on Two Pointer Approach

The two-pointer technique is an efficient way to solve problems on arrays and vectors, especially when dealing with sorted arrays or situations requiring linear traversal.

### Key Idea:

Use two pointers (start and end) to traverse the array simultaneously and solve problems efficiently, often in O(n) time.

---

### Example 1: Segregate 0s and 1s

**Problem:** Rearrange a binary array so that all 0s appear before all 1s.

#### Code:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 1, 0, 1, 0};
    int n = arr.size();

    // Two-pointer approach
    int start = 0, end = n - 1;
    while (start < end) {
        if (arr[start] == 0) {
            start++;
        } else {
            if (arr[end] == 0) {
                swap(arr[start], arr[end]);
                start++;
                end--;
            } else {
                end--;
            }
        }
    }

    // Print the segregated array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
```

#### Explanation:

1. Use two pointers: `start` begins at index 0, and `end` begins at the last index.
2. Move `start` forward if the element is 0.
3. Swap `arr[start]` and `arr[end]` if `arr[start]` is 1 and `arr[end]` is 0.
4. Decrement `end` if no swap is needed.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### Example 2: Two Sum

**Problem:** Find two numbers in a sorted array that sum up to a target.

#### Code:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum == target) {
            cout << "Pair found: (" << arr[start] << ", " << arr[end] << ")" << endl;
            return 0;
        } else if (sum < target) {
            start++;
        } else {
            end--;
        }
    }

    cout << "No pair found." << endl;
    return 0;
}
```

#### Explanation:

1. Start two pointers at the beginning and end of the array.
2. Calculate the sum of elements at `start` and `end`.
3. Adjust pointers:
   - Increment `start` if the sum is less than the target.
   - Decrement `end` if the sum is greater than the target.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### Example 3: Pair with Given Difference

**Problem:** Check if there exists a pair in the array with a given difference `k`.

#### Code:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {5, 20, 3, 2, 50, 80};
    int k = 78;

    sort(arr.begin(), arr.end()); // Sort the array
    int start = 0, end = 1;

    while (end < arr.size()) {
        int diff = arr[end] - arr[start];

        if (diff == k) {
            cout << "Pair found: (" << arr[start] << ", " << arr[end] << ")" << endl;
            return 0;
        } else if (diff < k) {
            end++;
        } else {
            start++;
        }
    }

    cout << "No pair found." << endl;
    return 0;
}
```

#### Explanation:

1. Sort the array.
2. Use two pointers: `start` and `end`.
3. Check the difference between `arr[end]` and `arr[start]`.
4. Adjust pointers based on the difference.

**Time Complexity:** O(n log n) (due to sorting)  
**Space Complexity:** O(1)

---

### Example 4: Product Pair

**Problem:** Find if there exists a pair of elements in the array whose product equals a given value.

#### Code:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 9, 40};
    int target = 400;

    int start = 0, end = arr.size() - 1;
    sort(arr.begin(), arr.end()); // Sort the array

    while (start < end) {
        int product = arr[start] * arr[end];

        if (product == target) {
            cout << "Pair found: (" << arr[start] << ", " << arr[end] << ")" << endl;
            return 0;
        } else if (product < target) {
            start++;
        } else {
            end--;
        }
    }

    cout << "No pair found." << endl;
    return 0;


    //for geeks of geeks problem solving
    //like this we have to solve 
    bool isProduct(vector<int> arr, long long x) {
        // code here
    int n=arr.size();
        int start=0,end=n-1;
        sort(arr.begin() ,arr.end());
        while(start<end){
          // long long holdes more amount of numbers
            long long product = (long long)arr[start] * arr[end];
            if(product==x)
            return true;
            else if(product<x)
            start++;
            else
            end--;
        }

        return false;
    }
}
```

#### Explanation:

1. Sort the array.
2. Use two pointers to check the product of elements at `start` and `end`.
3. Adjust pointers based on the product.

**Time Complexity:** O(n log n) (due to sorting)  
**Space Complexity:** O(1)
