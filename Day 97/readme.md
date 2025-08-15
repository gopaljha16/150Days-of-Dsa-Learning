# C++ Heap Problems - Complete Guide

## Overview

This document contains solutions to 6 different heap-related problems commonly asked in coding interviews. These problems demonstrate various applications of heap data structures including:

- **Height of Heap**: Finding the height of a complete binary heap
- **Minimum Cost of Ropes**: Using min-heap to minimize rope connection costs
- **Profit Maximization**: Using max-heap for ticket selling optimization
- **Take Gifts From Richest Pile**: Using max-heap with square root operations
- **Magician and Chocolates**: Using max-heap with division operations
- **Last Stone Weight**: Using max-heap for stone collision simulation

---

## Problem 1: Height of Heap

### Code
```cpp
class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        if(n==1)
         return 1;
         
         int height = 0;
         while(n>1){
             height++;
             n/=2;
         }
         
         return height;
    }
};
```

### Explanation

This function calculates the height of a complete binary heap with `n` nodes.

**Line-by-line breakdown:**
- `if(n==1) return 1;` - Base case: a single node has height 1
- `int height = 0;` - Initialize height counter
- `while(n>1)` - Continue until we reach the root level
- `height++;` - Increment height for each level
- `n/=2;` - Move up one level (each level has half the nodes of the level below)
- `return height;` - Return the calculated height

### Key Concept
In a complete binary heap, each level (except possibly the last) is completely filled. The relationship between nodes and height follows: **height = floor(log₂(n))**

### Example Input/Output

| Input (n) | Output (height) | Explanation |
|-----------|-----------------|-------------|
| 1 | 1 | Single node |
| 2 | 2 | Two levels |
| 3 | 2 | Two levels |
| 7 | 3 | Three levels |
| 15 | 4 | Four levels |

### Dry Run (n = 7)

```
Initial: n = 7, height = 0

Step 1: n > 1? Yes
        height = 1, n = 7/2 = 3

Step 2: n > 1? Yes  
        height = 2, n = 3/2 = 1

Step 3: n > 1? No
        Exit loop

Return height = 2
```

### Visual Representation
```
For n = 7:
       1      ← Level 1
      / \
     2   3    ← Level 2  
    / \ / \
   4 5 6 7   ← Level 3

Height = 3 levels
```

---

## Problem 2: Minimum Cost of Ropes

### Code
```cpp
class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        
        //priority queue min heap
        priority_queue<int,vector<int>,greater<int>>p;
        
        //insert all element in the priority queue
        for(int i=0; i<n; i++){
            p.push(arr[i]);
        }
        
        //now cost calculation 
        int cost = 0;
        
        while(p.size()>1){ //break when it's size is only 1 element
            int rope = p.top(); //first smallest element
            p.pop();
            rope+=p.top();//second smallest element
            p.pop();
            cost+=rope; //added to cost
            p.push(rope);//pushed to queue
        }
        
        return cost;
    }
};
```

### Explanation

This problem uses a **greedy approach with min-heap** to minimize the cost of connecting ropes.

**Strategy**: Always connect the two shortest ropes first to minimize total cost.

**Section-wise breakdown:**

1. **Setup Min-Heap**: `priority_queue<int,vector<int>,greater<int>>p;`
   - Creates a min-heap using priority queue with custom comparator

2. **Insert All Ropes**: Insert all rope lengths into the min-heap

3. **Cost Calculation Loop**:
   - Extract two smallest ropes
   - Add their lengths (this is the cost to connect them)
   - Add this cost to total cost
   - Insert the combined rope back into heap

### Example Input/Output

**Input**: `arr = [4, 3, 2, 6]`
**Output**: `29`

### Dry Run

```
Initial array: [4, 3, 2, 6]
Min-heap after insertion: [2, 3, 4, 6]

Step 1: Extract 2 and 3
        rope = 2 + 3 = 5
        cost = 0 + 5 = 5
        Insert 5 back
        Heap: [4, 5, 6]

Step 2: Extract 4 and 5  
        rope = 4 + 5 = 9
        cost = 5 + 9 = 14
        Insert 9 back
        Heap: [6, 9]

Step 3: Extract 6 and 9
        rope = 6 + 9 = 15  
        cost = 14 + 15 = 29
        Insert 15 back
        Heap: [15]

Final cost = 29
```

### Visual Representation
```
Connection Tree:
      (15)
     /    \
   (5)    (9)
   / \    / \
  2   3  4   6

Cost = 5 + 9 + 15 = 29
```

---

## Problem 3: Profit Maximization (Ticket Selling)

### Code
```cpp
int Solution::solve(vector<int> &A, int B) {
    int sum = 0;
    priority_queue<int>p;
    
    //insert element
    for(int i=0 ; i<A.size() ; i++){
        p.push(A[i]);
    }
    
    //ticket selling to the B people
    while(B&&!p.empty()){
        //maximum ticket
        sum+=p.top();
        if(p.top()-1){
            p.push(p.top()-1);
        }
        p.pop();
        B--;//decrease tickets
    }
    
    return sum;
}
```

### Explanation

This problem maximizes profit by always selling the most expensive ticket available.

**Strategy**: Use max-heap to always get the highest-priced ticket, then reduce its value by 1 and put it back.

**Section-wise breakdown:**

1. **Setup Max-Heap**: `priority_queue<int>p;` (default is max-heap)
2. **Insert All Tickets**: Add all ticket prices to heap
3. **Sell B Tickets**:
   - Always sell the most expensive ticket (heap top)
   - Add its price to profit
   - If price > 1, add (price-1) back to heap
   - Decrement available customer count

### Example Input/Output

**Input**: `A = [2, 3, 1, 5], B = 4`
**Output**: `11`

### Dry Run

```
Initial: A = [2, 3, 1, 5], B = 4
Max-heap: [5, 3, 2, 1]

Customer 1: Sell ticket of price 5
           sum = 0 + 5 = 5
           Add 4 back to heap
           Heap: [4, 3, 2, 1], B = 3

Customer 2: Sell ticket of price 4  
           sum = 5 + 4 = 9
           Add 3 back to heap
           Heap: [3, 3, 2, 1], B = 2

Customer 3: Sell ticket of price 3
           sum = 9 + 3 = 12  
           Add 2 back to heap
           Heap: [3, 2, 2, 1], B = 1

Customer 4: Sell ticket of price 3
           sum = 12 + 3 = 15
           Add 2 back to heap
           B = 0 (stop)

Final sum = 15
```

---

## Problem 4: Take Gifts From Richest Pile

### Code
```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
     
     priority_queue<int>p;

     for(int i=0 ; i<gifts.size() ; i++){
        p.push(gifts[i]);
     }

     while(k){
       int gift = sqrt(p.top());
       p.pop();
       if(gift)
       p.push(gift);
       k--;
     }

     long long sum=0; 
     while(!p.empty()){
        sum+=p.top();
        p.pop();
     }

   return sum;
    }
};
```

### Explanation

This problem simulates taking gifts from the richest pile, where after taking from a pile, its size becomes the square root of the original size.

**Strategy**: Use max-heap to always pick from the largest pile, apply square root operation, and continue for k operations.

**Section-wise breakdown:**

1. **Setup Max-Heap**: Insert all gift pile sizes
2. **K Operations**: For each operation:
   - Pick the largest pile (heap top)
   - Take square root (floor value)
   - If result > 0, put back in heap
3. **Calculate Remaining**: Sum all remaining gifts

### Example Input/Output

**Input**: `gifts = [25, 64, 9, 4, 100], k = 4`
**Output**: `29`

### Dry Run

```
Initial: gifts = [25, 64, 9, 4, 100], k = 4
Max-heap: [100, 64, 25, 9, 4]

Operation 1: Pick 100
            gift = sqrt(100) = 10
            Insert 10 back
            Heap: [64, 25, 10, 9, 4], k = 3

Operation 2: Pick 64
            gift = sqrt(64) = 8  
            Insert 8 back
            Heap: [25, 10, 9, 8, 4], k = 2

Operation 3: Pick 25
            gift = sqrt(25) = 5
            Insert 5 back  
            Heap: [10, 9, 8, 5, 4], k = 1

Operation 4: Pick 10
            gift = sqrt(10) = 3
            Insert 3 back
            Heap: [9, 8, 5, 4, 3], k = 0

Final sum = 9 + 8 + 5 + 4 + 3 = 29
```

---

## Problem 5: Magician and Chocolates

### Code
```cpp
int Solution::nchoc(int A, vector<int> &B) {

   //maxheap 
   priority_queue<int>p;
   
   //insert all element
   for(int i=0 ; i<B.size() ; i++){
       p.push(B[i]);
   }
   
   //max chocolate
   long long MaxChoc = 0;
   
   //condition A should be present and p should not be empty 
   while(A&&(!p.empty())){
       MaxChoc+=p.top(); // added the height element
       
       if(p.top()/2){ //checking the element is 0 or not
           p.push(p.top()/2);
       }
       
       p.pop();
       A--;
   }
   
   return MaxChoc%1000000007;
}
```

### Explanation

A magician can eat chocolates from bags, and after eating from a bag, the bag's chocolate count becomes half of its original count.

**Strategy**: Use max-heap to always eat from the bag with most chocolates, then update the bag size.

**Section-wise breakdown:**

1. **Setup Max-Heap**: Insert all bag sizes
2. **A Time Units**: For each time unit:
   - Eat from the largest bag
   - Add chocolates to total
   - If bag still has chocolates (> 0), add half of original count back
3. **Modulo Operation**: Return result modulo 1000000007 to prevent overflow

### Example Input/Output

**Input**: `A = 3, B = [6, 5]`
**Output**: `14`

### Dry Run

```
Initial: A = 3, B = [6, 5]  
Max-heap: [6, 5]

Time 1: Eat from bag with 6 chocolates
        MaxChoc = 0 + 6 = 6
        Add 6/2 = 3 back to heap
        Heap: [5, 3], A = 2

Time 2: Eat from bag with 5 chocolates
        MaxChoc = 6 + 5 = 11  
        Add 5/2 = 2 back to heap
        Heap: [3, 2], A = 1

Time 3: Eat from bag with 3 chocolates
        MaxChoc = 11 + 3 = 14
        Add 3/2 = 1 back to heap  
        Heap: [2, 1], A = 0

Final MaxChoc = 14
```

---

## Problem 6: Last Stone Weight

### Code
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;

        //insert stones
        for(int i=0 ; i<stones.size();i++){
            p.push(stones[i]);
        }

        while(p.size()>1){ // iteration until the size is 1
         int weight = p.top(); // first largest
         p.pop();
         weight-=p.top(); //second largest se minus
         p.pop();
         if(weight){ //if weight exists
            p.push(weight);
         }
        }

        return p.empty() ? 0 : p.top();
    }
};
```

### Explanation

This problem simulates stone collisions where two heaviest stones collide, and the difference (if any) remains.

**Strategy**: Use max-heap to always get the two heaviest stones, calculate their difference, and continue until at most one stone remains.

**Section-wise breakdown:**

1. **Setup Max-Heap**: Insert all stone weights
2. **Collision Simulation**: While more than 1 stone exists:
   - Take two heaviest stones
   - Calculate their difference
   - If difference > 0, add it back to heap
3. **Final Result**: Return remaining stone weight or 0 if no stones left

### Example Input/Output

**Input**: `stones = [2, 7, 4, 1, 8, 1]`
**Output**: `1`

### Dry Run

```
Initial: stones = [2, 7, 4, 1, 8, 1]
Max-heap: [8, 7, 4, 2, 1, 1]

Round 1: Collide 8 and 7
         weight = 8 - 7 = 1
         Add 1 back
         Heap: [4, 2, 1, 1, 1]

Round 2: Collide 4 and 2  
         weight = 4 - 2 = 2
         Add 2 back
         Heap: [2, 1, 1, 1]

Round 3: Collide 2 and 1
         weight = 2 - 1 = 1  
         Add 1 back
         Heap: [1, 1, 1]

Round 4: Collide 1 and 1
         weight = 1 - 1 = 0
         Don't add back (weight is 0)
         Heap: [1]

Round 5: Only 1 stone left, exit loop

Return 1
```

### Visual Representation
```
Collision Tree:
[8,7,4,2,1,1] → [4,2,1,1,1] → [2,1,1,1] → [1,1,1] → [1]
    ↓               ↓             ↓           ↓
   8-7=1          4-2=2        2-1=1      1-1=0
```

---

## Common Patterns and Techniques

### Heap Types Used

| Problem | Heap Type | Reason |
|---------|-----------|---------|
| Height of Heap | None (mathematical) | Uses logarithmic relationship |
| Min Cost Ropes | Min-Heap | Always connect smallest ropes first |
| Profit Maximization | Max-Heap | Always sell highest-priced ticket |
| Take Gifts | Max-Heap | Always take from largest pile |
| Magician Chocolates | Max-Heap | Always eat from largest bag |
| Last Stone Weight | Max-Heap | Always collide heaviest stones |

### Key Algorithmic Insights

1. **Greedy Strategy**: Most heap problems use greedy approach - make locally optimal choice
2. **Priority Queue**: C++ `priority_queue` is implemented as max-heap by default
3. **Min-Heap Creation**: Use `priority_queue<int, vector<int>, greater<int>>` for min-heap
4. **Overflow Prevention**: Use `long long` for large sums and modulo operation when required

### Time Complexity Analysis

| Problem | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| Height of Heap | O(log n) | O(1) |
| Min Cost Ropes | O(n log n) | O(n) |
| Profit Maximization | O(B log n) | O(n) |
| Take Gifts | O(k log n) | O(n) |
| Magician Chocolates | O(A log n) | O(n) |
| Last Stone Weight | O(n log n) | O(n) |

---

## Summary

These problems demonstrate the versatility of heap data structures in solving optimization problems. The key patterns include:

- **Min-Heap**: When you need the smallest element repeatedly (rope problem)
- **Max-Heap**: When you need the largest element repeatedly (ticket, gifts, chocolates, stones)
- **Greedy Approach**: Making locally optimal choices that lead to globally optimal solutions
- **Simulation**: Using heaps to simulate real-world processes (stone collisions, eating chocolates)

The heap data structure provides efficient O(log n) insertion and extraction operations, making it ideal for problems where you need to repeatedly access extreme values (minimum or maximum) while maintaining the ability to modify the dataset.

