# Binary Heap Problems - Complete Guide

## Overview

This document covers three fundamental binary heap problems commonly asked in coding interviews:

1. **Merge Two Binary Max Heaps** - Combines two max heaps into a single max heap
2. **Is Binary Tree Heap** - Validates if a binary tree satisfies max heap properties
3. **BST to Max Heap** - Converts a Binary Search Tree to a Max Heap while preserving structure

All solutions are implemented in C++ and demonstrate key heap operations and tree traversal techniques.

---

## Problem 1: Merge Two Binary Max Heaps

### Code Explanation

```cpp
class Solution {
public:
    // Heapify function to maintain max heap property
    void Heapify(vector<int>&ans, int index, int n) {
        int largest = index;          // Assume current node is largest
        int left = 2*index + 1;       // Left child index
        int right = 2*index + 2;      // Right child index
        
        // Compare with left child
        if(left < n && ans[left] > ans[largest]) {
            largest = left;
        }
        
        // Compare with right child
        if(right < n && ans[right] > ans[largest]) {
            largest = right;
        }
        
        // If largest is not the current node, swap and recursively heapify
        if(largest != index) {
            swap(ans[largest], ans[index]);
            Heapify(ans, largest, n);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        // Step 1: Merge both arrays
        for(int i = 0; i < n; i++) {
            ans.push_back(a[i]);
        }
        
        for(int i = 0; i < m; i++) {
            ans.push_back(b[i]);
        }
        
        // Step 2: Convert merged array to max heap
        n = ans.size();
        for(int i = n/2 - 1; i >= 0; i--) {
            Heapify(ans, i, n);
        }
        
        return ans;
    }
};
```

### Algorithm Steps

1. **Merge Arrays**: Combine elements from both heaps into a single vector
2. **Build Heap**: Apply heapify from last non-leaf node to root
3. **Return Result**: The merged vector now satisfies max heap property

### Example Input and Output

**Input:**
- Heap A: `[10, 5, 6, 2]`
- Heap B: `[12, 7, 9]`

**Output:**
- Merged Max Heap: `[12, 7, 10, 2, 5, 6, 9]`

### Dry Run Walkthrough

```
Initial Arrays:
A = [10, 5, 6, 2]
B = [12, 7, 9]

Step 1: Merge arrays
ans = [10, 5, 6, 2, 12, 7, 9]

Step 2: Heapify from index (7/2-1) = 2 down to 0

Index 2: Element 6
├── Left child (5): 12
├── Right child (6): 7
├── Largest = 5 (value 12)
├── Swap: [10, 5, 12, 2, 6, 7, 9]

Index 1: Element 5
├── Left child (3): 2
├── Right child (4): 6
├── Largest = 4 (value 6)
├── Swap: [10, 6, 12, 2, 5, 7, 9]

Index 0: Element 10
├── Left child (1): 6
├── Right child (2): 12
├── Largest = 2 (value 12)
├── Swap: [12, 6, 10, 2, 5, 7, 9]
└── Heapify index 2: no swaps needed

Final Result: [12, 6, 10, 2, 5, 7, 9]
```

### Visual Representation

```
Original Heaps:
    10           12
   /  \         /  \
  5    6       7    9
 /
2

Merged Array: [10, 5, 6, 2, 12, 7, 9]

Final Max Heap:
      12
    /    \
   6      10
  / \    /  \
 2   5  7    9
```

---

## Problem 2: Is Binary Tree Heap

### Code Explanation

```cpp
class Solution {
public:
    // Count total nodes in the tree
    int count(Node *root) {
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    
    // Check if tree is a Complete Binary Tree
    bool CBT(Node *root, int index, int nodes) {
        if(!root) return true;  // Null nodes are valid
        
        if(index >= nodes) return false;  // Index out of bounds
        
        // Recursively check left and right subtrees
        return CBT(root->left, 2*index + 1, nodes) && 
               CBT(root->right, 2*index + 2, nodes);
    }
    
    // Check if tree satisfies max heap property
    bool MaxHeap(Node *root) {
        // Check left child
        if(root->left) {
            if(root->data < root->left->data) return false;
            if(!MaxHeap(root->left)) return false;
        }
        
        // Check right child
        if(root->right) {
            if(root->data < root->right->data) return false;
            return MaxHeap(root->right);
        }
        
        return true;  // Leaf node
    }
    
    bool isHeap(Node* tree) {
        int num = count(tree);
        
        // Check if it's a Complete Binary Tree
        if(!CBT(tree, 0, num)) return false;
        
        // Check if it satisfies max heap property
        return MaxHeap(tree);
    }
};
```

### Algorithm Steps

1. **Count Nodes**: Calculate total number of nodes
2. **Check CBT**: Verify Complete Binary Tree property using index mapping
3. **Check Max Heap**: Ensure parent ≥ children for all nodes

### Example Input and Output

**Valid Heap:**
```
Input Tree:
      10
     /  \
    9    8
   / \
  7   6

Output: true
```

**Invalid Heap:**
```
Input Tree:
      10
     /  \
    12   8  // 12 > 10 violates max heap
   /
  7

Output: false
```

### CBT Index Mapping

```
Complete Binary Tree Index Mapping:
      0
    /   \
   1     2
  / \   / \
 3   4 5   6

For node at index i:
- Left child: 2*i + 1
- Right child: 2*i + 2
- Parent: (i-1)/2
```

---

## Problem 3: BST to Max Heap

### Code Explanation

```cpp
class Solution {
public:
    // Inorder traversal to get sorted elements
    void inOrder(Node *root, vector<int>&ans) {
        if(!root) return;
        
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
    
    // Postorder traversal to fill nodes with sorted elements
    void postOrder(Node *root, vector<int>&ans, int &index) {
        if(!root) return;
        
        postOrder(root->left, ans, index);
        postOrder(root->right, ans, index);
        root->data = ans[index++];
    }
    
    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;
        
        // Get sorted elements using inorder
        inOrder(root, ans);
        
        // Fill tree using postorder with sorted elements
        int index = 0;
        postOrder(root, ans, index);
    }
};
```

### Algorithm Steps

1. **Extract Elements**: Use inorder traversal to get sorted array
2. **Reconstruct Tree**: Use postorder traversal to assign values
3. **Result**: Tree structure preserved, values arranged as max heap

### Example Input and Output

**Input BST:**
```
      4
     / \
    2   6
   / \ / \
  1  3 5  7
```

**Output Max Heap:**
```
      7
     / \
    3   6
   / \ / \
  1  2 4  5
```

### Dry Run Walkthrough

```
Step 1: Inorder traversal of BST
BST:       4
          / \
         2   6
        / \ / \
       1 3 5  7

Inorder: [1, 2, 3, 4, 5, 6, 7]

Step 2: Postorder assignment
Postorder visits: 1 → 3 → 2 → 5 → 7 → 6 → 4
Assign values:    1   2   3   4   5   6   7

Final tree values:
      7 (root assigned last)
     / \
    3   6
   / \ / \
  1  2 4  5
```

### Visual Transformation

```
BST (Inorder: 1,2,3,4,5,6,7)    Max Heap (Postorder assignment)
      4                               7
     / \                             / \
    2   6              →             3   6
   / \ / \                          / \ / \
  1  3 5  7                        1  2 4  5
```

---

## Time and Space Complexity

| Problem | Time Complexity | Space Complexity | Notes |
|---------|----------------|------------------|-------|
| Merge Heaps | O((n+m) log(n+m)) | O(n+m) | Heapify takes O(log n) for each node |
| Is Binary Tree Heap | O(n) | O(h) | h is height of tree for recursion |
| BST to Max Heap | O(n) | O(n) | Two tree traversals |

---

## Key Concepts

### Heap Properties
- **Complete Binary Tree**: All levels filled except possibly the last
- **Max Heap Property**: Parent ≥ Children for all nodes
- **Array Representation**: For index i, left child = 2i+1, right child = 2i+2

### Traversal Types
- **Inorder**: Left → Root → Right (gives sorted sequence for BST)
- **Postorder**: Left → Right → Root (processes children before parent)

### Heapify Process
```
Bottom-up approach:
1. Start from last non-leaf node (n/2-1)
2. Compare with children
3. Swap if necessary
4. Recursively heapify affected subtree
```

---

## Summary

These three problems demonstrate essential heap operations:

1. **Merging Heaps**: Combines arrays and rebuilds heap structure using bottom-up heapify
2. **Heap Validation**: Checks both structural (CBT) and ordering (max heap) properties
3. **BST Conversion**: Leverages tree traversal properties to transform data while preserving structure

All solutions maintain optimal time complexity while handling edge cases appropriately. The key insight is understanding how heap properties relate to array indices and tree traversal orders.