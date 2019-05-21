class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      res.push_back(q.back()->val);
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur->left != NULL) q.push(cur->left);
        if (cur->right != NULL) q.push(cur->right);
      }
    }
    return res;
  }
};
