class Solution {
public:
  bool helper(TreeNode* x, TreeNode* y) {
    if ((x==NULL ^ y==NULL) || ((x!=NULL&&y!=NULL)&&(x->val != y->val))) {
      return false;
    }
    if (x!= NULL && y != NULL) {
      return helper(x->left, y->right) && helper(x->right, y->left);
    }
    return true;
  }
  bool isSymmetric(TreeNode* root) {
    if (root == NULL || (root->left == NULL&&root->right == NULL)) {
      return true;
    }
    else {
      return helper(root->left, root->right);
    }
  }
};
