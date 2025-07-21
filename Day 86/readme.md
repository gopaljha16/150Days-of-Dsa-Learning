# Binary Search Tree (BST) - Complete Implementation

## Overview

This code demonstrates a complete implementation of a Binary Search Tree (BST) data structure in C++. A BST is a hierarchical data structure where each node has at most two children, and for every node:
- All values in the left subtree are less than the node's value
- All values in the right subtree are greater than or equal to the node's value

The implementation includes insertion, searching, deletion operations, and handles duplicate values by placing them in the right subtree.

## Code Structure

### 1. Node Class Definition

```cpp
class Node{
    public:
    int data;
    Node *left , *right;

    //constructor
    Node (int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
```

**Explanation:**
- `data`: Stores the integer value of the node
- `left`: Pointer to the left child node
- `right`: Pointer to the right child node
- **Constructor**: Initializes a new node with the given value and sets both child pointers to NULL

### 2. Insertion Function

```cpp
Node * insert(Node *root , int target){
    //base case
    if(!root){
        Node *temp = new Node(target);
        return temp;
    }

    //left then right subtree
    if(target < root->data){
        root->left = insert(root->left , target);
    }else{
        root->right = insert(root->right , target);
    }

    return root;
}
```

**Line-by-Line Explanation:**
1. **Base Case**: If root is NULL (empty tree or reached a leaf), create a new node
2. **Left Insertion**: If target is less than current node's data, insert in left subtree
3. **Right Insertion**: If target is greater than or equal to current node's data, insert in right subtree
4. **Return**: Return the root of the modified tree

**Note**: Duplicates are handled by placing them in the right subtree (target >= root->data goes right)

### 3. Search Function

```cpp
bool search(Node *root , int target){
    //base case
    if(!root)
     return 0;
    
     //if element found
     if(root->data==target)
      return 1;

    //if not found but could be present in left or right
    if(root->data > target){ //left side
        return search(root->left , target);
    }else{
        return search(root->right , target); //right side
    }
}
```

**Line-by-Line Explanation:**
1. **Base Case**: If root is NULL, element not found, return false (0)
2. **Found**: If current node's data equals target, return true (1)
3. **Left Search**: If target is smaller than current data, search left subtree
4. **Right Search**: If target is larger than current data, search right subtree

### 4. Deletion Function (Enhanced with Duplicate Handling)

```cpp
Node* deleteNode(Node *root, int target) {
    // Base case - empty tree
    if (!root) {
        return NULL;
    }
    
    // Navigate to the node to delete
    if (target < root->data) {
        root->left = deleteNode(root->left, target);
    }
    else if (target > root->data) {
        root->right = deleteNode(root->right, target);
    }
    else {
        // Node to delete found
        
        // Case 1: Leaf node (no children)
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        
        // Case 2: One child only
        else if (!root->left) {  // Only right child exists
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {  // Only left child exists
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Two children exist
        else {
            // Find inorder successor (smallest in right subtree)
            Node *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            
            // Replace root's data with successor's data
            root->data = successor->data;
            
            // Delete the successor
            root->right = deleteNode(root->right, successor->data);
        }
    }
    
    return root;
}
```

### 5. Inorder Traversal (for printing)

```cpp
void inorder(Node *root){
    if(!root) 
    return;

    //left , node , right
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
```

**Explanation:**
- **Base Case**: If root is NULL, return
- **Traversal Order**: Left subtree → Current node → Right subtree
- This prints the BST elements in sorted order

## Complete Working Example

```cpp
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left , *right;

    Node (int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node * insert(Node *root , int target){
    if(!root){
        Node *temp = new Node(target);
        return temp;
    }

    if(target < root->data){
        root->left = insert(root->left , target);
    }else{
        root->right = insert(root->right , target);
    }

    return root;
}

bool search(Node *root , int target){
    if(!root)
     return 0;
    
     if(root->data==target)
      return 1;

    if(root->data > target){
        return search(root->left , target);
    }else{
        return search(root->right , target);
    }
}

Node* deleteNode(Node *root, int target) {
    if (!root) {
        return NULL;
    }
    
    if (target < root->data) {
        root->left = deleteNode(root->left, target);
    }
    else if (target > root->data) {
        root->right = deleteNode(root->right, target);
    }
    else {
        // Node found - handle three cases
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if (!root->left) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else {
            // Find inorder successor
            Node *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    
    return root;
}

void inorder(Node *root){
    if(!root) 
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[] = {6,1,2,9,5,3,4,8,7,7,19};
    Node *root = NULL;

    // Insert all elements
    for(int i=0 ; i<11 ; i++){
        root = insert(root , arr[i]);
        cout << "Inserted: " << arr[i] << endl;
    }

    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search examples
    cout << "\nSearch 7: " << (search(root, 7) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (search(root, 99) ? "Found" : "Not Found") << endl;

    // Delete examples
    cout << "\nDeleting 7..." << endl;
    root = deleteNode(root, 7);
    cout << "After deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
```

## Example Input and Expected Output

**Input Array:** `{6, 1, 2, 9, 5, 3, 4, 8, 7, 7, 19}`

**Expected Output:**
```
Inserted: 6
Inserted: 1
Inserted: 2
Inserted: 9
Inserted: 5
Inserted: 3
Inserted: 4
Inserted: 8
Inserted: 7
Inserted: 7
Inserted: 19

Inorder Traversal: 1 2 3 4 5 6 7 7 8 9 19

Search 7: Found
Search 99: Not Found

Deleting 7...
After deletion: 1 2 3 4 5 6 7 8 9 19
```

## Step-by-Step Dry Run

Let's trace the insertion of elements `{6, 1, 2}`:

### Step 1: Insert 6
```
root = NULL
Insert 6: Create new node
Result: 
    6
```

### Step 2: Insert 1
```
Current tree: 6
1 < 6, so go left
Left is NULL, create new node
Result:
    6
   /
  1
```

### Step 3: Insert 2
```
Current tree: 
    6
   /
  1

2 < 6, so go left to node 1
2 > 1, so go right from node 1
Right is NULL, create new node
Result:
    6
   /
  1
   \
    2
```

## Visual Tree Structure

After inserting all elements `{6,1,2,9,5,3,4,8,7,7,19}`:

```
                6
              /   \
            1       9
             \     / \
              2   8   19
             / \ /
            5  7
           /    \
          3      7
           \
            4
```

## BST Properties Verification Table

| Node | Left Subtree Max | Right Subtree Min | Valid BST? |
|------|------------------|-------------------|------------|
| 6    | 5                | 7                 | ✓         |
| 1    | -                | 2                 | ✓         |
| 9    | 8                | 19                | ✓         |
| 2    | -                | 5                 | ✓         |
| 5    | 4                | -                 | ✓         |

## Time Complexity Analysis

| Operation | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Search    | O(log n)  | O(log n)     | O(n)      |
| Insert    | O(log n)  | O(log n)     | O(n)      |
| Delete    | O(log n)  | O(log n)     | O(n)      |

**Note:** Worst case occurs when the tree becomes skewed (like a linked list)

## Duplicate Handling

This implementation handles duplicates by:
1. **Insertion**: Duplicates go to the right subtree
2. **Search**: Finds any occurrence of the value
3. **Deletion**: Removes only one occurrence at a time

**Example with duplicates:**
- Insert sequence: `7, 7, 7`
- Tree structure:
  ```
  7
   \
    7
     \
      7
  ```

## Key Features

✅ **Complete Implementation**: Insert, Search, Delete operations
✅ **Duplicate Handling**: Properly manages duplicate values  
✅ **Memory Management**: Proper allocation and deallocation
✅ **Recursive Approach**: Clean and readable code structure
✅ **BST Property Maintained**: All operations preserve BST invariant

## Common Use Cases

- **Searching**: Fast lookup operations
- **Sorting**: Inorder traversal gives sorted sequence
- **Range Queries**: Find elements within a range
- **Database Indexing**: Efficient data organization
- **Expression Parsing**: Syntax trees in compilers

## Summary

This BST implementation provides a foundation for understanding tree-based data structures. The code demonstrates how recursive thinking simplifies complex operations while maintaining the fundamental BST property that enables efficient searching, insertion, and deletion operations. The handling of duplicates makes it practical for real-world applications where repeated values are common.