Here are your **Day 64: Introduction to Stack** notes with **detailed explanation, code walkthroughs, diagrams**, and **time/space complexity** analysis.

---

# 📚 Day 64: Introduction to Stack – Implementation Using Array & Linked List

---

## 📌 1. What is a Stack?

A **Stack** is a **linear data structure** that follows the **LIFO (Last In First Out)** principle.

* Think of a **stack of plates** – you add (push) plates on top and remove (pop) the topmost plate first.

### 🔑 Key Operations:

| Operation | Description                    |
| --------- | ------------------------------ |
| `push`    | Adds element to the top        |
| `pop`     | Removes element from the top   |
| `peek`    | Views the top element          |
| `isEmpty` | Checks if the stack is empty   |
| `size`    | Returns the number of elements |

---

## 🔧 2. Stack Using Array (Code Explained Line-by-Line)

### ✅ Code

```cpp
#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int size;
    int top;
public:
    int flag;
    Stack(int s) {
        size = s;
        top = -1;              // top = -1 means stack is empty
        arr = new int[s];      // dynamic array of size 's'
        flag = 1;              // flag = 1 means empty stack
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = value;
        cout << "Pushed " << value << " Into the stack\n";
        flag = 0; // flag = 0 means stack has elements now
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
        } else {
            cout << "Popped " << arr[top] << " from the stack\n";
            top--;
            if(top == -1) flag = 1;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int IsSize() {
        return top + 1;
    }
};

int main() {
    Stack S(5);
    int value = S.peek();
    if(S.flag == 0){
        cout << value;
    }
}
```

---

### 💡 Stack Visualization (Array)

```txt
Index :   0     1     2     3     4
Stack : [10] [20] [30] [40] [50]
                   ↑
                 top=4
```

---

### ⏱️ Time & Space Complexity (Array Stack)

| Operation | Time | Space |
| --------- | ---- | ----- |
| Push      | O(1) | O(n)  |
| Pop       | O(1) | O(n)  |
| Peek      | O(1) | O(1)  |
| isEmpty   | O(1) | O(1)  |

* Space is O(n) due to dynamic array allocation

---

## 🔗 3. Stack Using Linked List (Deep Explanation)

### ✅ Code

```cpp
class Node {
public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Stack {
    Node *top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int value) {
        Node *temp = new Node(value);
        if (temp == NULL) {
            cout << "Stack Overflow" << endl;
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        cout << "Pushed " << value << " in stack " << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is Underflow";
            return;
        }
        Node *temp = top;
        cout << "Popped " << temp->data << " from the stack" << endl;
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    int IsSize() {
        return size;
    }
};
```

---

### 🧠 Line-by-Line Execution (Linked List)

```cpp
S.push(10);
```

* Creates Node(10) → top points to Node(10)

```cpp
S.push(20);
```

* Creates Node(20) → Node(20)->next = Node(10)

```cpp
S.pop();
```

* Removes Node(20) → top = Node(10)

```cpp
S.peek(); // Returns 10
```

---

### 📊 Diagrammatic View (Linked List Stack)

```txt
TOP → [30 | *] → [20 | *] → [10 | NULL]
```

Each node stores:

* Value (data)
* Pointer to next node

---

### ⏱️ Time & Space Complexity (Linked List Stack)

| Operation | Time | Space |
| --------- | ---- | ----- |
| Push      | O(1) | O(n)  |
| Pop       | O(1) | O(n)  |
| Peek      | O(1) | O(1)  |
| isEmpty   | O(1) | O(1)  |

* Space = O(n) for `n` nodes (each with data + pointer)

---

## 🔄 4. STL Stack in C++

```cpp
#include <stack>
using namespace std;

int main() {
    stack<int> S;
    S.push(10);    // O(1)
    S.push(20);
    S.push(30);
    cout << S.top() << endl; // 30
    S.pop();
    cout << S.size() << endl; // 2
    cout << S.empty() << endl; // false
}
```

* `std::stack` uses **deque** internally
* Same LIFO behavior
* Fast and memory-safe

---

## 🧠 When to Use Which Stack?

| Scenario                    | Use         |
| --------------------------- | ----------- |
| Fixed-size stack            | Array       |
| Dynamic-size stack          | Linked List |
| Standard C++ program        | STL `stack` |
| Low memory & custom control | Linked List |

---

## 🎯 Use Case: Stack Examples

1. **Browser History** – back/forward (LIFO)
2. **Undo Operation** – most recent action undone first
3. **Parenthesis Matching** – check balanced expressions
4. **Function Call Stack** – recursion management

---

## 🧩 Summary Table

| Feature         | Array Stack       | Linked List Stack     |
| --------------- | ----------------- | --------------------- |
| Fixed Size      | ✅ Yes             | ❌ No                  |
| Dynamic Growth  | ❌ Needs resizing  | ✅ Easy                |
| Memory Usage    | ✅ Contiguous      | ❌ Extra pointer space |
| Code Simplicity | ✅ Easy            | ❌ More pointers       |
| Access Speed    | ✅ Fast (indexing) | ✅ Fast (top only)     |

---

