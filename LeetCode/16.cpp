class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int min_dis = INT_MAX;
    int res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size() - 3; i++) {
      int new_target = target - nums[i];
      int p = i + 1, q = nums.size() - 1;
      int p_last = -1, q_last = -1;
      while (p < q) {
        if (nums[p] + nums[q] == new_target) {
          res = nums[i] + nums[p] + nums[q];
          return res;
        }
        else if (nums[p] + nums[q] > new_target) {
          if (abs(nums[p] + nums[q] - new_target) < min_dis) {
            min_dis = abs(nums[p] + nums[q] - new_target);
            res = nums[i] + nums[p] + nums[q];
          }
          while (true) {
            q--;
            if (q <= i || nums[q] != nums[q + 1]) {
              break;
            }
          }
        }
        else {
          if (abs(nums[p] + nums[q] - new_target) < min_dis) {
            min_dis = abs(nums[p] + nums[q] - new_target);
            res = nums[i] + nums[p] + nums[q];
          }
          while (true) {
            p++;
            if (p >= nums.size() || nums[p] != nums[p - 1]) {
              break;
            }
          }
        }
      }
    }
    return res;
  }
};
