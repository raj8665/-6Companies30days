// Leetcode - 845 

int longestMountain(vector<int>& arr) {
        // There is a 3 time traversal  in this solution 
        int n = arr.size();
        vector<int> up(n,0) , down(n,0);
 
        // Case-1 : in reverse direction
        for(int i=n-2;i>=0;i--){
           if(arr[i]>arr[i+1]) down[i] = down[i+1] + 1;
        }

        // Case-2 : in forward Direction
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]) up[i] = up[i-1] + 1;
        }

        // Last traversal for answer
        int ans = 0;
        for(int i=0;i<n;i++){
          if(up[i] && down[i]) ans = max(ans,up[i]+down[i]+1);
        }
        return ans;
    }