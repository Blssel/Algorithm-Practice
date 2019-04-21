class Solution {
public:
  void helper(TreeNode* root, TreeNode*& p) {
        //if(root==NULL) return;
        TreeNode* l = root->left;
        root->left = NULL;
        TreeNode* r = root->right;
        root->right = NULL;
    

    if (l != NULL) {
      cout << l->val << endl;
      root->right = l;
      cout << root->right->val << endl;
      p = root->right;
      helper(l, p);
    }
    if (r != NULL) {
      p->right = r;
            p=p->right;
      helper(r, p);
    }
  }
  void flatten(TreeNode* root) {
        if(root==NULL) return;
    TreeNode* p = root;
    helper(root, p);
  }
};
