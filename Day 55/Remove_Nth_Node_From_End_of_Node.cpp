// 19. Remove Nth Node From End of List Leetcode medium level 

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
//         ListNode* removeNthFromEnd(ListNode* head, int n) {
//             ListNode *temp = head;
//             int count = 0;
//             // count the nodes
//             while(temp){
//                 count++;
//                 temp = temp->next;
//             }
            
//             count-=n;
//             // first Node handling
//             if(count==0){
//                 temp = head;
//                 head = head->next;
//                 delete temp;
//                 return head;
//             }
    
//             ListNode *curr = head , *prev = NULL;
//             while(count--){
//                 prev = curr;
//                 curr = curr->next;
//             }
    
//             prev->next = curr->next; //attaching to the curr next node
//             delete curr; //deleting node
    
//             return head;
//         }
//     };
