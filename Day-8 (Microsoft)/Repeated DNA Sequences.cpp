
// Leetcode - 187

vector<string> findRepeatedDnaSequences(string s) {
        // T.C. = O(2N) and the S.C. is O(N) because hashmap takes extra O(N) for storing the 
        // the substring and O(2N) time complexity for iterating the string and map
        int n = s.size();
        vector<string> ans;
        if(n<=10) return ans;
        unordered_map<string,int> mpp;
        for(int i=0;i<=n-10;i++){
            string h = s.substr(i,10);
            mpp[h]++;
        }
        for(auto it : mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }