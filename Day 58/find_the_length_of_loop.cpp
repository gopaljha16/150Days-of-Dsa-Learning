// Find length of Loop gfg easy level question 

// class Solution {
//   public:
//     // Function to find the length of a loop in the linked list.
//     int countNodesinLoop(Node *head) {
//        Node *slow = head;
//        Node *fast = head;
       
//        while(fast!=NULL && fast->next!=NULL){ //if fast is null then loop deosnt exisits
//            slow = slow->next; //move 1 step
//            fast = fast->next->next; //move 2 step
           
//            if(slow==fast) //slow and fast at same position brek
//             break;
//        }
       
//     //   edge case if fast null and fast->next is Null then 0
//     if(fast==NULL || fast->next==NULL)
//     return 0;
       
//     //loop exists then count lenght
//     int count  = 0; //count = 1 we can take becuase moving first so assining the 1 count
//     slow = fast->next; //move slow to next node
//     while(slow!=fast){ //if slow and fast not equal then move if equal then stop or break loop
//         count++; // increase count
//         slow = slow->next; //move slow
//     }
    
//     return count+1; //length return added one because first move the slow..
        
//     }
// };
