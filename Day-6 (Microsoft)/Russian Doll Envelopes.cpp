      
            // Leetcode - 354

   // To Solve this question think about the Longest Increasing Why because it uses a same concept 

       // This is brute for solution Taking Time Complexity O(n^2 ) for Lis  and O(nlogn) for Sorting 
int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // sort the envelope
        sort(envelopes.begin(),envelopes.end());

        int maxi = 1;
        vector<int> dp(n,1);

        // Taking O(n^2) time complexity will give me TLE
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
            }
        }

        return maxi;
    }


     // This is O(nlogn) solution 

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        // Step 1: Sort the envelopes
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1]; 
                 // Sort heights in descending order if widths are the same
                 return a[0] < b[0]; // Sort widths in ascending order
             });

        // Step 2: Extract the heights and apply LIS
        vector<int> heights;
        for (auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        // Step 3: Find LIS using binary search
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h); // Extend LIS if h is larger than any element
            } else {
                *it = h; // Replace the position with the current height
            }
        }

        return lis.size(); // The size of LIS is the maximum number of envelopes
    }