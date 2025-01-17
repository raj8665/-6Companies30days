// Leetcode - 2385

class Solution {
public:
    vector<vector<int>> graph;
    int maxi = 0;

    void findMaxValue(TreeNode* root) {
        if (root == NULL) return;
        maxi = max(maxi, root->val);
        findMaxValue(root->left);
        findMaxValue(root->right);
    }

    void constructGraph(TreeNode* root) {
        if (root == NULL) return;

        if (root->left) {
            graph[root->left->val].push_back(root->val);
            graph[root->val].push_back(root->left->val);
        }
        if (root->right) {
            graph[root->right->val].push_back(root->val);
            graph[root->val].push_back(root->right->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        // to decide the size of graph and vis array
        findMaxValue(root);

        // Resize graph to accommodate all node values
        graph.resize(maxi + 1);

        // Construct the graph 
        constructGraph(root);

        queue<pair<int, int>> q;
        vector<int> vis(maxi + 1, 0);
        q.push({start, 0});
        vis[start] = 1;

        int time = 0;
        while (!q.empty()) {
            int node = q.front().first;
            int tm = q.front().second;
            q.pop();
            time = max(time, tm);

            for (auto it : graph[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, tm + 1});
                }
            }
        }
        return time;
    }
};
