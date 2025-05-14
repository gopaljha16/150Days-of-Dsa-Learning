Here are your **Day 57 Linked List Problem Notes**:
We'll cover three problems:

---

# 📘 **Day 57: Linked List Problems**

## 🚀 Problems Covered:

1. **Remove Duplicates from a Sorted Linked List** (GFG Easy)
2. **Merge Two Sorted Linked Lists** (GFG Medium)
3. **Sort a Linked List of 0s, 1s, and 2s** (GFG Medium)

---

# ✅ **1. Remove Duplicates from a Sorted Linked List**

## 🔹 Problem Statement:

Given a **sorted linked list**, remove all duplicate elements so that each element appears only once.

---

## 🔸 Brute Force Approach (Using Extra Space)

### 🧠 Logic:

* Traverse the list and **store unique elements** in a vector.
* Then, reassign the values of the original list from the vector.
* Unlink the extra nodes at the end.

### ✅ Code:

```cpp
Node* removeDuplicates(Node* head) {
    vector<int> ans;
    ans.push_back(head->data);  // Store the first element
    
    Node* curr = head->next;

    // Store only unique elements
    while (curr) {
        if (ans.back() != curr->data) {
            ans.push_back(curr->data);
        }
        curr = curr->next;
    }

    // Re-assign values
    curr = head;
    int index = 0;
    while (index < ans.size()) {
        curr->data = ans[index++];
        curr = curr->next;
    }

    // Unlink extra nodes
    curr = head;
    int size = ans.size() - 1;
    while (size--) curr = curr->next;
    curr->next = NULL;

    return head;
}
```

### 🧾 Time & Space Complexity:

* **Time:** O(N)
* **Space:** O(N) (vector to store elements)

---

## 🔹 Optimized Approach (No Extra Space)

### 🧠 Logic:

* Since the list is **sorted**, duplicates will be **adjacent**.
* Traverse using `prev` and `curr`.
* If values match, skip the duplicate node using `prev->next = curr->next`.

### ✅ Code:

```cpp
Node* removeDuplicates(Node* head) {
    Node* prev = head;
    Node* curr = head->next;

    while (curr) {
        if (curr->data == prev->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
```

### 🧾 Time & Space Complexity:

* **Time:** O(N)
* **Space:** O(1)

---

# ✅ **2. Merge Two Sorted Linked Lists**

## 🔹 Problem Statement:

Given two **sorted linked lists**, merge them into one sorted list.

---

## 🔸 Approach:

### 🧠 Logic:

* Use a **dummy node** to simplify head tracking.
* Compare nodes of both lists, attach the smaller one.
* After one list ends, attach the remaining part of the other list.

### ✅ Code:

```cpp
Node* sortedMerge(Node* head1, Node* head2) {
    Node* head = new Node(0);  // dummy node
    Node* tail = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
        tail->next = NULL;  // Maintain tail
    }

    // Attach the remaining list
    if (head1) tail->next = head1;
    else tail->next = head2;

    Node* realHead = head->next;
    delete head;  // Remove dummy
    return realHead;
}
```

### 🧾 Time & Space Complexity:

* **Time:** O(N + M), where N and M are lengths of the two lists
* **Space:** O(1)

---

# ✅ **3. Sort a Linked List of 0s, 1s, and 2s**

## 🔹 Problem Statement:

Given a linked list containing only 0s, 1s, and 2s, sort it in ascending order.

---

## 🔸 Approach (Counting Method)

### 🧠 Logic:

* Count number of 0s, 1s, and 2s.
* Traverse again and fill the list with 0s, then 1s, then 2s.

### ✅ Code:

```cpp
Node* segregate(Node* head) {
    int count0 = 0, count1 = 0, count2 = 0;
    Node* curr = head;

    // Count 0s, 1s, 2s
    while (curr) {
        if (curr->data == 0) count0++;
        else if (curr->data == 1) count1++;
        else count2++;
        curr = curr->next;
    }

    curr = head;

    // Rewrite values
    while (count0--) {
        curr->data = 0;
        curr = curr->next;
    }
    while (count1--) {
        curr->data = 1;
        curr = curr->next;
    }
    while (count2--) {
        curr->data = 2;
        curr = curr->next;
    }

    return head;
}
```

### 🧾 Time & Space Complexity:

* **Time:** O(N)
* **Space:** O(1) (only counters used)

---

# 🔍 Summary Table

| Problem                | Approach    | Time     | Space |
| ---------------------- | ----------- | -------- | ----- |
| Remove Duplicates      | Brute Force | O(N)     | O(N)  |
| Remove Duplicates      | Optimized   | O(N)     | O(1)  |
| Merge Two Sorted Lists | Dummy Node  | O(N + M) | O(1)  |
| Sort 0s,1s,2s          | Counting    | O(N)     | O(1)  |

---

# 🧠 Diagram for Merge 2 Sorted Linked Lists:

```
List1: 1 -> 3 -> 5  
List2: 2 -> 4 -> 6  

Dummy ->  
       |
       V  
Merged: 1 -> 2 -> 3 -> 4 -> 5 -> 6
```

---

