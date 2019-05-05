class Solution {
public:
  void helper(vector<int>& nums, vector<bool>& used, vector<int>& perm, int ele_left, vector<vector<int>>& res) {
    cout << ele_left << endl;
    if (ele_left == 0) {
      //cout << "###########" << endl;
      res.push_back(perm);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!used[i]) {
        used[i] = true;
        perm.push_back(nums[i]);
        helper(nums, used, perm, ele_left - 1, res);
        //cout << "!!!!!!!" << endl;
        //cout << nums.size() - 1 << endl;
        perm.erase(perm.begin() + perm.size() - 1); //回溯
        //cout << "*******" << endl;
        used[i] = false;
      }
    }

  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<bool> used(nums.size(), false);
    vector<int> perm;
    helper(nums, used, perm, nums.size(), res);
    return res;
  }
};
