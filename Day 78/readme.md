# Binary Tree Problems - Day 78 Technical Interview Preparation

## Table of Contents
1. [Introduction](#introduction)
2. [Basic Binary Tree Structure](#basic-binary-tree-structure)
3. [Level Order Traversal](#level-order-traversal)
4. [Size of Binary Tree](#size-of-binary-tree)
5. [Sum of Binary Tree](#sum-of-binary-tree)
6. [Count Leaves in Binary Tree](#count-leaves-in-binary-tree)
7. [Count Non-Leaf Nodes](#count-non-leaf-nodes)
8. [Height of Binary Tree](#height-of-binary-tree)
9. [Time and Space Complexity Analysis](#time-and-space-complexity-analysis)
10. [Practice Problems](#practice-problems)

## Introduction

Binary Tree is a hierarchical data structure where each node has at most two children, referred to as left child and right child. These problems are fundamental for technical interviews and form the basis for more complex tree operations.

## Basic Binary Tree Structure

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
```

## Level Order Traversal

**Problem**: Traverse the binary tree level by level and return a 2D vector where each inner vector contains nodes at the same level.

**Approach**: Use BFS (Breadth-First Search) with a queue to process nodes level by level.

### Implementation
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            
            for (int i = 0; i < levelSize; i++) {
                Node* temp = q.front();
                q.pop();
                
                level.push_back(temp->data);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};
```

### Example
```
Input Tree:
       1
      / \
     2   3
    / \
   4   5

Output: [[1], [2, 3], [4, 5]]
```

**Time Complexity**: O(N) - Visit each node once  
**Space Complexity**: O(W) - Where W is maximum width of tree

## Size of Binary Tree

**Problem**: Find the total number of nodes in a binary tree.

### Method 1: Using Reference Parameter (Preorder Traversal)
```cpp
class Solution {
public:
    void countNodes(Node *root, int &count) {
        // Base case
        if (root == NULL) return;
        
        count++;                    // Count current node
        countNodes(root->left, count);   // Count left subtree
        countNodes(root->right, count);  // Count right subtree
    }
    
    int getSize(Node* node) {
        int count = 0;
        countNodes(node, count);
        return count;
    }
};
```

### Method 2: Recursive Return Approach
```cpp
class Solution {
public:
    int getSize(Node* node) {
        // Base case
        if (node == NULL) return 0;
        
        // 1 (current) + left subtree size + right subtree size
        return 1 + getSize(node->left) + getSize(node->right);
    }
};
```

### Example
```
Input Tree:
       1
      / \
     2   3
    / \   \
   4   5   6

Output: 6 (total nodes)
```

**Time Complexity**: O(N) - Visit each node once  
**Space Complexity**: O(H) - Height of tree (recursion stack)

## Sum of Binary Tree

**Problem**: Calculate the sum of all node values in a binary tree.

### Method 1: Using Reference Parameter
```cpp
class Solution {
public:
    void calculateSum(Node *root, int &sum) {
        // Base case
        if (root == NULL) return;
        
        sum += root->data;                    // Add current node
        calculateSum(root->left, sum);        // Add left subtree
        calculateSum(root->right, sum);       // Add right subtree
    }
    
    int sumBT(Node* root) {
        int sum = 0;
        calculateSum(root, sum);
        return sum;
    }
};
```

### Method 2: Recursive Return Approach
```cpp
class Solution {
public:
    int sumBT(Node* root) {
        // Base case
        if (root == NULL) return 0;
        
        // Current node + left subtree sum + right subtree sum
        return root->data + sumBT(root->left) + sumBT(root->right);
    }
};
```

### Example
```
Input Tree:
       1
      / \
     2   3
    / \
   4   5

Output: 15 (1+2+3+4+5)
```

**Time Complexity**: O(N) - Visit each node once  
**Space Complexity**: O(H) - Height of tree (recursion stack)

## Count Leaves in Binary Tree

**Problem**: Count the number of leaf nodes (nodes with no children) in a binary tree.

**Definition**: A leaf node is a node that has no left child and no right child.

### Method 1: Using Reference Parameter
```cpp
class Solution {
public:
    void countLeaf(Node *root, int &count) {
        if (root == NULL) return;
        
        // Check if it's a leaf node
        if (!root->left && !root->right) {
            count++;
            return;
        }
        
        countLeaf(root->left, count);
        countLeaf(root->right, count);
    }
    
    int countLeaves(Node* root) {
        int count = 0;
        countLeaf(root, count);
        return count;
    }
};
```

### Method 2: Recursive Return Approach
```cpp
class Solution {
public:
    int countLeaves(Node* root) {
        // Base case
        if (!root) return 0;
        
        // If it's a leaf node
        if (!root->left && !root->right) return 1;
        
        // Count leaves in left and right subtrees
        return countLeaves(root->left) + countLeaves(root->right);
    }
};
```

### Example
```
Input Tree:
       1
      / \
     2   3
    / \   \
   4   5   6

Output: 3 (nodes 4, 5, 6 are leaves)
```

**Time Complexity**: O(N) - Visit each node once  
**Space Complexity**: O(H) - Height of tree (recursion stack)

## Count Non-Leaf Nodes

**Problem**: Count the number of internal nodes (nodes with at least one child) in a binary tree.

**Definition**: A non-leaf node is a node that has at least one child (left or right).

### Method 1: Using Reference Parameter
```cpp
class Solution {
public:
    void countNonLeaf(Node *root, int &count) {
        if (root == NULL) return;
        
        // If it's a leaf node, don't count
        if (!root->left && !root->right) return;
        
        count++;                           // Count current non-leaf node
        countNonLeaf(root->left, count);   // Count in left subtree
        countNonLeaf(root->right, count);  // Count in right subtree
    }
    
    int countNonLeafNodes(Node* root) {
        int count = 0;
        countNonLeaf(root, count);
        return count;
    }
};
```

### Method 2: Recursive Return Approach
```cpp
class Solution {
public:
    int countNonLeafNodes(Node* root) {
        // Base case
        if (!root) return 0;
        
        // If it's a leaf node
        if (!root->left && !root->right) return 0;
        
        // 1 (current non-leaf) + count from subtrees
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};
```

### Example
```
Input Tree:
       1
      / \
     2   3
    / \   \
   4   5   6

Output: 3 (nodes 1, 2, 3 are non-leaf nodes)
```

**Time Complexity**: O(N) - Visit each node once  
**Space Complexity**: O(H) - Height of tree (recursion stack)

## Height of Binary Tree

**Problem**: Find the height (or depth) of a binary tree.

**Definition**: Height of a tree is the length of the longest path from root to any leaf node. Height of empty tree is -1, height of tree with single node is 0.

### Implementation
```cpp
class Solution {
public:
    int height(Node* node) {
        // Base case: empty tree has height -1
        if (node == NULL) return -1;
        
        // Height = 1 + maximum height of left and right subtrees
        return 1 + max(height(node->left), height(node->right));
    }
};
```

### Alternative Definition (Height starting from 1)
```cpp
class Solution {
public:
    int height(Node* node) {
        // Base case: empty tree has height 0
        if (node == NULL) return 0;
        
        // Height = 1 + maximum height of left and right subtrees
        return 1 + max(height(node->left), height(node->right));
    }
};
```

### Example
```
Input Tree:
       1
      / \
     2   3
    / \
   4   5
  /
 6

Output: 3 (path: 1->2->4->6, length = 3)
```

**Time Complexity**: O(N) - Visit each node once  
**Space Complexity**: O(H) - Height of tree (recursion stack)

## Time and Space Complexity Analysis

| Operation | Time Complexity | Space Complexity | Notes |
|-----------|----------------|------------------|-------|
| Level Order Traversal | O(N) | O(W) | W = maximum width |
| Size of Tree | O(N) | O(H) | H = height of tree |
| Sum of Tree | O(N) | O(H) | H = height of tree |
| Count Leaves | O(N) | O(H) | H = height of tree |
| Count Non-Leaves | O(N) | O(H) | H = height of tree |
| Height of Tree | O(N) | O(H) | H = height of tree |

**Where:**
- N = Total number of nodes
- H = Height of the tree
- W = Maximum width of the tree


## Key Points to Remember

1. **Base Case**: Always handle NULL nodes properly
2. **Recursion**: Most tree problems can be solved recursively
3. **Two Approaches**: Reference parameter vs return value method
4. **Space Complexity**: Consider recursion stack in space analysis
5. **Edge Cases**: Empty tree, single node tree, skewed tree
6. **Tree Properties**: 
   - Leaf node: No children
   - Internal node: At least one child
   - Height: Longest path from root to leaf
   - Size: Total number of nodes

## Tips for Interviews

1. **Draw the tree** before coding
2. **Start with base case** (NULL node)
3. **Think recursively** - what to do at current node, then recurse
4. **Consider both methods** (reference vs return) and choose based on preference
5. **Test with examples** including edge cases
6. **Analyze complexity** after implementation