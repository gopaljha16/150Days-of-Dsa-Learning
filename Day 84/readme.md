# Morris Traversal - Complete Guide

## Table of Contents
- [Introduction](#introduction)
- [Key Concepts](#key-concepts)
- [Morris Inorder Traversal](#morris-inorder-traversal)
- [Morris Preorder Traversal](#morris-preorder-traversal)
- [Morris Postorder Traversal](#morris-postorder-traversal)
- [Flatten Binary Tree to Linked List](#flatten-binary-tree-to-linked-list)
- [Complexity Analysis](#complexity-analysis)
- [Practice Problems](#practice-problems)

## Introduction

**Morris Traversal** is a tree traversal technique that allows us to traverse a binary tree without using recursion or an explicit stack. This algorithm achieves **O(1) space complexity** while maintaining **O(n) time complexity**.

### Why Morris Traversal?
- **Space Efficient**: No extra space for recursion stack or explicit stack
- **In-place**: Temporarily modifies the tree structure during traversal
- **Optimal**: Achieves the best possible space complexity for tree traversal

## Key Concepts

### The Core Idea
Morris Traversal uses **threaded binary trees** concept:
1. **Temporary Links**: Create temporary links from inorder predecessor to current node
2. **Link Detection**: Use these links to detect when we've finished processing a subtree
3. **Link Removal**: Remove temporary links to restore original tree structure

### Inorder Predecessor
For any node in a binary tree:
- **Inorder Predecessor**: The rightmost node in the left subtree
- This node will be visited just before the current node in inorder traversal

## Morris Inorder Traversal

### Algorithm Steps
1. Start from root
2. If current node has no left child:
   - Process current node
   - Move to right child
3. If current node has left child:
   - Find inorder predecessor (rightmost node in left subtree)
   - If predecessor's right is NULL:
     - Create link: predecessor->right = current
     - Move to left child
   - If predecessor's right points to current:
     - Remove link: predecessor->right = NULL
     - Process current node
     - Move to right child

### Code Implementation

```cpp
class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        
        while(root) {
            // Case 1: No left child
            if(!root->left) {
                ans.push_back(root->data);
                root = root->right;
            }
            // Case 2: Left child exists
            else {
                Node* curr = root->left;
                
                // Find inorder predecessor
                while(curr->right && curr->right != root) {
                    curr = curr->right;
                }
                
                // Create link if not exists
                if(curr->right == NULL) {
                    curr->right = root;
                    root = root->left;
                }
                // Remove link and process node
                else {
                    curr->right = NULL;
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        
        return ans;
    }
};
```

### Example Walkthrough

```
Tree:     1
         / \
        2   3
       / \
      4   5

Inorder: 4, 2, 5, 1, 3
```

**Step-by-step execution:**
1. Start at 1, has left child (2)
2. Find predecessor of 1 in left subtree: rightmost in left subtree is 5
3. Create link: 5->right = 1, move to 2
4. At 2, has left child (4)
5. Find predecessor of 2: rightmost in left subtree is 4
6. Create link: 4->right = 2, move to 4
7. At 4, no left child, process 4, move right (to 2 via link)
8. At 2, predecessor 4 already links to 2, remove link, process 2, move right to 5
9. Continue this process...

## Morris Preorder Traversal

### Key Difference from Inorder
In preorder, we process the node **before** going to left subtree, so we add the node to result when we create the link (not when we remove it).

### Code Implementation

```cpp
class Solution {
public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        
        while(root) {
            // Case 1: No left child
            if(!root->left) {
                ans.push_back(root->data);
                root = root->right;
            }
            // Case 2: Left child exists
            else {
                Node* curr = root->left;
                
                // Find inorder predecessor
                while(curr->right && curr->right != root) {
                    curr = curr->right;
                }
                
                // Create link and process node
                if(curr->right == NULL) {
                    ans.push_back(root->data);  // Process BEFORE going left
                    curr->right = root;
                    root = root->left;
                }
                // Remove link and move right
                else {
                    curr->right = NULL;
                    root = root->right;
                }
            }
        }
        
        return ans;
    }
};
```

### Example
```
Tree:     1
         / \
        2   3
       / \
      4   5

Preorder: 1, 2, 4, 5, 3
```

## Morris Postorder Traversal

### Approach
Postorder is trickier because we need to process nodes after visiting both subtrees. The approach:
1. **Mirror of Preorder**: Use right subtree instead of left
2. **Reverse Result**: Reverse the final result to get correct postorder

### Algorithm Logic
- Process right subtree first (mirror of preorder on right subtree)
- This gives us reverse postorder
- Reverse the result to get correct postorder

### Code Implementation

```cpp
class Solution {
public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        
        while(root) {
            // Case 1: No right child
            if(!root->right) {
                ans.push_back(root->data);
                root = root->left;
            }
            // Case 2: Right child exists
            else {
                Node* curr = root->right;
                
                // Find inorder successor (leftmost in right subtree)
                while(curr->left && curr->left != root) {
                    curr = curr->left;
                }
                
                // Create link and process node
                if(curr->left == NULL) {
                    ans.push_back(root->data);
                    curr->left = root;
                    root = root->right;
                }
                // Remove link and move left
                else {
                    curr->left = NULL;
                    root = root->left;
                }
            }
        }
        
        // Reverse to get correct postorder
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

### Example
```
Tree:     1
         / \
        2   3
       / \
      4   5

Postorder: 4, 5, 2, 3, 1
```

## Flatten Binary Tree to Linked List

### Problem Statement
Convert a binary tree to a linked list in-place where:
- The linked list should be in preorder traversal order
- Use the right pointer as next pointer
- Left pointer should be NULL

### Algorithm
1. For each node with left child:
   - Find rightmost node in left subtree
   - Connect rightmost->right to current->right
   - Move current->left to current->right
   - Set current->left to NULL

### Code Implementation

```cpp
class Solution {
public:
    void flatten(Node* root) {
        while(root) {
            // Case 1: No left child, move right
            if(!root->left) {
                root = root->right;
            }
            // Case 2: Left child exists
            else {
                Node* curr = root->left;
                
                // Find rightmost node in left subtree
                while(curr->right) {
                    curr = curr->right;
                }
                
                // Connect rightmost to current's right
                curr->right = root->right;
                
                // Move left subtree to right
                root->right = root->left;
                root->left = NULL;
                
                // Move to next node
                root = root->right;
            }
        }
    }
};
```

### Example Walkthrough

```
Original Tree:    1
                 / \
                2   5
               / \   \
              3   4   6

Step 1: At node 1
- Find rightmost in left subtree (2's subtree): node 4
- Connect 4->right = 5
- Move 2 to right of 1
- Set 1->left = NULL

Tree becomes:     1
                   \
                    2
                   / \
                  3   4
                       \
                        5
                         \
                          6

Continue this process until we get:
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

## Complexity Analysis

### Time Complexity: O(n)
- Each edge is traversed at most twice
- Once while creating link, once while removing link
- Total edges = n-1, so O(2*(n-1)) = O(n)

### Space Complexity: O(1)
- No recursion stack
- No additional data structures
- Only temporary links that are removed


## Key Takeaways

1. **Space Optimization**: Morris Traversal is the most space-efficient tree traversal method
2. **Temporary Modification**: The algorithm temporarily modifies tree structure but restores it
3. **Pattern Recognition**: Understanding the threading concept helps in solving various tree problems
4. **Interview Favorite**: Commonly asked in technical interviews for space optimization discussions

## Common Mistakes to Avoid

1. **Forgetting to Remove Links**: Always remove temporary links to restore original structure
2. **Infinite Loops**: Ensure proper link detection to avoid cycles
3. **Wrong Predecessor**: Make sure to find the correct inorder predecessor
4. **Edge Cases**: Handle NULL nodes and single node trees properly

---

