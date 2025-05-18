// Remove loop in Linked List  gfg medium level question 
// method 1 slow fast pointer approch. with some mathematical approach 

// class Solution {
//   public:
//     // Function to remove a loop in the linked list.
//     void removeLoop(Node* head) {
//         // Detect the loop
//         Node *slow = head , *fast  = head;
        
//         while(fast!=NULL && fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
            
//             if(slow==fast)
//                break;
//         }
        
//         // if there is no loop so return 
//         if(fast==NULL || fast->next==NULL)
//          return;
         
//         //move slow to head
//         slow = head;
//         //meet the slow and fast
//         while(slow!=fast){
//             slow = slow->next;
//             fast = fast->next;
//         }
        
//         // both met then slow move to until the slow->next = fast;
//         while(slow->next!=fast){
//             slow  = slow->next;
//         }
        
//         // match then break the loop
//         slow->next = NULL;
        
    
        
//     }
// };


// method 2.
// class Solution {
//   public:
//     // Function to remove a loop in the linked list.
//     void removeLoop(Node* head) {
//         // Detect the loop
//         Node *slow = head , *fast  = head;
        
//         while(fast!=NULL && fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
            
//             if(slow==fast)
//               break;
//         }
        
//         // if there is no loop
//         if(fast==NULL || fast->next==NULL)
//          return;
         
//         //find the length of loop
//         slow = fast->next;
//         int count =1;
//         while(slow!=fast){
//             count++;
//             slow = slow->next;
//         } //we got the lenght of the loop
//         // now move slow to head and fast move to count
//         slow = head , fast = head;
//         while(count--)
//          fast= fast->next;
         
//         //now meet the slow and fast 
//         while(slow!=fast){
//             slow = slow->next;
//             fast = fast->next;
//         }
        
//         // then move slow until we get the slow->next = fast;
//         while(slow->next!=fast){
//             slow = slow->next;
//         }
        
//         //break the loop
//         slow->next = NULL;
       
    
        
//     }
// };
