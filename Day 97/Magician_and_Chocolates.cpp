// Magician and Chocolates interview bit medium level question..

// int Solution::nchoc(int A, vector<int> &B) {

//    //maxheap 
//    priority_queue<int>p;
   
//    //insert all element
//    for(int i=0 ; i<B.size() ; i++){
//        p.push(B[i]);
//    }
   
//    //max chocolate
//    long long MaxChoc = 0;
   
//    //condition A should be present and p should not be empty 
//    while(A&&(!p.empty())){
//        MaxChoc+=p.top(); // added the height element
       
//        if(p.top()/2){ //checking the element is 0 or not
//            p.push(p.top()/2);
//        }
       
//        p.pop();
//        A--;
//    }
   
//    return MaxChoc%1000000007;

// }


