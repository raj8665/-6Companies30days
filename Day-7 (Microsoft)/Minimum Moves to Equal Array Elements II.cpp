 
    // Leetcode - 462

// Solution -1 : O(nlogn + n) solution nlogn for sorting but this is basic approach not satisfied with this extra nlogn for sorting 

int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int median = nums[n/2];

        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += abs(median-nums[i]);
        }
        return cnt;
    }

// Solution - 2 : Trying to remove this extra O(nlogn) for sorting and solve it in O(n) time complexity 
 int minMoves2(vector<int>& nums) {
        int n = nums.size();

        // Quick Sort C++ STL as quick Sort take O(n) t.c.
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end());

        int median = nums[n/2];

        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += abs(median-nums[i]);
        }
        return cnt;
    }