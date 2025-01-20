// GFG 

void matchPairs(int n, char nuts[], char bolts[]) {
        // we have defined an array in the order for sorting of bolts and nuts 
        char arr[] = { '!', '#', '$', '%', '&', '*', '?', '@', '^'};
        
        int idx = 0;
        
        for(int i=0;i<9;i++){
            
            for(int j=0;j<n;j++){
                
                // For Sorting them whichever find first in the order of array we put them 
                // in the first position for nuts and then do similar copy in bolts also.. 
                if(arr[i] == nuts[j]){
                    swap(nuts[j],nuts[idx]);
                    bolts[idx] = nuts[idx];
                    idx++;
                }
            }
        }
    }