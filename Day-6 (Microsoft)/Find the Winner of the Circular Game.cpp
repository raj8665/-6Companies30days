 
         // Leetcode - 1823

// Recurssion Solution  T.c. = O(n) and S.C. = O(n)

 int solve(int n, int k){
        if(n==1) return 0;

        int idx = solve(n-1,k);
        idx = (idx+k) % n; // To get the original index as we are moving the index 

        return idx;

    }
    int findTheWinner(int n, int k) {
        // in answer there is a + 1 because we are following a 0 based indexing
        return solve(n,k) + 1;
    }

// Bottom up dp T.C. O(n) and S.c = O(1)

int findTheWinner(int n, int k) {
        // in answer there is a + 1 because we are following a 0 based indexing

        // As we have a base case of n==1 so we are ignoring that because it return 0 as we are 
        // following the 0 based indexing
        
        int ans = 0;
        for (int i=2;i<=n;i++){
            ans = (ans+k) % i;
        }
        return ans + 1;
    }