// Leetcode - 3154

 // Now think of T.C. and S.C. both are O(32x32x2x32)
    // 32 for upjump, 32 for downjump, 2 for is there a downjump or upjump, 32 for jump
    int solve(int i, int k, int wasDownJump, int jump, 
        unordered_map<int,unordered_map<int,unordered_map<int,int>>> &dp){
        // ye wala base case tb shi hota agr hme wo bolta ki jaise hi given stair pe pahuch jaye
        // to process rok do but hme carrie on krna h to ye base case nhi hoga 
        // if(i==k || (wasDownJump == 0 && i==k+1)) return 1;
        
        // ye base case hoga ki ab jyada hi ho gya to k pe to nhi phauch skte na kuki agr downJump
        // bhi hui to bhi k pe to nhi aayenge kuki i>k+1
        if (i > k + 1 || jump >= 32) return 0;
 
        // Now do memoization 
        if(dp.count(i) && dp[i].count(wasDownJump) && dp[i][wasDownJump].count(jump)) {
            return dp[i][wasDownJump][jump];
        }
           
        // agr i==k hua to ans = 1 otherwise 0
        int ans = (i==k);

        // (1<<i) mtlb pow(2,jump)
        ans+= solve(i+ (1<<jump) , k, 0, jump+1, dp);

        if(i!=0 && wasDownJump==0){
            ans+= solve(i-1,k,1,jump,dp);
        }

        return dp[i][wasDownJump][jump] = ans;
        
    }
    int waysToReachStair(int k) {
        unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
        return solve(1,k,0,0,dp);
    }