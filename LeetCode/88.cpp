class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = 0, q = 0;
    while (p < m && q < n) {
      if (nums1[p] <= nums2[q]) {
        p++;
      }
      else {
        nums1.insert(nums1.begin()+p, nums2[q]);
                m++;
                p++;
        q++;
      }
    }

    while (q < n) {
      nums1.insert(nums1.begin() + p, nums2[q]);
            m++;
            p++;
      q++;
    }
    for (int i = m + n - 1; i >= m; i--) {
      nums1.erase(nums1.begin() + i);
    }
  }
};
