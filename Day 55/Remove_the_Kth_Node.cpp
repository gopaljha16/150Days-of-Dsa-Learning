// gfg  remove the kth node from linked list (easy level)

// class Solution {
//     public:
//       Node* deleteK(Node* head, int k) {
          
//           Node *curr = head , *prev = NULL;
//           int count = 1;
          
//           // edge case all nodes deleting
//           if(k==1)
//            return NULL;
          
//           // till curr exists
//           while(curr){
//               // k == count delete node and move forward
//               if(k==count){
//                   prev->next = curr->next;
//                   delete curr; 
//                   curr = prev->next;
//                   count = 1;
//               }
//               // no node deleting and moving
//               else{
//                   prev = curr;
//                   curr = curr->next;
//                   count++;
//               }
//           }
          
//           return head;
          
//       }
//   };