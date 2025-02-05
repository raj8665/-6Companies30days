// Leetcode - 2970

// T.c. of O(n2) and a space but it is empty at the end .. but can consider of O(N)
int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for (int j = i; j < n; j++) {
            vector<int> temp;
            
            // Build new array excluding nums[i:j]
            for (int k = 0; k < i; k++) temp.push_back(nums[k]);
            for (int k = j + 1; k < n; k++) temp.push_back(nums[k]);

            // Check if the remaining array is strictly increasing
            bool flag = true;
            for (int k = 1; k < temp.size(); k++) {
                if (temp[k] <= temp[k - 1]) {
                    flag = false;
                    break;
                }
            }

            if (flag) cnt++;
        }
        }
        return cnt;

    }