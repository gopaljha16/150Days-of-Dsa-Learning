# DAY 82: Binary Tree Problems

## Table of Contents
- [Bottom View of Binary Tree](#bottom-view-of-binary-tree)
- [Construct Tree from Inorder & Preorder](#construct-tree-from-inorder--preorder)
- [Construct Tree from Inorder & Postorder](#construct-tree-from-inorder--postorder)
- [Key Concepts](#key-concepts)
- [Practice Problems](#practice-problems)

---

## Bottom View of Binary Tree

### Problem Statement
Given a binary tree, return the bottom view of the tree. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

### Key Concepts
- **Horizontal Distance (HD)**: Distance of a node from the root in horizontal direction
- **Level**: Depth of node from root
- For bottom view, we need the **lowest level node** at each horizontal distance

### Approach 1: Level Order Traversal (BFS)

**Algorithm:**
1. Find the leftmost and rightmost horizontal distances
2. Use BFS to traverse level by level
3. Keep overwriting nodes at same horizontal distance (last one wins)

```cpp
class Solution {
public:
    void findPos(Node *root, int pos, int &left, int &right) {
        if (!root) return;
        
        left = min(pos, left);
        right = max(pos, right);
        
        findPos(root->left, pos - 1, left, right);
        findPos(root->right, pos + 1, left, right);
    }
    
    vector<int> bottomView(Node *root) {
        if (!root) return {};
        
        int leftMost = 0, rightMost = 0;
        findPos(root, 0, leftMost, rightMost);
        
        int size = rightMost - leftMost + 1;
        vector<int> ans(size);
        
        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(-leftMost); // Normalize index to start from 0
        
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            
            ans[pos] = temp->data; // Keep overwriting for bottom view
            
            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }
        return ans;
    }
};
```

**Time Complexity:** O(N)  
**Space Complexity:** O(N)

### Approach 2: Recursive DFS with Level Tracking

**Algorithm:**
1. Track the level of each horizontal distance
2. Update node only if current level >= stored level
3. This ensures we get the bottommost node

```cpp
class Solution {
public:
    void findPos(Node *root, int pos, int &left, int &right) {
        if (!root) return;
        
        left = min(pos, left);
        right = max(pos, right);
        
        findPos(root->left, pos - 1, left, right);
        findPos(root->right, pos + 1, left, right);
    }
    
    void bottomV(Node *root, int pos, vector<int> &ans, vector<int> &level, int l) {
        if (!root) return;
        
        // Update if current level is greater or equal
        if (level[pos] <= l) {
            ans[pos] = root->data;
            level[pos] = l;
        }
        
        bottomV(root->left, pos - 1, ans, level, l + 1);
        bottomV(root->right, pos + 1, ans, level, l + 1);
    }
    
    vector<int> bottomView(Node *root) {
        if (!root) return {};
        
        int leftMost = 0, rightMost = 0;
        findPos(root, 0, leftMost, rightMost);
        
        int size = rightMost - leftMost + 1;
        vector<int> ans(size);
        vector<int> level(size, INT_MIN);
        
        bottomV(root, -leftMost, ans, level, 0);
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
     /   / \
    4   5   6
           /
          7

Horizontal Distances:
4(-2) 2(-1) 1(0) 5(1) 3(2) 6(3) 7(2)

Bottom View: [4, 2, 5, 7, 6]
```

---

## Construct Tree from Inorder & Preorder

### Problem Statement
Given inorder and preorder traversal arrays, construct the original binary tree.

### Key Concepts
- **Preorder**: Root → Left → Right
- **Inorder**: Left → Root → Right
- First element in preorder is always the root
- Root divides inorder into left and right subtrees

### Algorithm
1. Pick first element from preorder as root
2. Find root's position in inorder
3. Elements before root in inorder = left subtree
4. Elements after root in inorder = right subtree
5. Recursively build left and right subtrees

```cpp
class Solution {
public:
    int findPos(vector<int> &in, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    Node* buildTreeHelper(vector<int> &in, vector<int> &pre, 
                         int inStart, int inEnd, int &preIndex) {
        // Base case
        if (inStart > inEnd) {
            return NULL;
        }
        
        // Create root node
        Node *root = new Node(pre[preIndex]);
        preIndex++;
        
        // Find root position in inorder
        int pos = findPos(in, root->data, inStart, inEnd);
        
        // Build left subtree first (preorder: root -> left -> right)
        root->left = buildTreeHelper(in, pre, inStart, pos - 1, preIndex);
        // Build right subtree
        root->right = buildTreeHelper(in, pre, pos + 1, inEnd, preIndex);
        
        return root;
    }
    
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preIndex = 0;
        int n = inorder.size();
        return buildTreeHelper(inorder, preorder, 0, n - 1, preIndex);
    }
};
```

### Optimized Version with HashMap

```cpp
class Solution {
public:
    unordered_map<int, int> inorderMap;
    
    Node* buildTreeHelper(vector<int> &pre, int inStart, int inEnd, int &preIndex) {
        if (inStart > inEnd) return NULL;
        
        Node *root = new Node(pre[preIndex++]);
        int pos = inorderMap[root->data];
        
        root->left = buildTreeHelper(pre, inStart, pos - 1, preIndex);
        root->right = buildTreeHelper(pre, pos + 1, inEnd, preIndex);
        
        return root;
    }
    
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        // Build hashmap for O(1) lookups
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int preIndex = 0;
        return buildTreeHelper(preorder, 0, inorder.size() - 1, preIndex);
    }
};
```

### Example
```
Preorder: [3, 9, 20, 15, 7]
Inorder:  [9, 3, 15, 20, 7]

Step-by-step construction:
1. Root = 3 (first in preorder)
2. Find 3 in inorder at index 1
3. Left subtree: [9], Right subtree: [15, 20, 7]
4. Continue recursively...

Result Tree:
    3
   / \
  9   20
     /  \
    15   7
```

**Time Complexity:** O(N) with hashmap, O(N²) without  
**Space Complexity:** O(N)

---

## Construct Tree from Inorder & Postorder

### Problem Statement
Given inorder and postorder traversal arrays, construct the original binary tree.

### Key Concepts
- **Postorder**: Left → Right → Root
- **Inorder**: Left → Root → Right
- Last element in postorder is always the root
- Build right subtree first, then left (reverse of postorder)

### Algorithm
1. Pick last element from postorder as root
2. Find root's position in inorder
3. Build right subtree first, then left subtree
4. Decrement postorder index after creating each node

```cpp
class Solution {
public:
    int findPos(vector<int> &in, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    Node* buildTreeHelper(vector<int> &in, vector<int> &post,
                         int inStart, int inEnd, int &postIndex) {
        // Base case
        if (inStart > inEnd) {
            return NULL;
        }
        
        // Create root node
        Node *root = new Node(post[postIndex]);
        postIndex--;
        
        // Find root position in inorder
        int pos = findPos(in, root->data, inStart, inEnd);
        
        // Build RIGHT subtree first (reverse postorder)
        root->right = buildTreeHelper(in, post, pos + 1, inEnd, postIndex);
        // Build LEFT subtree
        root->left = buildTreeHelper(in, post, inStart, pos - 1, postIndex);
        
        return root;
    }
    
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int n = postorder.size();
        int postIndex = n - 1; // Start from last element
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }
};
```

### Example
```
Inorder:   [9, 3, 15, 20, 7]
Postorder: [9, 15, 7, 20, 3]

Step-by-step construction:
1. Root = 3 (last in postorder)
2. Find 3 in inorder at index 1
3. Build right subtree [15, 20, 7] first
4. Then build left subtree [9]

Result Tree:
    3
   / \
  9   20
     /  \
    15   7
```

**Time Complexity:** O(N²) without hashmap, O(N) with hashmap  
**Space Complexity:** O(N)

---

## Key Concepts

### Tree Traversals
1. **Preorder**: Root → Left → Right
2. **Inorder**: Left → Root → Right  
3. **Postorder**: Left → Right → Root
4. **Level Order**: Level by level (BFS)

### Important Properties
- **Inorder of BST**: Always gives sorted array
- **Preorder**: First element is root
- **Postorder**: Last element is root
- **Tree Construction**: Need inorder + any other traversal

### Common Patterns
1. **Position Finding**: Use hashmap for O(1) lookup
2. **Index Management**: Pass by reference to maintain state
3. **Base Cases**: Always check for null or invalid ranges
4. **Recursive Structure**: Divide problem into subproblems

---


### Tips for Interviews
1. Always clarify if tree has duplicate values
2. Discuss time/space complexity trade-offs
3. Consider edge cases (empty tree, single node)
4. Practice drawing trees for better visualization
5. Understand the relationship between different traversals

---

## Complexity Summary

| Problem | Time Complexity | Space Complexity | Key Technique |
|---------|----------------|------------------|---------------|
| Bottom View (BFS) | O(N) | O(N) | Level Order Traversal |
| Bottom View (DFS) | O(N) | O(N) | Recursive with Level Tracking |
| Inorder + Preorder | O(N) | O(N) | Recursive Division |
| Inorder + Postorder | O(N) | O(N) | Reverse Recursive Division |

