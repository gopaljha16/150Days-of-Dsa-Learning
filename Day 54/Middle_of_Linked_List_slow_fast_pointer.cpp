// Middle of Linked List by slow and fast pointer approach 

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
//           ListNode *slow = head , *fast = head;
//           while(fast&&fast->next){
//             slow = slow->next; //1step
//             fast = fast->next->next; // 2 step
//           }
//           return slow; // answer
//         }
//     };