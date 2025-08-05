# Construct BST From Preorder Traversal - Complete Documentation

## Problem 1: Construct BST From Preorder Traversal (LeetCode Medium)

### Code Structure
```cpp
class Solution {
public:
    TreeNode * BST(vector<int>&preorder, int &index, int lower, int upper) {
        // Base case: check bounds and array limits
        if(index == preorder.size() || lower > preorder[index] || upper < preorder[index]) {
            return NULL;
        }

        // Create root node with current element
        TreeNode *root = new TreeNode(preorder[index++]);
        
        // Recursively build left subtree (values < root->val)
        root->left = BST(preorder, index, lower, root->val);
        
        // Recursively build right subtree (values > root->val)
        root->right = BST(preorder, index, root->val, upper);

        return root;
    }
 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, index, INT_MIN, INT_MAX);
    }
};
```

### Line-by-Line Explanation

#### Helper Function `BST()`:
- **Line 1**: `TreeNode * BST(vector<int>&preorder, int &index, int lower, int upper)`
  - Takes preorder array by reference, current index by reference, and valid range [lower, upper]
  - Returns pointer to constructed subtree root

- **Lines 3-5**: Base case conditions
  - `index == preorder.size()`: No more elements to process
  - `lower > preorder[index]`: Current value violates lower bound (too small for current position)
  - `upper < preorder[index]`: Current value violates upper bound (too large for current position)

- **Line 8**: `TreeNode *root = new TreeNode(preorder[index++]);`
  - Create new node with current preorder element
  - Post-increment index to move to next element

- **Line 10**: `root->left = BST(preorder, index, lower, root->val);`
  - Build left subtree with range [lower, root->val)
  - All left subtree values must be less than root

- **Line 12**: `root->right = BST(preorder, index, root->val, upper);`
  - Build right subtree with range (root->val, upper]
  - All right subtree values must be greater than root

#### Main Function `bstFromPreorder()`:
- **Line 17**: Initialize index to 0
- **Line 18**: Start recursion with full integer range [INT_MIN, INT_MAX]

### Example Input and Expected Output

**Input**: `preorder = [8, 5, 1, 7, 10, 12]`

**Expected BST Structure**:
```
       8
      / \
     5   10
    / \    \
   1   7    12
```

**Output**: Root node of the constructed BST

### Step-by-Step Dry Run

Let's trace through `preorder = [8, 5, 1, 7, 10, 12]`:

```
Initial Call: BST(preorder, index=0, lower=INT_MIN, upper=INT_MAX)

Step 1: index=0, element=8
├── 8 is within [INT_MIN, INT_MAX] ✓
├── Create root(8), index becomes 1
├── Build left subtree: BST(preorder, index=1, lower=INT_MIN, upper=8)
│
│   Step 2: index=1, element=5  
│   ├── 5 is within [INT_MIN, 8) ✓
│   ├── Create root(5), index becomes 2
│   ├── Build left subtree: BST(preorder, index=2, lower=INT_MIN, upper=5)
│   │
│   │   Step 3: index=2, element=1
│   │   ├── 1 is within [INT_MIN, 5) ✓
│   │   ├── Create root(1), index becomes 3
│   │   ├── Build left subtree: BST(preorder, index=3, lower=INT_MIN, upper=1)
│   │   │   └── element=7, 7 > 1, violates upper bound → return NULL
│   │   ├── Build right subtree: BST(preorder, index=3, lower=1, upper=5)
│   │   │   └── element=7, 7 > 5, violates upper bound → return NULL
│   │   └── Return node(1)
│   │
│   ├── Build right subtree: BST(preorder, index=3, lower=5, upper=8)
│   │
│   │   Step 4: index=3, element=7
│   │   ├── 7 is within (5, 8) ✓
│   │   ├── Create root(7), index becomes 4
│   │   ├── Build left subtree: BST(preorder, index=4, lower=5, upper=7)
│   │   │   └── element=10, 10 > 7, violates upper bound → return NULL
│   │   ├── Build right subtree: BST(preorder, index=4, lower=7, upper=8)
│   │   │   └── element=10, 10 > 8, violates upper bound → return NULL
│   │   └── Return node(7)
│   │
│   └── Return node(5) with left=node(1), right=node(7)
│
├── Build right subtree: BST(preorder, index=4, lower=8, upper=INT_MAX)
│
│   Step 5: index=4, element=10
│   ├── 10 is within (8, INT_MAX] ✓
│   ├── Create root(10), index becomes 5
│   ├── Build left subtree: BST(preorder, index=5, lower=8, upper=10)
│   │   └── element=12, 12 > 10, violates upper bound → return NULL
│   ├── Build right subtree: BST(preorder, index=5, lower=10, upper=INT_MAX)
│   │
│   │   Step 6: index=5, element=12
│   │   ├── 12 is within (10, INT_MAX] ✓
│   │   ├── Create root(12), index becomes 6
│   │   ├── Build left subtree: BST(preorder, index=6, ...)
│   │   │   └── index=6 == size, return NULL
│   │   ├── Build right subtree: BST(preorder, index=6, ...)
│   │   │   └── index=6 == size, return NULL
│   │   └── Return node(12)
│   │
│   └── Return node(10) with right=node(12)
│
└── Return node(8) with left=subtree(5), right=subtree(10)
```

### Visual Representation

#### Preorder Traversal Process:
```
Preorder: [8, 5, 1, 7, 10, 12]
           ↑  ↑  ↑  ↑   ↑   ↑
           │  │  │  │   │   └── Right child of 10
           │  │  │  │   └────── Right child of 8  
           │  │  │  └────────── Right child of 5
           │  │  └───────────── Left child of 5
           │  └──────────────── Left child of 8
           └─────────────────── Root
```

#### Range Validation:
```
Node | Range              | Valid?
-----|-------------------|--------
8    | [INT_MIN, INT_MAX]| ✓
5    | [INT_MIN, 8)      | ✓
1    | [INT_MIN, 5)      | ✓  
7    | (5, 8)            | ✓
10   | (8, INT_MAX]      | ✓
12   | (10, INT_MAX]     | ✓
```

---

## Problem 2: Construct BST From Postorder Traversal (GFG Easy)

### Code Structure
```cpp
Node * BST(int post[], int &index, int lower, int upper) {
    // Base case
    if(index < 0 || post[index] < lower || post[index] > upper) {
        return NULL;
    }
    
    // Process in reverse order (NRL instead of LNR)
    Node *root = new Node(post[index--]);
    
    // Build right subtree first (reverse of preorder)
    root->right = BST(post, index, root->data, upper);
    
    // Then build left subtree
    root->left = BST(post, index, lower, root->data);
    
    return root;
}

Node *constructTree(int post[], int size) {
    int index = size - 1;  // Start from last element
    return BST(post, index, INT_MIN, INT_MAX);
}
```

### Key Differences from Preorder:
1. **Start from end**: `index = size - 1` instead of `index = 0`
2. **Decrement index**: `post[index--]` moves backwards through array
3. **Right before left**: Build right subtree first, then left (NRL pattern)
4. **Base case includes**: `index < 0` instead of `index >= size`

### Example Walkthrough

**Input**: `postorder = [1, 7, 5, 12, 10, 8]`

**Process**:
```
Postorder: [1, 7, 5, 12, 10, 8]
            ↑  ↑  ↑   ↑   ↑  ↑
            │  │  │   │   │  └── Root (process first)
            │  │  │   │   └───── Left child of 8
            │  │  │   └───────── Right child of 10  
            │  │  └───────────── Parent of 1,7
            │  └──────────────── Right child of 5
            └─────────────────── Left child of 5
```

---

## Problem 3: Validate Preorder Traversal of BST (GFG Medium)

### Code Structure
```cpp
class Solution {
public:
    int canRepresentBST(int arr[], int N) {
        stack<int> lower, upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        
        int LowerBound, UpperBound;
       
        for(int i = 0; i < N; i++) {
            // Check if current element violates lower bound
            if(arr[i] < lower.top())
                return 0;
            
            // Pop ranges that current element exceeds
            while(arr[i] > upper.top()) {
                upper.pop();
                lower.pop();
            }
          
            // Get current valid range
            LowerBound = lower.top();
            UpperBound = upper.top();
            lower.pop();
            upper.pop();
            
            // Push ranges for right child then left child
            lower.push(arr[i]);      // Right child range: [arr[i], UpperBound]
            upper.push(UpperBound);
            
            lower.push(LowerBound);  // Left child range: [LowerBound, arr[i]]
            upper.push(arr[i]);
        }
       
        return 1;
    }
};
```

### Algorithm Explanation:
1. **Stack-based validation**: Use two stacks to track valid ranges for upcoming elements
2. **Range tracking**: Each stack position represents a potential node's valid range
3. **Violation check**: If current element < lower bound, traversal is invalid
4. **Range adjustment**: Pop ranges that current element exceeds
5. **Range pushing**: Push new ranges for left and right children

### Example Validation

**Input**: `arr = [8, 5, 1, 7, 10, 12]`

```
i=0, arr[i]=8:
├── Stacks: lower=[INT_MIN], upper=[INT_MAX]
├── 8 >= INT_MIN ✓
├── 8 <= INT_MAX ✓
└── Push ranges: lower=[8, INT_MIN], upper=[INT_MAX, 8]

i=1, arr[i]=5:
├── Stacks: lower=[8, INT_MIN], upper=[INT_MAX, 8]  
├── 5 >= INT_MIN ✓
├── 5 <= 8 ✓
└── Push ranges: lower=[5, INT_MIN, 8], upper=[8, 5, INT_MAX]

i=2, arr[i]=1:
├── Stacks: lower=[5, INT_MIN, 8], upper=[8, 5, INT_MAX]
├── 1 >= INT_MIN ✓
├── 1 <= 5 ✓
└── Continue...
```

---

## Complexity Analysis

### Time Complexity:
- **Problem 1 & 2**: O(n) - Each element processed exactly once
- **Problem 3**: O(n) - Each element pushed/popped at most once

### Space Complexity:
- **Problem 1 & 2**: O(h) where h is tree height (recursion stack)
- **Problem 3**: O(n) for the validation stacks

---

## Key Insights

1. **Range-based approach**: All three solutions use the BST property with valid ranges
2. **Index management**: Preorder uses forward iteration, postorder uses backward
3. **Recursive patterns**: Preorder follows LNR, postorder follows NRL
4. **Validation strategy**: Stack-based simulation of tree construction process

## Summary

These three problems demonstrate different aspects of BST construction and validation:

- **Construction from preorder**: Forward processing with left-then-right recursion
- **Construction from postorder**: Backward processing with right-then-left recursion  
- **Preorder validation**: Stack-based simulation without actual tree construction

All solutions leverage the fundamental BST property that elements must fall within specific ranges based on their position in the tree structure.