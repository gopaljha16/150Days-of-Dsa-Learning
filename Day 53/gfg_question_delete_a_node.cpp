// Gfg Delete in a Singly Linked List easy level


// class Solution {
//     public:
//       /* Function to delete a node from a linked list */
//       Node* deleteNode(Node* head, int x) {
//         if(x==1){
//             Node *temp = head;
//             head = head->next;
//             delete temp;
//             return head;
//         }else{
//             x--;
//             Node *curr = head;
//             Node *prev = NULL;
//             while(x--){
//                 prev = curr;
//                 curr = curr->next;
//             }
//             prev->next = curr->next;
//             delete curr;
//             return head;
//         }
//       }
//   };