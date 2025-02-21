// Smallest Distinct Window (gfg Medium level question)

// int findSubString(string& s) {
//     vector<int>count(256, 0);
//     int first = 0 , second = 0 , len = s.size()  , diff = 0;
    
//     // diff calculatate
//     while(first<s.size()){
//         if(count[s[first]]==0)
//         diff++;  // increase the diffrent if first is 0
        
//         count[s[first]]++; 
        
//         first++;
//     }
    
//     // count make it 0 
//     for(int i=0; i<256; i++){
//         count[i] =0;
//     }
    
//     //update first position 
//     first =0;
    
//     // second is greater than str length break the loop
//     while(second<s.size()){
        
//         // break when diff exisit and second is greater than size
//         while(diff && second<s.size()){
            
//             //if second is character is present then decrease the dif
//             if(count[s[second]]==0)
//             diff--;
            
//             // conunt increase of character
//             count[s[second]]++;
//             // increment of second
//             second++;
//         }
        
//         // update the len for getting the min and smallest length 
//         len = min(len , second-first);
        
//         // diff value when if then window drcreases
//         while(diff!=1){
            
//             // update in every iteration len 
//             len  = min(len , second - first);
            
//             // decrease until diff values becomes 1
//             count[s[first]]--;
            
//             // when becomes 1 then first value becomes 0 then increase diff
//             if(count[s[first]]==0)
//             diff++;
            
//             // increment of first to make an window
//             first++;
//         }
//     }
    
//     return len;
// }