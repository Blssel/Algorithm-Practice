//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* copy(TreeNode* T, TreeNode* c) {
    if (T != NULL) {
      TreeNode* n = new TreeNode(T->val);
    }
  }
  TreeNode* helper(int begin, int end, TreeNode* T, vector<TreeNode*>& res) {
    if (begin < end) {
      TreeNode* c;
      copy(T, c);
      res.push_back(c);
    }
    for (int i = begin; i <= end; i++) {
      TreeNode* root = new TreeNode(i);
      root->left = helper(begin, i - 1, T);
      root->right = helper(i + 1, end, T);
    }
  }
  vector<TreeNode*> generateTrees(int n) {
    for (int i = 0; i <= n; i++) {
      TreeNode* root = new TreeNode(i);
      root->left = helper(0, i - 1, root);
      root->right = helper(i + 1, n, root);
    }

    helper(1, n, NULL);
  }
};
