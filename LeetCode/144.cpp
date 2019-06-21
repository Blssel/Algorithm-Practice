class Solution {
public:
  void helper(TreeNode* root, vector<int>& res) {
    if (root == NULL) {
      return;
    }
    else {
      res.push_back(root->val);
      helper(root->left, res);
      helper(root->right, res);
    }
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
};
