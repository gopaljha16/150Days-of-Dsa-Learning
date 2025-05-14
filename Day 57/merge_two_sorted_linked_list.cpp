//   Merge two sorted linked lists gfg medium level question 


// class Solution {
//   public:
//     Node* sortedMerge(Node* head1, Node* head2) {
    
//      Node *head = new Node(0);
//      Node *tail = head;
     
//      while(head1 && head2){ //head1 and head to exisits
//          if(head1->data<=head2->data){ // if head1 is smaller then head2
//              tail->next = head1; // connect to head1
//              head1 = head1->next; /// move head1
//              tail = tail->next; //move tail which new connected
//              tail->next = NULL; // unlink make it tail next to null;
//          }else{ //if head2 is smaller than head1;
//              tail->next = head2;
//              head2 = head2->next;
//              tail = tail->next;
//              tail->next = NULL;
//          }
//      }
     
//     //  if head1 and head2 exists
//     if(head1)
//        tail->next = head1;
//      else
//        tail->next = head2;
       
//     //   delete extra node created at start
//     tail = head; // move tail to start
//     head = head->next; // move head to next node
//     delete tail; //delete the extra node created at start
    
//     return head;
//     }
// };

