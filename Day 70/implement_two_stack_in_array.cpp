// Two Stacks in an Array medium level question 

// class twoStacks {
//   public:
//     int *arr;
//     int top1 , top2;
//     int size;
//     twoStacks(int n=100) {
//         size = n;
//         arr = new int[n];
//         top1 = -1;
//         top2 = n;
//     }

//     // Function to push an integer into the stack1.
//     void push1(int x) {
//             if(top1+1==top2){ //stack is full.
//                 return;
//             }else{
//                 top1++;
//                 arr[top1] = x;
//             }
        
//     }

//     // Function to push an integer into the stack2.
//     void push2(int x) {
//     if(top2-1==top1){ //matches then cant enter in element in stack full
//        return;
//       }else{
//         top2--;
//         arr[top2]=x;
//     }

//     }

//     // Function to remove an element from top of the stack1.
        
//     int pop1() {
//        if(top1==-1){ //empty
//            return -1;
//        }else{ //element present
//            int num = arr[top1];
//            top1--;
//            return num;
//        }
//     }

        
//     // Function to remove an element from top of the stack2.
//     int pop2() {
//        if(top2==size){ //empty
//            return -1; 
//        }else{ //element present
//            int num = arr[top2];
//            top2++;
//            return num;
//        }
//     }
// };