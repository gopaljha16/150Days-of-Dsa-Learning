
# Day93: AVL Tree Deletion — Theory, Dry Run & C++ Implementation

---

# Chatgpt Response Notes: 

## The Code (cleaned & ready-to-read)

```cpp
// Day93: AVL Tree Deletion (GfG-style)
// Node structure
struct Node {
    int data, height;
    Node *left, *right;
    Node(int x) {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

// Helpers
int getHeight(Node *root){
    if(!root) return 0;
    return root->height;
}

int getBalance(Node *root){
    if(!root) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// Right rotation (rotate-down on root; child = root->left)
Node *rightRotation(Node *root){
    Node *child = root->left;
    Node *childRight = child->right;

    // perform rotation
    child->right = root;
    root->left = childRight;

    // update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child; // new root of this subtree
}

// Left rotation (mirror of rightRotation)
Node *leftRotation(Node *root){
    Node *child = root->right;
    Node *childLeft = child->left;

    // perform rotation
    child->left = root;
    root->right = childLeft;

    // update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child; // new root of this subtree
}

// Main deletion function
Node* deleteNode(Node* root, int key) {
    // 1. Standard BST deletion search:
    if(!root) return NULL;

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // root->data == key -> delete this node

        // Case A: leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // Case B: only left child exists
        else if(root->left && !root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Case C: only right child exists
        else if(root->right && !root->left) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Case D: two children -> replace with inorder successor (smallest in right subtree)
        else {
            Node *curr = root->right;
            while(curr->left) curr = curr->left;
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // 2. Update height after deletion in subtrees
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Check balance and perform rotations if required
    int balance = getBalance(root);

    // Left-heavy
    if(balance > 1){
        // Left-Left (LL)
        if(getBalance(root->left) >= 0)
            return rightRotation(root);

        // Left-Right (LR)
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right-heavy
    else if(balance < -1){
        // Right-Right (RR)
        if(getBalance(root->right) <= 0)
            return leftRotation(root);

        // Right-Left (RL)
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // Balanced
    return root;
}
```

---

# Detailed explanation (section-wise / line-by-line where important)

> I group lines into small logical blocks for clarity (helpers, rotations, BST deletion, rebalancing).

### `struct Node`

* `data`: stored key
* `height`: height of subtree rooted at this node (leaf has height 1)
* `left`, `right`: child pointers
* Constructor sets `height = 1` for a new leaf.

### `getHeight(Node *root)`

* Returns `0` if `root == NULL` (convention: empty subtree height = 0).
* Otherwise returns `root->height`.
* Used to compute heights quickly without repeated recursion.

### `getBalance(Node *root)`

* Returns `height(left) - height(right)`.
* Sign:

  * `> 0` → left subtree is taller
  * `< 0` → right subtree is taller
  * `0` → balanced at this node

### Rotations

**Purpose:** Restore AVL balance while preserving BST property.

#### `rightRotation(root)`

Preconditions:

* The subtree rooted at `root` is left-heavy and we want to rotate right.
  Mechanics:

```
    root                  child
    /    ---right-->    /    \
  child               child.left  root
    \                             /
   childRight                 childRight
```

Implementation steps:

1. Save `child = root->left` and `childRight = child->right`.
2. `child->right = root; root->left = childRight;`
3. Recompute heights of `root` then `child`:

   * `root->height = 1 + max(h(root->left), h(root->right))`
   * `child->height = 1 + max(h(child->left), h(child->right))`
4. Return `child` (new root of subtree).

#### `leftRotation(root)`

Mirror of `rightRotation`:

1. `child = root->right; childLeft = child->left;`
2. `child->left = root; root->right = childLeft;`
3. Update heights (root then child).
4. Return `child`.

**Important:** Always update the child-subtree heights after rearranging children. The code updates `root` height first (child now lower) then `child` height.

### `deleteNode(root, key)` — high level

1. **BST search:** If `key < root->data`, recurse to `root->left`. If larger, recurse to `root->right`.
2. **Delete node when found:**

   * **Leaf:** delete and return `NULL`.
   * **One child:** return the non-NULL child (and delete current node).
   * **Two children:** find inorder successor (`min` in right subtree), copy its `data` to current node, and delete the successor node recursively from `root->right`.
3. **After deletion in subtree:** update `root->height`.
4. **Check `balance = getBalance(root)` and rebalance**:

   * `balance > 1` → left-heavy:

     * If `getBalance(root->left) >= 0` → **LL** → `rightRotation(root)`.
     * Else **LR** → `root->left = leftRotation(root->left); rightRotation(root)`.
   * `balance < -1` → right-heavy:

     * If `getBalance(root->right) <= 0` → **RR** → `leftRotation(root)`.
     * Else **RL** → `root->right = rightRotation(root->right); leftRotation(root)`.

**Why use successor from right subtree when deleting a two-child node?**

* The inorder successor (smallest node in right subtree) is the next larger element. Replacing `root->data` with successor preserves BST ordering; then we remove that successor node (which has at most one child).

---

## Rotation case quick reference

| Unbalanced at `root`                                            |             Child balance (checked) | Action                                                      |
| --------------------------------------------------------------- | ----------------------------------: | ----------------------------------------------------------- |
| `balance > 1` (left-heavy) and `getBalance(root->left) >= 0`    |   left child balanced or left-heavy | Right rotation (LL)                                         |
| `balance > 1` and `getBalance(root->left) < 0`                  |                     left-right case | `leftRotation(root->left)` then `rightRotation(root)` (LR)  |
| `balance < -1` (right-heavy) and `getBalance(root->right) <= 0` | right child balanced or right-heavy | Left rotation (RR)                                          |
| `balance < -1` and `getBalance(root->right) > 0`                |                     right-left case | `rightRotation(root->right)` then `leftRotation(root)` (RL) |

---

## Example Input(s) and Expected Output(s)

We'll use this concrete example (popular GfG AVL example):

**Operations**

1. Insert keys in this order:
   `9, 5, 10, 0, 6, 11, -1, 1, 2`
   (assume an AVL insertion routine has already built a valid AVL tree)
2. Then **delete** the key `10`.

**Inorder traversal (sorted)**

* Before deletion: `[-1, 0, 1, 2, 5, 6, 9, 10, 11]`
* After deletion:  `[-1, 0, 1, 2, 5, 6, 9, 11]`

**ASCII tree (with node heights) — BEFORE deletion (root = 9)**

```
            9 (h=4)
          /   \
      1(h=3)  10(h=2)
      /   \      \
  0(h=2) 5(h=2)  11(h=1)
  /      /  \
-1(h=1)2(h=1)6(h=1)
```

**ASCII tree — AFTER deleting 10**
(Here the tree rebalances; final root becomes `1` after rotation)

```
         1 (h=4)
       /   \
   0(h=2)  9(h=3)
   /       /   \
-1(h=1) 5(h=2) 11(h=1)
         / \
       2(h1)6(h1)
```

**Expected console-ish output** (if you print inorder before/after):

```
Inorder before deletion: -1 0 1 2 5 6 9 10 11
Deleting 10...
Inorder after deletion:  -1 0 1 2 5 6 9 11
```

---

## Step-by-step dry run (delete key = `10`)

We walk through `deleteNode(root = node 9, key = 10)` on the initial tree above.

**Initial snapshot**

* `root = 9`

  * `root->left = 1 (h=3)`, `root->right = 10 (h=2)`

**1) Search path**

* Compare `10` with `9`: `10 > 9` → go right: call `deleteNode(root->right, 10)` where `root->right` is node `10`.

**2) At node 10**

* `root = 10`, key matches (`10 == root->data`).
* Check children of `10`:

  * left child: `NULL`
  * right child: `11`
* This is **one-child case** (only right child present) → we return `root->right` to the parent and delete the `10` node.
* So the right child of original `9` becomes `11`. (Effectively the `10` node is removed and replaced by `11`.)

**3) Back at node 9 — update & rebalance**

* After the recursive delete returns, at `root = 9` we update:

  * `root->height = 1 + max(getHeight(left), getHeight(right))`

    * left height = height(1) = 3
    * right height = height(11) = 1  → `root->height = 1 + max(3,1) = 4`
  * `balance = getHeight(left) - getHeight(right) = 3 - 1 = 2` → **left-heavy** (unbalanced)
* Determine rotation type:

  * Check `getBalance(root->left)` which is `getBalance(1)`:

    * `getBalance(1) = getHeight(1->left) - getHeight(1->right) = 2 - 2 = 0` → **>= 0**
  * So we are in **Left-Left (LL)** case.

**4) Perform rotation**

* For **LL**, do a single **right rotation** on `root` (node `9`):

  * Let `child = root->left` (node `1`)
  * `childRight = child->right` (node `5`)
  * Rotation steps:

    * `child->right = root;` // 1->right becomes 9
    * `root->left = childRight;` // 9->left becomes 5
    * Update `root->height` and `child->height` accordingly
* The new subtree root becomes `child` (`1`). So overall tree root becomes `1`.

**5) Final result**

* New root (of whole tree) is `1`.
* Tree structure after rotation matches the “AFTER” ASCII diagram shown earlier.
* Inorder traversal now yields `[-1, 0, 1, 2, 5, 6, 9, 11]`.

---

## Visuals: rotation diagrams (ASCII)

### Right Rotation (LL case)

Before rotation:

```
    z                       y
   / \                     / \
  y   T4    --RR-->       x   z
 / \                         / \
x  T3                      T3  T4
/ \
T1 T2
```

After `rightRotation(z)`:

* `y` becomes the new root of this subtree.
* `z` becomes `y->right`.
* `x` stays `y->left`.
* `T3` becomes `z->left`.

### Left Rotation (RR case) — mirror

Before:

```
  z                         y
 / \                       / \
T1  y       --LR-->       z   x
    / \                 / \
   T2  x               T1  T2
```

---

## Quick checklist: common pitfalls & gotchas

* **Height values** must be updated after every structural change (rotation or delete). The code updates `root` then `child` after rotation — that's correct.
* When deleting a node with **two children**, copying data from the **inorder successor** and then deleting that successor avoids needing to reorganize both subtrees.
* Use `getHeight(NULL) = 0` consistent convention — ensures `leaf.height == 1`.
* Be careful to test all 4 rotation cases in unit tests (LL, LR, RR, RL) — deletion can create any of them.

---

## Complexity

* **Search + delete (BST part):** O(h) where h = height of tree
* **Height of AVL tree:** O(log n)
* **Overall deletion cost:** **O(log n)** per delete (since you may need at most O(1) rotations on the path back up, and height updates / rotations are O(1) each).
* **Space:** O(h) due to recursion stack — O(log n) typically.

---

## Small C++ test harness (manual construction)

If you want to test just the delete function without implementing AVL insert, you can manually create nodes and link them to match the “before” tree and then call `deleteNode`:

```cpp
// Add a helper inorder print
void inorderPrint(Node* root) {
    if(!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// Example main (pseudo)
int main(){
    // Construct nodes
    Node* n9 = new Node(9);
    Node* n1 = new Node(1);
    Node* n10 = new Node(10);
    Node* n0 = new Node(0);
    Node* n5 = new Node(5);
    Node* n11 = new Node(11);
    Node* n_1 = new Node(-1);
    Node* n2 = new Node(2);
    Node* n6 = new Node(6);

    // Link to recreate BEFORE-deletion tree (heights must match example)
    n9->left = n1; n9->right = n10; n9->height = 4;
    n1->left = n0; n1->right = n5; n1->height = 3;
    n0->left = n_1; n0->height = 2;
    n5->left = n2; n5->right = n6; n5->height = 2;
    n10->right = n11; n10->height = 2;
    // n11, n2, n6, n_1 are leaves (height = 1 already)

    Node* root = n9;
    cout << "Before: ";
    inorderPrint(root); cout << "\n";

    root = deleteNode(root, 10);

    cout << "After delete(10): ";
    inorderPrint(root); cout << "\n";
    return 0;
}
```

(Expected inorder before/after shown earlier.)

---

## Summary

* The provided code performs **AVL deletion**: it finds the node to delete (BST style), handles the 3 deletion cases (leaf, one child, two children), updates heights, and then **rebalance** the subtree using rotations.
* Rebalancing uses the standard LL, LR, RR, RL patterns depending on subtree balances.
* Deletion is O(log n) time in AVL trees.
* The dry run (delete 10) showed a **single right rotation** correcting a left-heavy imbalance, and final inorder confirms the node was removed and tree remains an AVL.

---

# Claude Response 

# AVL Tree Deletion Implementation

## Overview

This code implements the deletion operation for an AVL (Adelson-Velsky and Landis) tree, which is a self-balancing binary search tree. The AVL tree maintains its balance by ensuring that for any node, the heights of its left and right subtrees differ by at most 1. When this balance condition is violated after deletion, the tree performs rotations to restore balance.

## Table of Contents
- [Node Structure](#node-structure)
- [Helper Functions](#helper-functions)
- [Rotation Functions](#rotation-functions)
- [Main Deletion Function](#main-deletion-function)
- [Example Usage](#example-usage)
- [Step-by-Step Walkthrough](#step-by-step-walkthrough)
- [Visual Diagrams](#visual-diagrams)
- [Summary](#summary)

## Node Structure

```cpp
struct Node {
    int data, height;
    Node *left, *right;
    Node(int x) {
        data = x;
        height = 1;
        left = right = NULL;
    }
};
```

Each node contains:
- `data`: The value stored in the node
- `height`: The height of the subtree rooted at this node
- `left`, `right`: Pointers to left and right children

## Helper Functions

### getHeight Function
```cpp
int getHeight(Node *root) {
    if(!root)
        return 0;
    return root->height;
}
```
**Purpose**: Returns the height of a node (0 if null)

### getBalance Function
```cpp
int getBalance(Node *root) {
    return getHeight(root->left) - getHeight(root->right);
}
```
**Purpose**: Calculates the balance factor of a node
- **Positive value**: Left subtree is taller
- **Negative value**: Right subtree is taller
- **Zero**: Both subtrees have equal height

## Rotation Functions

### Right Rotation
```cpp
Node *rightRotation(Node *root) {
    Node *child = root->left;
    Node *childRight = child->right;

    // Perform rotation
    child->right = root;
    root->left = childRight;

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}
```

**Visual representation:**
```
Before Right Rotation:     After Right Rotation:
      A                           B
     / \                         / \
    B   C          →            D   A
   / \                             / \
  D   E                           E   C
```

### Left Rotation
```cpp
Node *leftRotation(Node *root) {
    Node *child = root->right;
    Node *childLeft = child->left;

    // Perform rotation
    child->left = root;
    root->right = childLeft;

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}
```

**Visual representation:**
```
Before Left Rotation:      After Left Rotation:
    A                           C
   / \                         / \
  B   C          →            A   E
     / \                     / \
    D   E                   B   D
```

## Main Deletion Function

```cpp
Node* deleteNode(Node* root, int key) {
    // Step 1: Standard BST deletion
    if(!root) {
        return NULL;
    }
    
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node to be deleted found
        if(!root->left && !root->right) {
            // Case 1: Leaf node
            delete root;
            return NULL;
        }
        else if(!root->right && root->left) {
            // Case 2a: Only left child exists
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right && !root->left) {
            // Case 2b: Only right child exists
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else {
            // Case 3: Both children exist
            // Find inorder successor (smallest in right subtree)
            Node *curr = root->right;
            while(curr->left) {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    
    // Step 2: Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    // Step 3: Check balance and perform rotations
    int balance = getBalance(root);
    
    // Left Heavy (balance > 1)
    if(balance > 1) {
        if(getBalance(root->left) >= 0) {
            // Left-Left case
            return rightRotation(root);
        }
        // Left-Right case
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Heavy (balance < -1)
    else if(balance < -1) {
        if(getBalance(root->right) <= 0) {
            // Right-Right case
            return leftRotation(root);
        }
        // Right-Left case
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    
    // No rotation needed
    return root;
}
```

## Example Usage

Let's consider an AVL tree and demonstrate deletion:

**Initial AVL Tree:**
```
        10
       /  \
      5    15
     / \   / \
    2   7 12  20
```

**Example Input:** Delete node with value 5

**Expected Output:** A balanced AVL tree without node 5

## Step-by-Step Walkthrough

Let's walk through deleting node **5** from the above tree:

### Step 1: Locate the node to delete
1. Start at root (10): 5 < 10, go left
2. Reach node (5): 5 == 5, found the node to delete

### Step 2: Handle deletion (Case 3 - both children exist)
1. Node 5 has both left (2) and right (7) children
2. Find inorder successor: smallest node in right subtree of 5
   - Go to right child (7)
   - 7 has no left child, so 7 is the inorder successor
3. Replace node 5's data with 7: `root->data = 7`
4. Delete the original node 7: `deleteNode(root->right, 7)`

### Step 3: Tree after replacement
```
        10
       /  \
      7    15
     /     / \
    2     12  20
```

### Step 4: Update heights and check balance
1. Update height of node 7: `height = 1 + max(1, 0) = 2`
2. Update height of node 10: `height = 1 + max(2, 2) = 3`
3. Check balance of node 7: `balance = 1 - 0 = 1` (balanced)
4. Check balance of node 10: `balance = 2 - 2 = 0` (balanced)

### Final Result
```
        10
       /  \
      7    15
     /     / \
    2     12  20
```

## Visual Diagrams

### Deletion Cases

| Case | Description | Before | After |
|------|-------------|---------|--------|
| 1 | Leaf node | `→ [X] ←` | `→ NULL ←` |
| 2a | Only left child | `→ [X] → [L]` | `→ [L]` |
| 2b | Only right child | `[R] ← [X] ←` | `← [R] ←` |
| 3 | Both children | `[L] ← [X] → [R]` | `[L] ← [S] → [R']` |

### Balance Conditions

```
Balance Factor = Height(Left) - Height(Right)

Balanced: -1 ≤ balance ≤ 1
Left Heavy: balance > 1    (Need right rotation)
Right Heavy: balance < -1  (Need left rotation)
```

### Rotation Patterns

```
Left-Left (LL):     Left-Right (LR):    Right-Right (RR):   Right-Left (RL):
     A                   A                    A                   A
    /        →          /         →          \        →          \         →
   B                   B                      B                   B
  /                     \                      \                 /
 C                       C                      C               C
```

## Time and Space Complexity

- **Time Complexity**: O(log n) - Due to the balanced nature of AVL trees
- **Space Complexity**: O(log n) - Due to recursive call stack

## Summary

This AVL tree deletion implementation ensures that the tree remains balanced after every deletion operation. The key steps are:

1. **Standard BST Deletion**: Handle three cases based on the number of children
2. **Height Update**: Recalculate heights bottom-up during recursion
3. **Balance Check**: Calculate balance factor for each node
4. **Rotations**: Perform appropriate rotations to maintain AVL property

The algorithm maintains the AVL tree's key property that the height difference between left and right subtrees never exceeds 1, ensuring O(log n) operations for search, insertion, and deletion.