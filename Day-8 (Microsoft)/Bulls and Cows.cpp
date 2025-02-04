    // Leetcode - 299

    // T.C. Just O(N) Solution but taking space of ~ O(3N) which is not good 

    string getHint(string secret, string guess) {
        int x = 0 , y = 0;
        int n = secret.size();
        unordered_map<int,int> mp1,mp2,mp3;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                mp1[secret[i]]++;
                x++;
            }
        }
        for(auto it : secret){
            mp2[it]++;
        }
        for(auto it : guess){
            mp3[it]++;
        }
        for(auto it : mp1){
            mp2[it.first]-=it.second;
            mp3[it.first]-=it.second;
        }
        for(auto it : mp3){
            if(mp2.find(it.first)!=mp2.end()){
                y += min(mp2[it.first],mp3[it.first]);
            }
        }
        return to_string(x) + "A" + to_string(y) + "B";
    }

    // Now our task is to get rid of this extra space of O(3N)

    string getHint(string secret, string guess) {
    int x = 0, y = 0;  
    int freq[10] = {0};

    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
            x++;
        } else {
            // Increment for secret digit, decrement for guess digit
            if (freq[secret[i] - '0']++ < 0) y++;  
            if (freq[guess[i] - '0']-- > 0) y++;  
        }
    }

    return to_string(x) + "A" + to_string(y) + "B";
    }