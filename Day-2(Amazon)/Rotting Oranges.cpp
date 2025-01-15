// Leetcode - 994

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int time = 0;
        vector<vector<int>> ans = grid;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    {vis[i][j] = 1;
                    q.push({{i,j},0});}
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            time = max(tm,time);

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && 
                grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},tm+1});
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = 2;
                }
            }
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==1) return -1;
            }
        }
        return time;
    }