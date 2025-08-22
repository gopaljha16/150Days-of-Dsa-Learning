# Merge K Sorted Data Structures

## Overview

This code demonstrates three different approaches to merge K sorted data structures:
1. **Merge K Sorted Linked Lists** using a min-heap (priority queue)
2. **Merge K Sorted Arrays** using a matrix approach with min-heap
3. **Merge K Sorted Arrays** using a divide-and-conquer merge sort approach

All approaches efficiently combine multiple sorted collections into a single sorted result while maintaining optimal time complexity.

---

## Approach 1: Merge K Sorted Linked Lists (Min-Heap)

### Code Structure

```cpp
struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min heap comparator
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Create min-heap with all list heads
        priority_queue<Node*, vector<Node*>, Compare> p(arr.begin(), arr.end());
        
        // Create dummy node for result
        Node *root = new Node(0);
        Node *tail = root;
        Node *temp;
        
        while(!p.empty()) {
            temp = p.top();    // Get minimum node
            p.pop();           // Remove from heap
            
            tail->next = temp; // Add to result list
            tail = tail->next; // Move tail pointer
            
            if(temp->next)     // If current node has next
                p.push(temp->next); // Add next node to heap
        }
        
        return root->next; // Return actual head (skip dummy)
    }
};
```

### Line-by-Line Explanation

1. **Node Structure**: Defines a basic linked list node with data and next pointer
2. **Compare Class**: Custom comparator for min-heap (smaller values have higher priority)
3. **Priority Queue**: Creates min-heap initialized with heads of all K lists
4. **Dummy Node**: `root` serves as a dummy head to simplify list construction
5. **Main Loop**: 
   - Extract minimum node from heap
   - Attach it to result list
   - If extracted node has a next node, add it to heap
6. **Return**: Skip dummy node and return actual merged list

### Example Input and Output

**Input**: 3 sorted linked lists
```
List 1: 1 → 4 → 5
List 2: 1 → 3 → 4  
List 3: 2 → 6
```

**Expected Output**: `1 → 1 → 2 → 3 → 4 → 4 → 5 → 6`

### Step-by-Step Dry Run

```
Initial heap: [1(L1), 1(L2), 2(L3)]  // L1=List1, L2=List2, L3=List3
Result: dummy →

Step 1: Pop 1(L1), add to result, push 4(L1)
Heap: [1(L2), 2(L3), 4(L1)]
Result: dummy → 1(L1) →

Step 2: Pop 1(L2), add to result, push 3(L2)
Heap: [2(L3), 4(L1), 3(L2)]
Result: dummy → 1(L1) → 1(L2) →

Step 3: Pop 2(L3), add to result, push 6(L3)
Heap: [3(L2), 4(L1), 6(L3)]
Result: dummy → 1(L1) → 1(L2) → 2(L3) →

... continues until heap is empty
```

### Complexity Analysis
- **Time**: O(N log K) where N = total nodes, K = number of lists
- **Space**: O(K) for the heap

---

## Approach 2: Merge K Sorted Arrays (Matrix/Heap)

### Code Structure

```cpp
class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<pair<int, pair<int, int>>> temp;
        
        // Insert first element of each array
        for(int i = 0; i < K; i++) {
            temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
        }
        
        // Create min-heap
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());
        
        vector<int> ans;
        
        while(!p.empty()) {
            auto element = p.top();
            p.pop();
            
            ans.push_back(element.first);  // Add value to result
            
            int i = element.second.first;   // row index
            int j = element.second.second;  // column index
            
            if(j + 1 < K)  // If next element exists in same array
                p.push(make_pair(arr[i][j+1], make_pair(i, j+1)));
        }
        
        return ans;
    }
};
```

### Data Structure Visualization

```
Heap stores: (value, (row_index, col_index))

Example:
arr[0] = [1, 4, 5]
arr[1] = [1, 3, 4]  
arr[2] = [2, 6]

Initial heap: [(1,(0,0)), (1,(1,0)), (2,(2,0))]
```

### Example Input and Output

**Input**: 
```cpp
vector<vector<int>> arr = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
K = 3;
```

**Expected Output**: `[1, 1, 2, 3, 4, 4, 5, 6]`

### Step-by-Step Dry Run

| Step | Heap State | Pop Element | Result | Next Push |
|------|------------|-------------|--------|-----------|
| 0 | [(1,(0,0)), (1,(1,0)), (2,(2,0))] | - | [] | - |
| 1 | [(1,(1,0)), (2,(2,0)), (4,(0,1))] | (1,(0,0)) | [1] | (4,(0,1)) |
| 2 | [(2,(2,0)), (3,(1,1)), (4,(0,1))] | (1,(1,0)) | [1,1] | (3,(1,1)) |
| 3 | [(3,(1,1)), (4,(0,1)), (6,(2,1))] | (2,(2,0)) | [1,1,2] | (6,(2,1)) |
| 4 | [(4,(0,1)), (4,(1,2)), (6,(2,1))] | (3,(1,1)) | [1,1,2,3] | (4,(1,2)) |

---

## Approach 3: Merge K Sorted Arrays (Divide & Conquer)

### Code Structure

```cpp
class Solution {
public:
    void Merge(vector<int>& arr, int start, int mid, int end) {
        vector<int> temp(end - start + 1);
        int index = 0, left = start, right = mid + 1;
        
        // Merge two sorted portions
        while(left <= mid && right <= end) {
            if(arr[left] < arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }
        
        // Copy remaining elements
        while(left <= mid) temp[index++] = arr[left++];
        while(right <= end) temp[index++] = arr[right++];
        
        // Copy back to original array
        for(int i = 0; i < temp.size(); i++) {
            arr[start + i] = temp[i];
        }
    }
    
    void MergeSort(vector<int>& arr, int start, int end, int portion, int K) {
        if(start == end || portion < 2) return;
        
        int mid = start + (portion/2) * K - 1;
        
        MergeSort(arr, start, mid, portion/2, K);
        MergeSort(arr, mid+1, end, portion - portion/2, K);
        
        Merge(arr, start, mid, end);
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> ans;
        
        // Flatten all arrays into single array
        for(int i = 0; i < K; i++) {
            for(int j = 0; j < K; j++) {
                ans.push_back(arr[i][j]);
            }
        }
        
        MergeSort(ans, 0, ans.size()-1, K, K);
        return ans;
    }
};
```

### Algorithm Visualization

```
Input: K=3 arrays of size 3 each
Flattened: [1,4,5, 1,3,4, 2,6,∞]

Divide & Conquer Tree:
                [1,4,5,1,3,4,2,6,∞]
                /                \
        [1,4,5,1,3,4]              [2,6,∞]
           /        \                  |
    [1,4,5]      [1,3,4]           [2,6,∞]
       |            |                 |
   Sorted       Sorted            Sorted
```

### Example with K=2 Arrays

**Input**: `[[1,4,7], [2,5,8]]`

**Steps**:
1. Flatten: `[1,4,7,2,5,8]`
2. MergeSort with portion tracking
3. Result: `[1,2,4,5,7,8]`

---

## Comparison of Approaches

| Approach | Time Complexity | Space Complexity | Best Use Case |
|----------|----------------|------------------|---------------|
| Min-Heap (Lists) | O(N log K) | O(K) | When data is in linked lists |
| Min-Heap (Arrays) | O(N log K) | O(K) | When you need to track positions |
| Divide & Conquer | O(N log K) | O(N) | When all arrays have same size |

## Visual Flow Diagram

```
Merge K Sorted Structures
         |
    ┌────┴────┐
    │  Input  │
    └────┬────┘
         │
    ┌────▼────┐
    │ Choose  │
    │Approach │
    └─┬─┬─┬──┘
      │ │ │
   ┌──▼─▼─▼──┐
   │Min-Heap │ ─── Linked Lists
   │         │ ─── Arrays (Matrix)
   │Div&Conq │ ─── Equal-sized Arrays
   └─────────┘
         │
    ┌────▼────┐
    │ Merged  │
    │ Output  │
    └─────────┘
```

## Summary

These three approaches solve the problem of merging K sorted data structures efficiently:

1. **Min-Heap for Linked Lists**: Uses a priority queue to always process the smallest available element, ideal for linked list structures.

2. **Min-Heap for Arrays (Matrix)**: Tracks both values and their positions, allowing efficient merging of arrays of potentially different sizes.

3. **Divide & Conquer**: Flattens all arrays and uses merge sort principles, most suitable when all arrays have the same size.

All approaches achieve O(N log K) time complexity where N is the total number of elements and K is the number of sorted structures, making them optimal solutions for this classic interview problem.

**Key Takeaway**: The choice of approach depends on your data structure (linked lists vs arrays) and size constraints. The min-heap approaches are generally more memory-efficient, while divide-and-conquer is conceptually simpler but requires more space.