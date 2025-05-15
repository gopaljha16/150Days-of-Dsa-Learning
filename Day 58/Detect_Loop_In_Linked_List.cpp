// Detect Loop in linked list gfg medium level question 

//method1; time complexity 0(n^2);
// class Solution {

//    bool check(vector<Node*>&visited , Node *curr){
    //    for(int i=0 ; i<visited.size() ; i++){
    //     if(visted[i]==curr){
    //         return 1;
    //     }
    //    }
    //    return 0;
//}
//   public:
//     // Function to check if the linked list has a loop.
//     bool detectLoop(Node* head) {
      
//       Node *curr = head;
//       vector<Node *>visited
      
//       while(curr!=NULL){
          
//          if(check(visited , curr)
                //  return 1;

        //    visited.push_back(curr);
//          curr = curr->next;
//       }
      
//       return 0;
        
//     }
// };


//method2:time complexity o(n) and space complexity o(n);

// class Solution {
//   public:
//     // Function to check if the linked list has a loop.
//     bool detectLoop(Node* head) {
      
//       Node *curr = head;
//       unordered_map<Node* , bool>visited;
      
//       while(curr!=NULL){
          
//           if(visited[curr]==1) //checking exisits or not
//             return 1;
         
//          //adding to map
//          visited[curr]=1;
//          curr = curr->next;
//       }
      
//       return 0;
        
//     }
// };


//method 3:detect the loop in linked list using slow and fast point in space complexity 0(1);

// class Solution {
//   public:
//     // Function to check if the linked list has a loop.
//     bool detectLoop(Node* head) {
      
//        Node *slow = head;
//        Node *fast = head;
       
//        while(fast!=NULL && fast->next!=NULL){ //fast and fast->next exisit 
//            slow = slow->next; //move 1 step
//            fast = fast->next->next; //move 2 step
//            if(slow==fast) //compare
//              return 1;
//        }
//       return 0;
        
//     }
// };