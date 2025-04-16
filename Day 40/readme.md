# Day 40: Recursion - Tower of Hanoi Problem

## 🔗 Problem Statement
Given `N` disks and 3 rods (source, auxiliary, destination), your task is to move all disks from the source rod to the destination rod following these rules:

1. Only one disk can be moved at a time.
2. You can only move the topmost disk of a rod.
3. No larger disk can be placed on top of a smaller disk.

## 📄 Function Signature
```cpp
void towerOfHanoi(int n, int source, int auxiliary, int destination);
```

---

## ⚙️ Full Code with Debugging
```cpp
#include <iostream>
using namespace std;

void towerOfHanoi(int n, int source, int auxiliary, int destination) {
    // Base Case
    if (n == 1) {
        cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move remaining 1 disk from source to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;

    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}
```

---

## ✅ Example Dry Run for `n = 3`
```
Move disk 1 from rod 1 to rod 3
Move disk 2 from rod 1 to rod 2
Move disk 1 from rod 3 to rod 2
Move disk 3 from rod 1 to rod 3
Move disk 1 from rod 2 to rod 1
Move disk 2 from rod 2 to rod 3
Move disk 1 from rod 1 to rod 3
```

### 🔧 Step-by-step Debug:
```
towerOfHanoi(3, 1, 2, 3)
    => towerOfHanoi(2, 1, 3, 2)
        => towerOfHanoi(1, 1, 2, 3)
            => Move disk 1 from rod 1 to rod 3
        => Move disk 2 from rod 1 to rod 2
        => towerOfHanoi(1, 3, 1, 2)
            => Move disk 1 from rod 3 to rod 2
    => Move disk 3 from rod 1 to rod 3
    => towerOfHanoi(2, 2, 1, 3)
        => towerOfHanoi(1, 2, 3, 1)
            => Move disk 1 from rod 2 to rod 1
        => Move disk 2 from rod 2 to rod 3
        => towerOfHanoi(1, 1, 2, 3)
            => Move disk 1 from rod 1 to rod 3
```

---

## ⏱️ Time and Space Complexity

### Time Complexity: `O(2^n)`
- Every call branches into two recursive calls, forming a binary tree of depth `n`.
- Total number of moves = `2^n - 1`

### Space Complexity: `O(n)`
- Due to recursion stack, we need space proportional to the depth of recursion which is `n`.

---

## 🎓 Notes:
- This problem is one of the classic examples of recursion.
- The number of moves required to solve Tower of Hanoi is always `2^n - 1`.
- For `n=3` disks, the total moves are `2^3 - 1 = 7`.

---
