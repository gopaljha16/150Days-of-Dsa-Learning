# Binary Search Tree: 5 Essential Interview Problems

## Overview

This code collection demonstrates five fundamental Binary Search Tree (BST) problems commonly asked in technical interviews. Each solution leverages the key property of BSTs: an inorder traversal yields elements in sorted order. The problems covered are:

1. **Check if Binary Tree is BST** (2 methods)
2. **Minimum Distance Between BST Nodes**
3. **Sum of K Smallest Elements in BST**
4. **Kth Largest Element in BST**
5. **Convert Sorted Array to BST**

---

## Problem 1: Check if Binary Tree is BST

### Method 1: Using Inorder Traversal

```cpp
class Solution {
public:
    void inorder(Node *root, vector<int>&ans) {
        if(!root) return;
        
        // Left -> Data -> Right
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    bool isBST(Node* root) {
        vector<int> ans;
        inorder(root, ans);
        
        // Check if inorder traversal is strictly increasing
        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] <= ans[i-1])
                return false;
        }
        return true;
    }
};
```

**Explanation:**
- Performs inorder traversal to collect all node values
- Checks if the resulting array is strictly increasing
- Time Complexity: O(n), Space Complexity: O(n)

### Method 2: Using Previous Node Reference

```cpp
class Solution {
public:
    bool checkBst(Node *root, int &prev) {
        if(!root) return true;
        
        // Check left subtree
        if(!checkBst(root->left, prev))
            return false;
        
        // Check current node
        if(root->data <= prev)
            return false;
        
        // Update previous value
        prev = root->data;
        
        // Check right subtree
        return checkBst(root->right, prev);
    }
    
    bool isBST(Node* root) {
        int prev = INT_MIN;
        return checkBst(root, prev);
    }
};
```

**Explanation:**
- Uses inorder traversal with previous node tracking
- More space-efficient (O(h) where h is height)
- Validates BST property during traversal

---

## Problem 2: Minimum Distance Between BST Nodes

```cpp
class Solution {
public:
    void minDist(TreeNode *root, int &prev, int &ans) {
        if(!root) return;
        
        // Process left subtree
        minDist(root->left, prev, ans);
        
        // Process current node
        if(prev != INT_MIN)
            ans = min(ans, root->val - prev);
        
        // Update previous for right subtree
        prev = root->val;
        minDist(root->right, prev, ans);
    }
    
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        minDist(root, prev, ans);
        return ans;
    }
};
```

**Explanation:**
- Uses inorder traversal to visit nodes in sorted order
- Calculates difference between consecutive nodes
- Maintains minimum difference found so far

---

## Problem 3: Sum of K Smallest Elements

```cpp
void ksum(Node *root, int &sum, int &k) {
    if(!root) return;
    
    // Process left subtree (smaller elements)
    ksum(root->left, sum, k);
    
    // Process current node
    k--;
    if(k >= 0)
        sum += root->data;
    
    // Early termination if k elements processed
    if(k <= 0) return;
    
    // Process right subtree
    ksum(root->right, sum, k);
}

int sum(Node* root, int k) {
    int sum = 0;
    ksum(root, sum, k);
    return sum;
}
```

**Explanation:**
- Performs inorder traversal to get elements in ascending order
- Adds first k elements encountered
- Uses early termination for efficiency

---

## Problem 4: Kth Largest Element

```cpp
class Solution {
public:
    void kLargest(Node *root, int &ans, int &k) {
        if(!root) return;
        
        // Process right subtree first (larger elements)
        kLargest(root->right, ans, k);
        
        // Process current node
        k--;
        if(k == 0)
            ans = root->data;
        
        // Early termination
        if(k <= 0) return;
        
        // Process left subtree
        kLargest(root->left, ans, k);
    }
    
    int kthLargest(Node *root, int k) {
        int ans;
        kLargest(root, ans, k);
        return ans;
    }
};
```

**Explanation:**
- Uses reverse inorder traversal (Right -> Root -> Left)
- Visits nodes in descending order
- Returns the kth element encountered

---

## Problem 5: Convert Sorted Array to BST

```cpp
class Solution {
public:
    Node* ArrToBST(vector<int>&arr, int start, int end) {
        if(start > end) return NULL;
        
        // Choose middle element as root
        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);
        
        // Recursively build left and right subtrees
        root->left = ArrToBST(arr, start, mid - 1);
        root->right = ArrToBST(arr, mid + 1, end);
        
        return root;
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {
        return ArrToBST(nums, 0, nums.size() - 1);
    }
};
```

**Explanation:**
- Uses divide and conquer approach
- Middle element becomes root to ensure balance
- Recursively constructs left and right subtrees

---

## Step-by-Step Walkthrough: Check BST (Method 2)

Let's trace through checking if this tree is a BST:
```
    5
   / \
  3   8
 / \ / \
1  4 7  9
```

**Initial Call:** `checkBst(5, prev=-∞)`

1. **Process left subtree:** `checkBst(3, prev=-∞)`
   - **Process left:** `checkBst(1, prev=-∞)`
     - Left subtree: NULL ✓
     - Check: 1 > -∞ ✓, update prev = 1
     - Right subtree: NULL ✓
   - **Check current:** 3 > 1 ✓, update prev = 3
   - **Process right:** `checkBst(4, prev=3)`
     - Check: 4 > 3 ✓, update prev = 4

2. **Check root:** 5 > 4 ✓, update prev = 5

3. **Process right subtree:** `checkBst(8, prev=5)`
   - **Process left:** `checkBst(7, prev=5)`
     - Check: 7 > 5 ✓, update prev = 7
   - **Check current:** 8 > 7 ✓, update prev = 8
   - **Process right:** `checkBst(9, prev=8)`
     - Check: 9 > 8 ✓

**Result:** All checks pass, tree is a valid BST!

---

## Visual Representation: Array to BST

**Input Array:** `[1, 3, 4, 5, 7, 8, 9]`

```
Step 1: Choose middle (index 3) = 5
        5
       
Step 2: Left subarray [1,3,4], Right subarray [7,8,9]
        5
       / \
      3   8
      
Step 3: Continue recursively
        5
       / \
      3   8
     / \ / \
    1  4 7  9
```

## Example Inputs and Outputs

| Problem | Input | Output | Explanation |
|---------|-------|--------|-------------|
| Check BST | Tree: 2→1,3 | `true` | Inorder: [1,2,3] is sorted |
| Min Distance | Tree: 4→2,6→1,3 | `1` | Min diff between 2-3 or 1-2 |
| Sum K Smallest | Tree: 5→3,6→2,4, k=3 | `9` | Sum of [2,3,4] |
| Kth Largest | Tree: 3→1,4→null,2, k=1 | `4` | Largest element |
| Array to BST | [1,3] | Tree: 3→1 | Balanced BST |

---

## Summary

These five problems demonstrate essential BST operations and properties:

- **BST Validation** leverages the sorted inorder property
- **Tree Traversals** (inorder, reverse inorder) solve multiple problems efficiently  
- **Divide and Conquer** creates balanced BSTs from sorted arrays
- **Early Termination** optimizes k-based searches
- **Space-Time Tradeoffs** between different algorithmic approaches

**Key Takeaway:** The inorder traversal property of BSTs (yielding sorted sequences) is the foundation for solving most BST-related interview problems efficiently.