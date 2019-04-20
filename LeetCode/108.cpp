class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) return NULL;
    vector<int> left_nums;
    vector<int> right_nums;
    int index_of_root = nums.size() / 2;
    TreeNode* root = new TreeNode(nums[index_of_root]);
    for (int i = 0; i < index_of_root; i++) {
      left_nums.push_back(nums[i]);
    }
    for (int i = index_of_root+1; i < nums.size(); i++) {
      right_nums.push_back(nums[i]);
    }
    root->left = sortedArrayToBST(left_nums);
    root->right = sortedArrayToBST(right_nums);
    return root;
  }
};
