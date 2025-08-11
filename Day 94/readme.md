# Day 94 C++ STL Containers Guide - List, Pair, Set, Map

## Overview

This code demonstrates the usage of essential STL (Standard Template Library) containers in C++, including:
- **List**: Doubly-linked list implementation
- **Pair**: Container to hold two values together
- **Set/Multiset**: Sorted containers with unique/duplicate elements
- **Map/Multimap**: Key-value pair containers with sorted keys
- **Unordered variants**: Hash-based versions of set and map for faster access

The code showcases basic operations like insertion, deletion, iteration, and searching for each container type.

---

## 1. List Container

### Code Analysis

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    //creating list 
    list<int>l; //type is int and this will be creating the list in the doubly linked list
    //operation 
    // push_back , push_front , pop_front() , pop_back() , size , front , back , empty;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.pop_front();

    //iterator prints the value
    for(auto it=l.begin() ; it!=l.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //so here we can print the reversly also 
    for(auto it=l.rbegin() ; it!=l.rend(); it++){
        cout<<*it<<" ";
    }
}
```

### Line-by-Line Explanation

- **Line 6**: `list<int>l;` - Creates an empty doubly-linked list of integers
- **Lines 9-12**: Add elements to the back of the list using `push_back()`
- **Line 13**: `l.pop_front();` - Removes the first element (20)
- **Lines 15-18**: Forward iteration using iterators from `begin()` to `end()`
- **Lines 21-23**: Reverse iteration using reverse iterators from `rbegin()` to `rend()`

### Example Input/Output

**Operations performed:**
```
Initial: []
After push_back(20): [20]
After push_back(30): [20, 30]
After push_back(40): [20, 30, 40]
After push_back(50): [20, 30, 40, 50]
After pop_front(): [30, 40, 50]
```

**Output:**
```
30 40 50 
50 40 30 
```

### Dry Run Walkthrough

1. **Initialization**: Empty list `l`
2. **Insertion phase**: 
   ```
   Step 1: l = [20]
   Step 2: l = [20, 30]
   Step 3: l = [20, 30, 40]
   Step 4: l = [20, 30, 40, 50]
   ```
3. **Deletion**: `pop_front()` removes 20 → `l = [30, 40, 50]`
4. **Forward iteration**: Prints 30, 40, 50
5. **Reverse iteration**: Prints 50, 40, 30

### Visual Representation

```
Initial List Structure (Doubly-linked):
┌─────┐    ┌─────┐    ┌─────┐
│ 30  │<-->│ 40  │<-->│ 50  │
└─────┘    └─────┘    └─────┘
   ↑                     ↑
 begin()               end()-1

Iteration Direction:
Forward:  30 → 40 → 50
Reverse:  50 ← 40 ← 30
```

---

## 2. Pair Container

### Code Analysis

```cpp
int main(){
    pair<string , pair<int, int>>p;
    p = make_pair("Gopal" , make_pair(20,50)); //name age weight
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
}
```

### Line-by-Line Explanation

- **Line 2**: Creates a nested pair: `string` paired with another pair of `int, int`
- **Line 3**: Uses `make_pair()` to assign values - "Gopal" and nested pair (20, 50)
- **Line 4**: Accesses nested values using `first`, `second.first`, `second.second`

### Example Input/Output

**Input data:** Name="Gopal", Age=20, Weight=50

**Output:**
```
Gopal 20 50
```

### Dry Run

1. **Declaration**: `p` can hold `(string, (int, int))`
2. **Assignment**: 
   - `p.first = "Gopal"`
   - `p.second.first = 20`
   - `p.second.second = 50`
3. **Access**: Print all three values

### Visual Structure

```
Pair Structure:
┌─────────────────────────────┐
│ p                           │
├─────────────┬───────────────┤
│ first       │ second        │
│ "Gopal"     │ ┌─────┬─────┐ │
│             │ │ 20  │ 50  │ │
│             │ └─────┴─────┘ │
│             │ first second  │
└─────────────┴───────────────┘
```

---

## 3. Set Container (with Custom Class)

### Code Analysis

```cpp
class Person{
    public:
    int age;
    string name;

    bool operator < (const Person &other) const{
        return age>other.age;
    }
};

int main(){
    set<Person>s;
    Person p1,p2,p3;
    p1.age = 20 , p1.name = "Gopal";
    p2.age = 30 , p2.name = "Gopu";
    p3.age = 40 , p3.name = "Npu";

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for(auto it=s.begin() ; it!=s.end() ; it++){
        cout<<it->age<<" "<<it->name<<endl;
    }
}
```

### Line-by-Line Explanation

- **Lines 1-8**: Define `Person` class with custom `operator<` for sorting by age (descending)
- **Lines 11-15**: Create three `Person` objects with different ages
- **Lines 17-19**: Insert objects into the set
- **Lines 21-23**: Iterate and print using arrow operator to access member variables

### Example Output

```
40 Npu
30 Gopu
20 Gopal
```

### Dry Run

1. **Object creation**:
   - p1: age=20, name="Gopal"
   - p2: age=30, name="Gopu" 
   - p3: age=40, name="Npu"

2. **Insertion with custom sorting**:
   - Custom `operator<` returns `age > other.age`
   - This creates descending age order: 40 → 30 → 20

3. **Final set order**: [p3(40), p2(30), p1(20)]

### Set Ordering Visualization

```
Custom Operator Logic:
For p1.age=20, p2.age=30: p1 < p2 → 20 > 30 → false
For p2.age=30, p3.age=40: p2 < p3 → 30 > 40 → false
For p1.age=20, p3.age=40: p1 < p3 → 20 > 40 → false

Result: Set orders as [40, 30, 20] (descending)
```

---

## 4. Multiset Container

### Code Analysis

```cpp
int main(){
    multiset<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(10);  // Duplicate allowed

    s.erase(10);   // Removes ALL occurrences

    for(auto it=s.begin() ; it!=s.end() ; it++){
        cout<<*it<<" ";
    }
}
```

### Key Differences from Set

- **Duplicates allowed**: Can insert multiple identical values
- **Erase behavior**: `erase(10)` removes ALL occurrences of 10

### Example Output

```
20 30 40 
```

### Dry Run

1. **Insertions**: `s = [10, 10, 20, 30, 40]` (sorted with duplicates)
2. **Erase**: Remove all 10s → `s = [20, 30, 40]`
3. **Output**: Print remaining elements

---

## 5. Map Container

### Code Analysis

```cpp
int main(){
    map<int,int>m;
    
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,10));
    m.insert(make_pair(40,110));
    m.insert(make_pair(50,33));
    m.insert(make_pair(60,40));
    m.insert(make_pair(20,50));  // Duplicate key - ignored

    m.erase(20);

    if(m.count(20)){
        cout<<m[20]<<endl;
    }

    for(auto it=m.begin() ; it!=m.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
```

### Key Features

- **Unique keys**: Duplicate key insertion is ignored
- **Sorted by keys**: Automatically sorts by key values
- **Safe access**: Use `count()` to check existence before accessing

### Example Output

```
30 10
40 110
50 33
60 40
```

### Map Operations Table

| Operation | Before | After | Notes |
|-----------|---------|--------|--------|
| `insert(20,30)` | `{}` | `{20:30}` | First insertion |
| `insert(20,50)` | `{20:30,...}` | `{20:30,...}` | Duplicate key ignored |
| `erase(20)` | `{20:30,...}` | `{30:10,...}` | Key-value pair removed |
| `m[key]` | - | - | Direct access (creates if not exists) |

---

## 6. Unordered Containers

### Unordered Multiset

```cpp
unordered_multiset<int>s;
s.insert(10);
s.insert(20);
s.insert(30);
s.insert(40);
s.insert(50);
s.insert(50);  // Duplicate allowed
```

### Unordered Multimap

```cpp
unordered_multimap<int,int>m;
m.insert(make_pair(20, 30));
m.insert(make_pair(30, 10));
// ... more insertions
m.insert(make_pair(20, 50));  // Duplicate key allowed
```

### Key Characteristics

- **Hash-based**: O(1) average access time
- **No ordering**: Elements not sorted
- **Multimap**: Allows duplicate keys

---

## Container Comparison Summary

| Container | Ordering | Duplicates | Key Features |
|-----------|----------|------------|--------------|
| `list` | Insertion order | Yes | Doubly-linked, efficient insertion/deletion |
| `set` | Sorted | No | Unique elements, O(log n) operations |
| `multiset` | Sorted | Yes | Allows duplicates, O(log n) operations |
| `map` | Sorted by key | Keys: No, Values: Yes | Key-value pairs, O(log n) operations |
| `multimap` | Sorted by key | Yes | Multiple identical keys allowed |
| `unordered_set` | None | No | Hash-based, O(1) average operations |
| `unordered_multiset` | None | Yes | Hash-based with duplicates |
| `unordered_map` | None | Keys: No, Values: Yes | Hash-based key-value pairs |
| `unordered_multimap` | None | Yes | Hash-based with duplicate keys |

## Performance Characteristics

```
Time Complexity Comparison:
┌─────────────────┬─────────────┬─────────────┬─────────────┐
│ Container       │ Insert      │ Search      │ Delete      │
├─────────────────┼─────────────┼─────────────┼─────────────┤
│ list            │ O(1)*       │ O(n)        │ O(1)*       │
│ set/multiset    │ O(log n)    │ O(log n)    │ O(log n)    │
│ map/multimap    │ O(log n)    │ O(log n)    │ O(log n)    │
│ unordered_*     │ O(1) avg    │ O(1) avg    │ O(1) avg    │
└─────────────────┴─────────────┴─────────────┴─────────────┘
* At known position
```

This comprehensive guide covers the fundamental STL containers, their operations, and practical usage patterns. Each container serves specific use cases based on requirements for ordering, uniqueness, and performance characteristics.

# Chatgpt response 
# Day 94 — STL in C++: `list`, `pair`, `set`, `multiset`, `map`, `unordered_*`

## Overview

This README explains several short C++ examples demonstrating common STL containers and utilities from **Day 94**: `std::list`, `std::pair` (and nested `pair`), `std::set` (including custom comparator via `operator<`), `std::multiset`, `std::map`, `std::unordered_multiset` and `std::unordered_multimap`.
For each snippet I give:

* a clear, section-wise explanation,
* example outputs,
* a detailed dry-run for the `set<Person>` example,
* helpful ASCII diagrams and a short summary.

> Note: these snippets are simple, self-contained programs that print outputs (no runtime **input** is required). Compile with e.g. `g++ -std=c++17 file.cpp -o out && ./out`.

---

## Table of contents

* [1 — Common includes / style notes](#1---common-includes--style-notes)
* [2 — `std::list` (doubly linked list)](#2---stdlist-doubly-linked-list)
* [3 — `std::pair` (nested pair example)](#3---stdpair-nested-pair-example)
* [4 — `std::set` with class + custom `operator<`](#4---stdset-with-class--custom-operator)
* [5 — `std::multiset`](#5---stdmultiset)
* [6 — `std::map`](#6---stdmap)
* [7 — `std::unordered_multiset`](#7---stdunordered_multiset)
* [8 — `std::unordered_multimap`](#8---stdunordered_multimap)
* [9 — Comparison summary table](#9---comparison-summary-table)
* [10 — Summary](#10---summary)

---

## 1 — Common includes / style notes

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
```

* `#include <iostream>` — needed for `cout`, `endl`.
* `#include <bits/stdc++.h>` — convenient (includes most STL headers) but non-standard: works on many compilers (GCC) but not portable. For production prefer explicit headers like `<list>`, `<set>`, `<map>`, `<unordered_set>`, `<unordered_map>`, `<utility>`, `<string>`.
* `using namespace std;` — convenient in small code examples but consider avoiding it in large projects to prevent name collisions.

---

## 2 — `std::list` (doubly linked list)

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    // creating list
    list<int> l; // doubly linked list of int

    // operations: push_back, push_front, pop_front, pop_back, size, front, back, empty
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.pop_front();

    // forward print using iterator
    for(auto it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    // reverse print using reverse iterator
    for(auto it = l.rbegin(); it != l.rend(); ++it){
        cout << *it << " ";
    }
}
```

### Explanation (section-wise)

* `list<int> l;` — constructs an empty doubly-linked list of integers.
* `push_back(value)` — append `value` at the tail. O(1).
* `pop_front()` — removes the element at the head. O(1).
* `begin(), end()` — forward iterators to iterate from first to past-last.
* `rbegin(), rend()` — reverse iterators to iterate from last to before-first.

### Expected output

After the `push_back` sequence and `pop_front()` (removes `20`), the list becomes `30 40 50`.

```
30 40 50 
50 40 30 
```

(first line is forward order, second is reverse order).

### Visual (ASCII) of `std::list` after operations

```
head -> [30] <-> [40] <-> [50] -> tail
         ^        ^        ^
        prev     prev     prev
```

Each node stores links to `prev` and `next`. Iterators traverse these links.

---

## 3 — `std::pair` (nested pair example)

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<string, pair<int,int>> p;
    p = make_pair("Gopal", make_pair(20, 50)); // name, age, weight
    cout << p.first << " " << p.second.first << " " << p.second.second << endl;
}
```

### Explanation

* `pair<T1,T2>` stores two elements: `first` and `second`.
* Here the `second` itself is another `pair<int,int>` — nested pair used to hold `age` and `weight`.
* `make_pair(...)` constructs the pair conveniently.
* `p.first` => `"Gopal"`, `p.second.first` => `20`, `p.second.second` => `50`.

### Expected output

```
Gopal 20 50
```

---

## 4 — `std::set` with class + custom `operator<` (ordering)

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    int age;
    string name;

    bool operator < (const Person &other) const {
        return age > other.age;
    }
};

int main() {
    set<Person> s;
    Person p1, p2, p3;
    p1.age = 20; p1.name = "Gopal";
    p2.age = 30; p2.name = "Gopu";
    p3.age = 40; p3.name = "Npu";

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for(auto it = s.begin(); it != s.end(); ++it) {
        cout << it->age << " " << it->name << endl;
    }
}
```

### Explanation (section-wise)

* `class Person { ... bool operator<(const Person&) const; };`

  * `operator<` defines a strict ordering used by `std::set`.
  * **Important:** `return age > other.age;` — this intentionally **reverses** the usual ascending order: it makes the set order by **descending age**.
* `set<Person> s;` — `std::set` requires elements to be comparable using `<` (or a comparator template argument). Internally it's typically implemented as a balanced binary search tree (e.g., red-black tree).
* `s.insert(p1)` — inserts the element if no equivalent key exists. Set enforces **unique** elements (uniqueness judged by ordering equivalence).
* Iteration `s.begin()` → `s.end()` visits elements in the sorted order defined by `operator<`.

### Expected output

Because `operator<` returns `age > other.age` the set sorts **descending by age**:

```
40 Npu
30 Gopu
20 Gopal
```

### Detailed dry-run (step-by-step) — **inserting into `set<Person>`**

We will trace insertions and comparisons. The comparator is `a < b` ↔ `(a.age > b.age)` — so `a` comes before `b` when `a.age` is greater.

1. Start: `s` empty.

2. Insert `p1` (20, "Gopal"):

   * `s` becomes: \[ (20, Gopal) ]

3. Insert `p2` (30, "Gopu"):

   * Compare `p2` with node `(20, Gopal)`:
     `p2 < p1` evaluates to `(30 > 20)` → `true`, so `p2` is considered "less" (comes earlier) than `p1` in set order.
   * Insert `p2` to come before `p1`.
   * `s` becomes: \[ (30, Gopu), (20, Gopal) ]

4. Insert `p3` (40, "Npu"):

   * Compare `p3` vs root `(30, Gopu)`: `p3 < p2` -> `(40 > 30)` → `true` => goes before `(30, Gopu)`.
   * `s` becomes: \[ (40, Npu), (30, Gopu), (20, Gopal) ]

5. Iteration prints elements from first to last (which is descending ages 40→30→20).

### ASCII tree-like visualization (conceptual)

```
      (30,Gopu)
     /        \
 (40,Npu)    (20,Gopal)
```

> (This is a simplified view — real implementation uses balanced tree invariants, but relative order shown: 40 before 30 before 20.)

### Notes & gotchas

* `operator<` must implement a strict weak ordering. Returning `age > other.age` is legal but must be consistent.
* If two `Person` objects have same `age` and `operator<` doesn't distinguish them, the set may treat them as equivalent (only one will be stored). To allow duplicates you would use `multiset`.

---

## 5 — `std::multiset`

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(10);

    // erase all elements equal to 10
    s.erase(10);

    for(auto it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
}
```

### Explanation

* `multiset<int>` allows **duplicate** elements and keeps all elements sorted.
* `s.erase(10);` removes **all** occurrences of the value `10` from a `multiset`. (If you want to remove only one instance, you should `find` an iterator and `erase(iterator)`.)

### Expected output

After removing all `10`s:

```
20 30 40 
```

---

## 6 — `std::map`

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> m;

    m.insert(make_pair(20,30));
    m.insert(make_pair(30,10));
    m.insert(make_pair(40,110));
    m.insert(make_pair(50,33));
    m.insert(make_pair(60,40));
    m.insert(make_pair(20,50)); // duplicate key: ignored by insert

    // delete key 20
    m.erase(20);

    // safe access: check count before using operator[]
    if(m.count(20)){
        cout << m[20] << endl;
    }

    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
}
```

### Explanation

* `map<int,int>` is an ordered associative container with **unique keys**, usually implemented as a balanced tree.
* `insert(make_pair(key,value))` inserts only if `key` is not already present — the second insert for key `20` will have no effect.
* `m.erase(20)` removes the key `20`.
* `m.count(key)` returns `1` if the key exists (0 otherwise).
* `m[20]` returns a reference to the value for key `20` — if key doesn't exist, `m[20]` will insert a new element with default-constructed value (usually undesirable if you just want to check existence).

### Expected output

After erase(20), the map contains:

```
30 10
40 110
50 33
60 40
```

(each on its own line, in ascending key order).

---

## 7 — `std::unordered_multiset`

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_multiset<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(50);

    for(auto it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
}
```

### Explanation

* `unordered_multiset` uses a **hash table** (buckets) and allows **duplicates**.
* Elements are **not stored in sorted order**. Iteration order is unspecified (depends on hashing and bucket layout).
* Complexities: average O(1) for `insert`/`find`/`erase` (amortized) but worst-case can be different.

### Expected output

Order is unspecified; an example output might be:

```
20 40 50 10 30 50 
```

But your actual output may differ between runs/implementations.

---

## 8 — `std::unordered_multimap`

### Code snippet

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<int,int> m;
    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 10));
    m.insert(make_pair(40, 110));
    m.insert(make_pair(50, 33));
    m.insert(make_pair(60, 40));
    m.insert(make_pair(20, 50));

    for(auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}
```

### Explanation

* `unordered_multimap` stores **(key, value)** pairs in a hash-table-like structure.
* Multiple entries can have the same key (hence *multi*).
* Iteration order is **unspecified**.

### Example possible output

```
40 110
20 30
50 33
20 50
30 10
60 40
```

(Again, actual order may vary)

---

## 9 — Comparison summary table

| Container                 |                               Allows duplicates? | Ordering                  | Typical implementation | Typical lookup complexity |
| ------------------------- | -----------------------------------------------: | ------------------------- | ---------------------- | ------------------------: |
| `list<T>`                 | No (container elements can equal, but not keyed) | Sequence, insertion order | Doubly linked list     |               O(n) search |
| `pair<T1,T2>`             |                                              N/A | N/A                       | Utility struct         |                       N/A |
| `set<T>`                  |                                           **No** | Sorted (by `<`)           | Balanced BST (RB-tree) |                  O(log n) |
| `multiset<T>`             |                                          **Yes** | Sorted                    | Balanced BST           |                  O(log n) |
| `map<K,V>`                |                                      Keys unique | Sorted by key             | Balanced BST           |                  O(log n) |
| `unordered_set<T>`        |                                               No | Unordered                 | Hash table             |                  Avg O(1) |
| `unordered_multiset<T>`   |                                              Yes | Unordered                 | Hash table             |                  Avg O(1) |
| `unordered_map<K,V>`      |                                      Keys unique | Unordered                 | Hash table             |                  Avg O(1) |
| `unordered_multimap<K,V>` |                                              Yes | Unordered                 | Hash table             |                  Avg O(1) |

---

## 10 — Additional tips & best practices

* Prefer including only required headers (e.g., `<list>`, `<set>`, `<map>`, `<unordered_set>`, `<utility>`, `<string>`) for portability.
* Avoid `using namespace std;` in headers or large projects.
* Use `emplace()` instead of `insert(make_pair(...))` when constructing elements in-place to avoid copies:

  ```cpp
  m.emplace(20, 30);
  s.emplace(10);
  ```
* For `multiset`, if you want to remove just one element equal to `x`, do:

  ```cpp
  auto it = s.find(x);
  if (it != s.end()) s.erase(it); // erases only that iterator
  ```
* When using classes in ordered containers, make the comparator strict and consistent; prefer providing `struct Compare` to `set<T,Compare>` for clarity, or overload `operator<` carefully.

---

## Summary

This document walked through small example programs demonstrating:

* `std::list` — doubly linked list operations and forward/reverse iteration.
* `std::pair` — nested pairs for grouping values.
* `std::set` with a custom `operator<` — how the comparator controls ordering (we walked through insertion and ordering).
* `std::multiset` — duplicates allowed; `erase(value)` removes **all** occurrences.
* `std::map` — unique sorted keys; `insert` doesn’t overwrite existing keys; `operator[]` inserts if missing.
* `std::unordered_multiset` and `std::unordered_multimap` — hash-based, unordered, allow duplicates (multimap).
