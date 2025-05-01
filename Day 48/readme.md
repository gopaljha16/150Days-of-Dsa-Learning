Here are the detailed **Day 48 notes** on types of inheritance in C++ along with full code walkthrough, explanations, and flowchart-style diagrams for each type of inheritance:

---

# 📘 **Day 48: Types of Inheritance in C++**

---

## 🔶 1. **Single Inheritance**
- One derived class inherits from one base class.

### 📊 Diagram:
```
  Human
    ↑
 Student
```

### ✅ Use Case:
Reusability of code when a derived class needs the base class properties and behaviors.

### 🧠 Code:

```cpp
class Human {
protected:
    string name;
    int age;

public:
    Human(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << name << " " << age << endl;
    }

    void work() {
        cout << "I am working" << endl;
    }
};

class Student : public Human {
    int roll_no, fees;

public:
    Student(string name, int age, int roll_no, int fees) : Human(name, age) {
        this->roll_no = roll_no;
        this->fees = fees;
    }

    void show() {
        cout << name << " " << age << " " << roll_no << " " << fees << endl;
    }
};
```

---

## 🔷 2. **Multilevel Inheritance**
- A derived class is inherited from another derived class.

### 📊 Diagram:
```
  Person
    ↑
 Employee
    ↑
 Manager
```

### ✅ Use Case:
Modeling "is-a" relationships across multiple levels.

### 🧠 Code:
```cpp
class Person {
protected:
    string name;

public:
    void introduce() {
        cout << "My name is: " << name << endl;
    }
};

class Employee : public Person {
protected:
    int salary;

public:
    void monthly_salary() {
        cout << "My monthly salary is: " << salary << endl;
    }
};

class Manager : public Employee {
public:
    string department;

    Manager(string name, int salary, string department) {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void myDepartment() {
        cout << "Leading department: " << department << endl;
    }
};
```

---

## 🔶 3. **Multiple Inheritance**
- A class inherits from more than one base class.

### 📊 Diagram:
```
 Engineer    Employee
     \         /
      \       /
       \     /
        Student
```

### ✅ Use Case:
When a class needs functionality from multiple sources.

### 🧠 Code:
```cpp
class Engineer {
public:
    string specilization;

    void myspecilization() {
        cout << "Specialization: " << specilization << endl;
    }
};

class Employee {
public:
    int salary;

    void mySalary() {
        cout << "Salary: " << salary << endl;
    }
};

class Student : public Engineer, public Employee {
public:
    string name;

    Student(string name, string specilization, int salary) {
        this->name = name;
        this->specilization = specilization;
        this->salary = salary;
    }

    void showcase() {
        cout << "Name: " << name << endl;
        myspecilization();
        mySalary();
    }
};
```

---

## 🔷 4. **Hierarchical Inheritance**
- Multiple classes are derived from a single base class.

### 📊 Diagram:
```
        Human
       /     \
  Student   Teacher
```

### ✅ Use Case:
Different roles sharing common base class behavior.

### 🧠 Code:
```cpp
class Human {
protected:
    string name;
    int age;

public:
    Human(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << name << " " << age << endl;
    }
};

class Student : public Human {
    int roll_no, fees;

public:
    Student(string name, int age, int roll_no, int fees) : Human(name, age) {
        this->roll_no = roll_no;
        this->fees = fees;
    }

    void display() {
        cout << name << " " << age << " " << roll_no << " " << fees << endl;
    }
};

class Teacher : public Human {
public:
    int salary;

    Teacher(string name, int age, int salary) : Human(name, age) {
        this->salary = salary;
    }

    void display() {
        cout << name << " " << age << " " << salary << endl;
    }
};
```

---

## 🔶 5. **Hybrid Inheritance**
- Combination of multiple and hierarchical inheritance.

### 📊 Diagram:
```
   Student
   /     \
Male     Female
   \     /
    Boy/Girl
```

### ✅ Use Case:
Complex real-world relationships where multiple forms of inheritance are needed.

### 🧠 Code:
```cpp
class Student {
public:
    void print() {
        cout << "I am Student" << endl;
    }
};

class Male {
public:
    void male() {
        cout << "I am Male" << endl;
    }
};

class Female {
public:
    void female() {
        cout << "I am Female" << endl;
    }
};

class Boy : public Student, public Male {
public:
    void BoyPrint() {
        cout << "I am Boy" << endl;
    }
};

class Girl : public Student, public Female {
public:
    void GirlPrint() {
        cout << "I am Girl" << endl;
    }
};
```

---

## 🔷 6. **Multipath Inheritance (Diamond Problem)**
- Derived class inherits from two classes that have a common base class.
- Solved using **virtual inheritance**.

### 📊 Diagram:
```
    Human
   /     \
Engineer Employee
   \     /
   Student
```

### ⚠️ Problem:
Ambiguity due to multiple copies of `Human`.

### ✅ Solution:
Use `virtual` keyword.

### 🧠 Code:
```cpp
class Human {
public:
    string name;

    void display() {
        cout << "Name: " << name << endl;
    }
};

class Engineer : virtual public Human {
public:
    string specialization;

    void showSpecialization() {
        cout << "Specialization: " << specialization << endl;
    }
};

class Employee : virtual public Human {
public:
    int salary;

    void showSalary() {
        cout << "Salary: " << salary << endl;
    }
};

class Student : public Engineer, public Employee {
public:
    int age;

    Student(string name, string specialization, int salary, int age) {
        this->name = name;
        this->specialization = specialization;
        this->salary = salary;
        this->age = age;
    }

    void showAll() {
        display();
        showSpecialization();
        showSalary();
    }
};
```

---

## 🧩 Summary Table of Inheritance Types

| Inheritance Type  | Description                                | Use Case                                        |
|-------------------|--------------------------------------------|-------------------------------------------------|
| Single            | 1 base → 1 derived                         | Simple extension of class                      |
| Multilevel        | A → B → C                                   | Hierarchical chains                            |
| Multiple          | A, B → C                                    | Inherit features from multiple unrelated bases |
| Hierarchical      | A → B, A → C                                | One base for many types                        |
| Hybrid            | Combo of multiple + hierarchical            | Real-world complex models                      |
| Multipath         | Inherited from common base (diamond)        | Use virtual to avoid ambiguity                 |

---

