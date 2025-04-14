Great! Here's your **Day 36: Subset Sum and Target Sum** detailed notes, with:

- 💡 Concept Explanation  
- 📄 Code Breakdown (line-by-line)  
- 🧪 Example + Output  
- 🌲 Recursion Tree (explained)

---

## ✅ Subset Sum Problem

**🧠 Goal**: Find the sum of all subsets in an array.

### 📄 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void SubsetSum(int arr[], int index, int n, int sum, vector<int>& ans) {
    // base case: if we reach the end, store the current subset sum
    if(index == n) {
        ans.push_back(sum);
        return;
    }

    // Not including arr[index] in sum
    SubsetSum(arr, index + 1, n, sum, ans);

    // Including arr[index] in sum
    SubsetSum(arr, index + 1, n, sum + arr[index], ans);
}

int main() {
    int arr[] = {3, 4, 5};
    vector<int> ans;
    SubsetSum(arr, 0, 3, 0, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
```

### 🧠 What Happens?

We make two decisions at each index:
1. **Include** the element in the sum.
2. **Exclude** the element.

⛓️ Recursive calls try both paths at every step.

---

### 🧪 Example:

**Input**: `{3, 4, 5}`  
**Output**: `0 5 4 9 3 8 7 12`

### 🌲 Recursion Tree

```
           sum = 0, i = 0
         /               \
     not include         include (3)
    i=1,sum=0          i=1,sum=3
    /       \            /       \
 i=2,s=0  i=2,s=4    i=2,s=3   i=2,s=7
  / \       / \        / \       / \
s=0 5     4 9        3 8       7 12
```

---

## ✅ Target Sum Problem

**🧠 Goal**: Return `true` if there exists any subset with sum equal to `target`.

### 📄 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool TargetSum(int arr[], int index, int n, int target) {
    // base case: target matched
    if(target == 0)
        return true;

    // base case: invalid path
    if(index == n || target < 0)
        return false;

    // Try both: without current + with current
    return TargetSum(arr, index + 1, n, target) ||
           TargetSum(arr, index + 1, n, target - arr[index]);
}

int main() {
    int arr[] = {2, 3, 6};
    int target = 10;
    cout << TargetSum(arr, 0, 3, target);
}
```

---

### 🧠 Logic Flow:

- Each call tries including and excluding `arr[index]`.
- If target becomes 0 → return `true`.
- If we exhaust elements or go negative → return `false`.

---

### 🧪 Example:

**Input**: `{2, 3, 6}`, Target = `10`  
**Output**: `1` (`true`)

### 🌲 Recursion Tree (partial)

```
           Target=10, i=0
          /             \
  not include        include (2)
T=10,i=1           T=8,i=1
 /     \             /     \
10      7           8       5
...                  ✅ ← This branch gets Target = 0
```

🧠 For input `{2,3,6}` and target `10`, the subset `{2, 3, 5}` gives sum `10`, so output is `true`.

---

### ✅ Final Notes

| Function      | Time Complexity         | Space Complexity |
|---------------|--------------------------|------------------|
| SubsetSum     | O(2^n)                    | O(2^n) (for output) |
| TargetSum     | O(2^n)                    | O(n) (recursion stack) |

---
