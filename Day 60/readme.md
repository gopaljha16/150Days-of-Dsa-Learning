// ✅ DAY 60: Add Two Numbers Represented by Linked Lists & Reverse in Groups of K

/* -------------------------------------------------------------------
   🧠 Problem 1: Add Two Numbers Represented by Linked Lists (GFG Medium)
   ------------------------------------------------------------------- */

// 🔁 Recursive function to reverse a linked list
Node* Reverse(Node *curr , Node *prev) {
    if (curr == NULL) return prev; // base case

    Node *fut = curr->next; // store next node
    curr->next = prev;      // reverse the link
    return Reverse(fut, curr); // recurse
}

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // Step 1: Reverse both lists
        num1 = Reverse(num1 , NULL);
        num2 = Reverse(num2 , NULL);

        // Step 2: Prepare dummy node for result list
        Node *curr1 = num1 , *curr2 = num2;
        Node *head = new Node(0); // dummy node to simplify logic
        Node *tail = head;
        int carry = 0;

        // Step 3: Add digits from both lists with carry
        while(curr1 && curr2) {
            int sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum % 10);
            carry = sum / 10;

            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        // Step 4: If num1 is longer
        while(curr1) {
            int sum = curr1->data + carry;
            tail->next = new Node(sum % 10);
            carry = sum / 10;
            tail = tail->next;
            curr1 = curr1->next;
        }

        // Step 5: If num2 is longer
        while(curr2) {
            int sum = curr2->data + carry;
            tail->next = new Node(sum % 10);
            carry = sum / 10;
            tail = tail->next;
            curr2 = curr2->next;
        }

        // Step 6: If carry still exists
        while(carry) {
            tail->next = new Node(carry % 10);
            carry /= 10;
            tail = tail->next;
        }

        // Step 7: Reverse the result list
        return Reverse(head->next, NULL);
    }
};

/* -------------------------------------------------------------------
   🧠 Problem 2: Reverse a Linked List in Groups of Size K (GFG Medium)
   ------------------------------------------------------------------- */

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // Step 1: Create dummy node for simplified handling
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *first = dummy;

        while(first->next) {
            int x = k;
            Node *second = first->next; // start of group
            Node *prev = first;
            Node *curr = first->next;
            Node *front;

            // Step 2: Reverse k nodes
            while(x && curr) {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                x--;
            }

            // Step 3: Update pointers
            first->next = prev;
            second->next = curr;
            first = second;
        }

        // Step 4: Cleanup dummy
        Node *temp = dummy;
        head = dummy->next;
        delete temp;
        return head;
    }
};

/*
🧮 Time & Space Complexities
----------------------------
1. AddTwoLists:
   - Time: O(N + M), where N and M are lengths of num1 and num2
   - Space: O(Max(N, M)) for result linked list

2. ReverseKGroup:
   - Time: O(N), each node visited once
   - Space: O(1), in-place reversal (excluding recursion stack if using recursion)

🧪 Example:
----------
num1 = 7 -> 5 -> 9 (represents 957)
num2 = 5 -> 6 -> 4 (represents 465)
Output: 2 -> 2 -> 4 -> 1 (represents 1422)

Reverse In Groups of 3:
Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4

🧠 Visual Diagrams:
-------------------
1. Reverse:
   Before: A -> B -> C -> NULL
   After : C -> B -> A -> NULL

2. AddTwoLists:
   Reverse both → Add → Handle carry → Reverse result

3. ReverseKGroup:
   Group1: Reverse k nodes → update links → repeat
*/
You're right — the current `reverseKGroup` implementation in your Day 60 file doesn't correctly reverse the list in **groups of size K**, especially if the number of nodes is **not a multiple of K**. Let's fix that by implementing a correct version of the "Reverse K-Group" problem with full explanation and updated code.

---

### ✅ Updated Code: `reverseKGroup` with Proper Group Checking

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: Count total nodes
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Step 2: Initialize dummy for ease
        Node* dummy = new Node(0);
        dummy->next = head;

        Node* prevGroupEnd = dummy;

        while (count >= k) {
            Node* curr = prevGroupEnd->next;
            Node* next = curr->next;

            // Step 3: Reverse K nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prevGroupEnd->next;
                prevGroupEnd->next = next;
                next = curr->next;
            }

            // Move prevGroupEnd k steps forward
            prevGroupEnd = curr;
            count -= k;
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
```

---

### ✅ Explanation with Dry Run

#### Suppose input:

```
List = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7, k = 3
```

#### Step-by-step groups:

* Group 1: 1 -> 2 -> 3 → reversed to 3 -> 2 -> 1
* Group 2: 4 -> 5 -> 6 → reversed to 6 -> 5 -> 4
* Remaining: 7 (less than k, so left as-is)

#### Final Output:

```
3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
```

---

### ✅ Why Previous Code Fails

Your earlier implementation:

```cpp
while(x && curr) { /* reverse */ }
```

It **reverses whatever nodes are available**, even if less than `k`, leading to incorrect results when:

* Total nodes are not a multiple of `k`.
* It allows incomplete groups to reverse, which should not happen.

---

### ✅ Time & Space Complexity

* **Time:** O(N), where N is total number of nodes
* **Space:** O(1), as it's an in-place algorithm (no recursion used)

---


