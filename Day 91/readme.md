# Largest BST & Maximum Sum BST Solutions

## Overview

This document contains solutions to two related binary tree problems:

1. **Largest BST Problem**: Find the size of the largest subtree that is also a Binary Search Tree (BST)
2. **Maximum Sum BST Problem**: Find the maximum sum of values in any subtree that is also a BST

Both solutions use a **bottom-up approach** with a helper class `Box` to store information about subtrees as we traverse upward from leaves to root.

---

## Problem 1: Largest BST Subtree

### Key Concepts

A **Binary Search Tree (BST)** satisfies:
- All nodes in left subtree < current node
- All nodes in right subtree > current node
- Both left and right subtrees are also BSTs

### Solution Structure

#### Box Class
```cpp
class Box {
    public:
    bool BST;      // Is this subtree a valid BST?
    int size;      // Size of the subtree
    int min, max;  // Min and max values in the subtree
    
    Box() {
        BST = 1;           // Initially assume it's a BST
        size = 0;          // Empty subtree has size 0
        min = INT_MAX;     // Will be updated with actual min
        max = INT_MIN;     // Will be updated with actual max
    }
};
```

#### Main Algorithm
```cpp
Box* find(Node *root, int &totalSize) {
    // Base case: empty subtree
    if (!root) {
        return new Box();  // Returns valid empty BST
    }
    
    // Recursively process left and right subtrees
    Box *leftHead = find(root->left, totalSize);
    Box *rightHead = find(root->right, totalSize);
    
    // Check if current subtree can be a BST
    if (leftHead->BST && rightHead->BST && 
        leftHead->max < root->data && rightHead->min > root->data) {
        
        // Create new Box for current valid BST
        Box *head = new Box();
        head->size = 1 + leftHead->size + rightHead->size;
        head->min = min(root->data, leftHead->min);
        head->max = max(root->data, rightHead->max);
        
        // Update global maximum
        totalSize = max(totalSize, head->size);
        return head;
    } else {
        // Not a BST, mark as invalid and return
        leftHead->BST = 0;
        return leftHead;
    }
}
```

### Step-by-Step Walkthrough

Let's trace through this example tree:
```
        10
       /  \
      5    15
     / \     \
    1   8     7
```

**Step 1: Process leaf nodes**
- Node 1: `Box{BST=1, size=1, min=1, max=1}`, totalSize = 1
- Node 8: `Box{BST=1, size=1, min=8, max=8}`, totalSize = 1  
- Node 7: `Box{BST=1, size=1, min=7, max=7}`, totalSize = 1

**Step 2: Process node 5**
- Left: `Box{BST=1, size=1, min=1, max=1}`
- Right: `Box{BST=1, size=1, min=8, max=8}`
- Check: `1 < 5 < 8` ✓ (Valid BST)
- Result: `Box{BST=1, size=3, min=1, max=8}`, totalSize = 3

**Step 3: Process node 15**
- Left: empty → `Box{BST=1, size=0, min=INT_MAX, max=INT_MIN}`
- Right: `Box{BST=1, size=1, min=7, max=7}`
- Check: `INT_MAX > 15` ✗ and `7 < 15` ✗ (Invalid BST - right child is smaller)
- Result: `Box{BST=0, size=1, min=7, max=7}`

**Step 4: Process node 10**
- Left: `Box{BST=1, size=3, min=1, max=8}`
- Right: `Box{BST=0, ...}` (already invalid)
- Since right subtree is not BST, entire tree cannot be BST
- Result: `Box{BST=0, ...}`

**Final Answer**: 3 (largest BST is subtree rooted at node 5)

### Visual Representation

```
Original Tree:           Largest BST Subtree:
        10                       5
       /  \                     / \
      5    15                  1   8
     / \     \                
    1   8     7               Size = 3
```

---

## Problem 2: Maximum Sum BST

### Key Differences from Problem 1

1. **Box class tracks `sum` instead of `size`**
2. **Goal is to maximize sum rather than count nodes**
3. **Algorithm structure remains the same**

### Box Class for Sum Problem
```cpp
class Box {
    public:
    bool BST;      // Is this subtree a valid BST?
    int sum;       // Sum of all values in the subtree
    int min, max;  // Min and max values in the subtree
    
    Box() {
        BST = 1;
        sum = 0;           // Empty subtree has sum 0
        min = INT_MAX;
        max = INT_MIN;
    }
};
```

### Modified Algorithm
```cpp
Box* find(TreeNode *root, int &totalSum) {
    if (!root) {
        return new Box();
    }
    
    Box *leftHead = find(root->left, totalSum);
    Box *rightHead = find(root->right, totalSum);
    
    if (leftHead->BST && rightHead->BST && 
        leftHead->max < root->val && rightHead->min > root->val) {
        
        Box *head = new Box();
        head->sum = root->val + leftHead->sum + rightHead->sum;  // Sum instead of size
        head->min = min(root->val, leftHead->min);
        head->max = max(root->val, rightHead->max);
        
        totalSum = max(totalSum, head->sum);  // Track maximum sum
        return head;
    } else {
        leftHead->BST = 0;
        return leftHead;
    }
}
```

### Example for Sum Problem

Tree:
```
        1
       / \
      4   3
     / \   \
    2   4   2
           /
          5
           \
            6
```

**Walkthrough:**
- Leaf nodes: 2, 4, 5, 6 each contribute their own values
- Node with 5-6: Forms BST with sum = 5 + 6 = 11
- Node 4 (right): Forms BST with sum = 4 + 11 = 15  
- And so on...

**Maximum Sum BST**: The subtree that gives the highest sum while maintaining BST property.

---

## Complexity Analysis

### Time Complexity
- **O(n)** where n is the number of nodes
- Each node is visited exactly once during the recursive traversal

### Space Complexity
- **O(h)** where h is the height of the tree
- Space used by recursion stack
- Additional space for Box objects (also O(h) in worst case)

---

## Key Insights

1. **Bottom-up approach**: We gather information from children before making decisions about parent
2. **Early termination**: Once a subtree is marked as non-BST, we don't need to check further up
3. **Information passing**: The Box class efficiently carries all needed information upward
4. **Global tracking**: We maintain a global maximum (size/sum) that gets updated whenever we find a valid BST

---

## Edge Cases Handled

1. **Empty tree**: Returns 0
2. **Single node**: Always a valid BST with size/sum = node value
3. **All nodes form BST**: Returns size/sum of entire tree
4. **No valid BST**: Returns 0 for sum problem, or 1 for size problem (single nodes)

---

## Summary

Both solutions use the same fundamental approach:
- **Recursive traversal** with information gathering
- **Validation at each step** using BST properties  
- **Global maximum tracking** for the final answer
- **Efficient single-pass** algorithm with optimal time complexity

The key insight is that we can determine if a subtree is a BST by checking:
1. Both children are BSTs
2. Left subtree's maximum < current node < right subtree's minimum