class Solution {
public:
  void helper(TreeNode* root, int sum, int cur_sum, vector<vector<int>>& res, vector<int> path) {
    cur_sum = cur_sum + root->val;
    path.push_back(root->val);
    if (root->left == NULL&&root->right == NULL) {
            //cout<<"######"<<endl;
      if (cur_sum == sum) {
        res.push_back(path);
      }
    }
    else{
            if (root->left != NULL) {
          helper(root->left, sum, cur_sum, res, path);
            }
            if (root->right != NULL) {
          helper(root->right, sum, cur_sum, res, path);  
            }
        } 
  }
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
        if(root==NULL) return res;
    vector<int> path;
    int cur_sum = 0;
    helper(root, sum, cur_sum, res, path);
    return res;
  }
};
