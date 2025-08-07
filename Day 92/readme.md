# AVL Tree Implementation in C++

## Overview

This code implements an **AVL (Adelson-Velsky and Landis) Tree**, which is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one. If at any time they differ by more than one, rebalancing is done to restore this property through rotations.

**Key Features:**
- Self-balancing binary search tree
- Guarantees O(log n) height
- Supports insertion with automatic balancing
- Uses rotations to maintain balance factor

---

## Code Structure

### 1. Node Class Definition

```cpp
class Node {
    public:
    int data , height;
    Node *left , *right; 

    Node(int val){
      data=val;
      height=1;
      left=right=NULL;
    }
};
```

**Explanation:**
- `data`: Stores the value of the node
- `height`: Stores the height of the subtree rooted at this node
- `left`, `right`: Pointers to left and right child nodes
- Constructor initializes a new node with given value, height 1, and null children

### 2. Height Calculation Function

```cpp
int getHeight(Node *root){
    //null
    if(!root)
     return 0;
    
    //exists
    return root->height;
}
```

**Purpose:** Returns the height of a node (0 for null nodes)

### 3. Balance Factor Calculation

```cpp
int getBalance(Node *root){
    return getHeight(root->left)-getHeight(root->right);
}
```

**Purpose:** Calculates balance factor = height(left subtree) - height(right subtree)
- **Balance Factor > 1:** Left-heavy (needs right rotation)
- **Balance Factor < -1:** Right-heavy (needs left rotation)
- **Balance Factor ∈ [-1, 1]:** Balanced

### 4. Right Rotation Function

```cpp
Node *rightRotation(Node *root){
  Node *child = root->left;
  Node *childRight = child->right;

  //update
  child->right = root;
  root->left = childRight;

  //update height
  root->height = 1+max(getHeight(root->left),getHeight(root->right));
  child->height = 1+max(getHeight(child->left) , getHeight(child->right));

  return child;
}
```

**Purpose:** Performs right rotation to fix left-heavy imbalance

**Visual Representation:**
```
    Before Right Rotation:        After Right Rotation:
         A                              B
        / \                            / \
       B   C          -->             D   A
      / \                                / \
     D   E                              E   C
```

### 5. Left Rotation Function

```cpp
Node *leftRotation(Node *root){
    Node *child = root->right;
    Node *childLeft = child->left;

    //update
    child->left = root;
    root->right = childLeft;

    //update height
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left) , getHeight(child->right));

    return child;
}
```

**Purpose:** Performs left rotation to fix right-heavy imbalance

**Visual Representation:**
```
    Before Left Rotation:         After Left Rotation:
         A                              B
        / \                            / \
       C   B          -->             A   E
          / \                        / \
         D   E                      C   D
```

### 6. Insert Function (Core AVL Logic)

```cpp
Node * insert(Node *root , int key){
    //null root doesn't exists
    if(!root)
     return new Node(key);

     //exists then comparision
     //left side
     if(key<root->data){
        root->left = insert(root->left , key);
     }
     else if(key>root->data){
        root->right = insert(root->right , key);
     }else{
        //no duplicate
        return root;
     }

     //update height
     root->height = 1+max(getHeight(root->left),getHeight(root->right));

     //balancing 
     int balance = getBalance(root);

    //unbalanced - 4 cases
    //left left case
    if(balance>1 && key<root->left->data){
        return rightRotation(root);
    }
    //right right case
    else if(balance<-1 && root->right->data<key){
        return leftRotation(root);
    }
    //left right
    else if(balance>1 && key>root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right left case 
    else if(balance<-1 && root->right->data>key){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }else{
        //no rotation 
        return root;
    }
}
```

**Four Rotation Cases:**

| Case | Condition | Solution |
|------|-----------|----------|
| Left-Left (LL) | `balance > 1 && key < root->left->data` | Right Rotation |
| Right-Right (RR) | `balance < -1 && key > root->right->data` | Left Rotation |
| Left-Right (LR) | `balance > 1 && key > root->left->data` | Left + Right Rotation |
| Right-Left (RL) | `balance < -1 && key < root->right->data` | Right + Left Rotation |

### 7. Traversal Functions

```cpp
void preorder(Node *root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
```

---

## Example Input and Expected Output

### Input Sequence:
```cpp
insert(root, 10);
insert(root, 20);
insert(root, 9);
insert(root, 6);
insert(root, 12);
insert(root, 25);
insert(root, 90);
insert(root, 3);
```

### Expected Output:
```
Pre order: 10 6 3 9 20 12 25 90 
in order: 3 6 9 10 12 20 25 90 
```

---

## Step-by-Step Dry Run

Let's trace through inserting the first few values:

### Step 1: Insert 10
```
Tree: 10 (height=1, balance=0)
```

### Step 2: Insert 20
```
Tree: 
   10
    \
     20
Balance factors: 10(balance=-1), 20(balance=0) → Balanced
```

### Step 3: Insert 9
```
Tree:
    10
   /  \
  9    20
Balance factors: 10(balance=0), 9(balance=0), 20(balance=0) → Balanced
```

### Step 4: Insert 6
```
Tree:
    10
   /  \
  9    20
 /
6

Balance factors: 10(balance=1), 9(balance=1), 20(balance=0), 6(balance=0) → Balanced
```

### Step 5: Insert 12
```
Tree:
     10
   /    \
  9      20
 /      /
6      12

All nodes remain balanced
```

### Step 6: Insert 25
```
Tree:
     10
   /    \
  9      20
 /      /  \
6      12   25

All nodes remain balanced
```

### Step 7: Insert 90
```
Before balancing:
     10
   /    \
  9      20
 /      /  \
6      12   25
            \
             90

Node 20: balance = 0 - 2 = -2 (Right-heavy!)
Node 25: balance = 0 - 1 = -1
This triggers RR case: Left rotation at node 20

After left rotation:
     10
   /    \
  9      25
 /      /  \
6      20   90
      /
     12
```

### Final Tree Structure:
```
         10
       /    \
      6      20
     / \    /  \
    3   9  12  25
              \
               90
```

---

## Visual Tree Diagram (Final Result)

```
                    10
                  /    \
                 6      20  
                / \    /  \
               3   9  12  25
                         \
                         90

Height: 4
All balance factors ∈ [-1, 1]
```

---

## Algorithm Flowchart

```
START INSERT(root, key)
         |
    [Is root NULL?] ──YES──> Create new Node(key)
         |                        |
        NO                      RETURN
         |
    [key < root->data?] ──YES──> INSERT(root->left, key)
         |                        |
        NO                       └─┐
         |                         |
    [key > root->data?] ──YES──> INSERT(root->right, key)
         |                        |
        NO                       └─┤
         |                         |
    Return root                    |
    (duplicate)                    |
                                  |
                            Update Heights
                                  |
                         Calculate Balance
                                  |
                          [Balance > 1?] ──YES──> LL or LR Case
                                  |                     |
                                 NO                  Rotate
                                  |                     |
                          [Balance < -1?] ──YES──> RR or RL Case
                                  |                     |
                                 NO                  Rotate
                                  |                     |
                            Return root ←─────────────┘
```

---

## Time and Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert | O(log n) | O(log n) - recursion |
| Search | O(log n) | O(log n) - recursion |
| Height Calculation | O(1) | O(1) |
| Rotation | O(1) | O(1) |

**Why O(log n)?** 
AVL trees maintain balance, ensuring the height is always O(log n), which bounds all operations.

---

## Summary

This AVL tree implementation provides:

1. **Automatic Balancing**: Maintains balance factor ∈ [-1, 1] for all nodes
2. **Four Rotation Types**: LL, RR, LR, RL to handle different imbalance scenarios
3. **Efficient Operations**: All operations run in O(log n) time
4. **No Duplicates**: Prevents insertion of duplicate values
5. **Height Tracking**: Each node maintains its subtree height for quick balance calculations

The key insight is that AVL trees sacrifice some insertion/deletion time (due to rotations) to guarantee optimal search time by maintaining a balanced structure. This makes them ideal for applications with frequent searches and occasional insertions.