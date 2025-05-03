Here are the detailed revision notes for **Day 51: File Handling in C++**, covering everything from basic file operations to reading and writing structured data, with examples and explanations.

---

# 📁 **Day 51: File Handling in C++**

---

## 🧠 What is File Handling?

File handling in C++ is used to store data permanently in files instead of temporary memory (RAM). It uses file streams (`ifstream`, `ofstream`, `fstream`) to read/write files.

---

## 📂 File Handling Classes

| Class      | Purpose                      |
| ---------- | ---------------------------- |
| `ofstream` | For writing to files         |
| `ifstream` | For reading from files       |
| `fstream`  | For both reading and writing |

---

## ✅ 1. Writing to a File

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout;             // Create ofstream object
    fout.open("zoom.txt");     // Open/create file
    fout << "Hello India";     // Write to file
    fout.close();              // Always close after use
}
```

### 📌 Explanation:

* `ofstream fout;` creates an object for writing.
* `fout.open("zoom.txt");` opens or creates the file.
* `fout << "Hello India";` writes text to the file.
* `fout.close();` releases the file resource.

---

## ✅ 2. Reading from a File (Character by Character)

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    fin.open("zoom.txt");
    char c = fin.get();       // Read first char (includes spaces)

    while(!fin.eof()){        // Check for End Of File
        cout << c;
        c = fin.get();
    }

    fin.close();
}
```

### 📌 Explanation:

* `fin.get()` reads **including spaces and tabs**.
* `eof()` checks if the end of the file is reached.

---

## ✅ 3. Writing a Vector to a File

```cpp
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr(5);

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) cin >> arr[i];

    ofstream fout("zero.txt");
    for (int num : arr) fout << num << " ";
    fout.close();
}
```

### 📌 Explanation:

* Store multiple values in a file.
* Outputs: `12 34 5 6 78` (example) in the file.

---

## ✅ 4. Writing Sorted Data to File

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr(5);
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) cin >> arr[i];

    fstream fout("zero.txt", ios::out);  // both read/write
    fout << "Original Data\n";
    for (int i : arr) fout << i << " ";

    sort(arr.begin(), arr.end());
    fout << "\nSorted Data\n";
    for (int i : arr) fout << i << " ";

    fout.close();
}
```

### 📌 Explanation:

* `fstream` can read/write both.
* Writes **original and sorted** data into the same file.

---

## ✅ 5. Reading Lines from a File

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout("z1.txt");
    fout << "Hello world\nHello bhai\nHello Gopal\n";
    fout.close();

    ifstream fin("z1.txt");
    string line;
    while(getline(fin, line)){  // Reads line-by-line
        cout << line << endl;
    }

    fin.close();
}
```

### 📌 Explanation:

* `getline(fin, line)` reads a full line with spaces.
* Perfect for reading structured text files.

---

## 🔄 Flowchart: Basic File Operations

```
┌────────────┐
│  Open File │
└─────┬──────┘
      ↓
 ┌────┴─────┐
 │ Read/Write│
 └────┬─────┘
      ↓
 ┌────┴──────┐
 │  Close it │
 └───────────┘
```

---

## ⚠️ Common File Modes

| Mode          | Description                |
| ------------- | -------------------------- |
| `ios::in`     | Open for reading           |
| `ios::out`    | Open for writing (default) |
| `ios::app`    | Append to file             |
| `ios::binary` | Binary file mode           |
| `ios::ate`    | Start at end of file       |

```cpp
fstream file("data.txt", ios::in | ios::out | ios::app);
```

---

## 🧪 Revision Tips:

* Use `fout << data` to write.
* Use `fin >> data` for reading words/tokens.
* Use `fin.get()` for reading characters (with whitespace).
* Use `getline(fin, str)` for full line reading.
* Always `.close()` files after use.

---


