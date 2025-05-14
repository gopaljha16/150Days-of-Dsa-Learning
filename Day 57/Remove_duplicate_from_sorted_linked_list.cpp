
// Remove Duplicates from a Sorted Linked List  gfg easy level question 

// first method

// class Solution {
//   public:
//     // Function to remove duplicates from sorted linked list.
//     Node* removeDuplicates(Node* head) {
//      vector<int>ans;
//      ans.push_back(head->data);
     
//      Node *curr = head->next;
//      while(curr){
//          if(ans[ans.size()-1]!=curr->data){ //not get a duplicates
//              ans.push_back(curr->data);
//              curr = curr->next;
//          }else{ //get duplicate then move
//               curr = curr->next;
//          }
//      }
     
//      //now link the list
//      curr = head;
//      int index = 0;
//      while(index<ans.size()){
//          curr->data = ans[index];
//          index++;
//          curr = curr->next;
//      }
//      //unlinking
//      curr= head;
//      int size = ans.size()-1;
//      while(size--){
//          curr = curr->next;
//      }
//      curr->next = NULL;
//      return head;      
//}



// second method optimized where no extra space has taken.


// class Solution {
//   public:
//     // Function to remove duplicates from sorted linked list.
//     Node* removeDuplicates(Node* head) {
//        Node *curr = head->next;
//        Node *prev = head;
       
//       while(curr){  //until current exisits
//           if(curr->data==prev->data){
//               prev->next = curr->next;
//               delete curr;
//               curr = prev->next;
//           }else{
//               curr = curr->next;
//               prev = prev->next;
//           }
//       }
//       return head;
      
//    } 

// };