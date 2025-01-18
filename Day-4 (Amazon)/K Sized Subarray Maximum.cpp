// GFG 

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<pair<int, int>> pq; 
        vector<int> ans;
        int n = arr.size(); 

        for (int i = 0; i < k; i++) {
            pq.push({arr[i], i});
        }
        ans.push_back(pq.top().first);

        for (int i = k; i < n; i++) {
            pq.push({arr[i], i});
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;
    }