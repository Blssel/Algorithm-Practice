class Solution {
public:
  void swap(vector<int>& nums, int x, int y) {
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
  }
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int p = 0;
    //while (p < nums.size()) {
    while (p <= r) {
            if(nums[p]==1){
                p++;
                continue;
            }
      if (nums[p] == 0) {
        swap(nums, l, p);
        if (p == l) {
          l++;
          p++;
        }
        else {
          l++;
        }
      }
      if (p<=r && nums[p] == 2) {
        swap(nums, r, p);
        r--;
      }
    }
  }
};
