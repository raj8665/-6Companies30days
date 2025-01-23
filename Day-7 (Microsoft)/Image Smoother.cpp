      
      // Leetcode - 661

 // Solution 1 - It is accepted but not Satisfied with this extra space O(nm) to store the answer 
 // T.c. O(nm) and S.C O(nm)

  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        
        // take extra space O(mn) for storing average of each cell
        vector<vector<int>> ans(n,vector<int> (m,0)); 

        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int curSum = 0;
                int cnt = 0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1; l<=1; l++){
                        int nrow = i + k;
                        int ncol = j + l;
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                            curSum+= img[nrow][ncol];
                            cnt++;
                        }
                    }
                }
               ans[i][j] = curSum/cnt;
            }
        }
        return ans;
    }

    