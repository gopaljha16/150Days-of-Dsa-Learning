Here are detailed, GitHub-style notes for **Day 62: Clone a Linked List with Next and Random Pointer** (Hard Level – GFG), including 3 methods, full line-by-line code explanations, and **step-by-step diagrammatic walkthroughs** with **time and space complexity**.

---

# 📚 Day 62: Clone a Linked List with Next and Random Pointer

## 🔗 Problem Statement

You are given a linked list where each node has two pointers:

* `next` → points to the next node
* `random` → points to a **random node** in the list or `NULL`

**Goal:** Clone this list **deeply**, i.e., create a **new list** where each node is a **new object**, with `next` and `random` pointers having the **same structure** as the original list.

---

## 👨‍🔬 Example

```
Original List:    A → B → C → D → NULL
Random Pointers:  A.random → C  
                  B.random → A  
                  C.random → NULL  
                  D.random → B  

Cloned List:      A' → B' → C' → D' → NULL
Random Pointers:  A'.random → C'  
                  B'.random → A'  
                  C'.random → NULL  
                  D'.random → B'
```

---

## ✅ Method 1: Brute Force with Helper Find Function

### Time: `O(n^2)`

### Space: `O(n)` for cloned list

---

### 🔧 Idea

* Create a copy list with only `next` pointers.
* For `random` pointers, **for each original node**, use a **`find` function** to locate and assign the matching random node in the copied list.

---

### 🔍 `find(curr1, curr2, x)`

This function finds the node in the cloned list that corresponds to the address `x` in the original list.

---

### 🧠 Code Breakdown

```cpp
Node* find(Node *curr1 , Node *curr2 , Node *x){
    if(x == NULL) return NULL;
    while(curr1 != x){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr2;
}
```

---

### 🧩 Full Clone Function

```cpp
Node *cloneLinkedList(Node *head) {
    // 1. Create a dummy node for cloned list
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // 2. Copy only next pointers (linear traversal)
    while(temp){
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    // 3. Remove dummy
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // 4. Set random pointers using find()
    tailCopy = headCopy;
    temp = head;
    while(temp){
        tailCopy->random = find(head, headCopy, temp->random);
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    return headCopy;
}
```

---

### 🔄 Dry Run Diagram

```
Original:   A → B → C
Clone:      A'→ B'→ C'
Temp:        ↑   ↑   ↑
Rand:     A.random → C → C'
```

`find(head, headCopy, temp->random)` moves both original and copy together until match.

---

### 📊 Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n²) |
| Space Complexity | O(n)  |

---

## 🚀 Method 2: Using `unordered_map`

### Time: `O(n)`

### Space: `O(n)`

---

### 🧠 Idea

* Create the clone with only `next` pointers.
* Use a map to **link original nodes** to **their copies**.
* For each `random`, look up using the map.

---

### 🔍 Code with Explanation

```cpp
Node *cloneLinkedList(Node *head) {
    // 1. Create dummy and clone next pointers
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;
    
    while(temp){
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // 2. Map each original node to its clone
    unordered_map<Node*, Node*> m;
    tailCopy = headCopy;
    temp = head;
    while(temp){
        m[temp] = tailCopy;
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    // 3. Assign random pointers using map
    temp = head;
    tailCopy = headCopy;
    while(temp){
        tailCopy->random = m[temp->random];
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    return headCopy;
}
```

---

### 🔄 Dry Run

```
Original:  A → B → C
Clone:     A'→ B'→ C'
Map:   A→A', B→B', C→C'
Random: A.random → C → m[C] → C'
```

---

### 📊 Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(n)  |

---

## 🏆 Method 3: Most Optimized (No Extra Space)

### Time: `O(n)`

### Space: `O(1)` (excluding output list)

---

### 🔧 Idea

1. **Insert cloned nodes** in between original nodes.
2. Use interleaved structure to set random pointers.
3. Detach the interleaved lists into two.

---

### 🔍 Code Walkthrough

```cpp
Node *cloneLinkedList(Node *head) {
    if(!head) return NULL;

    // Step 1: Insert cloned nodes
    Node *curr = head;
    while(curr){
        Node *copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Assign random pointers
    curr = head;
    while(curr){
        if(curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate original and cloned lists
    Node *original = head;
    Node *copy = head->next;
    Node *copyHead = copy;

    while(original){
        original->next = original->next->next;
        if(copy->next)
            copy->next = copy->next->next;
        original = original->next;
        copy = copy->next;
    }

    return copyHead;
}
```

---

### 🧩 Example Diagram

```
Original + Clone Interleaved:

A → A' → B → B' → C → C' → NULL
     ↑        ↑        ↑
     |        |        |
    A'.rand B'.rand  C'.rand (set by curr->random->next)

Step 3:
Split into two:
Original: A → B → C
Clone:    A'→ B'→ C'
```

---

### 📊 Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

---

## 🧾 Final Notes

| Method     | Time  | Space | Extra Data Structure  |
| ---------- | ----- | ----- | --------------------- |
| Method 1   | O(n²) | O(n)  | No                    |
| Method 2   | O(n)  | O(n)  | Unordered Map         |
| Method 3 ✅ | O(n)  | O(1)  | In-place manipulation |

✅ **Recommended Approach:** Method 3 (interleaving technique) for optimal performance.

---

L