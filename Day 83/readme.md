# Binary Tree Traversal: Advanced Techniques

## Table of Contents
1. [Vertical Order Traversal](#vertical-order-traversal)
2. [Diagonal Traversal](#diagonal-traversal)
3. [Boundary Traversal](#boundary-traversal)
4. [Time & Space Complexity](#complexity-analysis)
5. [Practice Problems](#practice-problems)

---

## Vertical Order Traversal

### Definition
Vertical Order Traversal involves traversing a binary tree column by column from left to right. Nodes at the same horizontal distance from the root are grouped together.

### Key Concepts
- **Horizontal Distance (HD)**: Distance of a node from the root in horizontal direction
- Root has HD = 0
- Left child has HD = parent's HD - 1
- Right child has HD = parent's HD + 1

### Visual Example
```
        1
      /   \
     2     3
   /  \   /  \
  4    5 6    7
```

**Vertical Lines:**
- HD = -2: [4]
- HD = -1: [2]
- HD = 0: [1, 5, 6]
- HD = 1: [3]
- HD = 2: [7]

**Output:** [[4], [2], [1, 5, 6], [3], [7]]

### Algorithm Approach

#### Method 1: Two-Pass Solution (Given Implementation)

**Step 1:** Find the range of horizontal distances
```cpp
void findPos(Node *root, int pos, int &l, int &r) {
    if (!root) return;
    
    l = min(pos, l);  // leftmost position
    r = max(pos, r);  // rightmost position
    
    findPos(root->left, pos - 1, l, r);
    findPos(root->right, pos + 1, l, r);
}
```

**Step 2:** Level order traversal with position tracking
```cpp
vector<vector<int>> verticalOrder(Node *root) {
    int l = 0, r = 0;
    findPos(root, 0, l, r);
    
    vector<vector<int>> positive(r + 1);
    vector<vector<int>> negative(abs(l) + 1);
    
    queue<Node*> q;
    queue<int> index;
    q.push(root);
    index.push(0);
    
    while (!q.empty()) {
        Node *temp = q.front(); q.pop();
        int pos = index.front(); index.pop();
        
        if (pos >= 0) {
            positive[pos].push_back(temp->data);
        } else {
            negative[-pos].push_back(temp->data);
        }
        
        if (temp->left) {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right) {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }
    
    vector<vector<int>> ans;
    
    // Add negative columns (right to left)
    for (int i = negative.size() - 1; i >= 0; i--) {
        if (!negative[i].empty()) {
            ans.push_back(negative[i]);
        }
    }
    
    // Add positive columns (left to right)
    for (int i = 0; i < positive.size(); i++) {
        if (!positive[i].empty()) {
            ans.push_back(positive[i]);
        }
    }
    
    return ans;
}
```

#### Method 2: Map-based Solution (Alternative)
```cpp
vector<vector<int>> verticalOrder(Node* root) {
    if (!root) return {};
    
    map<int, vector<int>> columnMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();
        
        columnMap[col].push_back(node->data);
        
        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }
    
    vector<vector<int>> result;
    for (auto& [col, nodes] : columnMap) {
        result.push_back(nodes);
    }
    return result;
}
```

---

## Diagonal Traversal

### Definition
Diagonal Traversal visits nodes along diagonal lines. A diagonal is formed by nodes where we can reach from one node to another by only going right or going down-left.

### Key Concepts
- **Diagonal Distance**: How many left turns we need to make from root
- Root has diagonal distance = 0
- Left child has diagonal distance = parent's distance + 1
- Right child has same diagonal distance as parent

### Visual Example
```
        8
      /   \
     3     10
   /  \      \
  1    6      14
      / \    /
     4   7  13
```

**Diagonals:**
- Diagonal 0: [8, 10, 14]
- Diagonal 1: [3, 6, 7, 13]
- Diagonal 2: [1, 4]

**Output:** [8, 10, 14, 3, 6, 7, 13, 1, 4]

### Algorithm Implementation

```cpp
class Solution {
public:
    void findPos(Node *root, int pos, int &leftMost) {
        if (!root) return;
        
        leftMost = max(pos, leftMost);
        
        findPos(root->left, pos + 1, leftMost);
        findPos(root->right, pos, leftMost);
    }
    
    void findDiagonal(Node *root, int pos, vector<vector<int>> &ans) {
        if (!root) return;
        
        ans[pos].push_back(root->data);
        
        findDiagonal(root->left, pos + 1, ans);   // Increase diagonal level
        findDiagonal(root->right, pos, ans);      // Same diagonal level
    }
    
    vector<int> diagonal(Node *root) {
        int leftMost = 0;
        findPos(root, 0, leftMost);
        
        vector<vector<int>> ans(leftMost + 1);
        findDiagonal(root, 0, ans);
        
        vector<int> result;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                result.push_back(ans[i][j]);
            }
        }
        
        return result;
    }
};
```

### Alternative Iterative Approach
```cpp
vector<int> diagonal(Node* root) {
    if (!root) return {};
    
    vector<int> result;
    queue<Node*> q;
    
    while (root || !q.empty()) {
        // Traverse the diagonal
        while (root) {
            result.push_back(root->data);
            if (root->left) q.push(root->left);
            root = root->right;
        }
        
        // Move to next diagonal
        if (!q.empty()) {
            root = q.front();
            q.pop();
        }
    }
    
    return result;
}
```

---

## Boundary Traversal

### Definition
Boundary Traversal involves printing the boundary nodes of a binary tree in anti-clockwise direction starting from the root.

### Components
1. **Root Node**
2. **Left Boundary** (excluding leaf nodes)
3. **Leaf Nodes** (left to right)
4. **Right Boundary** (excluding leaf nodes, in reverse order)

### Visual Example
```
        20
      /    \
     8      22
   /  \    /  \
  4   12  null 25
     /  \
    10  14
```

**Boundary Elements:**
- Root: [20]
- Left Boundary: [8, 12]
- Leaf Nodes: [4, 10, 14, 25]
- Right Boundary: [22] (in reverse)

**Output:** [20, 8, 12, 4, 10, 14, 25, 22]

### Algorithm Implementation

```cpp
class Solution {
public:
    void leftSub(Node *root, vector<int> &ans) {
        if (!root || (!root->left && !root->right)) return;
        
        ans.push_back(root->data);
        
        if (root->left)
            leftSub(root->left, ans);
        else
            leftSub(root->right, ans);
    }
    
    void leaf(Node *root, vector<int> &ans) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    
    void rightSub(Node *root, vector<int> &ans) {
        if (!root || (!root->left && !root->right)) return;
        
        if (root->right)
            rightSub(root->right, ans);
        else
            rightSub(root->left, ans);
        
        ans.push_back(root->data);  // Add after recursion for reverse order
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        // Step 1: Add root
        ans.push_back(root->data);
        
        // Step 2: Add left boundary (excluding leaf nodes)
        leftSub(root->left, ans);
        
        // Step 3: Add leaf nodes
        if (root->left || root->right)  // Only if tree has more than one node
            leaf(root, ans);
        
        // Step 4: Add right boundary (excluding leaf nodes, in reverse)
        rightSub(root->right, ans);
        
        return ans;
    }
};
```

### Edge Cases to Handle
1. **Single Node Tree**: Only root should be printed
2. **Only Left Subtree**: No right boundary
3. **Only Right Subtree**: No left boundary
4. **Linear Tree**: Handle both left-skewed and right-skewed trees

---

## Complexity Analysis

| Traversal Type | Time Complexity | Space Complexity | Notes |
|----------------|-----------------|------------------|-------|
| Vertical Order | O(N log N) | O(N) | Map operations add log N factor |
| Diagonal | O(N) | O(N) | Linear traversal with additional space |
| Boundary | O(N) | O(H) | H is height of tree for recursion stack |

**Where:**
- N = Number of nodes in the tree
- H = Height of the tree

## Key Takeaways

1. **Vertical Traversal**: Use level-order traversal with column indexing
2. **Diagonal Traversal**: Right child stays in same diagonal, left child moves to next diagonal
3. **Boundary Traversal**: Combine left boundary + leaves + right boundary (reversed)
4. **Common Patterns**: 
   - Use queues for level-order processing
   - Use maps for grouping by distance/position
   - Handle edge cases carefully (single node, skewed trees)

## Tips for Implementation
- Always check for null nodes before processing
- Use appropriate data structures (queues for BFS, maps for grouping)
- Handle edge cases explicitly
- Test with different tree structures (balanced, skewed, single node)

---

