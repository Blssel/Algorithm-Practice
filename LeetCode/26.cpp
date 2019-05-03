class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int pre = 0, cur = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[cur] == nums[pre]) cur++;
      else {
        //cout << cur<<endl;
        nums[++pre] = nums[cur++];
      }
    }
    return pre+1;
  }
};
