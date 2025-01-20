// GFG 

// Just MCM + Memoize Dp

int solve(int i, int j, vector<vector<int>>& dp, 
    vector<vector<string>>& solution, vector<int>& arr) {
    if (i == j) {
        solution[i][j] = string(1, 'A' + i - 1);
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    string bestOrder;

    for (int k = i; k < j; k++) {
        int cost = solve(i, k, dp, solution, arr) + solve(k + 1, j, dp, solution, arr) + 
        arr[i - 1] * arr[k] * arr[j];
        if (cost < mini) {
            mini = cost;
            bestOrder = "(" + solution[i][k] + solution[k + 1][j] + ")";
        }
    }

    solution[i][j] = bestOrder;
    return dp[i][j] = mini;
   }

    string matrixChainOrder(vector<int> &arr) {
        // code here
    int N = arr.size();
    vector<vector<int>> dp(N, vector<int>(N, -1));
    vector<vector<string>> solution(N, vector<string>(N, ""));

    solve(1, N - 1, dp, solution, arr);
    return solution[1][N - 1];
    }