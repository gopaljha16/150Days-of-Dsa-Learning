# Day 58: Circular Linked List - Detect Loop and Find Length of Loop

---

## Problem 1: **Detect Loop in a Linked List** (GFG Medium)

We are given a singly linked list. We need to detect if there is a cycle (loop) in the list.

---

### ✅ **Method 1: Brute Force using Vector**

```cpp
class Solution {
   bool check(vector<Node*>&visited , Node *curr){
       for(int i=0 ; i<visited.size() ; i++){
           if(visited[i]==curr){
               return true;
           }
       }
       return false;
   }
   public:
     bool detectLoop(Node* head) {
         Node *curr = head;
         vector<Node*> visited;
         
         while(curr != NULL){
             if(check(visited , curr))
                 return true;
             visited.push_back(curr);
             curr = curr->next;
         }
         return false;
     }
};
```

### ✅ **Explanation**

* **We maintain a vector `visited`** to store all visited nodes.
* Each time we visit a node, we check if it is already present in the `visited` vector.
* If found, a loop exists.
* Else, continue traversing.

### ⏱ Time Complexity: O(n^2)

* For every node, we check the visited list (linear search).

### ὋE Space Complexity: O(n)

* Stores all visited nodes.

---

### ✅ **Method 2: Using Hash Map**

```cpp
class Solution {
  public:
    bool detectLoop(Node* head) {
        Node *curr = head;
        unordered_map<Node*, bool> visited;
        
        while(curr != NULL){
            if(visited[curr])
                return true;
            visited[curr] = true;
            curr = curr->next;
        }
        return false;
    }
};
```

### ✅ **Explanation**

* We use a hash map to track nodes.
* If `curr` is already in the map, a loop exists.

### ⏱ Time Complexity: O(n)

* One pass over the list.

### ὋE Space Complexity: O(n)

* Stores visited nodes in the map.

---

### ✅ **Method 3: Floyd's Cycle Detection Algorithm (Tortoise & Hare)**

```cpp
class Solution {
  public:
    bool detectLoop(Node* head) {
        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;           // Move one step
            fast = fast->next->next;     // Move two steps
            if(slow == fast)
                return true;
        }
        return false;
    }
};
```

### ✅ **Explanation**

* `slow` moves one step; `fast` moves two steps.
* If a loop exists, they will eventually meet.

### ⏱ Time Complexity: O(n)

* At most 2n iterations.

### ὋE Space Complexity: O(1)

* No extra space used.

---

## Problem 2: **Find Length of Loop in a Linked List**

```cpp
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }

        // No loop case
        if(fast == NULL || fast->next == NULL)
            return 0;

        // Loop exists, count its length
        int count = 1;
        slow = slow->next;
        while(slow != fast){
            count++;
            slow = slow->next;
        }
        return count;
    }
};
```

### ✅ **Explanation**

* First detect loop using Floyd's algorithm.
* If found, move one pointer and count steps until it meets the other pointer again.

### ⏱ Time Complexity: O(n)

* One traversal to detect loop + one to count loop length.

### ὋE Space Complexity: O(1)

* No extra space used.

---

## 📘 Summary

| Method         | Approach        | Time Complexity | Space Complexity |
| -------------- | --------------- | --------------- | ---------------- |
| Brute Force    | Vector + Check  | O(n^2)          | O(n)             |
| Hashing        | Unordered Map   | O(n)            | O(n)             |
| Floyd's Cycle  | Two Pointers    | O(n)            | O(1)             |
| Length of Loop | Floyd + Counter | O(n)            | O(1)             |

---


