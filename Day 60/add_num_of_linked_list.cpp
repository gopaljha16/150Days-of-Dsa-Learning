// Add Number Linked Lists gfg medium level question 

// Node* Reverse(Node *curr , Node *prev){
//      //base case
//      if(curr==NULL){
//          return prev;
//      }
     
//      Node *fut = curr->next;
//      curr->next = prev;
     
//      return Reverse(fut , curr);
//  }

// class Solution {
//   public:
//     Node* addTwoLists(Node* num1, Node* num2) {
       
//     //   both num1 and num2 reverse it
//        num1 = Reverse(num1 , NULL);
//        num2 = Reverse(num2 , NULL);
//     //   both reversed
    
//     // two pointer create point to the num1 and num2; 
//     Node *curr1 = num1 , *curr2 = num2;
//     Node *head = new Node(0); //head adding one dummy node for not writing the extra condition
//     Node *tail = head; //adding at the last after this add the node 
//     int sum , carry = 0; //sum and carry
    
//     //addition
//     while(curr1 && curr2) //till curr1 and curr2 exisits
//     {
//         sum = curr1->data+curr2->data+carry; //addition
//         tail->next = new Node(sum%10); //creating the new node and linking to tail->next;
//         tail = tail->next; //moving tail
//         curr1 = curr1->next; //moving curr1
//         curr2 = curr2->next; //moving curr2
//         carry = sum/10; //carry getting from the sum
//     }
    
//     // edge casees if the curr1 and curr2 still exisits
//     while(curr1){ //still curr1 exisits
//         sum = curr1->data+carry; //addition of sum
//         tail->next = new Node(sum%10); //adding node
//         tail = tail->next; //moving tail
//         curr1 = curr1->next; //moving curr1 forward
//         carry = sum/10; // carry getting from the sum
//     }
    
//     // same as still curr2 exisits
//      while(curr2){ //still curr2 exisits
//         sum = curr2->data+carry; //addition of sum
//         tail->next = new Node(sum%10); //adding node
//         tail = tail->next; //moving tail
//         curr2 = curr2->next; //moving curr2 forward
//         carry = sum/10; // carry getting from the sum
//     }
    
//     // edge case if carry still exists
//     while(carry){ //still carry exisits
//         tail->next = new Node(carry%10); //carry addding the node
//         carry/=10; //removing the carry;
//     }
    
//     // now reversing the list and pointing head to next node
//     head = Reverse(head->next , NULL);//passing head->next and null to prev;
// //   the address comes of head then return head;

//    return head;
    
        
//     }
// };
