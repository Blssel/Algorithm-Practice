class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) != m.end()) {
        m[nums[i]]++;
      }
      else {
        m[nums[i]] = 1;
      }
      if (m[nums[i]] > (nums.size() / 2)) {
        return nums[i];
      }
    }
    return 0;
  }
};
