Here are the **Day 54 Notes: Reverse a Linked List & Middle of Linked List**, with detailed line-by-line explanation, flowcharts, and example dry runs to fully understand how each approach works.

---

## 📌 Problem 1: Reverse a Singly Linked List

---

### ✅ Method 1: Using Extra Space (Vector)

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> ans;
        ListNode *temp = head;

        // Store all values in vector
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        // Update the nodes' values from back of vector
        int i = ans.size() - 1;
        temp = head;
        while (temp) {
            temp->val = ans[i];
            i--;
            temp = temp->next;
        }

        return head;
    }
};
```

### 🧠 Explanation:

* You create a `vector<int> ans` to store node values.
* Then you iterate the list, pushing each node’s value into `ans`.
* Next, from the back of the vector, you update each node’s value (`temp->val = ans[i]`).
* **Note**: You don’t reverse node links, only their values.
* **Time**: O(n), **Space**: O(n)

---

### ✅ Method 2: Iterative In-Place Reversal (Best Approach)

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while (curr) {
            fut = curr->next;    // Store next node
            curr->next = prev;   // Reverse the current pointer
            prev = curr;         // Move prev to current
            curr = fut;          // Move curr to next
        }

        return prev; // New head is the last node
    }
};
```

### 🧠 Explanation:

#### Let's understand by example:

List: `1 → 2 → 3 → 4 → 5 → NULL`

* Initial:

  * `prev = NULL`
  * `curr = 1`
* First Iteration:

  * `fut = 2`
  * `curr->next = NULL`
  * `prev = 1`, `curr = 2`
* Final:

  * Links become `5 → 4 → 3 → 2 → 1 → NULL`

### 🔄 Flow Diagram:

```
Initial:       Reversing:

1 -> 2         1 <- 2
^              ^    ^
|              |    |
prev          curr fut
```

### ✅ Time: O(n), Space: O(1) — Optimal

---

### ✅ Method 3: Recursive Reversal

```cpp
class Solution {
public:
    ListNode* Reverse(ListNode *curr, ListNode *prev) {
        if (curr == NULL) return prev;

        ListNode *fut = curr->next;
        curr->next = prev;

        return Reverse(fut, curr);
    }

    ListNode* reverseList(ListNode* head) {
        return Reverse(head, NULL);
    }
};
```

### 🧠 Recursive Logic:

* Base Case: `curr == NULL`, return `prev` (new head)
* Step:

  * Save `next`
  * Reverse link: `curr->next = prev`
  * Recursive call: `Reverse(fut, curr)`

### ✅ Time: O(n), Space: O(n) — due to recursive call stack

---

## 📌 Problem 2: Find Middle of Linked List

---

### ✅ Method 1: Count Nodes Then Traverse

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *temp = head;

        // Count total nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Move to middle
        count /= 2;
        temp = head;
        while (count--) {
            temp = temp->next;
        }

        return temp;
    }
};
```

### 🧠 Dry Run:

List: `1 → 2 → 3 → 4 → 5 → NULL`

* Count: 5
* count/2 = 2 → move 2 steps from head
* Return: Node with value `3`

---

### ✅ Method 2: Two Pointer (Slow & Fast)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps
        }

        return slow;
    }
};
```

### 🧠 Intuition:

* For every 2 steps of `fast`, `slow` moves 1 step.
* So when `fast` reaches end, `slow` will be at middle.

### 🔄 Flow:

```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
s    f

     s         f
          s         f
Middle is where slow stopped: Node 3
```

### ✅ Time: O(n), Space: O(1) — Optimal

---

## 🔍 Summary Table

| Problem        | Method              | Time | Space | Reversal Type         |
| -------------- | ------------------- | ---- | ----- | --------------------- |
| Reverse List   | Vector              | O(n) | O(n)  | Value swap only       |
| Reverse List   | Iterative In-Place  | O(n) | O(1)  | Link reversal ✅       |
| Reverse List   | Recursion           | O(n) | O(n)  | Link reversal         |
| Middle of List | Count + Traverse    | O(n) | O(1)  | Count then middle     |
| Middle of List | Slow & Fast Pointer | O(n) | O(1)  | Real-time detection ✅ |

---


