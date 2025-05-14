// Sort a linked list of 0s, 1s and 2s gfg medium level question

// class Solution {
//   public:
//     Node* segregate(Node* head) {
//         Node *curr = head;
//         int count0 = 0 , count1 = 0, count2 = 0;
        
//         while(curr){
//             if(curr->data==0)
//               count0++;
//             else if(curr->data==1)
//                count1++;
//             else
//               count2++;
            
//             curr= curr->next; // move current
//         }
        
//         curr = head;
        
//         while(count0--){
//             curr->data = 0; //data enter
//             curr = curr->next; // move current
//         }
        
//          while(count1--){
//             curr->data = 1; //data enter
//             curr = curr->next;  // move current
//         }
        
//          while(count2--){
//             curr->data = 2; //data enter
//             curr = curr->next; // move current
//         }
        
//         return head;
        
//     }
// };