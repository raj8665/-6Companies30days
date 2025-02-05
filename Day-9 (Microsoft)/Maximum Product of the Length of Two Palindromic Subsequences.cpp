 // Leetcode - 2002

 int lcs(string &s1 , string &s2){
        int n = s1.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int answer(string &s){
        string ss = s;
        reverse(ss.begin(),ss.end());
        return lcs(s,ss);
    }
    int maxProduct(string s) {
        int n = s.size();
        int ans = 0;
        // The T.C. is O(2n * n2) and S.c. is O(n2) for the dp table table for lcs 
        // this code fails above the length of 15 but as of now it satisfies our constraintas 
        // that is 2 <= s.length <= 12
        // we are iterating all the posible subsequences and then try to maximise the product
        for(int i=0;i<=(1<<n);i++){
            string s1 = "", s2 = "";
            for(int j=0;j<n;j++){
                if((1<<j)&i) s1+=s[j];
                else s2 += s[j];
            }
            // what answer does it takes out the length of longest palindromic subsequences 
            // and then using answer we maximise this product 
            ans = max(ans,(answer(s1)*answer(s2)));
        }
        return ans;
    }