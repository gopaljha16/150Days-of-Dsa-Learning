// //  N Stacks In An Array hard level question coding nijas.

// #include <bits/stdc++.h> 
// #include <stack>

// class Node{
//     public:
//     int index;
//     Node *next;

//     Node(int x){
//         index = x;
//         next = NULL;
//     }
// };



// class NStack
// {
// public: 
//     int *arr; //original array
//     Node **Top; //store the top element index of particular stack
//     stack<int>st; //empty index

//     NStack(int N, int S)
//     {
//         arr = new int[S]; //array allocated the size
//         Top = new Node *[N]; //how many number of stack and which points node value

//         //array making in null
//         for(int i=0 ; i<N; i++){
//             Top[i] = NULL;
//         }        

//       ///entering the array value in stack 
//         for(int i=0; i<S; i++){
//             st.push(i);
//         }
//     }

    

//     // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
//     bool push(int x, int m)
//     {
//         if(st.empty()){ //empty can't push(array full)
//             return 0;
//         }

//         arr[st.top()] = x;  // index value putting array
//         Node *temp = new Node(st.top()); //new Node index we have from the stack
//         temp->next = Top[m-1]; //pointing to the top array pointer which points the node value
//         Top[m-1] = temp; //top array pointing the temp
//         st.pop(); //pop
//         return 1; 
//     }

//     // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
//     int pop(int m)
//     { 
//         //empty array 
//         if(Top[m-1]==NULL)
//          return -1;
        
//         //element present
    
//         int ele = arr[Top[m-1]->index]; //index value putting.
//         st.push(Top[m-1]->index); //pushing the top->next element which is going to be popped means space we have in array
//         Top[m-1] = Top[m-1]->next; //top pointing to the next node
    
//        return ele; //returning element
    
//     }
// };