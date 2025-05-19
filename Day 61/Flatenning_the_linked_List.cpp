// Flattening a Linked List gfg medium level question 

// class Solution {
//   public:
    
//     Node* Merge(Node *head1 , Node *head2){
//         //creating new dummy node for edge cases
//         Node *head = new Node(0);
//         Node *tail = head;
        
//         //merge code
//         while(head1 && head2){ // loop run it the head1 and head2 exisits
//             if(head1->data <= head2->data){ //if head is smaller than equal to head2
//                 tail->bottom = head1; // then connect to the tail here bottom we are connecting
//                 head1 = head1->bottom; // move head1 
//                 tail = tail->bottom; // move tail
//                 tail->bottom = NULL; // after connecting tail->bottom make it null
//             }else{ // head is smaller than the head1
//                 tail->bottom = head2; // connect to the tail head2 bottom 
//                 head2 = head2->bottom; // move head2
//                 tail = tail->bottom; // move tail 
//                 tail->bottom = NULL; // disconnec the tail.
//             }
            
//         }
            
//             //edge cases if head1 and head2 becomes null connect to tail
//             if(head1){ 
//                 tail->bottom = head1;
//             }else{
//                 tail->bottom = head2;
//             }
            
//             // delete the dummy node 
//             Node *temp = head;
//             head = head->bottom;
//             delete temp;
            
//             return head;
      
//     }
  
//     // Function which returns the  root of the flattened linked list.
//     Node *flatten(Node *root) {
        
//         // create three pointers
//         Node *head1 , *head2 , *head3;
        
//         while(root->next){ //till root->next exisits
//           //first link.
//             head1 = root;
//             head2 = root->next;
//             head3 = root->next->next;
            
//             // unlink
//             head1->next = NULL;
//             head2->next = NULL;
            
//             //then merge
//             root = Merge(head1 , head2); //store it in the root
            
//             root->next = head3; //then point the root->next to head3 then the process goes on..
//         }
        
//         return root;
        
//     }
// };