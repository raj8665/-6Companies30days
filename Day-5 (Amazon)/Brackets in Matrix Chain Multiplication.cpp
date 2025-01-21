// GFG 

// Just MCM + Memoize Dp

// question mein bs upper triangular matrix use ho rha h isliye answer s[1][n-1]
    // pe mil rha h if there is confustion then ask chatgpt to fill dp table and s table 
    // for any one of the example 
    int solve(int i, int j, vector<vector<int>> &dp, vector<int> &arr, 
    vector<vector<string>> &s){
        // Two Base Cases
        if(i>j) return 0;
        if(i==j) {
            s[i][j] = string(1, 'A' + i - 1);
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        string ans;
        int mini = INT_MAX;
        
        for(int k=i;k<j;k++){
            // Don't confuse in the index of arr and s they both have different function
            int cost = solve(i,k,dp,arr,s) + solve(k+1,j,dp,arr,s) +
            arr[i-1]*arr[k]*arr[j];
            
            if(cost<mini){
                mini = cost;
                ans = "(" + s[i][k] + s[k+1][j] + ")";
            }
        }
        
        s[i][j] = ans;
        return dp[i][j] = mini;
        
    }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        vector<vector<string>> s(n, vector<string> (n,""));
        solve(1,n-1,dp,arr,s);
        // kuki hm sirf upper triangular matrix hi use kr rhe h 
        return s[1][n-1];
    }