Here are your **Day 44 Notes: Deep Dive into C++ Classes, Access Modifiers, Memory Allocation, Getter/Setter, Object Size & Padding** — explained GitHub-style in detail:

---

# 📘 Day 44 – Object-Oriented Programming in C++ (Classes, Getter/Setter, Padding, Memory Allocation)

This note covers key OOP concepts in C++ like how to define classes, access modifiers (`public`/`private`), getter/setter methods, object memory size, padding, and both static & dynamic object memory allocation. All code snippets are explained **line-by-line**.

---

## 🧱 1. What is a Class?

A **class** is a user-defined data type that groups variables (called data members) and functions (called member functions or methods) into one unit.

```cpp
class Student {
  string name;
  int age;
  int roll_no;
  string grade;
};
```

---

## 🔐 2. Access Modifiers

C++ classes support three access specifiers:
- `private`: Only accessible within the class.
- `public`: Accessible from outside the class using objects.
- `protected`: Used in inheritance, discussed later.

### ➕ Default Access Modifier:
In C++, class members are **private by default**.

```cpp
class Student {
private:  // implicitly private even if not written
  string name;
};
```

---

## 🧑‍💻 3. Getter and Setter Methods (Encapsulation)

Encapsulation is about protecting data by using **getter and setter** functions.

### ✅ Setter Method
Sets the value of a private variable.

```cpp
void setName(string n) {
  if (n.size() == 0) {
    cout << "Empty name please enter the name";
    return;
  }
  name = n;
}
```

### 🔍 Getter Method
Retrieves (prints) the value of a variable.

```cpp
void getName() {
  cout << name << endl;
}
```

### 🔐 Secure Getter Example with PIN
```cpp
void getGrade(int pin) {
  if(pin == 123) {
    cout << grade << endl;
    return;
  }
  cout << "Access denied\n";
}
```

---

## 🛠️ 4. Full Class with Getters & Setters

```cpp
class Student {
private:
  string name;
  int age, roll_no;
  string grade;

public:
  void setName(string n);
  void setAge(int a);
  void setRoll_no(int r);
  void setGrade(string g);
  void getName();
  void getAge();
  void getRoll_no();
  void getGrade(int pin);
};
```

> 🔎 **Encapsulation** = Private members + Public getter/setter

---

## 🔢 5. Object Creation and Access

### 🔹 Static Object (Stored in Stack)
```cpp
Student s1;
s1.setName("Gopal");
s1.getName();
```

### 🔸 Dynamic Object (Stored in Heap)
```cpp
Student *s = new Student;
s->name = "Gopal";
s->age = 20;
```

> Use `.` for static objects and `->` for pointers (dynamic objects).

---

## 🧠 6. Understanding Memory Allocation

### 📌 Static Memory Allocation
- Done at **compile time**.
- Example:
  ```cpp
  Student s1;  // allocated on stack
  ```

### 💡 Dynamic Memory Allocation
- Done at **runtime**.
- Example:
  ```cpp
  Student *s = new Student();  // allocated on heap
  ```

---

## 📐 7. Object Size and Padding in C++

### ➕ Padding Concept:
To align memory access for CPU optimization, compilers add padding bytes between data members.

### 🧪 Example:
```cpp
class A {
  char b;     // 1 byte
  int a;      // 4 bytes
  char d;     // 1 byte
  double e;   // 8 bytes
};
```

- Total size will **NOT** be 1+4+1+8 = 14 bytes.
- Due to **padding**, actual size = **24 bytes** on 64-bit compilers.

> Use `sizeof()` to check actual object size.

### ⚠️ Empty Class
```cpp
class A {};  
A obj;
cout << sizeof(obj); // Output: 1
```

Because the compiler assigns **1 byte** to empty objects to make them addressable.

---

## 💻 Code Example with Full Explanation

```cpp
#include <iostream>
using namespace std;

class Student {
public:
  string name;
  int age, roll_no;
  string grade;
};

int main() {
  Student *s = new Student;

  (*s).name = "Gopal";      // OR s->name = "Gopal";
  (*s).age = 20;
  (*s).roll_no = 1216;
  (*s).grade = "A+";

  cout << s->name << endl;
  cout << s->age << endl;
  cout << s->roll_no << endl;
  cout << s->grade << endl;
}
```

---

## 🧮 Object Size Recap

| Data Type | Size (Bytes) |
|-----------|--------------|
| `char`    | 1            |
| `int`     | 4            |
| `string`  | 32 or 40+    |
| `double`  | 8            |

Use `sizeof(object)` and `sizeof(ClassName)` to analyze size.

---

## 🔚 Conclusion

- ✅ Use `private` for data security.
- ✅ `public` getter/setter functions allow safe access.
- ✅ `.` operator for static, `->` operator for dynamic access.
- ✅ Understand padding to optimize object design.
- ✅ Always free dynamic memory using `delete` (though not shown here for simplicity).

---

