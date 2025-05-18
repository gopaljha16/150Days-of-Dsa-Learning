// Linked List Group Reverse gfg medium level question

// class Solution {
//   public:
//     Node *reverseKGroup(Node *head, int k) {
        
//         //dummy Node
//         Node *first = new Node(0); //created dummy node for not writing an condtion
//         first->next = head; //pointing the first to head
//         head = first; //head to first pointing
//         int x;
//         Node *prev , *curr , *front , *second; //creating the pointers
        
//         while(first->next){ //it should run until the first->next exists
              
        
//         //pointing the pointers
//         x = k;
//         second = first->next;
//         prev = first;
//         curr = first->next;
        
//         // reverse the groups code is this..
//         while(x && curr){//x and curr exisits

//          front = curr->next;
//          curr->next = prev;
//          prev = curr;
//          curr = front;
//          x--;
//         }
        
//         //updating the list 
//         first->next = prev; // join to the prev
//         second->next = curr; //second join to curr
//         first = second; // first moving to second
//         }
        
//         //delete the extra node which created
//         first = head; //bring the first to head which is pointing to the dummy node
//         head = head->next; //move head to next
//         delete first; //delte the dummy node
        
//         return head; //return head;
      
        
        
//     }
// };