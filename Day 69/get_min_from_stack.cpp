// Get Minimum From stack gfg medium level question 

//method 1 but here the issue is that here we are using the one stack for the getmin element so here o(n)
// class Solution {
//     private:
//     stack<int>st1; //original values
//     stack<int>st2; // minium values
    
    
//   public:
//     Solution() {
       
//     }

//    // Add an element to the top of Stack
//     void push(int x) {
//         if(st1.empty()){ //if empty
//             st1.push(x);
//             st2.push(x);
//         }else{ //not empty stack
//             st1.push(x); 
//             st2.push(min(x,st2.top())); //min element from x and st.2 top element
//         }
//     }

//     // Remove the top element from the Stack
        
//     int pop() {
//         if(st1.empty()){// empty stack
//             return -1;
//         }else{ //not empty
//             int element = st1.top();
//             st1.pop();
//             st2.pop();
//             return element;
//         }
//     }

    
//     // Returns top element of the Stack
//     int peek() {
//        if(st1.empty()){ //if empty
//            return -1;
//        }else{ //not empty()
//            return st1.top();
//        }
//     }
        

//     // Finds minimum element of Stack
//     int getMin() {
//        if(st2.empty()){ //empty
//            return -1;
//        }else{ //not empty
//            return st2.top();
//        }
//     }
    
   
// };


//Method 2 get Minimum element in the constant space using modulos operator we put the value in stack.. and get the original value and  min value..
// class Solution {
//     private:
//     stack<long long>st1; //original values and performing the min element both in this..stack
//      const long long MULT = 1e9 + 1;  // 1 more than max possible value
  
//    public:
//     Solution() {
//     }

//    // Add an element to the top of Stack
//     void push(int x) {
//        if(st1.empty()){ //if stack is empty
//            st1.push(1LL*x*MULT+x);
//        }else{ //element is present
//             int currMin = st1.top() % MULT;
//             st1.push(1LL*x*MULT+min(x,currMin));
//        }
//     }

//     // Remove the top element from the Stack
//     int pop() {
//         if(st1.empty()){// empty stack
//             return -1;
//         }else{ //if element is present 
//             int element = st1.top()/MULT;
//             st1.pop();
//             return element;
//         }
//     }

    
//     // Returns top element of the Stack
//     int peek() {
//        if(st1.empty()){ //if empty
//            return -1;
//        }else{ //element present
//            return st1.top()/MULT;
//        }
//     }
        

//     // Finds minimum element of Stack
//     int getMin() {
//        if(st1.empty()){ //empty
//            return -1;
//        }else{ //if element present
//            return st1.top()%MULT;
//        }
//     }
    
// };