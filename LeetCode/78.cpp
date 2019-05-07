class Solution {
public:
  void helper(vector<int>& nums, int p, vector<vector<int>>& res, vector<int>& comb) {
    for (int i = p; i < nums.size(); i++) {
      comb.push_back(nums[i]);
      res.push_back(comb);
      if(i<nums.size()-1)
        helper(nums, i + 1, res, comb);
      comb.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> v;
    vector<int> comb;
    res.push_back(v);
    helper(nums, 0, res, comb);
    return res;
  }
};
