      
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

// Solution 2 - Takes O(m) space just store prevRow and prevCorner and update the give matrix 

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Just take any one of the cell and think of what we required just prevRow and one of prev
        // corner of the same row 
        // Now we take extra space O(n) for storing just prev row 
         // Save the dimensions of the image.
        int n = img.size();
        int m = img[0].size();

        // Create temp array of size n.
        vector<int> prevRow(m);
        // ye prev Corner isliye chahiye kuki jb hm prevRow ko update krenge to ye update ho
        // to isko hm store kr lenge 
        int prevCorner = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curSum = 0;
                int cnt = 0;

                // for checking upper row
                if(i-1>=0){
                    curSum+= prevRow[j];
                    cnt++;
                    if(j-1>=0){
                        curSum+= prevCorner;
                        cnt++;
                    }
                    if(j+1<m){
                        curSum+= prevRow[j+1];
                        cnt++;
                    }
                }
                // for checking the same row
                if(j-1>=0){
                    curSum+= prevRow[j-1];
                    cnt++;
                }
                if(j+1<m){
                    curSum += img[i][j+1];
                    cnt++;
                }
                curSum += img[i][j];
                cnt++;
                // for checking down row
                if(i+1<n){
                    curSum += img[i+1][j];
                    cnt++;
                    if(j-1>=0){
                        curSum+=img[i+1][j-1];
                        cnt++;
                    }
                    if(j+1<m){
                        curSum += img[i+1][j+1];
                        cnt++;
                    }
                }
              
              if(i-1>=0){
                prevCorner = prevRow[j];
              }
              prevRow[j] = img[i][j];

              img[i][j] = curSum/cnt;
            }
        }

        // Return the smooth image.
        return img;
    }