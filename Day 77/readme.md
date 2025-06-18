# Binary Tree in Data Structure - Complete Notes 🌳

## Table of Contents
- [Introduction](#introduction)
- [Basic Concepts](#basic-concepts)
- [Binary Tree Structure](#binary-tree-structure)
- [Binary Tree Creation](#binary-tree-creation)
- [Tree Traversal Methods](#tree-traversal-methods)
- [Code Implementations](#code-implementations)
- [Practice Problems](#practice-problems)
- [Time & Space Complexity](#time--space-complexity)


## Introduction

A **Binary Tree** is a hierarchical data structure where each node has at most two children, referred to as the **left child** and **right child**. It's one of the most fundamental data structures in computer science.

### Key Properties:
- Each node contains data and pointers to left and right children
- Maximum of 2 children per node
- Root node is the topmost node
- Leaf nodes have no children
- Height of tree = longest path from root to leaf

## Basic Concepts

### Terminology
- **Node**: Basic unit containing data and pointers
- **Root**: Topmost node of the tree
- **Parent**: Node that has children
- **Child**: Node connected below another node
- **Leaf**: Node with no children
- **Subtree**: Tree formed by a node and its descendants
- **Height**: Maximum depth of the tree
- **Depth**: Distance from root to a particular node

### Types of Binary Trees
1. **Full Binary Tree**: Every node has either 0 or 2 children
2. **Complete Binary Tree**: All levels filled except possibly the last
3. **Perfect Binary Tree**: All internal nodes have 2 children, all leaves at same level
4. **Balanced Binary Tree**: Height difference between left and right subtrees ≤ 1

## Binary Tree Structure

```cpp
class Node {
public:
    int data;           // Data stored in node
    Node *left;         // Pointer to left child
    Node *right;        // Pointer to right child
    
    // Constructor
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
```

## Binary Tree Creation

### Method 1: Manual Creation
```cpp
Node* createTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}
```

### Method 2: Recursive Input Method
```cpp
Node* BinaryTree() {
    int x;
    cout << "Enter node value (-1 for NULL): ";
    cin >> x;
    
    // Base case: -1 indicates NULL node
    if (x == -1) {
        return NULL;
    }
    
    // Create new node
    Node *temp = new Node(x);
    
    // Recursively create left subtree
    cout << "Enter the left child of " << x << ": ";
    temp->left = BinaryTree();
    
    // Recursively create right subtree
    cout << "Enter the right child of " << x << ": ";
    temp->right = BinaryTree();
    
    return temp;
}
```

## Tree Traversal Methods

Tree traversal is the process of visiting all nodes in a tree in a specific order.

### 1. Preorder Traversal (NLR)
**Order**: Node → Left → Right

```cpp
void preOrder(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    
    // Process current node
    cout << root->data << " ";
    
    // Traverse left subtree
    preOrder(root->left);
    
    // Traverse right subtree
    preOrder(root->right);
}
```

**Use Cases**: 
- Creating a copy of the tree
- Getting prefix expression of expression tree

### 2. Inorder Traversal (LNR)
**Order**: Left → Node → Right

```cpp
void inOrder(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    
    // Traverse left subtree
    inOrder(root->left);
    
    // Process current node
    cout << root->data << " ";
    
    // Traverse right subtree
    inOrder(root->right);
}
```

**Use Cases**:
- Binary Search Trees give sorted order
- Getting infix expression of expression tree

### 3. Postorder Traversal (LRN)
**Order**: Left → Right → Node

```cpp
void postOrder(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    
    // Traverse left subtree
    postOrder(root->left);
    
    // Traverse right subtree
    postOrder(root->right);
    
    // Process current node
    cout << root->data << " ";
}
```

**Use Cases**:
- Deleting nodes from tree
- Getting postfix expression of expression tree
- Calculating space used by tree

### 4. Level Order Traversal (BFS)
**Order**: Level by level from left to right

```cpp
#include <queue>

void levelOrder(Node* root) {
    if (root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        cout << current->data << " ";
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
```

## Code Implementations

### Complete Binary Tree Implementation

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    
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
    
    // Create tree using recursive input
    Node* createTree() {
        int x;
        cin >> x;
        
        if (x == -1) return NULL;
        
        Node *temp = new Node(x);
        cout << "Enter left child of " << x << ": ";
        temp->left = createTree();
        cout << "Enter right child of " << x << ": ";
        temp->right = createTree();
        
        return temp;
    }
    
    // Traversal Methods
    void preOrder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void inOrder(Node* root) {
        if (root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    
    void postOrder(Node* root) {
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    
    void levelOrder(Node* root) {
        if (root == NULL) return;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
    
    // Utility functions
    int height(Node* root) {
        if (root == NULL) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
    
    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int countLeaves(Node* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
};

int main() {
    BinaryTree bt;
    
    cout << "Enter the root node: ";
    bt.root = bt.createTree();
    
    cout << "\nPreorder: ";
    bt.preOrder(bt.root);
    
    cout << "\nInorder: ";
    bt.inOrder(bt.root);
    
    cout << "\nPostorder: ";
    bt.postOrder(bt.root);
    
    cout << "\nLevel order: ";
    bt.levelOrder(bt.root);
    
    cout << "\nHeight: " << bt.height(bt.root);
    cout << "\nTotal nodes: " << bt.countNodes(bt.root);
    cout << "\nLeaf nodes: " << bt.countLeaves(bt.root);
    
    return 0;
}
```

## Practice Problems

### GeeksforGeeks Style Solutions

#### 1. Preorder Traversal
```cpp
class Solution {
public:
    void preorderHelper(Node* root, vector<int>& result) {
        if (root == NULL) return;
        
        result.push_back(root->data);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
};
```

#### 2. Inorder Traversal
```cpp
class Solution {
public:
    void inorderHelper(Node* root, vector<int>& result) {
        if (root == NULL) return;
        
        inorderHelper(root->left, result);
        result.push_back(root->data);
        inorderHelper(root->right, result);
    }
    
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};
```

#### 3. Postorder Traversal
```cpp
class Solution {
public:
    void postorderHelper(Node* root, vector<int>& result) {
        if (root == NULL) return;
        
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
};
```

## Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Creation | O(n) | O(h) |
| Traversal | O(n) | O(h) |
| Search | O(n) | O(h) |
| Insertion | O(1) | O(1) |
| Deletion | O(n) | O(h) |

Where:
- n = number of nodes
- h = height of tree
- For balanced tree: h = O(log n)
- For skewed tree: h = O(n)

