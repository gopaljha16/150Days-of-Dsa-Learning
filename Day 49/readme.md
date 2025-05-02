Here are the **Day 49 Notes on Polymorphism in C++**, including detailed explanations, flowcharts, and code breakdowns:

---

# 📘 **Day 49 – Polymorphism in C++ (Function Overloading, Operator Overloading, Virtual Functions, Abstract Classes)**

---

## 🔶 What is Polymorphism?

**Polymorphism** means "many forms" — it allows the same interface (function or operator) to behave differently depending on the object or arguments.

### Two types:

1. **Compile-time Polymorphism** (Early Binding)

   * Function Overloading
   * Operator Overloading

2. **Runtime Polymorphism** (Late Binding)

   * Virtual Functions
   * Abstract Classes

---

## 1️⃣ Function Overloading (Compile-Time Polymorphism)

### ✅ Concept:

Multiple functions with the **same name** but **different parameter types/count**.

### 📂 Code:

```cpp
class Area {
public:
    int calculateArea(int r) {      // Circle
        return 3.14 * r * r;
    }

    int calculateArea(int l, int b) { // Rectangle
        return l * b;
    }
};
```

### 🔄 Flowchart:

```
User calls calculateArea(...)
           ↓
Check number/type of arguments
           ↓
Compiler picks appropriate overloaded function
```

### 💡 Example:

```cpp
Area A;
cout << A.calculateArea(4);      // Circle
cout << A.calculateArea(3, 4);   // Rectangle
```

### 🧠 Key Point:

Resolved at **compile time** based on parameters.

---

## 2️⃣ Operator Overloading (Compile-Time Polymorphism)

### ✅ Concept:

We redefine the behavior of operators (like `+`, `-`, etc.) for **user-defined types**.

### 📂 Code:

```cpp
class Complex {
    int real, img;

public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    Complex operator+(Complex& c) {
        Complex ans;
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }

    void display() {
        cout << real << "+i" << img << endl;
    }
};
```

### 🔄 Flowchart:

```
C1 + C2
↓
operator+() function is called
↓
Returns new Complex with summed parts
```

### 🧠 Key Point:

* Same syntax (`+`) but different meaning.
* Helps write readable & intuitive code.

---

## 3️⃣ Virtual Functions (Runtime Polymorphism)

### ✅ Concept:

Used to achieve runtime polymorphism where **base class pointer** points to a **derived class object** and calls the **overridden function** at **runtime**.

### 📂 Code:

```cpp
class Animal {
public:
    virtual void speak() = 0; // pure virtual function (abstract class)
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow" << endl;
    }
};
```

### 🔄 Flowchart:

```
Animal* p;
p = new Dog();
p->speak();
      ↓
Runtime checks which object p points to
      ↓
Dog::speak() called
```

### 🧪 Example:

```cpp
vector<Animal*> animals;
animals.push_back(new Dog());
animals.push_back(new Cat());

for (int i = 0; i < animals.size(); i++) {
    animals[i]->speak(); // Calls overridden function based on object type
}
```

---

## 4️⃣ Abstract Classes

### ✅ Concept:

An abstract class contains **at least one pure virtual function**, making it uninstantiable.

### 📂 Code:

```cpp
class Animal {
public:
    virtual void speak() = 0; // Pure virtual function
};
```

### 💡 Use:

* Acts as a base class.
* Ensures derived classes implement specific behavior.

---

## 🧩 Summary of Polymorphism Types:

| Type                 | Feature                              | Binding Time | Use Case                      |
| -------------------- | ------------------------------------ | ------------ | ----------------------------- |
| Function Overloading | Same function name, different params | Compile-time | Multiple forms of a function  |
| Operator Overloading | Redefine operators                   | Compile-time | Custom behavior for operators |
| Virtual Function     | Override behavior via pointer        | Runtime      | Object-based function calls   |
| Abstract Class       | Pure virtual function = 0            | Runtime      | Base class design contract    |

---

## ✅ Practical Example Summary

### Input:

```cpp
Animal* p;
p = new Dog();
p->speak();  // Output: Bark
```

### Flowchart Summary:

```
          Animal* p;
              ↓
     p = new Dog();        ---> Runtime knows p points to Dog
              ↓
          p->speak();      ---> Dog::speak() called
```

---

## 📌 Key Takeaways:

* Compile-time polymorphism is resolved by the **compiler**, and you can have many function versions.
* Runtime polymorphism is resolved using **virtual functions**, letting you override behavior dynamically.
* **Abstract classes** enforce structure and ensure derived classes implement essential functionality.
* Use **function overloading** for multiple ways to call a method and **operator overloading** for intuitive object interaction.

---

