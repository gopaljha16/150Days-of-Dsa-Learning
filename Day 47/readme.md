Here are detailed **Day 47 Notes** on **Access Specifiers and Inheritance in C++**, including examples, diagrams, and deep explanations of how `public`, `protected`, and `private` access modifiers behave in base and derived classes.

---

# 📘 **Day 47: Access Specifiers and Inheritance in C++**

---

## 🔐 **1. Access Modifiers in C++**
Access modifiers determine how class members (attributes/methods) can be accessed.

| Access Specifier | Access in Class | Access in Derived Class | Access Outside Class |
|------------------|------------------|--------------------------|-----------------------|
| `private`        | ✅ Yes           | ❌ No                    | ❌ No                 |
| `protected`      | ✅ Yes           | ✅ Yes                   | ❌ No                 |
| `public`         | ✅ Yes           | ✅ Yes                   | ✅ Yes                |

---

## 🧠 **2. Understanding With a Diagram**

### Class Scope and Access Modifier Flow

```txt
Base Class
|-----------------------------|
| private:    a              |  ❌ NOT accessible in derived class or outside
| protected:  b              |  ✅ accessible in derived class, ❌ outside
| public:     c              |  ✅ accessible everywhere
|-----------------------------|
```

### Inheritance Types and Effect on Access Modifiers

Let’s say:

```cpp
class Base {
protected:
    int x;
public:
    int y;
};
```

Now consider different inheritance types:

| Inheritance Type     | `x` in Derived | `y` in Derived | `x` Outside | `y` Outside |
|----------------------|----------------|----------------|-------------|-------------|
| `class Derived : public Base`    | ✅ protected   | ✅ public     | ❌           | ✅           |
| `class Derived : protected Base` | ✅ protected   | ✅ protected  | ❌           | ❌           |
| `class Derived : private Base`   | ✅ private     | ✅ private    | ❌           | ❌           |

---

## 🧪 **3. Access Modifier Example**

```cpp
class Human {
private:
    int a;
protected:
    int b;
public:
    int c;

    Human() {
        a = 10;
        b = 20;
        c = 30;
    }
};

int main() {
    Human h;
    // h.a = 10; ❌ Not allowed (private)
    // h.b = 20; ❌ Not allowed (protected)
    h.c = 40;     ✅ Allowed (public)
}
```

---

## 🧬 **4. Inheritance with Access Modifiers**

```cpp
class Human {
protected:
    string name;
    int age, phone;
};

class Student : protected Human {
public:
    int roll;
    string branch;

    Student(string n, int a, int p, int r, string b) {
        name = n;
        age = a;
        phone = p;
        roll = r;
        branch = b;
    }

    void display() {
        cout << name << " " << age << " " << phone << " " << roll << " " << branch << endl;
    }
};
```

- `Human`'s `protected` members are accessible in `Student`.
- But from outside main, we **cannot directly access** `name`, `age`, or `phone`.

---

## 🧾 **5. Real-World Analogy**

**🔒 Private:** Like your phone password. Only you (class) can see or use it.

**🔐 Protected:** Like your school ID that can be seen by teachers (child classes), but not outsiders.

**🌐 Public:** Like your profile picture. Everyone (main function, child classes) can see and use it.

---

## 🧱 **6. Deep Dive Into Inheritance Access Levels**

| Inheritance Type | Base Class `public` | Base Class `protected` | Base Class `private` |
|------------------|---------------------|--------------------------|------------------------|
| `public`         | remains `public`    | remains `protected`     | not inherited         |
| `protected`      | becomes `protected` | remains `protected`     | not inherited         |
| `private`        | becomes `private`   | becomes `private`       | not inherited         |

> ⚠️ **Private members are never inherited** but can be indirectly accessed via member functions.

---

## 🔧 **7. More Examples**

### ❌ Cannot access private members directly in derived class:

```cpp
class Base {
private:
    int secret = 42;
};

class Derived : public Base {
public:
    void show() {
        // cout << secret; ❌ Error
    }
};
```

---

### ✅ Access via public/protected members:

```cpp
class Base {
protected:
    int data;
};

class Derived : public Base {
public:
    void setData(int val) {
        data = val; // ✅
    }

    void print() {
        cout << data << endl;
    }
};
```

---

## 📦 **8. Summary**

| Feature        | Private | Protected | Public |
|----------------|---------|-----------|--------|
| Access in same class | ✅ Yes | ✅ Yes | ✅ Yes |
| Access in derived class | ❌ No | ✅ Yes | ✅ Yes |
| Access in main() | ❌ No | ❌ No | ✅ Yes |

---

## 🧩 **9. Visual Recap: Inheritance Mapping**

```txt
Base Class
------------------------------
| private:  Not Inherited    |
| protected: Inherited       |
| public:    Inherited       |
------------------------------

Inheritance Types:
---------------------------------------------
| Type      | public  | protected | private  |
|-----------|---------|-----------|----------|
| public    | public  | protected | ❌       |
| protected | protected | protected | ❌     |
| private   | private | private    | ❌      |
---------------------------------------------
```

---
