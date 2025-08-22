// Merge K Sorted Linked Lists gfg medium level question here we have used the priority queue to merge the k sorted linked list
// // /*Linked list Node structure

// struct Node
// {
//     int data;
//     Node* next;

//     Node(int x){
//         data = x;
//         next = NULL;
//     }

// };
// */

// class Compare{
  
//   public:
//   bool operator()(Node* a  ,Node *b){
//       return a->data > b->data; //min heap
//   } // using this for the according to the data is should pop the element here smallest element it will be removing the address
// };

// class Solution {
//   public:
  
  
  
//     Node* mergeKLists(vector<Node*>& arr) {
        
//         //min heap
//          priority_queue<Node*, vector<Node*>, Compare> p(arr.begin(), arr.end());
//         //dummy node
//         Node *root = new Node(0);
//         Node *tail= root;
//         Node *temp;
        
//         while(!p.empty()){ // operation goes until the queue is empty heap..
//             temp = p.top();
//             p.pop();
//             //now we have to  point the temp into he tail next element
//             tail->next = temp;
//             tail = tail->next; // move next element
//             if(temp->next) //if temp next eleement exists then push the element..
//              p.push(temp->next);
//         }
        
//         return root->next; //becuase we have created the dummy node soo root->next
        
//     }
// };