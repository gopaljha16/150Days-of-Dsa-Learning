Here are your **Day 9** notes on **Majority Elements, Counting Frequency, and Finding Missing & Repeating Elements**, with detailed explanations and code snippets. 🚀  

---

# **Day 9: Majority Elements, Count Frequency & Missing/Repeating Elements**  

## **1️⃣ Find the Missing and Repeating Elements**  
### **Problem Statement**  
Given an array `arr` of size `N`, where numbers are from `1` to `N`,  
- **One number is missing**, and  
- **One number is repeating**.  

Find both these numbers efficiently.  

### **Approach: Frequency Count (Efficient)**  
#### **Steps:**  
1. **Decrease all elements by 1** → so that elements range from `0` to `N-1`.  
2. **Use the modulo technique** to mark occurrences:  
   - Increase `arr[arr[i] % N]` by `N` to count occurrences indirectly.  
3. **Scan the array**:  
   - If `arr[i] / N == 2` → `i+1` is the **repeating number**.  
   - If `arr[i] / N == 0` → `i+1` is the **missing number**.  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    
    // Decrease all elements by 1 for easier indexing
    for (int i = 0; i < n; i++) {
        arr[i]--;
    }
    
    // Modify array to count occurrences
    for (int i = 0; i < n; i++) {
        arr[arr[i] % n] += n;
    }
    
    vector<int> ans(2); // [Repeating, Missing]

    // Identify the missing and repeating numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] / n == 2)  // Repeating number
            ans[0] = i + 1;
        else if (arr[i] / n == 0)  // Missing number
            ans[1] = i + 1;
    }
    
    return ans;
}

// Driver Code
int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> result = findTwoElement(arr);
    cout << "Repeating Number: " << result[0] << endl;
    cout << "Missing Number: " << result[1] << endl;
}
```
### **Time Complexity:**  
- **O(N)** → One pass for marking occurrences, one for checking counts.  
- **Space Complexity: O(1)** → No extra space used.  

---

## **2️⃣ Majority Element (Occurs More than N/2 Times)**  
### **Problem Statement**  
Given an array `nums[]` of size `N`, find the **majority element** (appearing more than `N/2` times).  
Return `-1` if no majority element exists.  

### **Approach: Boyer-Moore Voting Algorithm**  
- **Intuition:**  
  - If an element appears **more than N/2 times**, it **dominates** the array.  
  - We use a **voting system** to count potential candidates.  

#### **Steps:**  
1. **Find the Candidate:**  
   - Maintain a `count` and `candidate` variable.  
   - If `count == 0`, set `candidate = nums[i]`.  
   - If `candidate == nums[i]`, increase `count`.  
   - Else, decrease `count`.  
2. **Verify the Candidate:**  
   - Count occurrences of the candidate.  
   - If it appears **more than N/2 times**, return it; else return `-1`.  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int candidate = -1, count = 0;

    // Step 1: Find the potential majority element
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
    }

    // Step 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2)
        return candidate;
    else
        return -1;
}

// Driver Code
int main() {
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3, 1};
    int result = majorityElement(nums);
    if (result != -1)
        cout << "Majority Element: " << result << endl;
    else
        cout << "No Majority Element Found" << endl;
}
```
### **Time Complexity:**  
- **O(N)** → One pass to find the candidate, one pass to verify.  
- **Space Complexity: O(1)** → No extra space used.  

---

## **Summary of Day 9**  
| **Problem**                  | **Approach**                               | **Time Complexity** |
|------------------------------|-------------------------------------------|--------------------|
| **Find Missing & Repeating**  | **Frequency Count (Mod N trick)**         | **O(N)** |
| **Majority Element (N/2 rule)** | **Boyer-Moore Voting Algorithm**          | **O(N)** |

---

This concludes **Day 9** on **Majority Elements, Counting Frequency & Missing/Repeating Elements**! 🚀  
