class Solution {
public:
  bool helper(TreeNode* root, int sum, int cur_sum) {
    cur_sum = cur_sum + root->val;
        //cout<<cur_sum<<endl;
    if (root->left == NULL&&root->right == NULL) {
            if (cur_sum == sum) {
                //cout<<"####"<<endl;
                return true;
            }
            else {
                //cout<<"@@@@"<<endl;
                return false;
            } 
                
        }
    else if (root->left != NULL&&root->right != NULL) {
            return helper(root->left, sum, cur_sum) || helper(root->right, sum, cur_sum);
        }
    else if (root->left != NULL) {
            return helper(root->left, sum, cur_sum);   
        }
    else {
            return helper(root->right, sum, cur_sum);    
        }
  }
  bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
    int cur_sum = 0;
    return helper(root, sum, cur_sum);
  }
};
