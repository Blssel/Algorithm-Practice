/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& dp) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        if (!dp[start][end].empty()) {
            return dp[start][end];
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_nodes = helper(start, i - 1, dp);
            vector<TreeNode*> right_nodes = helper(i + 1, end, dp);
            for (auto l : left_nodes) {
                for (auto r : right_nodes) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        dp[start][end] = res;
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
        return helper(1, n, dp);
    }
};
