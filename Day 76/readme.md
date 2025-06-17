# Binary Trees in Data Structures - Day 76 Study Notes

## Table of Contents
- [Introduction](#introduction)
- [What is a Binary Tree?](#what-is-a-binary-tree)
- [Key Terminology](#key-terminology)
- [Properties of Binary Trees](#properties-of-binary-trees)
- [Types of Binary Trees](#types-of-binary-trees)
- [Binary Tree Representation](#binary-tree-representation)
- [Binary Tree Implementation](#binary-tree-implementation)
- [Tree Traversal Methods](#tree-traversal-methods)
- [Examples and Practice](#examples-and-practice)
- [Time and Space Complexity](#time-and-space-complexity)
- [Applications](#applications)

---

## Introduction

A **Binary Tree** is a hierarchical data structure in which each node has at most two children, referred to as the **left child** and **right child**. It's one of the most fundamental data structures in computer science and forms the basis for many other advanced data structures.

---

## What is a Binary Tree?

A binary tree is a tree data structure where:
- Each node has at most 2 children
- Children are labeled as "left child" and "right child"
- The topmost node is called the **root**
- Nodes with no children are called **leaf nodes**

### Visual Representation:
```
       1
      / \
     2   3
    / \   \
   4   5   6
```

---

## Key Terminology

| Term | Definition |
|------|------------|
| **Root** | The topmost node of the tree |
| **Parent** | A node that has child nodes |
| **Child** | A node that has a parent node |
| **Leaf/Terminal Node** | A node with no children |
| **Internal Node** | A node with at least one child |
| **Depth** | Number of edges from root to a particular node |
| **Height** | Number of edges from a node to the deepest leaf |
| **Level** | All nodes at the same depth |
| **Subtree** | A tree formed by a node and its descendants |

---

## Properties of Binary Trees

### 1. **Maximum Nodes at Each Level**
- Level 0 (root): 1 node
- Level 1: 2 nodes
- Level 2: 4 nodes
- Level k: 2^k nodes

### 2. **Maximum Nodes in Tree**
- For a tree of height h: **2^(h+1) - 1** nodes

### 3. **Minimum Height**
- For n nodes: **⌊log₂(n)⌋**

### 4. **Relationship Between Leaf Nodes and Internal Nodes**
- In a binary tree: **L = I + 1** (where L = leaf nodes, I = internal nodes with 2 children)

---

## Types of Binary Trees

### 1. **Full Binary Tree**
- Every node has either 0 or 2 children
- No node has exactly 1 child

```
       1
      / \
     2   3
    / \
   4   5
```

### 2. **Complete Binary Tree**
- All levels are filled except possibly the last level
- Last level is filled from left to right

```
       1
      / \
     2   3
    / \ /
   4  5 6
```

### 3. **Perfect Binary Tree**
- All internal nodes have exactly 2 children
- All leaf nodes are at the same level

```
       1
      / \
     2   3
    / \ / \
   4  5 6  7
```

### 4. **Balanced Binary Tree**
- Height of left and right subtrees differ by at most 1
- Examples: AVL trees, Red-Black trees

### 5. **Degenerate Binary Tree**
- Each internal node has exactly one child
- Essentially becomes a linked list

```
1
 \
  2
   \
    3
     \
      4
```



## Binary Tree Implementation
### Complete Implementation with Level-Order Construction

```cpp
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    
    // Constructor
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    
    BinaryTree() {
        root = NULL;
    }
    
    // Build tree using level-order input
    void buildTree() {
        queue<Node*> q;
        int x, first, second;
        
        cout << "Enter the root element: ";
        cin >> x;
        root = new Node(x);
        q.push(root);
        
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            cout << "Enter the left child of " << temp->data << " (-1 for no child): ";
            cin >> first;
            if (first != -1) {
                temp->left = new Node(first);
                q.push(temp->left);
            }
            
            cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
            cin >> second;
            if (second != -1) {
                temp->right = new Node(second);
                q.push(temp->right);
            }
        }
    }
    
    // Display tree structure
    void displayTree(Node* node, int space = 0) {
        if (node == NULL) return;
        
        space += 10;
        displayTree(node->right, space);
        
        cout << endl;
        for (int i = 10; i < space; i++) cout << " ";
        cout << node->data << endl;
        
        displayTree(node->left, space);
    }
};

int main() {
    BinaryTree tree;
    tree.buildTree();
    
    cout << "\nTree structure:\n";
    tree.displayTree(tree.root);
    
    return 0;
}
```


---

## Examples and Practice

### Example 1: Tree Construction
**Input Sequence**: 1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1

**Resulting Tree**:
```
       1
      / \
     2   3
    / \   \
   4   5   6
      /
     7
```


## Time and Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| **Insertion** | O(n) | O(h) |
| **Deletion** | O(n) | O(h) |
| **Search** | O(n) | O(h) |
| **Traversal** | O(n) | O(h) |

Where:
- n = number of nodes
- h = height of tree
- In worst case: h = n (skewed tree)
- In best case: h = log n (balanced tree)

---

## Applications

### 1. **Expression Trees**
- Represent mathematical expressions
- Evaluate expressions efficiently

### 2. **Binary Search Trees**
- Efficient searching and sorting
- Maintain sorted data

### 3. **Heap Trees**
- Priority queues
- Heap sort algorithm

### 4. **Huffman Coding Trees**
- Data compression
- Optimal prefix codes

### 5. **Decision Trees**
- Machine learning algorithms
- Game theory

### 6. **File System Organization**
- Directory structures
- Hierarchical data representation


## Key Points to Remember

1. **Binary trees are recursive structures** - most operations can be implemented recursively
2. **Queue-based level-order construction** is efficient for building complete trees
3. **Different traversal methods** serve different purposes in algorithms
4. **Height balancing** is crucial for optimal performance
5. **Memory management** is important - don't forget to deallocate nodes
6. **Base cases** in recursive functions prevent infinite recursion



### Input Format for Level-Order Construction
```
Enter root: 1
Enter left child of 1: 2
Enter right child of 1: 3
Enter left child of 2: 4
Enter right child of 2: 5
Enter left child of 3: -1
Enter right child of 3: 6
... continue until all nodes are processed
```


*Happy Learning! 🌳*