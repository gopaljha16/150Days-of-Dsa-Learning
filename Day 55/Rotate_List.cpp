// Reverse the List leetcode medium question.


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
//     public:
//         ListNode* rotateRight(ListNode* head, int k) {
//         //  if there no list there or only one list is present
//           if(head==NULL || head->next==NULL){
//             return head;
//           }
//                //  count the nodes
//             int count = 0;
//             ListNode *temp = head;
//             while(temp){
//                 count++;
//                 temp = temp->next;
//             }
    
//             k = k%count; // same rotation skips
          
       
//             count=-k; // skip the nodes
            
//              //   if there is not no rotation 
//             if(k==0){
//                 return head;
//             }
//             //moving the nodes
//             ListNode *curr = head , *prev = NULL;
//             while(count--){
//                 prev = curr;
//                 curr = curr->next;
//             }
    
//             // connection break 
//             prev->next = NULL;
    
//             // second list last moving
//             ListNode *tail = curr;
//             while(tail->next!=NULL){
//                 tail = tail->next; 
//             }
    
//         //    connect the node to head
//             tail->next = head;
//             // point the node to head
//             head = curr;
//             return head;
//         }
    
//     };