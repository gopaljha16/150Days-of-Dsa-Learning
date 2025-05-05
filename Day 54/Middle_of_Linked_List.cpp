// 876. Middle of the Linked List Problem Leetcode.


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
//         ListNode* middleNode(ListNode* head) {
//              int count = 0;
//             //  count the nodes 
//            ListNode *temp = head;
//            while(temp!=NULL){
//             count++;
//             temp = temp->next;
//            }
    
//         //    update count divide by 2
//         count/=2;
        
//         // step have to take according to count from the start
//         temp = head;
//         while(count--){
//             temp = temp->next;
//         }
//         return temp;
//         }
//     };