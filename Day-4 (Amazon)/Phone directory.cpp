// GFG

vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
    int m = s.size();
    vector<vector<string>> ans(m);

    // Sort contacts lexicographically
    sort(contact, contact + n);

    string t = "";
    for (int i = 0; i < m; i++) {
        t += s[i];
        vector<string> vec;

        for (int j = 0; j < n; j++) {
            // Skip duplicate contacts
            if (j > 0 && contact[j] == contact[j - 1])
                continue;
            // Check if contact[j] starts with the prefix t
            if (contact[j].find(t) == 0) {
                vec.push_back(contact[j]);
            }
        }

        // If no contacts matched for the prefix, add "0"
        if (vec.empty()) {
            vec.push_back("0");
        }

        // Store the result for the current prefix
        ans[i] = vec;
    }

    return ans;
    }