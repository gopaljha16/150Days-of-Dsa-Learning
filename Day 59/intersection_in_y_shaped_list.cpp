// Intersection in Y Shaped Lists gfg medium level question.

// METHOD 1

// class Solution {
//   public:
//    Node* intersectPoint(Node* head1, Node* head2) {
//         // lenth of head1;
//         Node *curr1 = head1;
//         int count1 =0;
//         while(curr1!=NULL){
//             count1++;
//             curr1 = curr1->next;
//         }
        
//         //lenght of head2
//         Node *curr2 = head2;
//         int count2 = 0;
//         while(curr2!=NULL){
//             count2++;
//             curr2 = curr2->next;
//         }
        
//         // again bring curr1 and curr2  to head1 and head2;
//         curr1 = head1;
//         curr2 = head2;
        
//         // handle count 1 and count 2 equal 
//         while(count1>count2){
//             curr1 = curr1->next;
//             count1--;
//         }
        
//         while(count2>count1){
//             curr2 = curr2->next;
//             count2--;
//         }
        
//         // intersect
//        while(curr1!=NULL && curr2!=NULL){
//            if(curr1==curr2)
//              return curr1;
             
//            curr1 = curr1->next;
//            curr2 = curr2->next;
//        }
       
//         return NULL;
       
//     }
// };


// method 2
// class Solution {
//   public:
//    Node* intersectPoint(Node* head1, Node* head2) {
       
       
      
//       Node *curr = head1;
//       while(curr->next){ // curr exisits
//           curr = curr->next;
//       }
      
//       curr->next = head1; //loop made
      
//     //   slow and fast point approach 
//     Node *slow = head2 , *fast = head2;
//     while(fast && fast->next){
//         slow = slow->next;
//         fast = fast->next->next;
        
//         if(slow==fast)
//          break;
//     }
    
//     if(!fast || !fast->next){
//         curr->next = NULL;
//         return NULL;
//     }
    
//     slow = head2;
//     while(slow!=fast){
//         slow = slow->next;
//         fast = fast->next;
//     }
    
//     curr->next = NULL;
    
//     return slow;
    
// }
// };
