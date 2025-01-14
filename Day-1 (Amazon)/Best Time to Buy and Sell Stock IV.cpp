// Leetcode - 188

int f(int i, int buy, int k, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp) {
        // Base-Case
        if (i == n || k == 0)
            return 0;

        // If the result is already computed, return it
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];

        int profit = 0;
        if (buy) {
            // Two choices: Buy the stock or skip
            profit = max(-prices[i] + f(i + 1, 0, k, prices, n, dp),
                         f(i + 1, 1, k, prices, n, dp));
        } else {
            // Two choices: Sell the stock or skip
            profit = max(prices[i] + f(i + 1, 1, k - 1, prices, n, dp),
                         f(i + 1, 0, k, prices, n, dp));
        }

        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, k, prices, n, dp);
    }