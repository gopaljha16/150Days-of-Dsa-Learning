### Day 59: Detect and Remove Loop in Linked List & Intersection in Y Shaped Lists

---

## 🔍 Problem 1: Remove Loop in Linked List

### ✅ Problem Statement (GFG Medium):

Given a linked list, detect and remove the loop (if any) without losing any nodes.

---

## 🔄 Method 1: Floyd’s Cycle Detection (Tortoise and Hare)

### Code:

```cpp
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect Loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // Step 2: No loop found
    if (fast == NULL || fast->next == NULL) return;

    // Step 3: Move slow to head
    slow = head;

    // Step 4: Find start of loop
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 5: Move to last node in loop and break it
    while (slow->next != fast) {
        slow = slow->next;
    }
    slow->next = NULL;
}
```

### 🔄 Line-by-Line Explanation:

1. **Loop detection**: Fast moves 2 steps, slow moves 1. If they meet, loop exists.
2. **Breaking Condition**: If `fast` or `fast->next` is NULL, no loop.
3. **Slow reset to head**: When loop detected, reset `slow`.
4. **Find loop start**: Move both one step at a time until they meet.
5. **Locate last loop node**: Move `slow` till `slow->next == fast` and remove loop.

### ⏱ Time Complexity:

* O(N) for detection
* O(N) for loop removal
* Total: **O(N)**

### ⚖️ Space Complexity:

* **O(1)** (no extra space)

---

## 🔄 Method 2: Using Loop Length

### Code:

```cpp
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Detect Loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (fast == NULL || fast->next == NULL) return;

    // Count loop length
    int count = 1;
    slow = slow->next;
    while (slow != fast) {
        count++;
        slow = slow->next;
    }

    // Move fast ahead by count nodes
    slow = head;
    fast = head;
    while (count--) fast = fast->next;

    // Move both to find start of loop
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Find last node and break loop
    while (slow->next != fast) slow = slow->next;
    slow->next = NULL;
}
```

### Key Idea:

* Count nodes in the loop.
* Move `fast` pointer that many steps ahead, then move both to meet.
* Find loop end and break it.

---

## 🌐 Problem 2: Intersection Point in Y Shaped Linked List

### ✅ Problem Statement:

Two singly linked lists intersect at some node. Find the intersection point.

---

## 🔄 Method 1: Length Based Traversal

### Code:

```cpp
Node* intersectPoint(Node* head1, Node* head2) {
    Node *curr1 = head1, *curr2 = head2;
    int count1 = 0, count2 = 0;

    while (curr1) { count1++; curr1 = curr1->next; }
    while (curr2) { count2++; curr2 = curr2->next; }

    curr1 = head1;
    curr2 = head2;

    while (count1 > count2) { curr1 = curr1->next; count1--; }
    while (count2 > count1) { curr2 = curr2->next; count2--; }

    while (curr1 && curr2) {
        if (curr1 == curr2) return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return NULL;
}
```

### 🔄 Line-by-Line:

1. Count length of both lists.
2. Move longer list's pointer by length difference.
3. Move both together and check if they meet.

### ⏱ Time: O(N + M)

### ⚖️ Space: O(1)

---

## 🔄 Method 2: Loop Trick

### Code:

```cpp
Node* intersectPoint(Node* head1, Node* head2) {
    Node *tail = head1;
    while (tail->next) tail = tail->next;
    tail->next = head1; // Make loop

    Node *slow = head2, *fast = head2;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (!fast || !fast->next) {
        tail->next = NULL;
        return NULL;
    }

    slow = head2;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    tail->next = NULL;
    return slow;
}
```

### 📅 Idea:

* Join end of list1 to head1 to form a loop.
* Use Floyd's detection from head2.
* Where they meet is the intersection point.
* Restore original structure by removing the loop.

### ⏱ Time: O(N + M)

### ⚖️ Space: O(1)

---

## 🔹 Visualization Diagram:

### 👀 Detect and Remove Loop:

```
A -> B -> C -> D -> E
          ^        |
          |________|
```

After removal:

```
A -> B -> C -> D -> E -> NULL
```

### 🌐 Y Shaped Intersection:

```
List1: A -> B -> C
                  \
                   D -> E -> F
                  /
List2:     X -> Y
```

Intersection at Node D

---

## ✅ Summary:

| Problem      | Method           | Time   | Space |
| ------------ | ---------------- | ------ | ----- |
| Remove Loop  | Floyd's          | O(N)   | O(1)  |
| Remove Loop  | Count-based      | O(N)   | O(1)  |
| Intersection | Length-based     | O(N+M) | O(1)  |
| Intersection | Loop-based trick | O(N+M) | O(1)  |
