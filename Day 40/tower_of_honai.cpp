// gfg question medium level Tower Of Hanoi


// class Solution {
//     public:
//       // void tohcal(int n , int source , int help , int dest){
//       //     // base case
//       //     if(n==1){
//       //         cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<dest<<endl;
//       //         return;
//       //     }
          
//       //     tohcal(n-1,source,dest,help);
//       //     cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<dest<<endl; 
//       //     tohcal(n-1,help,source,dest);
//       // }
  
//       int towerOfHanoi(int n, int from, int to, int aux) {
//       //   tohcal(n,from,aux,to);
//       //   ans step printing
//          return pow(2,n)-1;
//       }
//   };
// here in this question it just asked the step printing so only by giving the return pow(2,n)-1 it cases are runned..


// ✅ Day 40: Recursion - Tower of Hanoi Problem
// Medium Level Question (GFG)

#include <iostream>
#include <cmath> // for pow()
using namespace std;

// 🔁 Recursive Function to Print Steps of Tower of Hanoi
void tohcal(int n, int source, int help, int dest) {
    // ✅ Base Case: Only one disk left
    if (n == 1) {
        cout << "move disk " << n << " from rod " << source << " to rod " << dest << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to help using dest as auxiliary
    tohcal(n - 1, source, dest, help);

    // Step 2: Move the nth disk from source to destination
    cout << "move disk " << n << " from rod " << source << " to rod " << dest << endl;

    // Step 3: Move the n-1 disks from help to destination using source as auxiliary
    tohcal(n - 1, help, source, dest);
}

// 📌 Function that returns total number of steps for n disks
int towerOfHanoi(int n, int from, int to, int aux) {
    tohcal(n, from, aux, to);
    return pow(2, n) - 1; // Total steps = 2^n - 1
}

int main() {
    int n = 3; // Example with 3 disks
    int totalSteps = towerOfHanoi(n, 1, 3, 2);
    cout << "Total steps required: " << totalSteps << endl;
    return 0;
}

/*
🔍 Dry Run for n = 3:
Initial Call: tohcal(3, 1, 2, 3)

Step 1: tohcal(2, 1, 3, 2)
    Step 1.1: tohcal(1, 1, 2, 3)
        -> move disk 1 from rod 1 to rod 3
    Step 1.2: move disk 2 from rod 1 to rod 2
    Step 1.3: tohcal(1, 3, 1, 2)
        -> move disk 1 from rod 3 to rod 2

Step 2: move disk 3 from rod 1 to rod 3

Step 3: tohcal(2, 2, 1, 3)
    Step 3.1: tohcal(1, 2, 3, 1)
        -> move disk 1 from rod 2 to rod 1
    Step 3.2: move disk 2 from rod 2 to rod 3
    Step 3.3: tohcal(1, 1, 2, 3)
        -> move disk 1 from rod 1 to rod 3

✅ Final Output:
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
Total steps required: 7
*/

/*
🧠 Time Complexity:
- T(n) = 2T(n-1) + O(1) => O(2^n)
- At each level we are making 2 recursive calls.

📦 Space Complexity:
- O(n): due to recursion stack. Max depth = n.
*/
