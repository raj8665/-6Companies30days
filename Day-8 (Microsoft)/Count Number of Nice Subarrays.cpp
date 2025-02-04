
  // Leetcode - 1248

// The T.C. is O(4N) and the space complexity of O(1)
  int solve(vector<int> &nums, int k){
        if(k<0) return 0;
        int l=0 , r = 0, cnt = 0, sum = 0;
        int n = nums.size();
        while(r<n){
            sum += nums[r];
            while(sum>k){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Make all the even integer tp 0 and odd integer to 1 and use prefix sum technique to 
        // solve the problem 
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = nums[i]%2==0 ? 0 : 1;
        }
        // No. of Subarrays with no. of odds equal to k == no. of subarrays with odds atmost k -
        // no. of subarrays with odds atmost k-1
        return solve(nums,k) - solve(nums,k-1);
    }