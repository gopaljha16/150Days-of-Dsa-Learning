# Day 79: Binary Tree Problems - Complete Study Notes

## 📚 Table of Contents
1. [Largest Value in Each Level](#1-largest-value-in-each-level)
2. [Check if Two Trees are Identical](#2-check-if-two-trees-are-identical)
3. [Check for Balanced Tree](#3-check-for-balanced-tree)
4. [Level Order in Spiral Form](#4-level-order-in-spiral-form)
5. [Check if Two Nodes are Cousins](#5-check-if-two-nodes-are-cousins)

---

## 1. Largest Value in Each Level

### 🎯 Problem Statement
Given a binary tree, find the largest value in each level of the tree.

### 💡 Approach
- Use **Level Order Traversal (BFS)** with a queue
- For each level, track the maximum value
- Process all nodes at current level before moving to next level

### 🔧 Algorithm Steps
1. Initialize queue with root node
2. For each level:
   - Get current level size
   - Initialize level maximum to INT_MIN
   - Process all nodes in current level
   - Update maximum value for current level
   - Add children to queue for next level
3. Store level maximum in result vector

### 💻 Code Implementation
```cpp
class Solution {
public:
    vector<int> largestValues(Node* root) {
        vector<int> ans;
        
        if (!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelMax = INT_MIN;
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                Node* temp = q.front();
                q.pop();
                
                levelMax = max(levelMax, temp->data);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            ans.push_back(levelMax);
        }
        
        return ans;
    }
};
```

### 📊 Example
```
Input Tree:
       1
     /   \
    3     2
   / \     \
  5   3     9

Level 0: [1] → Max = 1
Level 1: [3, 2] → Max = 3
Level 2: [5, 3, 9] → Max = 9

Output: [1, 3, 9]
```

### ⏱️ Complexity Analysis
- **Time Complexity:** O(n) - Visit each node once
- **Space Complexity:** O(w) - Where w is maximum width of tree

---

## 2. Check if Two Trees are Identical

### 🎯 Problem Statement
Given two binary trees, determine if they are identical (same structure and same node values).

### 💡 Approach
- Use **Recursive Traversal**
- Compare nodes at each level
- Check structure and values simultaneously

### 🔧 Algorithm Steps
1. Base cases:
   - Both nodes are NULL → return true
   - One is NULL, other is not → return false
   - Node values are different → return false
2. Recursively check left and right subtrees
3. Return true only if both subtrees are identical

### 💻 Code Implementation
```cpp
class Solution {
public:
    bool isIdentical(Node *r1, Node *r2) {
        // Base case: both are NULL
        if (r1 == NULL && r2 == NULL)
            return true;
        
        // One is NULL, other is not
        if (!r1 || !r2)
            return false;
        
        // Data values are different
        if (r1->data != r2->data)
            return false;
        
        // Recursively check left and right subtrees
        return isIdentical(r1->left, r2->left) && 
               isIdentical(r1->right, r2->right);
    }
};
```

### 📊 Example
```
Tree 1:       Tree 2:
   1             1
  / \           / \
 2   3         2   3

Both trees are identical → Output: true

Tree 1:       Tree 2:
   1             1
  / \           / \
 2   3         3   2

Trees are not identical → Output: false
```

### ⏱️ Complexity Analysis
- **Time Complexity:** O(min(n1, n2)) - Where n1, n2 are sizes of trees
- **Space Complexity:** O(min(h1, h2)) - Where h1, h2 are heights of trees

---

## 3. Check for Balanced Tree

### 🎯 Problem Statement
A binary tree is balanced if the height difference between left and right subtrees of any node is at most 1.

### 💡 Approach
- Use **Recursive Height Calculation**
- Check balance condition at each node
- Optimize by early termination when imbalance is detected

### 🔧 Algorithm Steps
1. Calculate height of left and right subtrees
2. Check if absolute difference > 1
3. If imbalanced, set flag to false
4. Return height for parent calculations
5. Optimize: Stop further calculations if already imbalanced

### 💻 Code Implementation

#### Basic Approach:
```cpp
class Solution {
public:
    int height(Node *root, bool &valid) {
        if (!root) return 0;
        
        int left = height(root->left, valid);
        int right = height(root->right, valid);
        
        // Check balance condition
        if (abs(left - right) > 1) {
            valid = false;
        }
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(Node* root) {
        bool valid = true;
        height(root, valid);
        return valid;
    }
};
```

#### Optimized Approach:
```cpp
class Solution {
public:
    int height(Node *root, bool &valid) {
        if (!root) return 0;
        
        int left = height(root->left, valid);
        
        // Early termination if already imbalanced
        if (valid) {
            int right = height(root->right, valid);
            
            if (abs(left - right) > 1) {
                valid = false;
            }
            
            return 1 + max(left, right);
        }
        
        return -1; // Tree is already imbalanced
    }
    
    bool isBalanced(Node* root) {
        bool valid = true;
        height(root, valid);
        return valid;
    }
};
```

### 📊 Example
```
Balanced Tree:
       1
     /   \
    2     3
   / \
  4   5

Height difference at each node ≤ 1 → Output: true

Imbalanced Tree:
       1
     /   \
    2     3
   /
  4
 /
5

Height difference at node 1 = |3-1| = 2 > 1 → Output: false
```

### ⏱️ Complexity Analysis
- **Time Complexity:** O(n) - Visit each node once (optimized version)
- **Space Complexity:** O(h) - Recursion stack depth

---

## 4. Level Order in Spiral Form

### 🎯 Problem Statement
Print the level order traversal of a binary tree in spiral form (alternate levels in reverse order).

### 💡 Approach
- Use **Two Stacks** for alternating directions
- Stack 1: Left to Right traversal
- Stack 2: Right to Left traversal
- Alternate between stacks for each level

### 🔧 Algorithm Steps
1. Initialize two stacks (st1 for L→R, st2 for R→L)
2. Push root to st1
3. While either stack is not empty:
   - Process st1 (L→R): Add right child first, then left child to st2
   - Process st2 (R→L): Add left child first, then right child to st1
4. Continue until both stacks are empty

### 💻 Code Implementation
```cpp
class Solution {
public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        
        stack<Node*> st1; // Right to Left
        stack<Node*> st2; // Left to Right
        st1.push(root);
        vector<int> ans;
        
        while (!st1.empty() || !st2.empty()) {
            
            // Process Level: Right to Left
            if (!st1.empty()) {
                while (!st1.empty()) {
                    Node* temp = st1.top();
                    st1.pop();
                    
                    ans.push_back(temp->data);
                    
                    // Add children for next level (L→R processing)
                    if (temp->right) st2.push(temp->right);
                    if (temp->left) st2.push(temp->left);
                }
            }
            // Process Level: Left to Right
            else {
                while (!st2.empty()) {
                    Node* temp = st2.top();
                    st2.pop();
                    
                    ans.push_back(temp->data);
                    
                    // Add children for next level (R→L processing)
                    if (temp->left) st1.push(temp->left);
                    if (temp->right) st1.push(temp->right);
                }
            }
        }
        
        return ans;
    }
};
```

### 📊 Example
```
Input Tree:
       1
     /   \
    2     3
   / \   / \
  7   6 5   4

Level 0: 1 (L→R)
Level 1: 3, 2 (R→L)
Level 2: 7, 6, 5, 4 (L→R)

Output: [1, 3, 2, 7, 6, 5, 4]
```

### ⏱️ Complexity Analysis
- **Time Complexity:** O(n) - Visit each node once
- **Space Complexity:** O(w) - Where w is maximum width of tree

---

## 5. Check if Two Nodes are Cousins

### 🎯 Problem Statement
Two nodes are cousins if they are at the same level but have different parents.

### 💡 Approach
- Use **Level Order Traversal** to find levels
- Use **Separate Function** to check if nodes share same parent
- Combine both conditions: same level AND different parents

### 🔧 Algorithm Steps
1. **Find Levels:** Use BFS to determine level of both nodes
2. **Check Parent:** Use DFS to verify if nodes have same parent
3. **Validate:** Return true if same level AND different parents

### 💻 Code Implementation
```cpp
class Solution {
public:
    // Function to check if two nodes have same parent
    bool checkParent(Node *root, int x, int y) {
        if (!root) return false;
        
        // Check if current node is parent of both x and y
        if (root->left && root->right) {
            if ((root->left->data == x && root->right->data == y) ||
                (root->left->data == y && root->right->data == x)) {
                return true;
            }
        }
        
        // Recursively check in left and right subtrees
        return checkParent(root->left, x, y) || 
               checkParent(root->right, x, y);
    }
    
    bool isCousins(Node* root, int x, int y) {
        if (!root || x == y) return false;
        
        queue<Node*> q;
        q.push(root);
        int l1 = -1, l2 = -1; // Levels of nodes x and y
        int level = 0;
        
        // Find levels of both nodes
        while (!q.empty()) {
            int n = q.size();
            
            while (n--) {
                Node* temp = q.front();
                q.pop();
                
                if (temp->data == x) l1 = level;
                if (temp->data == y) l2 = level;
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            // Early termination if both levels found
            if (l1 != -1 && l2 != -1) break;
            level++;
        }
        
        // Check if both nodes exist
        if (l1 == -1 || l2 == -1) return false;
        
        // Nodes are cousins if: same level AND different parents
        return (l1 == l2) && !checkParent(root, x, y);
    }
};
```

### 📊 Example
```
Input Tree:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7

Case 1: x=4, y=6
- Level of 4: 2
- Level of 6: 2
- Parent of 4: 2, Parent of 6: 3
- Same level, different parents → Output: true

Case 2: x=4, y=5
- Level of 4: 2
- Level of 5: 2
- Parent of both 4 and 5: 2
- Same level, same parent → Output: false
```

### ⏱️ Complexity Analysis
- **Time Complexity:** O(n) - BFS + DFS traversals
- **Space Complexity:** O(h + w) - Recursion stack + queue space

---

## 🔑 Key Concepts Summary

### 1. **Level Order Traversal (BFS)**
- Use queue data structure
- Process nodes level by level
- Applications: Level-wise operations, finding levels

### 2. **Height Calculation**
- Recursive approach: `height = 1 + max(left_height, right_height)`
- Base case: NULL node has height 0
- Applications: Balance checking, tree properties

### 3. **Tree Comparison**
- Recursive structure and value comparison
- Base cases handle NULL scenarios
- Applications: Identical trees, subtree matching

### 4. **Spiral Traversal**
- Two-stack approach for alternating directions
- Careful ordering of child insertion
- Applications: Zigzag printing, spiral patterns

### 5. **Cousin Relationship**
- Combine level finding with parent checking
- Level Order Traversal + Parent verification
- Applications: Relationship queries, tree analysis

---
