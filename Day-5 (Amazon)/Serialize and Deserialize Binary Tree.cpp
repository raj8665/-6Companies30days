
     // Leetcode - 297

// Encodes a tree to a single string.
    // We are going with pre order traversal but we can use any one of the order traversal ...

    void buildString(TreeNode* root, string &res){
        if(root == NULL){   
            res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    string serialize(TreeNode* root) { 
        if(root==NULL) return ""; 
        string res = "";
        buildString(root, res);
        return res;
    }
    
    TreeNode* buildTree(queue<string> &q) {
        if(q.empty()) return NULL;
        
        string s = q.front();
        q.pop();
        
        if(s == "null") return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        string s = "";
        queue <string> q;
        
        for(char c: data) {
            if(c == ',') {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        
        return buildTree(q);
    }