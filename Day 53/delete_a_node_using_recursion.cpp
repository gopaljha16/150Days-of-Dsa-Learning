// Gfg Delete in a Singly Linked List easy level

// class Solution {
//     public:
//       /* Function to delete a node from a linked list */
//       Node* deleteNode(Node* curr, int x) {
//         if(x==1){
//             Node *temp = curr->next;
//             delete curr;
//             return temp;
//         }
        
//         curr->next = deleteNode(curr->next , x-1);
//         return curr;
//       }
//   };