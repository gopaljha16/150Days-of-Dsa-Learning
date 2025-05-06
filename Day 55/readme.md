Here's a **deeply explained Day 55 Linked List Notes** with full program flow, line-by-line breakdown, and all edge cases for the following problems:

---

## ✅ 1. **Leetcode 19: Remove Nth Node From End of List (Medium)**

### 🔹 Problem:

Remove the nth node from the **end** of a singly linked list and return the head.

---

### ✅ Code Explanation:

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp = head;
    int count = 0;

    // Step 1: Count the total number of nodes in the list
    while(temp){
        count++;
        temp = temp->next;
    }

    count -= n;  // Position from the front

    // Step 2: Special Case — Remove first node
    if(count == 0){
        temp = head;         // store head
        head = head->next;   // move head to next
        delete temp;         // delete the old head
        return head;         // return new head
    }

    // Step 3: Traverse to the (count-1)th node
    ListNode *curr = head, *prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }

    // Step 4: Bypass the node to be deleted
    prev->next = curr->next;
    delete curr;

    return head;
}
```

---

### 🔹 Step-by-step Flow:

1. **Count Nodes**:

   * Loop through the list and count total nodes.
   * Example: List = \[1, 2, 3, 4, 5], count = 5

2. **Find Position from Start**:

   * We want to delete 2nd from the end → 5 - 2 = 3
   * So delete 3rd node from start (0-indexed)

3. **Edge Case - Deleting first node**:

   * If `count == 0`, that means the head is the target node.
   * Just delete the head and return `head->next`

4. **Normal Case**:

   * Traverse to the node just before the one to delete (`prev`)
   * Bypass it by: `prev->next = curr->next`
   * Delete `curr`

---

### 🧠 Example:

**Input:** `[1,2,3,4,5], n = 2`
**Output:** `[1,2,3,5]`
Deleted 4th node (value 4)

---

## ✅ 2. **GFG: Delete Every Kth Node from Linked List (Easy)**

### 🔹 Problem:

Delete every kth node from the linked list.

---

### ✅ Code Explanation:

```cpp
Node* deleteK(Node* head, int k) {
    Node *curr = head, *prev = NULL;
    int count = 1;

    if(k == 1)
        return NULL;  // Delete all nodes

    while(curr){
        if(count == k){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 1;
        } else {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    return head;
}
```

---

### 🔹 Step-by-step Flow:

1. **Special Case**:

   * If `k == 1`, delete all nodes → Return NULL.

2. **Traverse List**:

   * Maintain count of nodes.
   * When `count == k`, delete that node and reset count.
   * Move pointers correctly after deletion.

---

### 🧠 Example:

**Input:** `[1,2,3,4,5,6], k=3`
**Output:** `[1,2,4,5]`
Deleted nodes at position 3 and 6.

---

## ✅ 3. **Leetcode: Rotate List Right (Medium)**

---

### ✅ Code Explanation:

```cpp
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL)
        return head;

    int count = 0;
    ListNode* temp = head;

    // Count total nodes
    while(temp){
        count++;
        temp = temp->next;
    }

    k = k % count;  // To avoid extra rotations
    if(k == 0)
        return head;

    // Position to split: count - k
    int skip = count - k;
    ListNode *curr = head, *prev = NULL;

    while(skip--){
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;  // Break the list into two parts

    ListNode* tail = curr;
    while(tail->next){
        tail = tail->next;
    }

    // Connect last part to first
    tail->next = head;

    return curr; // new head
}
```

---

### 🔹 Step-by-step Flow:

1. **Edge Case**:

   * If list has 0 or 1 node → No change.

2. **Count Nodes**:

   * Needed to find the point to rotate.

3. **Normalize k**:

   * Rotating length times doesn’t change the list.
   * `k = k % count`

4. **Split List**:

   * Break at position `count - k`
   * Part 1: Head to prev
   * Part 2: curr to tail

5. **Reconnect**:

   * Tail of part 2 → connects to head
   * Return `curr` as new head

---

### 🧠 Example:

**Input:** `[1,2,3,4,5], k=2`
**Output:** `[4,5,1,2,3]`

---

## ✅ 4. **Leetcode: Palindrome Linked List (Easy)**

---

### ✅ Code Explanation:

```cpp
bool isPalindrome(ListNode* head) {
    if(head->next == NULL)
        return true;

    // Count nodes
    int count = 0;
    ListNode *temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }

    count /= 2;

    // Break into two halves
    ListNode *curr = head, *prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    // Reverse second half
    ListNode *front = NULL;
    prev = NULL;
    while(curr){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    // Compare both halves
    ListNode *head1 = head, *head2 = prev;
    while(head1){
        if(head1->val != head2->val)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}
```

---

### 🔹 Step-by-step Flow:

1. **Edge Case**:

   * If only one node → Always a palindrome

2. **Count Total Nodes**:

   * Needed to split list in half

3. **Split the List**:

   * Traverse half of it and break the link

4. **Reverse Second Half**:

   * Classic list reversal to compare from end

5. **Compare Two Halves**:

   * One from start, one from reversed second half

---

### 🧠 Example:

**Input:** `[1,2,2,1]`
**Output:** `true`
First half: \[1,2], Second half reversed: \[1,2]

---

## 🔚 Summary Table

| Problem                  | Key Steps                    | Space | Time |
| ------------------------ | ---------------------------- | ----- | ---- |
| Remove Nth Node From End | Count, Traverse, Delete      | O(1)  | O(N) |
| Delete Every Kth Node    | Loop with count              | O(1)  | O(N) |
| Rotate Right             | Count, Break, Reconnect      | O(1)  | O(N) |
| Palindrome Check         | Reverse second half, Compare | O(1)  | O(N) |

---


