Here’s your **Day 61** full deep-dive explanation for:

---

# ✅ Day 61: Flattening a Linked List & Merge K Sorted Linked Lists

We’ll cover:

1. 🔹 Flattening a Linked List (GFG Medium)
2. 🔹 Merge K Sorted Linked Lists (GFG Medium)

   * Approach 1: Sequential Merge
   * Approach 2: Merge using Merge Sort

---

## ✅ PART 1: Flattening a Linked List

### 🔸 Problem:

Given a linked list where each node has two pointers:

* `next` → right pointer (to next horizontal node)
* `bottom` → down pointer (to vertical node)

Flatten the list so that all nodes appear in sorted order using only the **bottom pointer**.

---

### ✅ Input Format:

```cpp
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22    35
|           |     |
8           50    40
|                 |
30                45
```

### ✅ Output (flattened):

```
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50
```

---

### 🔸 Step-by-Step Plan

1. **Flatten from right to left** (start from the end).
2. Merge two sorted linked lists at a time using their `bottom` pointers.
3. Repeat until one flattened list remains.

---

### ✅ `Merge()` Function Breakdown

```cpp
Node* Merge(Node *head1, Node *head2) {
    Node *head = new Node(0); // dummy node
    Node *tail = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->bottom = head1;
            head1 = head1->bottom;
        } else {
            tail->bottom = head2;
            head2 = head2->bottom;
        }
        tail = tail->bottom;
        tail->bottom = NULL;
    }

    // Connect remaining nodes
    tail->bottom = head1 ? head1 : head2;

    // Remove dummy node
    Node *temp = head;
    head = head->bottom;
    delete temp;

    return head;
}
```

---

### ✅ `flatten()` Function Breakdown

```cpp
Node* flatten(Node* root) {
    while (root->next) {
        Node* head1 = root;
        Node* head2 = root->next;
        Node* head3 = root->next->next;

        head1->next = NULL; // disconnect
        head2->next = NULL;

        // Merge two sorted bottom lists
        root = Merge(head1, head2);

        // Connect root to the next group
        root->next = head3;
    }

    return root;
}
```

---

### 🔸 Diagram After Each Merge:

Let's say:

```
root = 5 -> 10 -> 19 -> 28
```

#### First merge: `5` bottom list with `10` bottom list

🔁 Merged into one sorted bottom list:

```
5 -> 7 -> 8 -> 10 -> 20 -> 30
```

Repeat with 19, then 28...

---

### ✅ Time & Space Complexity

| Operation     | Complexity              |
| ------------- | ----------------------- |
| Merge 2 lists | O(N)                    |
| Flattening    | O(N \* M) in worst case |
| Space (extra) | O(1) (in-place merge)   |

---

## ✅ PART 2: Merge K Sorted Linked Lists

---

### 🔹 Problem:

Given `K` linked lists, merge them into one sorted linked list.

---

### 🔸 Approach 1: Brute Force / Sequential Merge

```cpp
Node* mergeKLists(vector<Node*>& arr) {
    int k = arr.size();
    Node *head = arr[0];

    for (int i = 1; i < k; i++) {
        head = Merge(head, arr[i]);
    }

    return head;
}
```

---

#### 🔹 Merge Function (Used for `next` pointers):

```cpp
Node* Merge(Node *head1, Node *head2) {
    Node *head = new Node(0); // dummy node
    Node *tail = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
        tail->next = NULL;
    }

    tail->next = head1 ? head1 : head2;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}
```

---

### ✅ Time & Space Complexity – Approach 1

| Operation       | Complexity |
| --------------- | ---------- |
| Merging 2 lists | O(N)       |
| Merging K lists | O(KN)      |
| Space           | O(1)       |

Not optimal for large K.

---

### 🔸 Approach 2: Merge Sort Style (Divide & Conquer)

```cpp
void MergeSort(vector<Node*>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);

    arr[start] = Merge(arr[start], arr[mid + 1]);
}

Node* mergeKLists(vector<Node*>& arr) {
    int k = arr.size();
    if (k == 0) return NULL;

    MergeSort(arr, 0, k - 1);
    return arr[0];
}
```

---

### ✅ Time & Space Complexity – Approach 2

| Operation        | Complexity    |
| ---------------- | ------------- |
| Merge steps      | log(K)        |
| Each merge cost  | O(N)          |
| Total            | O(N \* log K) |
| Space (in-place) | O(1)          |

---

### 📊 Merge Sort Example Walkthrough:

Suppose K = 4, and lists are:

```
arr = [L1, L2, L3, L4]
```

Break them:

* MergeSort(L1, L2)
* MergeSort(L3, L4)
* Merge(Merged12, Merged34)

Final merged list in `arr[0]`

---

## ✅ Visualization: Merging 3 Lists

```text
L1: 1 -> 4 -> 7
L2: 2 -> 5 -> 8
L3: 3 -> 6 -> 9

Step 1: Merge L1 and L2 → 1 -> 2 -> 4 -> 5 -> 7 -> 8  
Step 2: Merge result with L3 → Final list:  
→ 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
```

---

## ✅ Summary Chart

| Feature            | Flatten List | Merge K Lists (Brute) | Merge K Lists (Sort) |
| ------------------ | ------------ | --------------------- | -------------------- |
| Merge pointer used | `bottom`     | `next`                | `next`               |
| In-place?          | ✅ Yes        | ✅ Yes                 | ✅ Yes                |
| Complexity         | O(N \* M)    | O(N \* K)             | O(N log K)           |
| Extra Space        | O(1)         | O(1)                  | O(1)                 |

---

