/*
🔵 Day 67: Stack Problems - Largest Rectangle in Histogram & Maximal Rectangle

✅ Topics Covered:
- Stack-based approach to find the largest rectangle in a histogram
- Using histogram logic to solve Maximal Rectangle problem in a binary matrix
- Code walkthrough, dry run, pseudocode, and flowchart explanation
*/

//---------------------------------------------------------------
// ✅ Problem 1: Largest Rectangle in Histogram (Leetcode Hard)
//---------------------------------------------------------------

/*
🔸 Intuition:
For every bar in histogram, find:
- Next smaller element on the left (NSL)
- Next smaller element on the right (NSR)
Use them to calculate width = right - left - 1
Max area = height * width

🔸 Pseudocode (Method 1):
1. Use 2 stacks to find NSL and NSR for each index
2. Store the indexes in two arrays: left[i], right[i]
3. Calculate area[i] = height[i] * (right[i] - left[i] - 1)
4. Return max area
*/

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> right(n), left(n);
    stack<int> st;

    // Step 1: Find Next Smaller Right (NSR)
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        right[st.top()] = n;
        st.pop();
    }

    // Step 2: Find Next Smaller Left (NSL)
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        left[st.top()] = -1;
        st.pop();
    }

    // Step 3: Compute max area
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        ans = max(ans, heights[i] * width);
    }
    return ans;
}

/*
🟠 Time Complexity: O(N)
🟠 Space Complexity: O(N) (for stacks and left/right arrays)
*/

//---------------------------------------------------------------
// ✅ Optimized Method (One Pass using Stack)
//---------------------------------------------------------------

int largestRectangleAreaOnePass(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int index = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, heights[index] * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int index = st.top(); st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        ans = max(ans, heights[index] * width);
    }
    return ans;
}


//---------------------------------------------------------------
// ✅ Problem 2: Maximal Rectangle (Leetcode Hard)
//---------------------------------------------------------------

/*
🔸 Problem:
Given a 2D binary matrix filled with 0s and 1s, find the largest rectangle containing only 1s.

🔸 Approach:
- Use each row as a histogram (like previous problem)
- Accumulate heights of 1s for each row
- Use largestRectangleArea function on each histogram
*/

int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> heights(col, 0);
    int ans = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '0') heights[j] = 0;
            else heights[j] += 1;
        }
        ans = max(ans, largestRectangleAreaOnePass(heights));
    }
    return ans;
}

/*
🔸 Dry Run Example:
Matrix:
[
 ['1','0','1','0','0'],
 ['1','0','1','1','1'],
 ['1','1','1','1','1'],
 ['1','0','0','1','0']
]

Heights after each row:
Row 0: [1,0,1,0,0]
Row 1: [2,0,2,1,1]
Row 2: [3,1,3,2,2]
Row 3: [4,0,0,3,0]

Each row is passed to histogram logic to compute max area.

🔸 Time: O(ROWS * COLS)
🔸 Space: O(COLS)
*/

//---------------------------------------------------------------
// ✅ Summary:
//---------------------------------------------------------------

/*
🔹 Largest Rectangle in Histogram:
- Use stack to find Next Smaller to Left/Right
- Max area = height * width (bounded by NSL and NSR)

🔹 Maximal Rectangle:
- Treat each row of matrix as histogram
- Accumulate height of 1s column-wise
- Use histogram logic to calculate max area at each row
*/

//---------------------------------------------------------------
// ✅ Flowchart & Visualization Steps:
//---------------------------------------------------------------

// [1] Build histogram per row from binary matrix
// [2] For each histogram, use stack to calculate:
//      - Area for bars as long as they are higher than next
// [3] Maintain max area found at each step

// Final result = max area found from all histograms

// ✅ Done! Notes ready to push to GitHub!
