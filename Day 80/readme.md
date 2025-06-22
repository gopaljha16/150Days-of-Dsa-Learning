# Binary Tree Views - Left, Right, and Top View

## Table of Contents
- [Introduction](#introduction)
- [Left View of Binary Tree](#left-view-of-binary-tree)
- [Right View of Binary Tree](#right-view-of-binary-tree)
- [Top View of Binary Tree](#top-view-of-binary-tree)
- [Comparison Table](#comparison-table)
- [Practice Problems](#practice-problems)

---

## Introduction

Binary Tree Views are fundamental problems in tree data structures that involve traversing and identifying specific nodes based on their visibility from different perspectives:

- **Left View**: Nodes visible when the tree is viewed from the left side
- **Right View**: Nodes visible when the tree is viewed from the right side  
- **Top View**: Nodes visible when the tree is viewed from above

### Visual Example
```
        1
       / \
      2   3
     / \   \
    4   5   6
   /
  7
```

- **Left View**: [1, 2, 4, 7]
- **Right View**: [1, 3, 6, 7]
- **Top View**: [4, 2, 1, 3, 6]

---

## Left View of Binary Tree

### Definition
The left view of a binary tree contains the first node encountered at each level when traversing from left to right.

### Approach 1: Level Order Traversal (BFS)

**Algorithm:**
1. Use a queue for level-order traversal
2. For each level, add the first node encountered to the result
3. Process all nodes at current level before moving to next

```cpp
class Solution {
public:
    vector<int> leftView(Node *root) {
        queue<Node*> q;
        vector<int> ans;
        
        if (!root) return ans;
        
        q.push(root);
        
        while (!q.empty()) {
            // Add first node of current level
            ans.push_back(q.front()->data);
            int levelSize = q.size();
            
            // Process all nodes at current level
            while (levelSize--) {
                Node* temp = q.front();
                q.pop();
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};
```

**Time Complexity:** O(N) - Visit each node once  
**Space Complexity:** O(W) - Where W is maximum width of tree

### Approach 2: Recursive (DFS)

**Algorithm:**
1. Traverse tree with level information
2. If current level equals result size, add node (first node at this level)
3. Recurse left first, then right

```cpp
class Solution {
public:
    void leftViewHelper(Node* root, int level, vector<int>& ans) {
        if (!root) return;
        
        // If this is the first node at current level
        if (level == ans.size()) {
            ans.push_back(root->data);
        }
        
        // Traverse left first, then right
        leftViewHelper(root->left, level + 1, ans);
        leftViewHelper(root->right, level + 1, ans);
    }
    
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        
        leftViewHelper(root, 0, ans);
        return ans;
    }
};
```

**Time Complexity:** O(N)  
**Space Complexity:** O(H) - Where H is height of tree (recursion stack)

### Example Walkthrough
```
Tree:     1
         / \
        2   3
       /   / \
      4   5   6

Level 0: [1] - First node is 1
Level 1: [2, 3] - First node is 2
Level 2: [4, 5, 6] - First node is 4

Left View: [1, 2, 4]
```

---

## Right View of Binary Tree

### Definition
The right view of a binary tree contains the last node encountered at each level when traversing from left to right.

### Approach 1: Level Order Traversal (BFS)

```cpp
class Solution {
public:
    vector<int> rightView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                Node* temp = q.front();
                q.pop();
                
                // If this is the last node at current level
                if (i == levelSize - 1) {
                    ans.push_back(temp->data);
                }
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};
```

### Approach 2: Recursive (DFS)

**Key Insight:** Visit right subtree before left subtree to get rightmost node first

```cpp
class Solution {
public:
    void rightViewHelper(Node* root, int level, vector<int>& ans) {
        if (!root) return;
        
        // If this is the first node we see at current level
        if (level == ans.size()) {
            ans.push_back(root->data);
        }
        
        // Traverse right first, then left
        rightViewHelper(root->right, level + 1, ans);
        rightViewHelper(root->left, level + 1, ans);
    }
    
    vector<int> rightView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        
        rightViewHelper(root, 0, ans);
        return ans;
    }
};
```

### Example Walkthrough
```
Tree:     1
         / \
        2   3
       /   / \
      4   5   6

Level 0: [1] - Last node is 1
Level 1: [2, 3] - Last node is 3  
Level 2: [4, 5, 6] - Last node is 6

Right View: [1, 3, 6]
```

---

## Top View of Binary Tree

### Definition
The top view of a binary tree shows nodes visible when viewed from above. Each horizontal distance should have only one node visible.

### Key Concept: Horizontal Distance (HD)
- Root has HD = 0
- Left child: HD = parent_HD - 1
- Right child: HD = parent_HD + 1

### Approach 1: Level Order Traversal

**Algorithm:**
1. Find leftmost and rightmost horizontal distances
2. Create result array of appropriate size
3. Use level-order traversal with position tracking
4. Fill only the first node encountered at each horizontal distance

```cpp
class Solution {
public:
    void findBounds(Node* root, int pos, int& leftmost, int& rightmost) {
        if (!root) return;
        
        leftmost = min(pos, leftmost);
        rightmost = max(pos, rightmost);
        
        findBounds(root->left, pos - 1, leftmost, rightmost);
        findBounds(root->right, pos + 1, leftmost, rightmost);
    }
    
    vector<int> topView(Node *root) {
        if (!root) return {};
        
        int leftmost = 0, rightmost = 0;
        findBounds(root, 0, leftmost, rightmost);
        
        int size = rightmost - leftmost + 1;
        vector<int> ans(size);
        vector<bool> filled(size, false);
        
        queue<Node*> nodeQueue;
        queue<int> posQueue;
        
        nodeQueue.push(root);
        posQueue.push(-leftmost); // Normalize position
        
        while (!nodeQueue.empty()) {
            Node* temp = nodeQueue.front();
            nodeQueue.pop();
            
            int pos = posQueue.front();
            posQueue.pop();
            
            // Fill only if position not already filled
            if (!filled[pos]) {
                filled[pos] = true;
                ans[pos] = temp->data;
            }
            
            if (temp->left) {
                nodeQueue.push(temp->left);
                posQueue.push(pos - 1);
            }
            
            if (temp->right) {
                nodeQueue.push(temp->right);
                posQueue.push(pos + 1);
            }
        }
        
        return ans;
    }
};
```

### Approach 2: Recursive with Level Tracking

**Algorithm:**
1. Track minimum level at each horizontal distance
2. Update node only if current level is smaller than stored level

```cpp
class Solution {
public:
    void findBounds(Node* root, int pos, int& leftmost, int& rightmost) {
        if (!root) return;
        
        leftmost = min(pos, leftmost);
        rightmost = max(pos, rightmost);
        
        findBounds(root->left, pos - 1, leftmost, rightmost);
        findBounds(root->right, pos + 1, leftmost, rightmost);
    }
    
    void topViewHelper(Node* root, int pos, vector<int>& ans, 
                      vector<int>& minLevel, int currentLevel, int offset) {
        if (!root) return;
        
        int index = pos + offset;
        
        // Update if current level is smaller (closer to root)
        if (minLevel[index] > currentLevel) {
            ans[index] = root->data;
            minLevel[index] = currentLevel;
        }
        
        topViewHelper(root->left, pos - 1, ans, minLevel, currentLevel + 1, offset);
        topViewHelper(root->right, pos + 1, ans, minLevel, currentLevel + 1, offset);
    }
    
    vector<int> topView(Node *root) {
        if (!root) return {};
        
        int leftmost = 0, rightmost = 0;
        findBounds(root, 0, leftmost, rightmost);
        
        int size = rightmost - leftmost + 1;
        vector<int> ans(size);
        vector<int> minLevel(size, INT_MAX);
        
        topViewHelper(root, 0, ans, minLevel, 0, -leftmost);
        
        return ans;
    }
};
```

### Example Walkthrough
```
Tree:       1
           / \
          2   3
         / \   \
        4   5   6
       /
      7

Horizontal Distances:
        1(0)
       /    \
    2(-1)   3(1)
    /  \      \
 4(-2) 5(0)   6(2)
 /
7(-3)

Positions from left to right: -3, -2, -1, 0, 1, 2
Corresponding nodes:           7,  4,  2, 1, 3, 6

Top View: [7, 4, 2, 1, 3, 6]
```

---

## Comparison Table

| Aspect | Left View | Right View | Top View |
|--------|-----------|------------|----------|
| **Traversal Order** | Level-order (left to right) | Level-order (left to right) | Level-order with position |
| **Selection Criteria** | First node at each level | Last node at each level | First node at each horizontal distance |
| **Key Technique** | Track level, pick first | Track level, pick last | Track horizontal distance |
| **Time Complexity** | O(N) | O(N) | O(N) |
| **Space Complexity** | O(W) iterative, O(H) recursive | O(W) iterative, O(H) recursive | O(N) |

---

## Additional Examples

### Example 1: Skewed Tree
```
Tree:  1
        \
         2
          \
           3
            \
             4

Left View: [1, 2, 3, 4]
Right View: [1, 2, 3, 4]  
Top View: [1, 2, 3, 4]
```

### Example 2: Complete Binary Tree
```
Tree:    1
       /   \
      2     3
     / \   / \
    4   5 6   7

Left View: [1, 2, 4]
Right View: [1, 3, 7]
Top View: [4, 2, 1, 3, 7]
```

### Example 3: Complex Tree
```
Tree:      1
         /   \
        2     3
       /     / \
      4     5   6
     /     /   / \
    8     9   10 11

Left View: [1, 2, 4, 8]
Right View: [1, 3, 6, 11]
Top View: [8, 4, 2, 1, 3, 6, 10, 11]
```

---

## Practice Problems

### GeeksforGeeks
- [Left View of Binary Tree](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)
- [Right View of Binary Tree](https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1)
- [Top View of Binary Tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

### LeetCode
- [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

## Key Takeaways

1. **Left/Right Views**: Focus on level-based traversal and node selection
2. **Top View**: Requires understanding of horizontal distances and position mapping
3. **Level Order vs Recursive**: Both approaches are valid, choose based on space constraints
4. **Edge Cases**: Handle empty trees, single nodes, and skewed trees
5. **Optimization**: Consider space-time tradeoffs between different approaches

---

*Happy Coding! 🌳*