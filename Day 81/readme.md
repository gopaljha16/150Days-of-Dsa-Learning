# Binary Tree Iterative Traversals - Complete Guide

## Table of Contents
- [Introduction](#introduction)
- [Tree Structure](#tree-structure)
- [PreOrder Traversal (Iterative)](#preorder-traversal-iterative)
- [PostOrder Traversal (Iterative)](#postorder-traversal-iterative)
- [InOrder Traversal (Iterative)](#inorder-traversal-iterative)
- [Comparison Table](#comparison-table)
- [Practice Problems](#practice-problems)
- [Time & Space Complexity](#time--space-complexity)

## Introduction

Binary tree traversals are fundamental algorithms for visiting all nodes in a binary tree. While recursive approaches are intuitive, iterative implementations using stacks are crucial for understanding the underlying mechanics and avoiding stack overflow issues with deep trees.

### Why Iterative Traversals?
- **Memory Control**: Explicit stack management vs implicit recursion stack
- **Performance**: Better control over memory allocation
- **Deep Trees**: Avoid stack overflow in very deep trees
- **Interview Prep**: Common technical interview questions

## Tree Structure

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

### Example Tree for All Demonstrations
```
        1
       / \
      2   3
     / \   \
    4   5   6
   /
  7
```

## PreOrder Traversal (Iterative)

### Definition
PreOrder traversal visits nodes in the order: **Root → Left → Right**

### Algorithm Steps
1. Initialize stack and result vector
2. Push root to stack
3. While stack is not empty:
   - Pop node from stack
   - Add node's data to result
   - Push right child first (if exists)
   - Push left child second (if exists)

### Why Right First, Then Left?
Stack is LIFO (Last In, First Out), so we push right first to ensure left is processed first.

### Implementation

```cpp
class Solution {
public:
    vector<int> preOrder(Node* root) {
        if (!root) return {};
        
        stack<Node*> st;
        vector<int> result;
        st.push(root);
        
        while (!st.empty()) {
            Node* current = st.top();
            st.pop();
            
            // Process current node
            result.push_back(current->data);
            
            // Push right first, then left
            if (current->right) {
                st.push(current->right);
            }
            if (current->left) {
                st.push(current->left);
            }
        }
        
        return result;
    }
};
```

### Step-by-Step Execution
For our example tree:

| Step | Stack | Current | Result | Action |
|------|-------|---------|--------|--------|
| 1 | [1] | - | [] | Initial |
| 2 | [] | 1 | [1] | Pop 1, push 3,2 |
| 3 | [3] | 2 | [1,2] | Pop 2, push 5,4 |
| 4 | [3,5] | 4 | [1,2,4] | Pop 4, push 7 |
| 5 | [3,5] | 7 | [1,2,4,7] | Pop 7 |
| 6 | [3] | 5 | [1,2,4,7,5] | Pop 5 |
| 7 | [] | 3 | [1,2,4,7,5,3] | Pop 3, push 6 |
| 8 | [] | 6 | [1,2,4,7,5,3,6] | Pop 6 |

**Final Result**: [1, 2, 4, 7, 5, 3, 6]

## PostOrder Traversal (Iterative)

### Definition
PostOrder traversal visits nodes in the order: **Left → Right → Root**

### Algorithm Strategy
Since direct iterative postorder is complex, we use a clever approach:
1. Perform modified preorder: **Root → Right → Left**
2. Reverse the result to get: **Left → Right → Root**

### Implementation

```cpp
class Solution {
public:
    vector<int> postOrder(Node* root) {
        if (!root) return {};
        
        stack<Node*> st;
        vector<int> result;
        st.push(root);
        
        while (!st.empty()) {
            Node* current = st.top();
            st.pop();
            
            // Process current node
            result.push_back(current->data);
            
            // Push left first, then right (opposite of preorder)
            if (current->left) {
                st.push(current->left);
            }
            if (current->right) {
                st.push(current->right);
            }
        }
        
        // Reverse to get postorder
        reverse(result.begin(), result.end());
        return result;
    }
};
```

### Alternative Implementation (Two Stacks)

```cpp
class Solution {
public:
    vector<int> postOrder(Node* root) {
        if (!root) return {};
        
        stack<Node*> st1, st2;
        vector<int> result;
        st1.push(root);
        
        // First stack for traversal, second for result order
        while (!st1.empty()) {
            Node* current = st1.top();
            st1.pop();
            st2.push(current);
            
            if (current->left) {
                st1.push(current->left);
            }
            if (current->right) {
                st1.push(current->right);
            }
        }
        
        // Pop from second stack to get postorder
        while (!st2.empty()) {
            result.push_back(st2.top()->data);
            st2.pop();
        }
        
        return result;
    }
};
```

### Step-by-Step Execution
For our example tree (using reverse method):

**Phase 1 - Modified PreOrder (Root→Right→Left)**:
| Step | Stack | Current | Temp Result |
|------|-------|---------|-------------|
| 1 | [1] | - | [] |
| 2 | [] | 1 | [1] |
| 3 | [2] | 3 | [1,3] |
| 4 | [2] | 6 | [1,3,6] |
| 5 | [4,5] | 2 | [1,3,6,2] |
| 6 | [4] | 5 | [1,3,6,2,5] |
| 7 | [7] | 4 | [1,3,6,2,5,4] |
| 8 | [] | 7 | [1,3,6,2,5,4,7] |

**Phase 2 - Reverse**: [7, 4, 5, 2, 6, 3, 1]

## InOrder Traversal (Iterative)

### Definition
InOrder traversal visits nodes in the order: **Left → Root → Right**

### Algorithm Strategy
We need to track whether a node has been visited before to decide whether to process it or explore its children.

### Implementation (Using Visited Flag)

```cpp
class Solution {
public:
    vector<int> inOrder(Node* root) {
        if (!root) return {};
        
        stack<Node*> nodeStack;
        stack<bool> visitedStack;
        vector<int> result;
        
        nodeStack.push(root);
        visitedStack.push(false);
        
        while (!nodeStack.empty()) {
            Node* current = nodeStack.top();
            nodeStack.pop();
            
            bool visited = visitedStack.top();
            visitedStack.pop();
            
            if (!visited) {
                // First time seeing this node
                // Push in reverse order: Right, Root (visited), Left
                
                if (current->right) {
                    nodeStack.push(current->right);
                    visitedStack.push(false);
                }
                
                // Push current node back with visited flag
                nodeStack.push(current);
                visitedStack.push(true);
                
                if (current->left) {
                    nodeStack.push(current->left);
                    visitedStack.push(false);
                }
            } else {
                // Second time seeing this node - process it
                result.push_back(current->data);
            }
        }
        
        return result;
    }
};
```

### Alternative Implementation (Standard Approach)

```cpp
class Solution {
public:
    vector<int> inOrder(Node* root) {
        stack<Node*> st;
        vector<int> result;
        Node* current = root;
        
        while (current != nullptr || !st.empty()) {
            // Go to leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Process current node
            current = st.top();
            st.pop();
            result.push_back(current->data);
            
            // Move to right subtree
            current = current->right;
        }
        
        return result;
    }
};
```

### Step-by-Step Execution (Using Visited Flag)
For our example tree:

| Step | Node Stack | Visited Stack | Current | Visited? | Result | Action |
|------|------------|---------------|---------|----------|--------|--------|
| 1 | [1] | [false] | - | - | [] | Initial |
| 2 | [] | [] | 1 | false | [] | Push 3(false), 1(true), 2(false) |
| 3 | [3,1,2] | [false,true,false] | 2 | false | [] | Push 5(false), 2(true), 4(false) |
| 4 | [3,1,5,2,4] | [false,true,false,true,false] | 4 | false | [] | Push 4(true), 7(false) |
| 5 | [3,1,5,2,4,7] | [false,true,false,true,true,false] | 7 | false | [] | Push 7(true) |
| 6 | [3,1,5,2,4,7] | [false,true,false,true,true,true] | 7 | true | [7] | Process 7 |
| 7 | [3,1,5,2,4] | [false,true,false,true,true] | 4 | true | [7,4] | Process 4 |
| 8 | [3,1,5,2] | [false,true,false,true] | 2 | true | [7,4,2] | Process 2 |
| 9 | [3,1,5] | [false,true,false] | 5 | false | [7,4,2] | Push 5(true) |
| 10 | [3,1,5] | [false,true,true] | 5 | true | [7,4,2,5] | Process 5 |
| 11 | [3,1] | [false,true] | 1 | true | [7,4,2,5,1] | Process 1 |
| 12 | [3] | [false] | 3 | false | [7,4,2,5,1] | Push 6(false), 3(true) |
| 13 | [3,6,3] | [true,false,true] | 3 | true | [7,4,2,5,1,3] | Process 3 |
| 14 | [6] | [false] | 6 | false | [7,4,2,5,1,3] | Push 6(true) |
| 15 | [6] | [true] | 6 | true | [7,4,2,5,1,3,6] | Process 6 |

**Final Result**: [7, 4, 2, 5, 1, 3, 6]

## Comparison Table

| Traversal | Order | Iterative Strategy | Time | Space |
|-----------|-------|-------------------|------|-------|
| PreOrder | Root→Left→Right | Direct stack simulation | O(n) | O(h) |
| PostOrder | Left→Right→Root | Reverse of Root→Right→Left | O(n) | O(h) |
| InOrder | Left→Root→Right | Visited flag or leftmost first | O(n) | O(h) |

Where `n` = number of nodes, `h` = height of tree


## Time & Space Complexity

### Time Complexity: O(n)
- Each node is visited exactly once
- Stack operations (push/pop) are O(1)
- Total: O(n) where n is the number of nodes

### Space Complexity: O(h)
- Stack space proportional to height of tree
- Best case (balanced tree): O(log n)
- Worst case (skewed tree): O(n)
- Where h is the height of the tree

## Key Points to Remember

1. **PreOrder**: Push right first, then left (stack is LIFO)
2. **PostOrder**: Use reverse technique or two stacks
3. **InOrder**: Track visited nodes or use leftmost-first approach
4. **Stack Management**: Always check for null pointers before pushing
5. **Edge Cases**: Handle empty trees and single-node trees
6. **Memory**: Iterative approaches give better control over memory usage

## Common Mistakes to Avoid

1. **Null Pointer Access**: Always check if node exists before accessing
2. **Wrong Push Order**: Remember stack is LIFO - order matters
3. **Infinite Loops**: Ensure proper termination conditions
4. **Memory Leaks**: In languages like C++, manage memory properly
5. **Edge Cases**: Don't forget empty tree cases

---

*These implementations are optimized for clarity and efficiency. Practice with different tree structures to master the concepts!*