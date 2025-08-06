# Binary Search Tree Operations - Day 90 Solutions

## Overview

This document contains three advanced Binary Search Tree (BST) problem solutions:

1. **Sorted Linked List to BST**: Converts a sorted linked list into a balanced BST
2. **Merge Two BSTs**: Merges two BSTs and returns their elements in sorted order
3. **Fix Two Swapped Nodes in BST**: Identifies and fixes two incorrectly swapped nodes in a BST using Morris Traversal

All solutions are optimized for performance and demonstrate different BST manipulation techniques.

---

## Problem 1: Sorted Linked List to BST

### Code Explanation

```cpp
TNode* BuildBST(vector<int>&Tree , int start , int end){
    // Base case: invalid range
    if(start > end){
        return NULL;
    }
    
    // Choose middle element as root for balanced BST
    int mid = start + (end - start + 1) / 2;
    TNode *root = new TNode(Tree[mid]);
    
    // Recursively build left and right subtrees
    root->left = BuildBST(Tree, start, mid-1);
    root->right = BuildBST(Tree, mid+1, end);
    
    return root;
}

TNode *sortedListToBST(LNode *head) {
    // Convert linked list to vector for random access
    vector<int> Tree;
    while(head){
        Tree.push_back(head->data);
        head = head->next;
    }
    
    // Build BST using divide and conquer
    return BuildBST(Tree, 0, Tree.size()-1);
}
```

**Line-by-Line Breakdown:**

1. **Lines 1-4**: Base case check - if start > end, return NULL (empty subtree)
2. **Line 7**: Calculate middle index using `start + (end-start+1)/2` to avoid overflow
3. **Line 8**: Create root node with middle element
4. **Lines 11-12**: Recursively build left subtree (elements before mid) and right subtree (elements after mid)
5. **Lines 17-21**: Convert linked list to vector for O(1) random access
6. **Line 24**: Call recursive BST builder with full range

### Example Input/Output

**Input Linked List**: `1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7`

**Expected BST Structure**:
```
       4
     /   \
    2     6
   / \   / \
  1   3 5   7
```

### Step-by-Step Dry Run

**Input**: `[1, 2, 3, 4, 5, 6, 7]`, start=0, end=6

1. **Call 1**: `BuildBST([1,2,3,4,5,6,7], 0, 6)`
   - mid = 0 + (6-0+1)/2 = 3
   - Create node with value 4
   - Recursively call left: `BuildBST(arr, 0, 2)` 
   - Recursively call right: `BuildBST(arr, 4, 6)`

2. **Call 2** (Left subtree): `BuildBST([1,2,3,4,5,6,7], 0, 2)`
   - mid = 0 + (2-0+1)/2 = 1
   - Create node with value 2
   - Left: `BuildBST(arr, 0, 0)` → Creates node 1
   - Right: `BuildBST(arr, 2, 2)` → Creates node 3

3. **Call 3** (Right subtree): `BuildBST([1,2,3,4,5,6,7], 4, 6)`
   - mid = 4 + (6-4+1)/2 = 6
   - Create node with value 6
   - Left: `BuildBST(arr, 4, 5)` → Creates subtree with root 5
   - Right: `BuildBST(arr, 7, 6)` → Returns NULL (invalid range)

**Time Complexity**: O(n)  
**Space Complexity**: O(n) for vector storage + O(log n) recursion depth

---

## Problem 2: Merge Two BSTs

### Code Explanation

```cpp
void inorder(Node *root, vector<int>&ans){
    // Base case: empty node
    if(!root) return;
    
    // Inorder traversal: Left -> Root -> Right
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> merge(Node *root1, Node *root2) {
    // Get sorted arrays from both BSTs
    vector<int> ans1, ans2;
    inorder(root1, ans1);
    inorder(root2, ans2);
    
    // Merge two sorted arrays
    vector<int> ans;
    int i = 0, j = 0;
    
    while(i < ans1.size() && j < ans2.size()){
        if(ans1[i] < ans2[j]){
            ans.push_back(ans1[i++]);
        } else {
            ans.push_back(ans2[j++]);
        }
    }
    
    // Add remaining elements
    while(i < ans1.size()) ans.push_back(ans1[i++]);
    while(j < ans2.size()) ans.push_back(ans2[j++]);
    
    return ans;
}
```

**Section-wise Breakdown:**

1. **Inorder Function (Lines 1-8)**: Performs inorder traversal to get sorted sequence from BST
2. **Initial Setup (Lines 11-14)**: Get inorder traversals of both BSTs
3. **Two-Pointer Merge (Lines 17-26)**: Standard merge algorithm for two sorted arrays
4. **Handle Remaining (Lines 28-29)**: Add any leftover elements from either array

### Example Input/Output

**BST 1**:
```
    3
   / \
  1   5
```

**BST 2**:
```
    4
   / \
  2   6
```

**Expected Output**: `[1, 2, 3, 4, 5, 6]`

### Visual Diagram

```
BST 1 Inorder: [1, 3, 5]
BST 2 Inorder: [2, 4, 6]

Merge Process:
Step 1: Compare 1 vs 2 → Add 1    | Result: [1]
Step 2: Compare 3 vs 2 → Add 2    | Result: [1, 2]
Step 3: Compare 3 vs 4 → Add 3    | Result: [1, 2, 3]
Step 4: Compare 5 vs 4 → Add 4    | Result: [1, 2, 3, 4]
Step 5: Compare 5 vs 6 → Add 5    | Result: [1, 2, 3, 4, 5]
Step 6: Add remaining 6           | Result: [1, 2, 3, 4, 5, 6]
```

**Time Complexity**: O(m + n) where m, n are sizes of BSTs  
**Space Complexity**: O(m + n) for storing inorder traversals

---

## Problem 3: Fix Two Swapped Nodes in BST

### Code Explanation

This solution uses **Morris Traversal** for O(1) space complexity inorder traversal.

```cpp
void correctBST(Node* root) {
    Node *curr = NULL;
    Node *first = NULL, *second = NULL;
    Node *last = NULL, *present = NULL;
    
    // Morris Traversal for inorder without recursion
    while(root){
        // Case 1: No left child
        if(!root->left){
            last = present;
            present = root;
            
            // Check for BST violation
            if(last && last->data > present->data){
                if(!first){ 
                    first = last; // First violation
                }
                second = present; // Update second node
            }
            root = root->right;
        }
        // Case 2: Left child exists
        else{ 
            curr = root->left; 
            // Find rightmost node in left subtree
            while(curr->right && curr->right != root){ 
                curr = curr->right;
            }
            
            // Create thread (first visit)
            if(curr->right == NULL){ 
                curr->right = root;
                root = root->left;
            }
            // Remove thread (second visit)
            else{ 
                curr->right = NULL;
                last = present;
                present = root;
                
                // Check for violation
                if(last && last->data > present->data){
                    if(!first){ 
                        first = last; 
                    }
                    second = present;
                }
                root = root->right;
            }
        }
    }

    // Swap the data of two nodes
    int temp = first->data;
    first->data = second->data;
    second->data = temp; 
}
```

**Section-wise Breakdown:**

1. **Variable Initialization (Lines 2-4)**: Set up pointers for Morris traversal and violation detection
2. **Morris Traversal Loop (Lines 6-46)**: Main algorithm using threading technique
3. **No Left Child Case (Lines 8-18)**: Process node and move to right child
4. **Left Child Exists Case (Lines 20-44)**: Create/remove threads for inorder traversal
5. **Fix Violations (Lines 48-51)**: Swap the incorrectly placed nodes

### Morris Traversal Concept

Morris Traversal uses **threading** to achieve inorder traversal without recursion or stack:

```
Original Tree:      After Threading:
    4                   4
   / \                 / \
  2   5               2   5
 / \       →         / \
1   3               1   3
                     \  /
                      thread
```

### Example Input/Output

**Input BST** (with swapped nodes 3 and 7):
```
    5
   / \
  7   8    ← 3 and 7 are swapped
 / \
1   4
```

**Current inorder**: `[1, 7, 4, 5, 3, 8]`  
**Expected inorder**: `[1, 3, 4, 5, 7, 8]`

**Detection Process**:
- **First violation**: `7 > 4` at positions 1,2 → `first = 7`
- **Second violation**: `5 > 3` at positions 3,4 → `second = 3`  
- **Fix**: Swap values of `first` and `second` nodes

### Step-by-Step Dry Run

**Morris Traversal Steps**:

| Step | Current | Action | last | present | Violation? | first | second |
|------|---------|---------|------|---------|------------|-------|--------|
| 1 | 5 | Thread to 4 | - | - | No | null | null |
| 2 | 7 | Thread to 4 | - | - | No | null | null |
| 3 | 1 | Visit | null | 1 | No | null | null |
| 4 | 7 | Visit | 1 | 7 | No | null | null |
| 5 | 4 | Visit | 7 | 4 | Yes (7>4) | 7 | 4 |
| 6 | 5 | Visit | 4 | 5 | No | 7 | 4 |
| 7 | 3 | Visit | 5 | 3 | Yes (5>3) | 7 | 3 |
| 8 | 8 | Visit | 3 | 8 | No | 7 | 3 |

**Final Step**: Swap `first->data` (7) with `second->data` (3)

**Time Complexity**: O(n)  
**Space Complexity**: O(1) - No recursion stack or extra data structures

### Morris Traversal Flow Chart

```
START
  ↓
Current = Root
  ↓
While Current ≠ NULL
  ↓
Has Left Child? ──No──→ Process Current, Move Right
  ↓ Yes
Find Rightmost in Left Subtree
  ↓
Already Threaded? ──No──→ Create Thread, Go Left
  ↓ Yes
Remove Thread, Process Current, Move Right
  ↓
Check for BST Violations
  ↓
Continue Loop
  ↓
Swap first & second nodes
  ↓
END
```

---

## Summary

| Problem | Approach | Time | Space | Key Technique |
|---------|----------|------|-------|---------------|
| Sorted List to BST | Divide & Conquer | O(n) | O(n) | Middle element as root |
| Merge Two BSTs | Inorder + Merge | O(m+n) | O(m+n) | Two-pointer merge |
| Fix Swapped Nodes | Morris Traversal | O(n) | O(1) | Threading for inorder |

### Key Takeaways

1. **Balanced BST Construction**: Always choose middle element as root for optimal height
2. **BST Property**: Inorder traversal of BST gives sorted sequence
3. **Space Optimization**: Morris Traversal achieves O(1) space for tree traversal
4. **Violation Detection**: In BST, any inorder sequence violation indicates swapped nodes

These solutions demonstrate advanced BST operations with different space-time trade-offs. The Morris Traversal technique is particularly elegant for achieving O(1) space complexity in tree traversals while maintaining the same time complexity as recursive approaches.