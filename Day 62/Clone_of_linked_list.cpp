// Clone the Linked list gfg hard level question 


//method 1 time complexity O(n^2) and space complexity O(n); 
// class Solution {
//   public:
  
//   Node* find(Node *curr1 , Node *curr2 , Node *x){ // x is the address to find
//         //base case
//         if(x==NULL)
//          return NULL;
         
//          while(curr1!=x){ //till curr1 is not equal to x move
//              curr1= curr1->next;
//              curr2  = curr2->next;
//          }
//          // join to the random pointer.
//          return curr2;
//   }
//     Node *cloneLinkedList(Node *head) {
        
//         //dummy node creating
//         Node *headCopy = new Node(0);
//         Node *tailCopy = headCopy;
//         Node *temp = head;
        
//         //creating the clone without random pointer
//         while(temp){ //till temp exisits
//           tailCopy->next = new Node(temp->data);
//           tailCopy = tailCopy->next;
//           temp = temp->next;
//         } //copy created without random pointer
        
//         //now delete the dummy node
//         tailCopy = headCopy;
//         headCopy = headCopy->next;
//         delete tailCopy;
        
//         //get the tailCopy to headCopy and temp to head starting 
//         tailCopy = headCopy;
//         temp = head;
        
//         while(temp){//till temp exisits
//         tailCopy->random = find(head , headCopy , temp->random); //it will coneect randmon ointer
//         tailCopy  = tailCopy->next; // move tailCopy
//         temp = temp->next; // move temp 
//         }
        
//         return headCopy;
        
//     }
// };


// Method 2 by using unordered map and the TC O(n) and SC O(n);

// class Solution {
//   public:
  

//     Node *cloneLinkedList(Node *head) {
        
//         //dummy node creating
//         Node *headCopy = new Node(0);
//         Node *tailCopy = headCopy;
//         Node *temp = head;
        
//         //creating the clone without random pointer
//         while(temp){ //till temp exisits
//           tailCopy->next = new Node(temp->data);
//           tailCopy = tailCopy->next;
//           temp = temp->next;
//         } //copy created without random pointer
        
//         //now delete the dummy node
//         tailCopy = headCopy;
//         headCopy = headCopy->next;
//         delete tailCopy;
        
//         //get the tailCopy to headCopy and temp to head starting 
//         tailCopy = headCopy;
//         temp = head;
        
//         //unordered map using 
//         unordered_map<Node * , Node *>m;
        
//         //fill the map with the address
//         while(temp){
//             m[temp] = tailCopy; //filling temp address to tailAddress
//             tailCopy = tailCopy->next; //move 
//             temp = temp->next; //move
//         }
        
//         // now random pointer conneting so get temp and tailCopy to start
//         tailCopy = headCopy;
//         temp = head;
        
//         while(temp){ //link the randon pointer
//             tailCopy->random = m[temp->random];
//             tailCopy = tailCopy->next;
//             temp = temp->next;
//         }
        
        
//         return headCopy;
        
//     }
// };

//method 3 most optimized approch 

// class Solution {
//   public:
  

//     Node *cloneLinkedList(Node *head) {
        
//         //dummy node creating
//         Node *headCopy = new Node(0);
//         Node *tailCopy = headCopy;
//         Node *temp = head;
        
//         //creating the clone without random pointer
//         while(temp){ //till temp exisits
//           tailCopy->next = new Node(temp->data);
//           tailCopy = tailCopy->next;
//           temp = temp->next;
//         } //copy created without random pointer
        
//         //now delete the dummy node
//         tailCopy = headCopy;
//         headCopy = headCopy->next;
//         delete tailCopy;
        
//         //get the tailCopy to headCopy and temp to head starting 
//         tailCopy = headCopy;
//         temp = head;
        
//         //insert them in original linked list merge
//         Node *curr1 = head ,  *curr2 = headCopy;
//         Node *front1 , *front2;
        
//         while(curr1){ //exists
//             front1 = curr1->next;
//             front2 = curr2->next;
//             curr1->next = curr2;
//             curr2->next = front1;
//             curr1 = front1;
//             curr2 = front2;
//         } //both the list is inserted merged.
       
//         //assign random pointer
//         curr1 = head;
//         while(curr1){
//             curr2 = curr1->next;
//             if(curr1->random)
//               curr2->random = curr1->random->next;
//              curr1 = curr2->next;
//         }
        
//         //break the linked list (diconnect);
//         curr1 = head;
//         while(curr1->next){ //till curr1->next exists
//             front1 = curr1->next;
//             curr1->next = front1->next;
//             curr1 = front1;
//         }
        
//         return headCopy;
//     }
    
// };