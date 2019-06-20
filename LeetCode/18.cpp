class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());
    for (int j = 0; j <= nums.size() - 4; j++) {
      if (j >= 1 && nums[j] == nums[j - 1]) {
        continue;
      }
      for (int i = j + 1; i <= nums.size() - 3; i++) {
        if (i > j + 1 && nums[i] == nums[i - 1]) {
          continue;
        }
        else {
          int new_target = target - (nums[j]+nums[i]);
          int p = i + 1, q = nums.size() - 1;
          while (p < q) {
            if (nums[p] + nums[q] == new_target) {
              vector<int> ele(4);
              ele[0] = nums[j], ele[1] = nums[i], ele[2] = nums[p], ele[3] = nums[q];
              res.push_back(ele);
              p++; q--;
              while (p < nums.size() && nums[p] == nums[p - 1]) {
                p++;
              }
              while (q > i && nums[q] == nums[q + 1]) {
                q--;
              }
            }
            else if (nums[p] + nums[q] > new_target) {
              q--;
            }
            else {
              p++;
            }
          }

        }

      }

      
    }
    return res;
  }
};
