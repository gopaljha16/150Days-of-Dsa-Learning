// Palindrome Linked List leetcode easy level question 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
//     public:
//         bool isPalindrome(ListNode* head) {
//             //   edge case if head is only one
//             if(head->next==NULL)
//                return 1;  //then palindrome
    
//             // count the linked list
//             int count = 0;
//             ListNode *temp = head;
//             while(temp){
//                 count++;
//                 temp = temp->next;
//             }
    
//             count/=2; //how many to skip in the linked list
    
//             ListNode *curr = head , *prev = NULL;
//             while(count--){
//                prev = curr;
//                curr = curr->next;
//             } 
//             prev->next = NULL; 
//             // Divided the list. first list is head and second list is curr
    
//             // reverse the second list
//             ListNode *front = NULL;
//             prev = NULL;
//             while(curr){
//                 front = curr->next;
//                 curr->next = prev;
//                 prev = curr;
//                 curr = front;
//             }
    
//             // comparing the 2 lists first list pointing is head  , second list pointing prev
//             ListNode *head1 = head , *head2 = prev;
//             while(head1){
//                 // not equal
//                 if(head1->val!=head2->val)
//                  return 0;
    
//             //   if equal the move
//                  head1 = head1->next;
//                  head2 = head2->next;
//             }
    
//             return 1; // it's palindrom return 1;
    
//         }
//     };