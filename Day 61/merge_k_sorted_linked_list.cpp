// Merge K sorted linked lists gfg medium level question 

//method 1;
// Node* Merge(Node *head1 , Node *head2){
    
//     Node *head = new Node(0);
//     Node *tail = head;
    
//     while(head1 && head2){
//         if(head1->data<=head2->data){
//             tail->next = head1;
//             head1 = head1->next;
//             tail = tail->next;
//             tail->next = NULL;
//         }else{
//             tail->next = head2;
//             head2 = head2->next;
//             tail = tail->next;
//             tail->next = NULL;
//         }
//     }
    
//     //edge cases // there is no nodes left connect with the tail
//      if(head1){ 
//          tail->next = head1;
//      }else{
//          tail->next = head2;
//      }
     
//      //remove the dummy node
//      Node *temp = head;
//      head = head->next;
//      delete temp;
     
//      return head;
   
// }

// class Solution {
//   public:
//     Node* mergeKLists(vector<Node*>& arr) {
//         // Your code here
//         int k = arr.size();
//         Node *head = arr[0];
//         for(int i=1 ; i<k ; i++){
//             head = Merge(head , arr[i]);
//         }
        
//         return head;
//     }
// };


//method 2 merge sort method.
// Node* Merge(Node *head1 , Node *head2){
    
//     Node *head = new Node(0);
//     Node *tail = head;
    
//     while(head1 && head2){
//         if(head1->data<=head2->data){
//             tail->next = head1;
//             head1 = head1->next;
//             tail = tail->next;
//             tail->next = NULL;
//         }else{
//             tail->next = head2;
//             head2 = head2->next;
//             tail = tail->next;
//             tail->next = NULL;
//         }
//     }
    
//     //edge cases // there is no nodes left connect with the tail
//      if(head1){ 
//          tail->next = head1;
//      }else{
//          tail->next = head2;
//      }
     
//      //remove the dummy node
//      Node *temp = head;
//      head = head->next;
//      delete temp;
     
//      return head;
   
// }

// void MergeSort(vector<Node*>& arr, int start , int end){
    
//     //base case
//     if(start>=end)
//      return;
     
//      int mid = start + (end - start)/2;
     
//      //left side
//      MergeSort(arr , start , mid);
//      //right side
//      MergeSort(arr , mid+1 , end);
     
//      //storing it to the arr[start] node so 0th node down returining.
//      arr[start] = Merge(arr[start] , arr[mid+1]);
// }
// class Solution {
//   public:
//     Node* mergeKLists(vector<Node*>& arr) {
//         // Your code here
//         int k = arr.size();
//         MergeSort(arr , 0 , k);
//         return arr[0]; //where the linked list will be stored.
//     }
// };