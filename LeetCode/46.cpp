class Solution {
public:
  void swap(vector<int>& nums, int x, int y) {
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
  }
  void helper(vector<int>& nums, int p, vector<vector<int>>& res) {
    if (p == nums.size()) {
      res.push_back(nums);
      return;
    }
    for (int i = p; i < nums.size(); i++) {
      swap(nums, p, i);
      helper(nums, p + 1, res);
      swap(nums, p, i);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    helper(nums, 0, res);
    return res;
  }
};
