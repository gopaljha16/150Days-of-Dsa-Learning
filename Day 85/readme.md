# Day 85: Burning Tree & Maximum Path Sum Between 2 Special Nodes

## 📚 Table of Contents
1. [Burning Tree Problem](#burning-tree-problem)
2. [Maximum Path Sum Between 2 Special Nodes](#maximum-path-sum-between-2-special-nodes)
3. [Key Concepts](#key-concepts)
4. [Practice Problems](#practice-problems)

---

## 🔥 Burning Tree Problem

### Problem Statement
Given a binary tree and a target node, find the minimum time required to burn the entire tree if fire starts from the target node. Fire spreads to adjacent nodes (parent and children) every second.

### Approach
The solution uses a two-phase approach:
1. **Find the target node** and calculate the maximum depth it can burn downwards
2. **Propagate upwards** and calculate the time needed to burn the entire tree

### Algorithm Steps
1. **Base Case**: If node doesn't exist, return 0
2. **Target Found**: Calculate maximum height of left and right subtrees
3. **Recursive Search**: Search in left and right subtrees
4. **Burning Propagation**: When fire comes from below, calculate time to burn opposite subtree

### Code Implementation

```cpp
class Solution {
public:
    // Helper function to calculate height of a subtree
    int Height(Node* root) {
        if (!root) return 0;
        return 1 + max(Height(root->left), Height(root->right));
    }
    
    // Main burning function
    int Burn(Node* root, int& timer, int target) {
        // Base case: node doesn't exist
        if (!root) return 0;
        
        // Target node found - start burning
        if (root->data == target) {
            int lh = Height(root->left);   // Left subtree height
            int rh = Height(root->right);  // Right subtree height
            timer = max(timer, max(lh, rh)); // Time to burn downwards
            return -1; // Negative indicates fire source
        }
        
        // Search in left and right subtrees
        int left = Burn(root->left, timer, target);
        int right = Burn(root->right, timer, target);
        
        // Fire coming from left subtree
        if (left < 0) {
            timer = max(timer, abs(left) + right); // Time to burn right subtree
            return left - 1; // Propagate fire upwards
        }
        
        // Fire coming from right subtree
        if (right < 0) {
            timer = max(timer, left + abs(right)); // Time to burn left subtree
            return right - 1; // Propagate fire upwards
        }
        
        // Normal case: return height
        return 1 + max(left, right);
    }
    
    int minTime(Node* root, int target) {
        int timer = 0;
        Burn(root, timer, target);
        return timer;
    }
};
```

### Example Walkthrough

```
Tree:        1
           /   \
          2     3
         / \     \
        4   5     6
               /
              7

Target = 5
```

**Step-by-step execution:**

1. **Find target node 5**: Fire starts here
2. **Burn downwards**: No children, so 0 time
3. **Propagate to parent 2**: 
   - Fire reaches 2 at time 1
   - Burns left child 4 (1 more second) = Total 2 seconds
4. **Propagate to root 1**:
   - Fire reaches 1 at time 2
   - Burns right subtree (3→6→7) = 3 more seconds
   - Total time = 2 + 3 = 5 seconds

**Answer: 5 seconds**

### Time & Space Complexity
- **Time Complexity**: O(N²) - Height calculation for each node
- **Space Complexity**: O(H) - Recursion stack where H is height
- **Optimized Version**: O(N) time using single traversal

---

## 💰 Maximum Path Sum Between 2 Special Nodes

### Problem Statement
Find the maximum sum path between any two special nodes in a binary tree. A special node is either a leaf node or a node with only one child.

### Key Insights
1. **Special Nodes**: Leaf nodes OR nodes with exactly one child
2. **Path**: Can go through any nodes, but must start and end at special nodes
3. **Strategy**: For each node, consider if it can be the "turning point" of the path

### Algorithm Steps
1. **Base Case**: If node is null, return 0
2. **Leaf Node**: Return node's value (it's a special node)
3. **Internal Node**: Calculate left and right path sums
4. **Both Children Exist**: Update global maximum and return best single path
5. **One Child**: Return sum including the child (node becomes special)

### Code Implementation

```cpp
class Solution {
public:
    int pathSum(Node* root, int& sum) {
        // Base case: null node
        if (!root) return 0;
        
        // Leaf node - special node
        if (!root->left && !root->right) {
            return root->data;
        }
        
        // Calculate path sums from left and right subtrees
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        
        // Both children exist - node can be turning point
        if (root->left && root->right) {
            // Update global maximum (path through this node)
            sum = max(sum, root->data + left + right);
            // Return best single path downwards
            return root->data + max(left, right);
        }
        
        // Only left child exists - current node is special
        if (root->left) {
            return root->data + left;
        }
        
        // Only right child exists - current node is special
        if (root->right) {
            return root->data + right;
        }
        
        return 0; // Should never reach here
    }
    
    int maxPathSum(Node* root) {
        int sum = INT_MIN;
        int val = pathSum(root, sum);
        
        // Edge case: if root has both children, it's not special
        if (root->left && root->right) {
            return sum;
        }
        
        // Root is special, consider it as endpoint
        return max(sum, val);
    }
};
```

### Example Walkthrough

```
Tree:        1
           /   \
          2     3
         /       \
        4         5
       /           \
      6             7

Special nodes: 6, 7 (leaves), 2, 3, 5 (single child)
```

**Path Analysis:**
- Path 6→4→2→1→3→5→7: 6+4+2+1+3+5+7 = 28
- Path 6→4→2: 6+4+2 = 12
- Path 2→1→3→5→7: 2+1+3+5+7 = 18

**Maximum Path Sum: 28**

### Another Example

```
Tree:        10
           /    \
          2      10
         / \       \
        20  1       -25
                   /    \
                  3      4

Special nodes: 20, 1, 3, 4 (leaves), 2 (has both children - NOT special)
```

**Best Path**: 20→2→10→10→(-25)→4 = 20+2+10+10-25+4 = 21

### Time & Space Complexity
- **Time Complexity**: O(N) - Single traversal
- **Space Complexity**: O(H) - Recursion stack

---

## 🎯 Key Concepts

### 1. Tree Traversal Patterns
- **Post-order traversal**: Process children before parent
- **Information propagation**: Pass data upwards through return values
- **Global state**: Use reference parameters for cross-subtree communication

### 2. Return Value Encoding
- **Positive values**: Normal heights/sums
- **Negative values**: Special markers (fire source in burning tree)
- **Multiple meanings**: Same return value serves different purposes

### 3. Edge Case Handling
- **Null nodes**: Always check for null pointers
- **Single nodes**: Handle trees with only root
- **Special root**: Root node might be special in path sum problem

### 4. Optimization Techniques
- **Single traversal**: Avoid multiple passes when possible
- **Early termination**: Stop when target found
- **Memoization**: Cache results for repeated subproblems

---

## 📝 Practice Problems

### Similar Problems to Solve:

1. **Binary Tree Maximum Path Sum** (LeetCode 124)
2. **Diameter of Binary Tree** (LeetCode 543)
3. **Lowest Common Ancestor** (LeetCode 236)
4. **Binary Tree Cameras** (LeetCode 968)
5. **Time to Burn Binary Tree** (GFG)

### Coding Patterns to Master:

1. **Tree DP Pattern**:
   ```cpp
   int solve(Node* root, int& globalResult) {
       if (!root) return baseCase;
       
       int left = solve(root->left, globalResult);
       int right = solve(root->right, globalResult);
       
       // Update global result
       globalResult = max(globalResult, someFunction(left, right, root));
       
       // Return value for parent
       return someOtherFunction(left, right, root);
   }
   ```

2. **Information Propagation Pattern**:
   ```cpp
   int propagate(Node* root, int& globalInfo, int target) {
       if (!root) return 0;
       
       if (root->data == target) {
           // Handle target found
           return specialValue;
       }
       
       int left = propagate(root->left, globalInfo, target);
       int right = propagate(root->right, globalInfo, target);
       
       // Process information from children
       if (left == specialValue || right == specialValue) {
           // Propagate special information
           globalInfo = updateGlobalInfo(globalInfo, left, right);
           return modifiedSpecialValue;
       }
       
       return normalValue;
   }
   ```

### 💡 Pro Tips

1. **Draw the recursion tree** for small examples
2. **Trace through the algorithm** step by step
3. **Handle edge cases** first (null, single node, etc.)
4. **Use meaningful variable names** (leftHeight vs left)
5. **Test with various tree shapes** (balanced, skewed, single path)

---

## 🔍 Summary

Both problems demonstrate advanced tree traversal techniques:

- **Burning Tree**: Uses negative return values to encode fire propagation direction
- **Path Sum**: Uses post-order traversal to consider all possible paths through each node

The key insight is that **information flows both ways** - downwards through parameters and upwards through return values. Master these patterns and you'll be able to solve most tree-based dynamic programming problems!

---

